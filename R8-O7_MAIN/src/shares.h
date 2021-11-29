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

#include "ME507_Support/taskqueue.h"
#include "ME507_Support/taskshare.h"

// A queue which stores the latitude from the GPS module
extern Queue<float> latitude_queue;
// A queue which stores the longitude from the GPS module
extern Queue<float> longitude_queue;
//
extern Queue<float> fence_distance;
//
extern Queue<float> fence_heading;

//
extern Queue<float> motorA_velocity_queue;
//
extern Queue<float> motorA_dtime_queue;
//
extern Queue<float> motorB_velocity_queue;
//
extern Queue<float> motorB_dtime_queue;

#endif // _SHARES_H_