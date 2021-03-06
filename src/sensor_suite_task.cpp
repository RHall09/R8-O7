/** @file sensor_suite_task.cpp
 *  @brief The task that checks the status of all active sensors.
 *  @details This file contains a task which updates the read values off of *all* sensors
 *  directly related to guest safety. This includes the crowd interaction suite
 *  and the foot mounted checks.
 * 
 *  @author Kai Quizon
 *  @date   2021-Nov-27 Original file 
 *  @copyright (c) 2021 by Kai Quizon, released under the LGPL 3.0.
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
#include "Adafruit_VL53L1X.h"


/// Force a for loop to say for EVER. More fun
#define EVER (;;)

/// Serial port to which the GPS module is attached
#define GPSSerial Serial1

/// Interrupt pin that the VL53L1X sensor is attached
#define IRQ_PIN 2
/// Shutoff pin that the VL53L1X sensor is attached
#define XSHUT_PIN 3

/// Object of Adafruit_VL53L1X class for operating a laser TOF sensor
Adafruit_VL53L1X vl53 = Adafruit_VL53L1X(XSHUT_PIN, IRQ_PIN);


void sensor_suite_task(void* p_param) {
    // Setup for TinyGPS++
    TinyGPSPlus gps;
    // Couple of intermediate variables for handling data processing
    // uint8_t num_ultra = 3;     // Number of ultrasonic sensor in use in the safety sensor suite

    
    
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
        
        // Now update the main Time of Flight Sensor
          int16_t distance;

        if (vl53.dataReady()) 
        {
            // new measurement for the taking!
            distance = vl53.distance();
            if (distance == -1) {
            // something went wrong!
            return;
            }
            else {
                tof_main.put(distance);
            }
        }

        // Now update the
}