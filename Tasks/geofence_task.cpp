/** @file geofence_task.cpp
 *  This file contains a task which calculates the shortest straight line distance
 *  from the bots current position to the edge of the geofence
 * 
 *  @author Kai Quizon
 *  @date   2021-Nov-27 Original file 
 */

#include <Arduino.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
#include "geofence_task.h"
#include "shares.h"
#include "geofencing.h"

#define EVER (;;)

void geofence_task (void* p_params) {
    float lat;                    // Holds lattitude of bot from sensor suite task
    float longitude;              // Holds longitude of bot from sensor suite task
    float fence_lat[] = {0,0,0};  // The geofence lattitude points to be used
    float fence_long[] = {0,0,0}; // The geofence longitude points to be used
    uint8_t fence_size = 3;       // The number of points defining the geofence
    float heading;                // The heading returned by the geofence task locating hte nearest geofence point
    float distance;               // The distance returned by the geofence task indicating the closest geofence point

    for EVER {
        // Grab the updated GPS data from the sensor suite task, if available.
        // This line is blocking, meaning that this task only runs when the GPS data
        // is updated. For now this means we aren't using a delay, however it may be needed
        // depending on how often GPS data is updated.
        if (geofence_enable.get()) {
            lat       = latitude_queue.get();
            longitude = longitude_queue.get();

            distance, heading = geofencing(lat, longitude, fence_lat, fence_long, fence_size);
            fence_distance.put(distance);
            fence_heading.put(heading);
            // vTaskDelay(5)    Currently delays for 5 seconds
        }
    }

}