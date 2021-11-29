






#include <Arduino.h>
#include <Motor_Drivers/Motor.h>
#include <Motor_Drivers/MotorCS.h>


// Constructor Function
MotorCS::MotorCS(float kProportional, float kIntegral, float kDerivative)
{
    kP = kProportional;
    kI = kIntegral;
    kD = kDerivative;
}

// Set Gain
void MotorCS::gainSet(CS_Gains k, float gain)
{
    if(k = Prop)
    {
        kP = gain;
    }
    else if(k = Integ)
    {
        kI = gain;
    }
    else
    {
        kD = gain;
    }

}

// Start & stop CS computations
void MotorCS::startCS(void)
{
    runCS = true;
}
void MotorCS::stopCS(void)
{
    runCS = false;
    integral = 0;
}
bool MotorCS::checkCS(void)
{
    return runCS;
}

// Change setpoint
void MotorCS::newSetpoint(int16_t set)
{
    setpoint = set;
}

// Run CS
void MotorCS::run(Motor motor, int16_t enc_velocity, uint16_t enc_dtime, int16_t set)
{
    if (runCS)
    {
        setpoint = set;
        float e = (float)setpoint - (float)enc_velocity;
        integral += e*enc_dtime;

        int8_t new_pwm = (int8_t)round(e*kP + integral*kI + (e - last_error)*kD);

        // Saturation Catch
        if(!(-100 <= new_pwm <= 100))
        {
            if (0 < new_pwm) {new_pwm = 100;}
            else {new_pwm = -100;}
        }

        motor.set(new_pwm);

        last_error = e;
    }

}

// Run CS
void MotorCS::run(Motor motor, int16_t enc_velocity, uint16_t enc_dtime)
{
    if (runCS)
    {
        float e = (float)setpoint - (float)enc_velocity;
        integral += e*enc_dtime;

        int8_t new_pwm = (int8_t)round(e*kP + integral*kI + (e - last_error)*kD);

        // Saturation Catch
        if(!(-255 <= new_pwm <= 255))
        {
            if (0 < new_pwm) {new_pwm = 255;}
            else {new_pwm = -255;}
        }

        motor.set(new_pwm);

        last_error = e;
    }

}