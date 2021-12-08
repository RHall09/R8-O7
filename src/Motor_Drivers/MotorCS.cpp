/** @file MotorCS.cpp
 *  @brief Member functions of a class to drive a motor from \b MD-L6205D.
 *  @details     This file contains the member functions of a class designed to drive a motor with two PWM signals
 *      and an enable pin using the \b MD-L6205D motor driverchip. This class implements a 
 *      PID control loop with user defined gains.
 *  @author Rick Hall
 *  @date 2021-4-Nov
 *  @copyright (c) 2021 by Rick Hall, released under the LGPL 3.0.
 */

#include <Arduino.h>
#include <Motor_Drivers/Motor.h>
#include <Motor_Drivers/MotorCS.h>


// Constructor Function. Store gains inside class object
MotorCS::MotorCS(float kProportional, float kIntegral, float kDerivative)
{
    // Set PID gains
    kP = kProportional;
    kI = kIntegral;
    kD = kDerivative;
}

// Change a gain
void MotorCS::gainSet(CS_Gains k, float gain)
{
    if(k = Prop)  //Change proportional
    {
        kP = gain;
    }
    else if(k = Integ)  // Change Integral
    {
        kI = gain;
    }
    else   // Change Derivative
    {
        kD = gain;
    }

}

// Start CS calculations
void MotorCS::startCS(void)
{
    // Enable control system 
    runCS = true;
}

// Stop CS Calculations
void MotorCS::stopCS(void)
{
    // Disable control system and clear integral counter
    runCS = false;
    integral = 0;
}

// Determine if the CS is currently running
bool MotorCS::checkCS(void)
{
    return runCS;
}

// Change setpoint (with overflow protect)
void MotorCS::newSetpoint(int16_t set)
{
    if ( (-255 < set) && (set < 255))   // If setpoint is a valid PWM signal, set equal to input
    {
        setpoint = set;
    }
    else if (255 < set)                 // If setpoint is too large, feed largest allowable PWM signal
    {
        setpoint = 255;
    }
    else                                // If setpoint is too low, feed lowest allowable PWM signal
    {
        setpoint = -255;
    }
}

// Run CS
void MotorCS::run(Motor motor, int16_t enc_velocity, int16_t set)
{
    // If the CS is enabled
    if (runCS)
    {
        // set the new setpoint
        this -> newSetpoint(set);

        // Determine the error between the encoder input velocity and the desired velocity
        float e = (float)setpoint - (float)enc_velocity;
        // Add the error to the integral counter
        integral += e;
        // Saturation Limit for integral
        if ( 32767 < integral)
        {
            integral = 32767;
        }
        else if (integral < -32767)
        {
            integral = -32767;
        }

        // Compute the new PWM with the PID equation
        int16_t new_pwm = (int16_t)round(e*kP + integral*kI + (e - last_error)*kD);

        // Saturation Catch
        if(!(-255 <= new_pwm) && !(new_pwm <= 255))
        {
            if (0 < new_pwm) {new_pwm = 255;}
            else {new_pwm = -255;}
        }

        // Set motor to new desired PWM
        motor.set(new_pwm);
        // Store computed error for next calculation
        last_error = e;
    }
    // If not, run motor directly at setpoint
    else
    {
        motor.set(setpoint);
    }

}

// Run CS
void MotorCS::run(Motor motor, int16_t enc_velocity)
{
    // If the CS is enabled
    if (runCS)
    {
        // Determine the error between the encoder input velocity and the desired velocity
        float e = (float)setpoint - (float)enc_velocity;
        // Add the error to the integral counter
        integral += e;
        // Saturation Limit for integral
        if ( 32767 < integral)
        {
            integral = 32767;
        }
        else if (integral < -32767)
        {
            integral = -32767;
        }

        // Compute the new PWM with the PID equation
        int16_t new_pwm = (int16_t)round(e*kP + integral*kI + (e - last_error)*kD);

        // Saturation Catch
        if(!(-255 <= new_pwm) && !(new_pwm <= 255))
        {
            if (0 < new_pwm) {new_pwm = 255;}
            else {new_pwm = -255;}
        }

        // Set motor to new desired PWM
        motor.set(new_pwm);
        // Store computed error for next calculation
        last_error = e;
    }
    // If not, run motor directly at setpoint
    else
    {
        motor.set(setpoint);
    }

}