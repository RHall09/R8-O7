/** @file MotorCS.h
 * 
 * 
 * 
 *  @author Rick Hall
 *  @date 2020-4-Nov
 */

#ifndef MOTOR_CS_H
#define MOTOR_CS_H

#include <Arduino.h>
#include <Motor.h>



enum CS_Gains {Prop, Int, Der};

// Motor Control System Class Declaration
class MotorCS
{
protected:
    /// Proportional Gain
    float kP = 0;
    /// Integral Gain
    float kI = 0;
    /// Derivative Gain
    float kD = 0;

    /// Current Setpoint
    int16_t setpoint = 0;
    /// Current output
    int16_t new_pwm = 0;

    /// Last error
    float last_error = 0;
    /// Integral sum
    int16_t integral = 0;

    /// CS Control Boolean
    bool runCS = false;

public:
    // Constructor Function
    MotorCS(float kProportional = 1, float kIntegral = 0.1, float kDerivative = 4);

    // Set Gain
    void gainSet(CS_Gains k, float gain);

    // Start & stop CS computations
    void startCS(void);
    void stopCS(void);

    // Change setpoint
    void newSetpoint(int16_t set);

    // Run CS with new setpoint
    void run(Motor motor, int16_t enc_velocity, uint16_t enc_dtime, int16_t set);
    // Run CS without new setpoint
    void run(Motor motor, int16_t enc_velocity, uint16_t enc_dtime);

};

#endif