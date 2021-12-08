/** @file navigation_task.h
 *  @brief The header for the main brain of R8-07.
 *  @details This file acts as a header for a task which takes inputs from all sensors 
 *  and the GPS to determine the path of the robot and output motor
 *  PWM values accordingly.
 * 
 *  @author Rick Hall
 *  @date   2021-Dec-02 Original file 
 *  @copyright (c) 2021 by Rick Hall, released under the LGPL 3.0.
 */

#ifndef _TASK_NAVIGATION_
#define _TASK_NAVIGATION_
/**
 *  @brief   This task runs the navigation of the bot within its geofence.
 *  @details This task updatest the motor setpoints by synthesizing data from
 *           the safety sensor suite and the geofence distances. It also determines
 *           if it is a safe instance for ShowSense moment. If a safe moment is available,
 *           trigger the ShowSense moment. Ultimately, this task asks as a general "brain"
 *           for R8-07.
 *  @param   p_params A pointer to function parameters which we don't use.
 */
void navigation_task (void* p_params);
#endif // _TASK_NAVIGATION_