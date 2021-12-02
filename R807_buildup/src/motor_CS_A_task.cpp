/** @file motor_CS_A_task.cpp
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

void motor_task_A (void* p_params) 
{
    
    Motor motor(13,12,27, Motor_0);     // Set up Left Motor
    MotorCS motC;
    motor.enable();

    uint8_t current_flag = 0;
    
    float enc_vel = 0;
    float enc_dt = 0;
    int16_t current_setpoint = 0;

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
                if(encVel_A_q.any())
                { 

                    enc_vel = encVel_A_q.get();
                    
                    // Get new setpoints and load into CS, if necessary
                    if(motorSet_A_q.any())
                    {
                        current_setpoint = motorSet_A_q.get();
                        motC.newSetpoint(current_setpoint);
                    }
      

                    // Run control system
                    motC.run(motor,enc_vel);

                }  
            }
            else
            {
                if(motC.checkCS())
                {
                    motC.stopCS();
                }

                if(motorSet_A_q.any())
                {
                    current_setpoint = motorSet_A_q.get();
                    motC.newSetpoint(current_setpoint);
                }
                
                //Run motor directly, without CS here

                motC.run(motor,0);

            }
        }
        else
        {
            if(!(bit_chk(Overcurrent_A)) && motor.FlagChk(ERROR))
            {
                bit_set(Overcurrent_A);
            }
            // When clear overcurrent flag is raised, clear motors to run again.
            if(bit_chk(OverC_Clear))
            {
                motor.clearOvercurrent();
                bit_clr(Overcurrent_A);
                if(!(bit_chk(Overcurrent_B)))
                {
                    bit_clr(OverC_Clear);
                }
            }
        }

        motorFlagRegister.put(current_flag);

        vTaskDelay(250);
    }

}