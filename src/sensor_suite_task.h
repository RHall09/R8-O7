/** @file sensor_suite_task.h
 * @brief The header for the sensor suite task which updates all sensors.
 *  @details This file acts as a header for a task which updates the read values off of *all* sensors
 *  directly related to guest safety. This includes the crowd interaction suite
 *  and the foot mounted checks.
 * 
 *  @author Kai Quizon
 *  @date   2021-Nov-27 Original file 
 *  @copyright (c) 2021 by Kai Quizon, released under the LGPL 3.0.
 */


#ifndef _TASK_SENSOR_SUITE_
#define _TASK_SENSOR_SUITE_
/**
 *  @brief   This task triggers the safety sensor suite and stores the data.
 *  @details This task runs at regular intervals to update the 8 safety critical
 *           sensors to prevent collisions with all objects and personnel. It includes
 *           drivers and code to run three types of sensors: laser time of flight, infrared
 *           time of flight, and ultrasonic distance.
 *  @param   p_params A pointer to function parameters which we don't use.
 */
void sensor_suite_task (void* p_params);
#endif // _TASK_SENSOR_SUITE_