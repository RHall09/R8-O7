/** @file encoder_B_task.cpp
 *  @brief This file contains a task which periodically reads the encoder for the right motor.
 * 
 *  @author Rick Hall
 *  @date   2021-Nov-27 Original file
 *  @copyright (c) 2021 by Rick Hall, released under the LGPL 3.0.
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
#include <Motor_Drivers/ESP32Encoder.h>
#include <Motor_Drivers/InterruptEncoder.h>
#include "encoder_B_task.h"

/// Force a for loop to say for EVER. More fun
#define EVER (;;)

void encoder_B_task (void* p_params) 
{
    
    ESP32Encoder my_encoder;
    my_encoder.attachFullQuad(GPIO_NUM_26,GPIO_NUM_25);

    bool count_overflow = false;
    uint64_t encoder_current_read = 0;
    uint64_t encoder_last_read = 0;
    uint64_t encoder_diff = 0;
    float encoder_velocity = 0;

    /// The pulses per revolution of the encoder
    #define ENCODER_PPR 4000
    


    for EVER 
    {
        encoder_current_read = my_encoder.getCount();

        if(encoder_current_read > 1000000)
        {
            my_encoder.clearCount();
            count_overflow = true;
        }

        encoder_diff = encoder_current_read - encoder_last_read;
        encoder_velocity = (float)encoder_diff / ENCODER_PPR;

        encVel_B_q.put(encoder_velocity);

        if(count_overflow)
        {
            encoder_last_read = 0;
            count_overflow = false;
        }
        else
        {
            encoder_last_read = encoder_current_read;
        }
        

        vTaskDelay(250);
    }

    

}