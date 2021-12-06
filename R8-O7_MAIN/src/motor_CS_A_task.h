/** @headerfile motor_CS_A_task.h ""
 *  This file acts as a header for a task that runs the motor control system.
 * 
 *  @author Rick Hall
 *  @date   2021-Nov-27 Original file
 *  @copyright (c) 2021 by Rick Hall, released under the LGPL 3.0.
 */
#ifndef _TASK_MOTOR_A_
#define _TASK_MOTOR_A_
/**
 *  @brief   This task runs the left motor.
 *  @details This task runs a control system to run the left motor at the desired
 *           setpoint when recieved from the navigation task. It also contains redundancies
 *           to prevent collisions if a threshhold is sensed by the sensor suite.
 *  @param   p_params A pointer to function parameters which we don't use.
 */
void motor_task_A (void* p_params);
#endif // _TASK_MOTOR_A_