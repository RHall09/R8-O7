/** @file encoder_A_task.h
 *  @brief This file acts as a header for a task that runs the encoder for the left motor.
 * 
 *  @author Rick Hall
 *  @date   2021-Nov-27 Original file
 *  @copyright (c) 2021 by Rick Hall, released under the LGPL 3.0.
 */
#ifndef _TASK_ENCODER_A_
#define _TASK_ENCODER_A_
/**
 *  @brief   This task runs the encoder attached to the left motor.
 *  @details This task updates information pertaining to the encoder attached
 *           to the left motor. Relevant updated parameters include: the time
 *           interval for speed calculations and the encoder reading. The task
 *           handles overflow internally and automatically. Dependent on hephaestus's \ref ESP32Encoder.
 *  @param   p_params A pointer to function parameters which we don't use.
 */
void encoder_A_task (void* p_params);
#endif // _TASK_ENCODER_A_