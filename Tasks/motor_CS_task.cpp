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

#include "shares.h"                          // Header for shares used in this project
#include "MotorCS.h"
#include "Motor.h"

#define EVER (;;)

void motor_task (void* p_params) 
{
    
    Motor motorA(GPIO13,GPIO12,GPIO11);     // Set up Left Motor
    MotorCS motAc(void);
    motorA.enable();
    Motor motorB(GPIO6,GPIO9,GPIO10);       // Set up Right Motor
    MotorCS motBc(void);
    motorB.enable();



    for EVER 
    {
        // Get motor flag register from share
        current_flag = motorFlagRegister.get();

        // Check motors for overcurrent fault
        motorA.checkOvercurrent();
        motorB.checkOvercurrent();

        if(!(motorA.FlagChk(ERROR) && motorB.FlagChk(ERROR)))
        {

            // Grab the last encoder velocity value and delta time, then run the
            if()
            { 
                encA_vel = encoderA_velocity_queue.get();
                encB_vel = encoderB_velocity_queue.get();
                encA_dt  = encoderA_dtime_queue.get();
                encB_dt  = encoderB_dtime_queue.get();
                
                // Get new setpoints and load into CS, if necessary
                if()
                {
                    motAc.newSetpoint(motorA_Set.get());
                }
                if()
                {
                    motBc.newSetpoint(motorB_Set.get());
                }        

                // Run control systems (toggle each time to average out computational difference in time between motors)
                static bool tog = true;     // boolean to average out minor variations in motor opearation
                if(tog)
                {
                    motAc.run(motorA,encA_vel,encA_dt);
                    motBC.run(motorB,encB_vel,encB_dt);
                }
                else
                {
                    motBc.run(motorB,encB_vel,encB_dt);
                    motAC.run(motorA,encA_vel,encA_dt);
                }
                tog = !tog;    
            }  
            
        }
        else
        {
            // When clear overcurrent flag is raised, clear motors to run again.
            if()
            {
                motorA.clearOvercurrent()
                motorB.clearOvercurrent()
            }
        }

    }

    // vTaskDelay(5)    Currently delays for 5 seconds

}