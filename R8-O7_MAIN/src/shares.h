/** @file shares.h
 *  This file contains extern declarations of shares and queues which are used
 *  in more than one file of a demonstration project.
 * 
 *  @author JR Ridgely
 *  @date   2021-Oct-23 Original file
 *  @copyright (c) 2021 by JR Ridgely, released under the LGPL 3.0. 
 */
 
#ifndef _SHARES_H_
#define _SHARES_H_

#include <ME507_Support/taskqueue.h>
#include <ME507_Support/taskshare.h>
#include <Misc_Drivers/RegOperators.h>

// A queue which stores the latitude from the GPS module
extern Queue<float> latitude_queue;
// A queue which stores the longitude from the GPS module
extern Queue<float> longitude_queue;
//
extern Queue<float> fence_distance;
//
extern Queue<float> fence_heading;

// Main Time of Flight Sensor Reading Queue (reads in mm)
extern Queue<int16_t> tof_main;

// Motor A Setpoint queue
extern Queue<int16_t> motorSet_A_q;
// Motor B Setpoint queue
extern Queue<int16_t> motorSet_B_q;
//
extern Queue<float> encVel_A_q;
//
extern Queue<float> encVel_B_q;
//
extern Queue<float> enc_dt_A_q;
//
extern Queue<float> enc_dt_B_q;
//
extern Share<uint8_t> motorFlagRegister;

#define Run_Motor_CS  current_flag, 5
#define OverC_Clear   current_flag, 6
#define Overcurrent_A current_flag, 7
#define Overcurrent_B current_flag, 8

#endif // _SHARES_H_