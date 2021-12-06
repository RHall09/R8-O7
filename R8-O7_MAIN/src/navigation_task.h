/** @file navigation_task.h
 *  This file contains a task which takes inputs from all sensors 
 *  and the GPS to determine the path of the robot and output motor
 *  PWM values accordingly.
 * 
 *  @author Rick Hall
 *  @date   2021-Dec-02 Original file 
 */

#ifndef _TASK_NAVIGATION_
#define _TASK_NAVIGATION_
void navigation_task (void* p_params);
#endif // _TASK_NAVIGATION_