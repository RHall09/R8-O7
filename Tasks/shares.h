/** @file shares.h
 *  This file contains extern declarations of shares and queues used in the full R8-07 operating sstem.
 * 
 *  @author Kai Quizon
 *  @date   2021-Nov-29 Original file 
 */

#ifndef _SHARES_H_
#define _SHARES_H_

#include "taskqueue.h"
#include "taskshare.h"

// A share which holds a boolean to enable or disable the safety sensor suite data collection. Written to by bluetooth or setup, read by geofence
extern Share<bool> sensor_suite_enable;


// A share which holds a boolean to enable or disable the safety sensor suite data collection. Written to by bluetooth or setup, read by geofence
extern Share<bool> geofence_enable;

// Two shares which hold the distance to the nearest point on the geofence. Written to by the geofence task, read by navigation
extern Share<float> fence_distance;
extern Share<float> fence_heading;

// A set of queues which triggers the geofence task to run by adding GPS data, written to by sensor suite, read by geofence
extern Queue<uint16_t> lattitude_queue;
extern Queue<uint16_t> longitude_queue;

// Queues related to the readings of the ultrasonic sensors. Written to by sensor suite, read by navigation.
extern Queue<float> sonic1_queue;
extern Queue<float> sonic2_queue;
extern Queue<float> sonic3_queue;

// Queues holding data from the time of flight sensor located in the crowd sensor suite. Written to by sensor suite, read by navigation.
extern Queue<float> tof_safetysuite_queue;


// Queues related to readings off of the encoders. Written to by encoder task, read by motor driver task
extern Queue<int16_t> encoderA_velocity_queue;
extern Queue<int16_t> encoderB_velocity_queue;

// If we use the encoder task for timing we will use these queues to store that data
extern Queue<uint16_t> encoderA_dtime_queue;
extern Queue<uint16_t> encoderB_dtime_queue;


#endif // _SHARES_H_