/** @file MotorCS.h
 *  @brief File acts as a header for a class for interacting with \b MD-L6205D motor driver chip.
 * @details     This file contains the class declaration of a class designed to drive a motor with two PWM signals
 *      and an enable pin using the \b MD-L6205D motor driverchip. This class implements a 
 *      PID control loop with user defined gains.
 *  @author Rick Hall
 *  @date 2021-4-Nov
 *  @copyright (c) 2021 by Rick Hall, released under the LGPL 3.0.
 */

#ifndef MOTOR_CS_H
#define MOTOR_CS_H

#include <Arduino.h>
#include <Motor_Drivers/Motor.h>


/// Enumerated variable for storing and interacting with Control System gains
enum CS_Gains {Prop, Integ, Der};

/** @brief A class containing functions for operating a PID control system for a single motor.
 *  @details   A class containing functions for driving a single motor using a control system and the \b MD-L6205D chip. Methods include declaraing
 *             PWM setpoints, changing controller gains, and toggling the control system on and off. This class is dependent
 *             on the \ref Motor class.
 *             This class \b does implements a control system for driving the motor with a speed, allowing for consisten speed under
 *             varying load conditions.
 **/
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
/** @brief Initialize an object of the MotorCS class by feeding it the desired controller gains.
 *  @details   Initialize an object of the MotorCS class by feeding it the desired controller gains.
 *             This function only creates an object of the class and stores the controller gains fed.
 *  @param kProportional The proportional gain desired for implementation in the PID controller.
 *  @param kIntegral The integral gain desired for implementation in the PID controller.
 *  @param kDerivative The derivative gain desired for implementation in the PID controller.
 **/
    MotorCS(float kProportional = 1, float kIntegral = 0.1, float kDerivative = 4);

/** @brief Interact with the enumerated CS_Gains type to change any of the three gains. Write only.
 *  @param k The desired gain type of CS_Gains to be changed.
 *  @param gain The new value of the changed CS_Gains value.
 **/
    void gainSet(CS_Gains k, float gain);

/** @brief Toggle a boolean \b on that enables the Control system calculations.
 **/
    void startCS(void);

/** @brief Toggle a boolean \b off that enables the Control system calculations.
 **/
    void stopCS(void);

/** @brief Check the status of the control system enable boolean.
 *  @return A boolean representing the status of the Control System. True for on, false for off.
 **/
    bool checkCS(void);

/** @brief Set a new PWM signal setpoint to drive the motors with.
 *  @param set The new setpoint (PWM signal) desired. Can be any number, but handled internally to between -255 and 255.
 **/
    void newSetpoint(int16_t set);

/** @brief Calculate the new necessary PWM signal to achieve the desired speed of the provided setpoint.
 *  @param motor The motor to be controlled.
 *  @param enc_velocity An updated encoder velocity from the attached encoder.
 *  @param set The new desired setpoint.
 **/
    void run(Motor motor, int16_t enc_velocity, int16_t set);

/** @brief Calculate the new necessary PWM signal to achieve the desired speed of the current stored setpoint.
 *  @param motor The motor to be controlled.
 *  @param enc_velocity An updated encoder velocity from the attached encoder.
 **/
    void run(Motor motor, int16_t enc_velocity);

};

#endif