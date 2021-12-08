/** @file motor_CS_B_task.cpp
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

/// Force a for loop to say for EVER. More fun
#define EVER (;;)

void motor_task_B (void* p_params) 
{
    
    Motor motor(GPIO_NUM_6,GPIO_NUM_9,GPIO_NUM_10);     // Set up Left Motor
    MotorCS motC;
    motor.enable();

    uint8_t current_flag = 0;
    
    float enc_vel = 0;
    float enc_dt = 0;

    for EVER 
    {
        // Get motor flag register from share
        current_flag = motorFlagRegister.get();

        // Check motors for overcurrent fault
        motor.checkOvercurrent();

        if(!(motor.FlagChk(ERROR)))
        {
            if(bit_chk(Run_Motor_CS))
            {
                if(!motC.checkCS() || !motC.checkCS())
                {
                    motC.startCS();
                }
                // Grab the last encoder velocity value and delta time, then run the
                if(encVel_B_q.any())
                { 

                    enc_vel = encVel_B_q.get();
                    enc_dt  = enc_dt_B_q.get();

                    
                    // Get new setpoints and load into CS, if necessary
                    if(motorSet_B_q.any())
                    {
                        motC.newSetpoint(motorSet_B_q.get());
                    }
      

                    // Run control system
                    motC.run(motor,enc_vel,enc_dt);

                }  
            }
            else
            {
                if(motC.checkCS())
                {
                    motC.stopCS();
                }

                
                //Run motor directly, without CS here


            }
        }
        else
        {
            if(!(bit_chk(Overcurrent_B)) && motor.FlagChk(ERROR))
            {
                bit_set(Overcurrent_B);
            }
            // When clear overcurrent flag is raised, clear motors to run again.
            if(bit_chk(OverC_Clear))
            {
                motor.clearOvercurrent();
                bit_clr(Overcurrent_B);
                if(!(bit_chk(Overcurrent_A)))
                {
                    bit_clr(OverC_Clear);
                }
            }
        }

        motorFlagRegister.put(current_flag);

        vTaskDelay(250);
    }

}