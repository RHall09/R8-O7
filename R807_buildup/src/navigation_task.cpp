/** @file sensor_suite_task.cpp
 *  This file contains a task which updates the read values off of *all* sensors
 *  directly related to guest safety. This includes the crowd interaction suite
 *  and the foot mounted checks.
 * 
 *  @author Kai Quizon
 *  @date   2021-Nov-27 Original file 
 */

#include <Arduino.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif

#include "shares.h"

#define EVER (;;)



void navigation_task(void* p_param) {
    // Geofence Heading variable
    float fence_head;
    // Geofence Distance variable
    float fence_dist;

    
    for EVER {

        // First update the distance to the fence and the heading
        fence_head = fence_heading.get();
        fence_dist = fence_distance.get();

        if (fence_dist <= 5) {
            motorSet_A_q.put(0);
            motorSet_A_q.put(100);
        }

        else {
            motorSet_A_q.put(150);
            motorSet_A_q.put(150);
        }
        
    }
}