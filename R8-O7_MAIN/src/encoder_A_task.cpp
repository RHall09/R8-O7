/** @file encoder_A_task.cpp
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
#include <Motor_Drivers/AiEsp32RotaryEncoder.h>
#include <Motor_Drivers/AiEsp32RotaryEncoderNumberSelector.h> 

#define EVER (;;)

void encoder_A (void* p_params) 
{
    

    for EVER 
    {


        vTaskDelay(250);
    }

    

}