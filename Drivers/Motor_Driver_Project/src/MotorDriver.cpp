/** @file MotorDriver.h
 * 
 * 
 * 
 *  @author Rick Hall
 *  @date 2020-4-Nov
 */

#include <Arduino.h>
#include <bit_bool.h>
#include <MotorDriver.h>

MotorDriver::MotorDriver(int Pin_En_A, int Pin_Mot_A1, int Pin_Mot_A2, 
            int Pin_En_B, int Pin_Mot_B1, int Pin_Mot_B2, 
            Mot_Orient mot_or = mA_B,
            Mot_Pinout mot_A_pin = p1_2,
            Mot_Pinout mot_B_pin = p1_2 )
{
    // Set up flag register
    mot_flag = 0;
    BitBool motor_orient(&mot_flag, 0);
    BitBool pin_orient_A(&mot_flag, 1);
    BitBool pin_orient_B(&mot_flag, 2);
    BitBool motor_constructed(&mot_flag, 7);

    // If incorrect input of flag position, exit constructor
    if (mot_or == mTog || mot_A_pin == pTog || mot_B_pin == pTog)
    {
        return;
    }
    else
    {
        // If any flag not default, set it
        if (mot_or = mB_A)
        {
            motor_orient.set();
        }
        if (mot_A_pin = p2_1)
        {
            pin_orient_A.set();
        }
        if (mot_B_pin = p2_1)
        {
            pin_orient_B.set();
        }

        // Store pins in pin array
        mot_pins[0] = Pin_En_A;
        mot_pins[1] = Pin_Mot_A1;
        mot_pins[2] = Pin_Mot_A2;
        mot_pins[3] = Pin_En_B;
        mot_pins[4] = Pin_Mot_B1;
        mot_pins[5] = Pin_Mot_B2;    

        // Set pins to output mode & confirm pins set low
        pinMode(PinEnA, OUTPUT);
        digitalWrite(PinEnA, LOW);
        pinMode(PinA1, OUTPUT);
        digitalWrite(PinA1, LOW);
        pinMode(PinA2, OUTPUT);
        digitalWrite(PinA2, LOW);
        pinMode(PinEnB, OUTPUT);
        digitalWrite(PinEnB, LOW);
        pinMode(PinB1, OUTPUT);
        digitalWrite(PinB1, LOW);
        pinMode(PinB2, OUTPUT);
        digitalWrite(PinB2, LOW);
    }

    motor_constructed.set();
}

//Enable Motors
void MotorDriver::enable(Mot_Select motor = mAB)
{

}
//Disable Motors
void MotorDriver::disable(Mot_Select motor = mAB)
{


}
//Set both motor behaviors with PWM %s
void MotorDriver::set(int8_t pwmA, int8_t pwmb)
{


}
//Set individual motor behavior with PWM %s
void MotorDriver::set(Mot_Select motor, int8_t pwm)
{


}
//Stop motors
void MotorDriver::stop(Mot_Select motor = mAB)
{


}

//Set/toggle motor orientation
void MotorDriver::setOrient(Mot_Orient mot_or = mTog)
{


}
//Set/toggle pin orientation
void MotorDriver::setPinout(Mot_Select motor, Mot_Pinout motor_pin_orient = pTog)
{


}

