/** @file motor_CS_task.cpp
 *  This file contains a task which... 
 * 
 *  @author Rick Hall
 *  @date   2021-Nov-27 Original file
 */

#include <Arduino.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif

#include <shares.h>                          // Header for shares used in this project
#include <Motor_Drivers/MotorCS.h>
#include <Motor_Drivers/Motor.h>
#include <ME507_Support/taskqueue.h>
#include <ME507_Support/taskshare.h>

#define EVER (;;)

void motor_task (void* p_params) 
{
    
    Motor motorA(GPIO_NUM_13,GPIO_NUM_12,GPIO_NUM_11);     // Set up Left Motor
    MotorCS motAc;
    motorA.enable();
    Motor motorB(GPIO_NUM_6,GPIO_NUM_9,GPIO_NUM_10);       // Set up Right Motor
    MotorCS motBc;
    motorB.enable();

    uint8_t current_flag = 0;
    
    float encA_vel = 0;
    float encA_dt = 0;
    float encB_vel = 0;
    float encB_dt = 0;

    motAc.gainSet(Integ, 0.72);

    for EVER 
    {
        // Get motor flag register from share
        current_flag = motorFlagRegister.get();

        // Check motors for overcurrent fault
        motorA.checkOvercurrent();
        motorB.checkOvercurrent();

        if(!(motorA.FlagChk(ERROR) && motorB.FlagChk(ERROR)))
        {
            if(bit_chk(Run_Motor_CS))
            {
                if(!motAc.checkCS() || !motBc.checkCS())
                {
                    motAc.startCS();
                    motBc.startCS();
                }
                // Grab the last encoder velocity value and delta time, then run the
                if(encVel_A_q.any() || encVel_B_q.any())
                { 
                    if(encVel_A_q.any())
                    {
                        encA_vel = encVel_A_q.get();
                        encA_dt  = enc_dt_A_q.get();
                    }
                    if(encVel_B_q.any())
                    {
                        encB_vel = encVel_B_q.get();
                        encB_dt  = enc_dt_B_q.get();
                    }
                    
                    // Get new setpoints and load into CS, if necessary
                    if(motorSet_A_q.any())
                    {
                        motAc.newSetpoint(motorSet_A_q.get());
                    }
                    if(motorSet_B_q.any())
                    {
                        motBc.newSetpoint(motorSet_B_q.get());
                    }        

                    // Run control systems (toggle each time to average out computational difference in time between motors)
                    static bool tog = true;     // boolean to average out minor variations in motor opearation
                    if(tog)
                    {
                        motAc.run(motorA,encA_vel,encA_dt);
                        motBc.run(motorB,encB_vel,encB_dt);
                    }
                    else
                    {
                        motBc.run(motorB,encB_vel,encB_dt);
                        motAc.run(motorA,encA_vel,encA_dt);
                    }
                    tog = !tog;    
                }  
            }
            else
            {
                if(motAc.checkCS() || motBc.checkCS())
                {
                    motAc.stopCS();
                    motBc.stopCS();
                }

                
                //Run motor directly, without CS here


            }
        }
        else
        {
            if(!(bit_chk(Overcurrent_A)) && motorA.FlagChk(ERROR))
            {
                bit_set(Overcurrent_A);
            }
            if(!(bit_chk(Overcurrent_B)) && motorB.FlagChk(ERROR))
            {
                bit_set(Overcurrent_B);
            }
            // When clear overcurrent flag is raised, clear motors to run again.
            if(bit_chk(OverC_Clear))
            {
                motorA.clearOvercurrent();
                motorB.clearOvercurrent();
                bit_clr(OverC_Clear);
                bit_clr(Overcurrent_A);
                bit_clr(Overcurrent_B);
            }
        }

        motorFlagRegister.put(current_flag);

    }

    // vTaskDelay(5)    Currently delays for 5 seconds

}