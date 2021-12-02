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
#include "Geofence_Drivers/geofencing.h"
#include "Geofence_Drivers/TinyGPS++.h"

#define EVER (;;)

void geofence_task (void* p_params) 
{
    float latitude;                    // Holds lattitude of bot from sensor suite task
    float longitude;              // Holds longitude of bot from sensor suite task
    float fence_lat[] =  { 35.30242, 35.30249, 35.30239, 35.30238};  // The geofence lattitude points to be used
    float fence_long[] = {120.66457,120.66477,120.66472,120.66461};  // The geofence longitude points to be used
    uint8_t fence_size = 4;       // The number of points defining the geofence
    float local_heading;                // The heading returned by the geofence task locating hte nearest geofence point
    float local_distance;               // The distance returned by the geofence task indicating the closest geofence point

    // GPS Initialization
    TinyGPSPlus gps;     // Start the TinyGPS++ module
    #define GPSSerial Serial1    // Define the serial port with the gps featherwing attached

    for EVER 
    {
        // Grab the updated GPS data from the sensor and feed the hungry hungry
        // tiny gps hippo. Once the beast is satiated, check for updated lattitude
        // and longggggitude values. Then run the geofence to update the distance 
        // and heading. Pretty cool if I do say so myself.

        while (GPSSerial.available() > 0) 
        {
        
            gps.encode(GPSSerial.read());
        }
        if (gps.location.isUpdated()) 
        {
            latitude  = gps.location.lat();
            longitude = gps.location.lng();
        }

        local_distance = geofencing(latitude, longitude, fence_lat, fence_long, fence_size); // , local_heading
        fence_distance.put(local_distance);
        //fence_heading.put(local_heading);

        Serial << "Fence at: " << local_distance << endl;
        
        vTaskDelay(250);    // Run this task every 250 ms

    }

}