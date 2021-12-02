/** @file Motor.cpp
 * 
 * 
 * 
 *  @author Rick Hall
 *  @date 2020-4-Nov
 */

#include <Arduino.h>
#include <Motor.h>

//Constructor Function
Motor::Motor(int Pin_En, int Pin_1, int Pin_2, uint8_t mot_num)
{
    // Store motor pins 
    PinE = Pin_En;
    Pin1 = Pin_1;
    Pin2 = Pin_2;

    // For each motor, the channels will be 2*mot_num and 2*mot_num + 1
    motor_channel_1 = mot_num << 1;
    motor_channel_2 = ++motor_channel_1;

    // Set pins to output mode & confirm pins set low
    pinMode(PinE, OUTPUT);
    digitalWrite(PinE, LOW);

    ledcAttachPin(Pin1, motor_channel_1);
    ledcSetup(motor_channel_1, 1000, 8);
    ledcWrite(motor_channel_1, 0);

    ledcAttachPin(Pin2, motor_channel_2);
    ledcSetup(motor_channel_2, 1000, 8);
    ledcWrite(motor_channel_2, 0);

}

//Enable Motors
void Motor::enable(void)
{
    digitalWrite(PinE, HIGH);
    enabled = true;
}
//Disable Motors
void Motor::disable(void)
{
    digitalWrite(PinE, LOW);
    enabled = false;
}
//Set both motor behaviors with PWM %s
void Motor::set(int16_t pwm)
{
    if ( (mot_error = 0) && (enabled = 1) )
    {
        uint16_t absPwm = (uint16_t)abs(pwm);

        if( 0 < pwm <= 255 )
        {
            ledcWrite(motor_channel_2, 0);
            ledcWrite(motor_channel_1, absPwm);
        }
        else if( -255 <= pwm < 0 )
        {
            ledcWrite(motor_channel_1, 0);
            ledcWrite(motor_channel_2, absPwm);
        }
        else
        {
            ledcWrite(motor_channel_1, 0);
            ledcWrite(motor_channel_2, 0);
        } 
    }

}
//Set individual motor behavior with PWM %s
//Stop motors
void Motor::stop(void)
{
    ledcWrite(motor_channel_1, 0);
    ledcWrite(motor_channel_2, 0);
}

//Set error-overcurrent flag
void Motor::checkOvercurrent(void)
{
    if(!(digitalRead(PinE)))
    {
        mot_error = 1;
        ledcWrite(motor_channel_1, 0);
        ledcWrite(motor_channel_2, 0);   
        this -> disable();
    }
}
//Clear error-overcurrent flag
void Motor::clearOvercurrent(void)
{
    mot_error = 0;
    this -> enable();
}


//Check Flags
bool Motor::FlagChk(MotFlag flag)
{
    if(flag = ERROR)
    {
        return mot_error;
    }
    else
    {
        return enabled;
    }

}

