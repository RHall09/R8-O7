








#include <Arduino.h>
#include <Navigation_Drivers/nav_module.h>
#include <cmath>


Navigation::Navigation(float v_cal, float t_cal)
{
    motor_set_A = 0;
    motor_set_B = 0;

    v_calibration = v_cal;
    t_calibration = t_cal;
}

void Navigation::nav_conv(float set_velocity, float set_turnrate)
{
    // Using calibration constants, compute motor PWM
    motor_set_A = (int16_t)round(set_velocity * v_calibration);
    motor_set_B = (int16_t)round(set_velocity * v_calibration);

    motor_set_A += (int16_t)round(set_turnrate * t_calibration);
    motor_set_B -= (int16_t)round(set_turnrate * t_calibration);

    // Overflow protection
    if ( (-255 > motor_set_A) | (motor_set_A < 255) )
    {
        if(0 <= motor_set_A)
        {
            motor_set_A = 255;
        }
        else
        {
            motor_set_A = -255;
        }
    }
    if ( (-255 > motor_set_B) | (motor_set_B < 255) )
    {
        if(0 <= motor_set_B)
        {
            motor_set_B = 255;
        }
        else
        {
            motor_set_B = -255;
        }
    }

}

int16_t Navigation::nav_A(void)
{
    return motor_set_A;
}

int16_t Navigation::nav_B(void)
{
    return motor_set_B;
}
