/** @file baby_motor_task.cpp
 *  This file contains a task which does stuff
 * 
 *  @author Rick Hall
 *  @date   2021-Dec-02 Original file 
 */



#include <Arduino.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
#include <Motor_Drivers/Adafruit_MotorShield.h>
#include <Motor_Drivers/utility/Adafruit_MS_PWMServoDriver.h>
#include <PrintStream.h>
#include <shares.h>

#define EVER (;;)

void baby_motor_task (void* p_params) 
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

    Serial << "Motors are setup" << endl;

    for EVER
    {
        //Serial << "Motor Task -----------" << endl;
        if(motorSet_A_q.any())
        {
            //Serial << "Motor A updated" << endl;
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
            //Serial << "Motor B updated" << endl;
            setB = motorSet_B_q.get();
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

        //Serial << "Now we're setting the motors to run" << endl;
        if(stopA)
        {
            //Serial << "Motor A Stopped" << endl;
            // leftMotor -> run(RELEASE);
        }
        else if(dirA)
        {
            //Serial << "Motor A Forward" << endl;
            // leftMotor -> setSpeed(setA);
            // leftMotor -> run(FORWARD);
        }
        else
        {
            //Serial << "Motor A Backward" << endl;
            // leftMotor -> setSpeed(setA);
            // leftMotor -> run(BACKWARD);
        }

        if(stopB)
        {
            //Serial << "Motor B Stopped" << endl;
            // rightMotor -> run(RELEASE);
        }
        else if(dirB)
        {
            //Serial << "Motor B Forward" << endl;
            // rightMotor -> setSpeed(setB);
            // rightMotor -> run(FORWARD);
        }
        else
        {
            //Serial << "Motor B Backward" << endl;
            // rightMotor -> setSpeed(setB);
            // rightMotor -> run(BACKWARD);
        }

        //Serial << "Motors are set at: " << setA << " and " << setB << endl;
        vTaskDelay(250);

    }
}