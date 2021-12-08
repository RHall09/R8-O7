/** @file bluetooth_task.h
 *    This file contains header file for a task that collects user input from a mobile
 *    application to control R-8O7 over bluetooth, interprets and converts the data as
 *    needed, and sends commands to the sensor suite and motor driver.
 * 
 *  @author Anil Singh
 *  @date   2021-Nov-27 Original file 
 */

#ifndef _TASK_BLUETOOTH_
#define _TASK_BLUETOOTH_
void bluetooth_task (void* p_params);
#endif // _TASK_BLUETOOTH_