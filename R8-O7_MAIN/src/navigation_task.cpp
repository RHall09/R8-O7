/** @file navigation_task.cpp
 *  This file contains a task which takes inputs from all sensors 
 *  and the GPS to determine the path of the robot and output motor
 *  PWM values accordingly.
 * 
 *  Update as of 12/4/21:
 *  Due to limitations in the current sensor module, only GPS data 
 *  is currently implemented in the navigation calculation. 
 * 
 *  @author Rick Hall
 *  @date   2021-Dec-02 Original file 
 */

#include <Arduino.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif

#include <PrintStream.h>
#include "shares.h"

#define FENCE_MIN 3

#define EVER (;;)

void navigation_task(void* p_param) {
    // Geofence Heading variable
    float fence_head;
    // Geofence Distance variable
    float fence_dist;
    // GPS Heading
    // float gps_head = 0;

    // Mathematical Heading
    float current_heading = 0;

    // Local copy of shared motor flag register
    uint8_t current_flag = 0;
    current_flag = motorFlagRegister.get();
    current_flag = bit_set(Run_Motor_CS);

    Serial << "Nav task is setup" << endl;

    
    for EVER {

        Serial << "Nav Task ------------ " << endl;
        
        if(!bit_chk(Overcurrent_A) | !bit_chk(Overcurrent_B))
        {
            // First update the distance to the fence and the heading
            fence_head = fence_heading.get();
            fence_dist = fence_distance.get();

            if (0 < (fence_dist - FENCE_MIN)) 
            {
                motorSet_A_q.put(0);
                motorSet_B_q.put(100);
            }
            else 
            {
                motorSet_A_q.put(150);
                motorSet_B_q.put(150);
            }
        }
        
    }
}