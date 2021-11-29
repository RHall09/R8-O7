s/** @file sensor_suite_task.cpp
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
#include "geofence_task.h"
#include "shares.h"
#include "analog_i2c.h"
#include "digital_i2c.h"
#include "TinyGPS++.h"


#define EVER (;;)

#define GPSSerial Serial1


void sensor_suite_task(void* p_param) {
    // Setup for TinyGPS++
    TinyGPSPlus gps;
    // Couple of intermediate variables for handling data processing
    uint8_t num_ultra = 3;     // Number of ultrasonic sensor in use in the safety sensor suite

    
    for EVER {
        // First update the GPS data from the GPS featherwing. We'll need to use the TinyGPS++ library to extract lattitude
        // and longitude from the NMEA string
        if (GPSSerial.available()) {
            gps.encode(GPSSerial.read());
        }
        // Update the lattitude and longitude queues if there is data to add to them
        if (gps.location.isUpdated()) {
            latitude_queue.put(gps.location.lat());
            longitude_queue.put(gps.location.lng());
        }
        
        // Now update the crowd sensor suite.
    }
}