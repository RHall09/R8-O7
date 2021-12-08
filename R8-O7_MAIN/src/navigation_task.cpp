/** @file navigation_task.cpp
 *  This file contains a task which takes inputs from all sensors 
 *  and the GPS to determine the path of the robot and output motor
 *  PWM values accordingly.
 * 
 *  Update as of 12/4/21:
 *  Due to limitations in the current sensor module, only GPS data 
 *  is currently implemented in the navigation calculation. 
 * 
 *  @author Rick Hall
 *  @date   2021-Dec-02 Original file 
 */

#include <Arduino.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif

#include <PrintStream.h>
#include "shares.h"
#include "cmath"
#include <Navigation_Drivers/nav_module.h>

/// Minimum distance to fence
#define FENCE_MIN (float)3
/// Calibration for conversion ft/s to pwm
#define V_CAL (float)0.3
/// Calibration for conversion deg/s to pwm
#define T_CAL (float)0.25
/// Preferred robot velocity
#define CRUISE_VEL (float) 3

/// Make the loop say for ever hehehe
#define EVER (;;)

void navigation_task(void* p_param) {
    // Geofence Heading variable
    float fnc_head;
    // Geofence Distance variable
    float fnc_dist;
    // GPS Forward Heading
    // float gps_fore = 0;

    // Mathematical Heading
    float current_heading = 0;      // Turn rate is in deg/s
    // Mathematical Velocity
    float current_velocity = 0;     // Velocity is in ft/s

    // Desired Turnrate
    float set_turn = 0;     // Turn rate is in deg/s
    // Desired Velocity
    float set_vel = 0;      // Velocity is in ft/s

    // Motor Set A
    int16_t set_A = 0;      // PWM from -255 to +255
    // Motor Set B
    int16_t set_B = 0;      // PWM from -255 to +255

    // Navigation decremental timer to determine point turns
    uint16_t nav_timer = 0;

    // Local copy of shared motor flag register
    uint8_t current_flag = 0;
    current_flag = motorFlagRegister.get();
    current_flag = bit_set(Run_Motor_CS);

    // Navigation calculation object
    Navigation nav(V_CAL,T_CAL);

    Serial << "Nav task is setup" << endl;

    
    for EVER {

        Serial << "Nav Task ------------ " << endl;
        
        if(!bit_chk(Overcurrent_A) | !bit_chk(Overcurrent_B))
        {
            // So long as the nav delay timer is not set, run algorithm
            if(nav_timer == 0)
            {
                // First update the distance to the fence and the heading
                fnc_head = fence_heading.get();
                fnc_dist = fence_distance.get();

                // If the fence distance is greater than the minimum by at least 0.5 ft
                // and the geofence heading is outside of a 30d area infront of the bot
                if ( (0.5 < (fnc_dist - FENCE_MIN)) && (((float)90 - fnc_head) > (float)15) )
                {
                    // Run natural fence avoidance algorithm

                    static float r = 0;

                    set_vel = CRUISE_VEL;

                    r = (fnc_dist - FENCE_MIN)/(1 - cos((90 - fnc_head) * (PI / (float)180)));

                    set_turn = (set_vel / r) * ((float)180 / PI);

                }
                else if (fnc_dist < (float)10) // otherwise
                {
                    // Stop and turn away from the fence

                    set_vel = 0;
                    set_turn = 5;

                    // Set timer to turn until robot is parallel to the fence plus a random angle between 30 and 150 degrees
                    nav_timer = (uint16_t)round(abs(((((float)90 - fnc_head) + (rand() % 120 + 30))/set_turn)));

                }

                // Convert speed/turn_rate to motor_A/motor_B
                nav.nav_conv(set_vel, set_turn);
                set_A = nav.nav_A();
                set_B = nav.nav_B();

                // Put computed PWM values in queues for Motor task
                motorSet_A_q.put(set_A);
                motorSet_B_q.put(set_B);
            }
            else
            {
                nav_timer = nav_timer - 1;

                // Software timer underflow protection
                if (nav_timer < 0)
                {
                    nav_timer = 0;
                }
            }
        }
        
    }
}