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
#include <Motor_Drivers/ESP32Encoder.h>
#include <Motor_Drivers/InterruptEncoder.h> 

#define EVER (;;)

void encoder_A (void* p_params) 
{
    
    ESP32Encoder my_encoder;
    my_encoder.attachFullQuad(GPIO_NUM_26,GPIO_NUM_25);

    uint64_t time_current_read = 0;
    uint64_t time_last_read = 0;

    uint64_t encoder_current_read = 0;
    uint64_t encoder_last_read = 0;
    


    for EVER 
    {
        my_encoder.getCount();

        vTaskDelay(250);
    }

    

}