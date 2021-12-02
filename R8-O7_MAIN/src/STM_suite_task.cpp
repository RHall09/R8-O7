/** @file STM_suite_task.cpp
 *  This file contains a task that communicates with the STM to query for a state of the area value.
 * 
 *  @author Kai Quizon
 *  @date   2021-Dec-1 Original file 
 */
 


#include <Arduino.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
#include "shares.h"

#include <Wire.h>

void STM_suite_task (void* p_param) {
    
}
