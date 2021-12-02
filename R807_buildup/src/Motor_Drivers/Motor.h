/** @file Motor.h
 * 
 * 
 * 
 *  @author Rick Hall
 *  @date 2020-4-Nov
 */

#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

enum Motor_Number {Motor_0 = 0, Motor_1 =  2, Motor_2 =  4, Motor_3 =  6,
                   Motor_4 = 8, Motor_5 = 10, Motor_6 = 12, Motor_7 = 14};
enum MotFlag {ENABLED, ERROR};
// Motor Class Declaration
class Motor
{
protected:
    // Current Motor PWM
    int8_t bot_mot_A = 0;       // +|- %
    // Motor Enable Flag
    bool enabled = false;
    // Motor Overcurrent Flag
    bool mot_error = false;

    //Motor Pins
    int PinE = 0;
    int Pin1 = 0;
    int Pin2 = 0;

    // PWM Channels
    uint8_t motor_channel_1 = 0;
    uint8_t motor_channel_2 = 0;

    // Current Set Points
    int16_t current_pwm = 0;
    int16_t curr_abs_pwm = 0;

public:
    //Constructor Function
    Motor(int Pin_En, int Pin_1, int Pin_2, Motor_Number mot_num);

    //Enable Motors
    void enable(void);
    //Disable Motors
    void disable(void);
    //Set both motor behaviors with PWM %s
    void set(int16_t pwm);
    //Set individual motor behavior with PWM %s
    //Stop motors
    void stop(void);

    //Set error-overcurrent flag
    void checkOvercurrent(void);
    //Clear error-overcurrent flag
    void clearOvercurrent(void);

    //Check Flags
    bool FlagChk(MotFlag flag);


};

#endif