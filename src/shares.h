/** @file shares.h
 * @brief Extern declarations of all RTOS shares and queues.
 *  This file contains extern declarations of shares and queues which are used
 *  in more than one file of a this RTOS system.
 * 
 *  @author Kai Quizon
 *  @date   2021-Oct-23 Original file
 *  @copyright (c) 2021 by Kai Quizon, released under the LGPL 3.0. 
 */
 
#ifndef _SHARES_H_
#define _SHARES_H_

#include <ME507_Support/taskqueue.h>
#include <ME507_Support/taskshare.h>
#include <Misc_Drivers/RegOperators.h>

/// A queue which stores the latitude from the GPS module
extern Queue<float> latitude_queue;
/// A queue which stores the longitude from the GPS module
extern Queue<float> longitude_queue;
/// A queue which stores the shortest perpendicular distance to the geofence
extern Queue<float> fence_distance;
/// A queue which stores the heading of the shortest perpendicular distance to the geofence
extern Queue<float> fence_heading;

/// Main Time of Flight Sensor Reading Queue (reads in mm)
extern Queue<int16_t> tof_main;

/// Motor A Setpoint queue
extern Queue<int16_t> motorSet_A_q;
/// Motor B Setpoint queue
extern Queue<int16_t> motorSet_B_q;
/// Velocity of encoder attached to Motor A Queue
extern Queue<float> encVel_A_q;
/// Velocity of encoder attached to Motor B Queue
extern Queue<float> encVel_B_q;
/// Time differential of encoder attached to Motor A Queue
extern Queue<float> enc_dt_A_q;
/// Time differential of encoder attached to Motor B Queue
extern Queue<float> enc_dt_B_q;
/// Share of motor flag registers, changes if motor faults detected
extern Share<uint8_t> motorFlagRegister;
/// Share of object detected by auxillary sensors
extern Share<bool> Obj_flag;

/// Share of navigation toggle 
extern Share<Bool> Navigation_enable;
/// Share of geofence toggle 
extern Share<Bool> Geofence_enable;
/// Share of sensor suite toggle 
extern Share<Bool> Sensor_enable;
/// Queue of throttle output from bluetooth task
extern Queue<float> Bot_Speed[1];
/// Queue of direction output from bluetooth task
extern Queue<float> Bot_turnrate[1];

/// Part of a Rick Flag Register that handles overcurrent motor faults
#define Run_Motor_CS  current_flag, 5
/// Part of a Rick Flag Register that handles overcurrent motor faults
#define OverC_Clear   current_flag, 6
/// Part of a Rick Flag Register that handles overcurrent motor faults
#define Overcurrent_A current_flag, 7
/// Part of a Rick Flag Register that handles overcurrent motor faults
#define Overcurrent_B current_flag, 8

#endif // _SHARES_H_