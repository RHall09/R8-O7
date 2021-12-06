/** @headerfile Motor.h ""
 *          File acting as a header for a class that drives a motor using the \b MD-L6205D motor driver chip.
 *          See \ref Motor.cpp for the member functions.
 * 
 * 
 *  @author Rick Hall
 *  @date 2021-4-Nov
 *  @copyright (c) 2021 by Rick Hall, released under the LGPL 3.0.
 */

#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <Arduino.h>

enum Motor_Number {Motor_0 = 0, Motor_1 =  2, Motor_2 =  4, Motor_3 =  6,
                   Motor_4 = 8, Motor_5 = 10, Motor_6 = 12, Motor_7 = 14};

enum MotFlag {ENABLED, ERROR};



/** @brief A class containing functions for driving a single motor using the \b MD-L6205D chip.
 *  @details   A class containing functions for driving a single motor using \b MD-L6205D chip. Methods include enabling,
 *             disabling, setting a desired PWM, checking for overcurrent conditions and clearing overcurrent conditions.
 *             This class does \b NOT implement a control system and thereby only governs motor PWM and not necessarily
 *             motor speed.
 **/
class Motor
{
protected:
    /// Current Motor PWM
    int8_t bot_mot_A = 0;       // +|- %
    /// Motor Enable Flag
    bool enabled = false;
    /// Motor Overcurrent Flag
    bool mot_error = false;

    /// Motor Enable Pin
    int PinE = 0;
    /// Motor Pin 1
    int Pin1 = 0;
    /// Motor Pin 2
    int Pin2 = 0;

    /// PWM Channel 1
    uint8_t motor_channel_1 = 0;
    /// PWM Channel 2
    uint8_t motor_channel_2 = 0;

    /// Current Motor PWM
    int16_t current_pwm = 0;
    /// Current absolute PWM
    int16_t curr_abs_pwm = 0;

public:
    
/** @brief Initialize the \b Motor class object, create appropriate PWM channels, and initially disable motors.
 *  @details   Initialize the motor class object and attach it to the provided enable and PWM pins. Additionally,
 *             assign a motor number. The motor number helps differentiate different instances of \b Motor classes
 *             and also allows for automatic generation of PWM channels. Then, lower the enable pin to disable the 
 *             motor until the \ref enable method is called.
 *  @param Pin_En The pin number of \b Pin object to which the motor enable pin is attached.
 *  @param Pin_1  The pin number or \b Pin object to which the first motor PWM pin is attached.
 *  @param Pin_2  The pin number or \b Pin object to which the second motor PWM pin is attached.
 *  @param mot_num A unique number assigned to the motor for generating unique PWM channels and motor identification.
 **/
    Motor(int Pin_En, int Pin_1, int Pin_2, Motor_Number mot_num);

/** @brief Enable the motor by raising the enable pin to a logical high state.
 **/
    void enable(void);

/** @brief Disbale the motor by lowering the enable pin to a logical low state.
 **/
    void disable(void);

/** @brief Set the motor PWM to the passed parameter.
 *  @details   Set the motor PWM to the passed parameter. Includes handling of negative PWMs to pass 
 *             appropriate PWMs to the two pins to allow for both speed and directional control of 
 *             a single motor.
 *  @param pwm The desired pulse width modulation value (between 0 and 255) desired to spin the motor.
 **/
    void set(int16_t pwm);

/** @brief Stop motor rotation.
 *  @details   Stop motor rotation by passing a PWM of zero to both PWM channels.
 **/
    void stop(void);

/** @brief Check for overcurrent conditions in the motor.
 *  @details   If overcurrent conditions are detected by the \b MD-L6205D chip, the chip attempts to pull the enable pin low
 *             This can be checked by reading this pin.
 **/
    void checkOvercurrent(void);
/** @brief Clear for overcurrent conditions in the motor.
 *  @details   Clear overcurrent conditions by stopping all motor action.
 **/
    void clearOvercurrent(void);

/** @brief Check Motor flags.
 *  @details   Check the motor flags to see if an error has been detected, otherwise return enabled.
 *  @param flag The flag of type MotFlag as defined by the class. 
 **/
    bool FlagChk(MotFlag flag);

};

#endif // _MOTOR_H_