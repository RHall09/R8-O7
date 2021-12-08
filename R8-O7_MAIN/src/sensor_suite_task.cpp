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

/// The interrupt pin off the digital I2C bus, used for pulseIn from ultrasonic sensors
#define INTERPIN 5




void sensor_suite_task(void* p_param) {
    // Setup for TinyGPS++
    TinyGPSPlus gps;

    /// Object of Adafruit_VL53L1X class for operating a laser TOF sensor
    Adafruit_VL53L1X vl53 = Adafruit_VL53L1X(XSHUT_PIN, IRQ_PIN);

    /// Instance of digital I2C expansion bus class
    i2cdig digpins;

    digpins.joini2c();   // Join the I2C bus ONLY IN THIS TASK!!


    // Couple of intermediate variables for handling data processing and pins
    /// Trigger Pin for first ultrasonic sensor
    uint8_t upin1 = 0;
    /// Trigger Pin for second ultrasonic sensor
    uint8_t upin2 = 1;
    /// Trigger Pin for third ultrasonic sensor
    uint8_t upin3 = 2;
    /// Echo pin for all triggers
    uint8_t echo = 3;

    // Configure the trigger pins as outputs, no need for echo since input is default
    digpins.configport(upin1, false);
    digpins.configport(upin2, false);
    digpins.configport(upin3, false);

    
    
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

        // Now update the three Ultrasonic sensors

        // Ultrasonic 1
        // Clears the trigPin condition
        digpins.setoutput(upin1, false);
        delayMicroseconds(2);
        // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
        digpins.setoutput(upin1, true);
        delayMicroseconds(10);
        digpins.setoutput(upin1, false);
        // Reads the echoPin, returns the sound wave travel time in microseconds
        duration = pulseIn(INTERPIN, HIGH);
        // Calculating the distance
        distance1 = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

        // Ultrasonic 2
        // Clears the trigPin condition
        digpins.setoutput(upin2, false);
        delayMicroseconds(2);
        // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
        digpins.setoutput(upin2, true);
        delayMicroseconds(10);
        digpins.setoutput(upin2, false);
        // Reads the echoPin, returns the sound wave travel time in microseconds
        duration = pulseIn(INTERPIN, HIGH);
        // Calculating the distance
        distance2 = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

        // Ultrasonic 3
        // Clears the trigPin condition
        digpins.setoutput(upin1, false);
        delayMicroseconds(2);
        // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
        digpins.setoutput(upin1, true);
        delayMicroseconds(10);
        digpins.setoutput(upin1, false);
        // Reads the echoPin, returns the sound wave travel time in microseconds
        duration = pulseIn(INTERPIN, HIGH);
        // Calculating the distance
        distance3 = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)


        if (distance1<16 || distance3<16) {
            Obj_flag.put(true);
        }
}