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

    int16_t setA = 0;
    int16_t setB = 0;
    uint8_t pwmA = 0;
    uint8_t pwmB = 0;

    bool dirA = true;
    bool dirB = true;
    bool stopA = true;
    bool stopB = true;

    for EVER
    {
        if(motorSet_A_q.any())
        {
            setA = motorSet_A_q.get();
            if (setA > 0)
            {
                pwmA = (uint8_t)abs(setA);
                dirA = true;
                stopA = false;
            }
            else if (setA < 0)
            {
                pwmA = (uint8_t)abs(setA);
                dirA = false;
                stopA = false;
            }
            else
            {
                stopA = true;
            }
        } 
        if(motorSet_B_q.any())
        {
            setA = motorSet_B_q.get();
            if (setB > 0)
            {
                pwmB = (uint8_t)abs(setB);
                dirB = true;
                stopB = false;
            }
            else if (setB < 0)
            {
                pwmB = (uint8_t)abs(setB);
                dirB = false;
                stopB = false;
            }
            else
            {
                stopB = true;
            }
        }

        if(stopA)
        {
            leftMotor -> run(RELEASE);
        }
        else if(dirA)
        {
            leftMotor -> setSpeed(setA);
            leftMotor -> run(FORWARD);
        }
        else
        {
            leftMotor -> setSpeed(setA);
            leftMotor -> run(BACKWARD);
        }

        if(stopB)
        {
            rightMotor -> run(RELEASE);
        }
        else if(dirB)
        {
            rightMotor -> setSpeed(setB);
            rightMotor -> run(FORWARD);
        }
        else
        {
            rightMotor -> setSpeed(setB);
            rightMotor -> run(BACKWARD);
        }

    }
}