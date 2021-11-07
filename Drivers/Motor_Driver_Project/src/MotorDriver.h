/** @file MotorDriver.h
 * 
 * 
 * 
 *  @author Rick Hall
 *  @date 2020-4-Nov
 */

#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include <Arduino.h>
#include <bit_bool.h>

enum Mot_Orient {mA_B, mB_A, mTog};
enum Mot_Select {mA, mB, mAB};
enum Mot_Pinout {p1_2, p2_1, pTog};

// Motor Class Declaration
class MotorDriver
{
protected:
    //Current Motor A PWM
    int8_t bot_mot_A = 0;       // +|- %
    //Current Motor B PWM
    int8_t bot_mot_B = 0;       // +|- %
    //Motor Flag Register
    uint8_t mot_flag = 0; 


    //Motor Pins
    int mot_pins[6];
    #define PinEnA mot_pins[0]
    #define PinA1 mot_pins[1]
    #define PinA2 mot_pins[2]
    #define PinEnB mot_pins[3]
    #define PinB1 mot_pins[4]
    #define PinB2 mot_pins[5]


public:
    //Constructor Function
    MotorDriver(int Pin_En_A, int Pin_Mot_A1, int Pin_Mot_A2, 
                int Pin_En_B, int Pin_Mot_B1, int Pin_Mot_B2, 
                Mot_Orient mot_or = mA_B,
                Mot_Pinout mot_A_pin = p1_2,
                Mot_Pinout mot_B_pin = p1_2 );

    //Enable Motors
    void enable(Mot_Select motor = mAB);
    //Disable Motors
    void disable(Mot_Select motor = mAB);
    //Set both motor behaviors with PWM %s
    void set(int8_t pwmA, int8_t pwmb);
    //Set individual motor behavior with PWM %s
    void set(Mot_Select motor, int8_t pwm);
    //Stop motors
    void stop(Mot_Select motor = mAB);

    //Set/toggle motor orientation
    void setOrient(Mot_Orient mot_or = mTog);
    //Set/toggle pin orientation
    void setPinout(Mot_Select motor, Mot_Pinout motor_pin_orient = pTog);

};

#endif