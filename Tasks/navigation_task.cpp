/** @file navigation_task.cpp
 *  This file contains a task which combines information from the geofence task, safety sensor suite task,
 *  ShowSense task, and bluetooth controller task to determine the necessary information to send to the 
 *  motor controller task.
 * 
 *  @author Kai Quizon
 *  @date   2021-Nov-29 Original file 
 */

#include <Arduino.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
#include "navigation_task.h"
#include "shares.h"

#define EVER (;;)

void navigation_task(void* p_param) {
    /*
    Ok there is a lot going on here so I'm going to outline everything in a nice little block here. 
    First and foremost this task looks for updated data from the safety sensor suite. If any obstacles are detected, 
    one of two possible aversions is performed:
        1) The bot immediately stops. This is used if the obstacle is within a critical distance to avoid collision.
        2) The bot slowly changes its heading to avoid the future collision.

    This task also checks the geofence returned data to see if a collision with the geofence is likely. If a collision
    with the fence is imminent, the bot changes its heading slowly to avoid colliding with the fence.

    Finally, this task contains overrides for the various tasks to allow for bluetooth RC style control and follow me protocols.
    If the shares are set from the bluetooth task, this task is essentially disabled, data collection is disabled, geofencing calculations
    are disabled, and the bot is simply controlled via bluetooth. The overrides take place in their respective tasks, including navigation.
    */
   
}