/** @file motor_CS_B_task.h
 *  This file acts as a header for a task that runs the motor control system.
 * 
 *  @author Rick Hall
 *  @date   2021-Nov-27 Original file
 */
#ifndef _TASK_MOTOR_CS_B_
#define _TASK_MOTOR_CS_B_
/**
 *  @brief   This task runs the right motor.
 *  @details This task runs a control system to run the right motor at the desired
 *           setpoint when recieved from the navigation task. It also contains redundancies
 *           to prevent collisions if a threshhold is sensed by the sensor suite.
 *  @param   p_params A pointer to function parameters which we don't use.
 */
void motor_task_B (void* p_params);
#endif // _TASK_MOTOR_CS_B_