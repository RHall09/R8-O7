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
Motor::Motor(int Pin_En, int Pin_1, int Pin_2)
{
    // Store motor pins 
    PinE = Pin_En;
    Pin1 = Pin_1;
    Pin2 = Pin_2;

    // Set pins to output mode & confirm pins set low
    pinMode(PinE, OUTPUT);
    digitalWrite(PinE, LOW);
    pinMode(Pin1, OUTPUT);
    digitalWrite(Pin1, LOW);
    pinMode(Pin2, OUTPUT);
    digitalWrite(Pin2, LOW);

}

//Enable Motors
void Motor::enable(void)
{
    pinMode(PinE, INPUT_PULLUP);
    enabled = true;
}
//Disable Motors
void Motor::disable(void)
{
    pinMode(PinE, OUTPUT);
    digitalWrite(PinE, LOW);
    enabled = false;
}
//Set both motor behaviors with PWM %s
void Motor::set(int16_t pwm)
{
    if ((mot_error = 0) && (enabled = 1))
    {
        uint8_t absPwm = abs(pwm);

        if( 0 < pwm <= 255 )
        {
            digitalWrite(Pin2, LOW);
            analogWrite(Pin1, absPwm);
        }
        else if( -255 <= pwm < 0 )
        {
            digitalWrite(Pin1, LOW);
            analogWrite(Pin2, absPwm);
        }
        else
        {
            digitalWrite(Pin1, LOW);
            digitalWrite(Pin2, LOW);
        } 
    }

}
//Set individual motor behavior with PWM %s
//Stop motors
void Motor::stop(void)
{
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, LOW);
}

//Set error-overcurrent flag
void Motor::checkOvercurrent(void)
{
    if(!(digitalRead(PinE)))
    {
        mot_error = 1;
        digitalWrite(Pin1, LOW);
        digitalWrite(Pin2, LOW);
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

