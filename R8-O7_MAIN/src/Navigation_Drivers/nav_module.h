






#ifndef _NAVIGATION_H_
#define _NAVIGATION_H_
#include <Arduino.h>



class Navigation
{
protected:

    int16_t motor_set_A = 0;
    int16_t motor_set_B = 0;

    /// Distance from bot center to wheel
    float v_calibration = 0;
    /// Radius of bot wheels
    float t_calibration = 0;

public:

Navigation(float v_cal, float t_cal);

void nav_conv(float set_velocity, float set_turnrate);

int16_t nav_A(void);

int16_t nav_B(void);

};

#endif