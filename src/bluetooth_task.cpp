/** @file bluetooth_task.cpp
 *  @brief A task that collects user input from a paired smartphone.
 * @details    This file contains source code for a task that collects user input from a mobile
 *    application to control R-8O7 over bluetooth, interprets and converts the data as
 *    needed, and sends commands to the sensor suite and motor driver.
 * 
 *  @author Anil Singh
 *  @date   2021-Nov-27 Original file 
 *  @copyright (c) 2021 by Anil Singh, released under the LGPL 3.0.
 */

#include <Arduino.h>
#include "bluetooth_task.h"
#include "PrintStream.h"
#include "BluetoothSerial.h"

/// Make the loop say for EVER
#define EVER (;;)

BluetoothSerial SerialBT;
void bluetooth_task (void* p_param)) {
    Serial.begin(115200);
    SerialBT.begin("ESP32test"); //Bluetooth device name
    Serial.println("Device Initialized, Ready for Pairing");

    for EVER  
    { 
        //Analog Input for Y axis, rescale for pwm (-255 to 255)
        analogTmp = analogRead(joysticYA);
        throttle = (512-analogTmp)/2;

        delayMicroseconds(100);
        //Analog Input for X axis, rescale for pwm (-255 to 255)
        analogTmp = analogRead(joysticXA);
        direction = -(512-analogTmp)/2;

        //Mix Input for Throttle & Direction
        leftMotor = throttle+direction;
        rightMotor = throttle-direction;

        //Print Initial Results
        Serial.print("LIN:"); Serial.print( leftMotor, DEC);
        Serial.print(", RIN:"); Serial.print( rightMotor, DEC);

        //Scale of result in comparison to 8-bit pwm
        leftMotorScale =  leftMotor/255.0;
        leftMotorScale = abs(leftMotorScale);
        rightMotorScale =  rightMotor/255.0;
        rightMotorScale = abs(rightMotorScale);

        Serial.print("| LSCALE:"); Serial.print( leftMotorScale,2);
        Serial.print(", RSCALE:"); Serial.print( rightMotorScale,2);

        //choose the max scale value if it is above 1
        maxMotorScale = max(leftMotorScale,rightMotorScale);
        maxMotorScale = max(1,maxMotorScale);

        //and apply it to the mixed values
        leftMotorScaled = constrain(leftMotor/maxMotorScale,-255,255);
        rightMotorScaled = constrain(rightMotor/maxMotorScale,-255,255);

        Serial.print("| LOUT:"); Serial.print( leftMotorScaled);
        Serial.print(", ROUT:"); Serial.print( rightMotorScaled);
    }