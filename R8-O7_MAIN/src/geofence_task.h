/** @headerfile geofence_task.h ""
 *  This file acts as a header for a task that updates the geofence heading and distance.
 * 
 *  @author Kai Quizon
 *  @date   2021-Nov-27 Original file
 *  @copyright (c) 2021 by Kai Quizon, released under the LGPL 3.0.
 */
#ifndef _TASK_GEOFENCE_
#define _TASK_GEOFENCE_
/**
 *  @brief   This task runs the geofence calculations to determine the nearest collision point of hte bot with the fence.
 *  @details This task calls \ref geofencing.cpp that geometrically calculates the nearest collision point of the bot with a user
 *           defined geofence. At this point, the geofence is defined within \ref geofence_task.cpp, but an SD reader on the board
 *           is a planned expansion.
 *  @param   p_params A pointer to function parameters which we don't use.
 */
void geofence_task (void* p_params);
#endif // _TASK_GEOFENCE_