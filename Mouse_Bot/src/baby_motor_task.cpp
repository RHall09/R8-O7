/** @file baby_motor_task.cpp
 *  This file contains a task which calculates the shortest straight line distance
 *  from the bots current position to the edge of the geofence
 * 
 *  @author Rick Hall
 *  @date   2021-Dec-02 Original file 
 */



#include <Arduino.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
#include <Wire.h>
#include <Motor_Drivers/Adafruit_MotorShield.h>
#include <Motor_Drivers/utility/Adafruit_MS_PWMServoDriver.h>
#include <time.h>
#include <shares.h>

#define EVER (;;)

void geofence_task (void* p_params) 
{
    // Adafruit MotorFeatherWing Initialization
    Adafruit_MotorShield AFMS = Adafruit_MotorShield();
    Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
    Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);

    

    for EVER
    {
        if(Motor_A_pwm.any())
        {
            pwmA = Motor_A_pwm.get()
        }                                                                                                           

    }
}