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
#include "sensor_suite_task.h"
#include "shares.h"
#include "analog_i2c.h"
#include "digital_i2c.h"
#include "TinyGPS++.h"
#include "Adafruit_VL53L0X.h"
// #include <HCSR04.h> Not going to use this library since we need to send signals through the digital i2c bus.

#define EVER (;;)

#define GPSSerial Serial1


void sensor_suite_task(void* p_param) {
    // Setup for TinyGPS++
    TinyGPSPlus gps;

    // Setup for Digital I2C chip and join i2c bus as master
    i2cdig dig_io;
    dig_io.joini2c();

    // Setup for Analog I2C chip
    i2cana ana_io;
    // Since we alredy joined the i2c bus above, we don't need to again with the analog since it is one hardware bus.

    // Time of flight sensor setup
    Adafruit_VL53L0X lox = Adafruit_VL53L0X;
    VL53LOX_RangingMeasurementData_t tofmeasure;

    // Pin declarations for the sensors, RELATIVE TO THE I2C CHIPS!!!
    uint8_t sonic1_trig = 0;
    uint8_t sonic2_trig = 1;
    uint8_t sonic3_trig = 2;

    // All the sensors are wired to a single echo pin since they are all called sequentially
    uint8_t sonic_echo = 3;

    // Because the configuration register defaults all pins to inputs, we only need to configure the trigger pins to outputs.
    // Create a list of the pins just to do it in a for loop because I'm cool like that.
    uint8_t trig_pins[] = {sonic1_trig, sonic2_trig, sonic3_trig};
    bool i_o = False; // Create a boolean false just to configure everything to outputs
    for(counter=0; counter<3; counter++) {
         dig_io.configport(trig_pins[counter], i_o);
         dig_io.setoutput(trig_pins[counter], i_o);   // Sets the outputs low after initializing them, since chip defaults to high.
    }

    // Some booleans for setting things low and high
    bool low = false;
    bool high = true;

    // This pin is connected to the interrupt pin of the digital io bus. We will use it to handle the pulse recorded by the ultrasonic
    // sensors.
    pinMode(5, INPUT)
    
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
        
        // Now update the ultrasonic sensors in the crowd sensor suite. THIS CODE IS BLOCKING. PRIORITY IS DISTRUBTED SUCH THAT
        // THIS CODE WILL EXECUTE ABOVE ALL OTHERS.

        // Ultrasonic 1
        dig_io.setoutput(sonic1_trig, low);
        delayMicroseconds(2);
        dig_io.setoutput(sonic1_trig, high);
        delaayMicroseconds(10);
        dig_io.setoutput(sonic1_trig, low);
        noInterrupts();
        float d = pulseIn(5, HIGH);
        interrupts();
        float sonic1_reading = d/58.0;
        sonic1_queue.put(sonic1_reaading);

        // Ultrasonic 2
        dig_io.setoutput(sonic2_trig, low);
        delayMicroseconds(2);
        dig_io.setoutput(sonic2_trig, high);
        delaayMicroseconds(10);
        dig_io.setoutput(sonic2_trig, low);
        noInterrupts();
        float d = pulseIn(5, HIGH);
        interrupts();
        float sonic2_reading = d/58.0;
        sonic2_queue.put(sonic2_reaading);


        // Ultrasonic 3
        dig_io.setoutput(sonic3_trig, low);
        delayMicroseconds(2);
        dig_io.setoutput(sonic3_trig, high);
        delaayMicroseconds(10);
        dig_io.setoutput(sonic3_trig, low);
        noInterrupts();
        float d = pulseIn(5, HIGH);
        interrupts();
        float sonic3_reading = d/58.0;
        sonic3_queue.put(sonic3_reaading);

        // Now we need to grab the time of flight sensor
        lox.rangingTest(&tofmeasure, false);   // Disable debug prinout
        if (tofmeasure.RangeStatus != 4) {     // Only pass data if its meaningful
            tof_safetysuite_queue.put(tofmeasure.RangeMilliMeter);  // Stick the reading in the queue
        }

    }
}