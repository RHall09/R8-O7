/** @headerfile nav_module.h ""
 *      This file contains the class declaration of a class for naturally driving the bot within a geofence.
 *      This class provides all motor set points unless overriden by the Bluetooth control task.
 *  @author Rick Hall
 *  @date 2021-4-Nov
 *  @copyright (c) 2021 by Rick Hall, released under the LGPL 3.0.
 **/
#ifndef _NAVIGATION_H_
#define _NAVIGATION_H_
#include <Arduino.h>


/** @brief A class containing functions for driving a dual-motor robot within a geofence.
 *  @details   This class contains member functions for driving a dual-motor robot within a geofence. The function attempts
 *             to drive the bot via "natural pathings" such that an onlooker may believe that the bot has a level of sentience. 
 **/
class Navigation
{
protected:

    /// The set point of motor A for natural pathing
    int16_t motor_set_A = 0;

    /// The set point of motor B for natural pathing
    int16_t motor_set_B = 0;

    /// The velocity calibration constant. Empirically determined. Converts ft/s to PWM.
    float v_calibration = 0;
    /// The turn rate calibration constant. Empirically determined. Converts ft/s to PWM; left turn is considered +.
    float t_calibration = 0;

public:

/** @brief Initialize an object of the Navigation class by defining the two calibration parameters.
 *  @details   Initialize an object of the Navigation class by feeding it two geometric paramters of the
 *             bot to be controlled. These parameters are fixed within the class object
 *  @param v_cal The velocity calibration constant. Empirically determined.
 *  @param t_cal The turn rate calibration constant. Empirically determined.
 **/
Navigation(float v_cal, float t_cal);


/** @brief Calculate the motor set points required for the desired speed and heading.
 *  @param set_velocity  The desired velocity of the \b entire bot. 
 *  @param set_turnrate  The desired turnrate of the \b entire bot.
 **/
void nav_conv(float set_velocity, float set_turnrate);

/** @brief Check the current set point of motor A.
 *  @return The signed 16 bit integer representing the necessary PWM signal to achieve the desired speed and turn rate.
 **/
int16_t nav_A(void);

/** @brief Check the current set point of motor B.
 *  @return The signed 16 bit integer representing the necessary PWM signal to achieve the desired speed and turn rate.
 **/
int16_t nav_B(void);

};

#endif