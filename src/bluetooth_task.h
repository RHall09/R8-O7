/** @file bluetooth_task.h
 *  @brief A header for the bluetooth task
 *  @details  This file contains header file for a task that collects user input from a mobile
 *    application to control R-8O7 over bluetooth, interprets and converts the data as
 *    needed, and sends commands to the sensor suite and motor driver.
 * 
 *  @author Anil Singh
 *  @date   2021-Nov-27 Original file 
 *  @copyright (c) 2021 Anil Singh, released under the LGPL 3.0.
 */

#ifndef _TASK_BLUETOOTH_
#define _TASK_BLUETOOTH_
/**
 *  @brief   This task runs the bluetooth interface for interacting with the app.
 *  @details This task updates information pertaining to the bluetooth interface when
 *           using an appropriately paired smartphone. If no device is paired, then no
 *           shares are updated. If a device is properly paired, it sends data every 15ms.
 *           The relevant data is passed to the navigation task.
 *  @param   p_params A pointer to function parameters which we don't use.
 */
void bluetooth_task (void* p_params);
#endif // _TASK_BLUETOOTH_