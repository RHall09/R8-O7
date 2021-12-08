/** @file main.cpp
 *  
 * 
 *  @author JR Ridgely
 *  @date   2021-Oct-23 Original file
 *  @copyright (c) 2021 by JR Ridgely, released under the LGPL 3.0. 
 */
#include <Arduino.h>
#if (defined STM32L4xx || defined STM32F4xx)
    #include <STM32FreeRTOS.h>
#endif
#include "ME507_Support/taskshare.h"         // Header for inter-task shared data
#include "ME507_Support/taskqueue.h"         // Header for inter-task data queues
#include "shares.h"                          // Header for shares used in this project


/**
/// A share which holds a counter of how many times a simulated event occurred
Share<bool> begin_recording ("Recording");
/// A queue which holds a bunch of data taken by a measurement task
Queue<uint16_t> data_queue (100, "Data");
/// The number of milliseconds between sets of data recorded
const uint32_t MS_PER_DATA_SET = 10000;
*/


/** @brief   
 *  @details 
 *  @param   p_params An unused pointer to nonexistent parameters
 */
void task_control (void* p_params)
{
  /**
    for (;;)
    {
        begin_recording.put (true);           // Tell recording task to begin
        vTaskDelay (MS_PER_DATA_SET);         // Then wait 10 seconds
    }
  */
}

/** @brief   
 *  @details 
 */
void setup () 
{
/**
    // Start the serial port, wait a short time, then say hello. Use the
    // non-RTOS delay() function because the RTOS hasn't been started yet
    Serial.begin (115200);
    delay (5000);
    // Initialize the recording share to indicate we're not taking data yet
    begin_recording.put (false);
    // Create a task which records data
    xTaskCreate (task_take_data,             // Task function
                 "Data Acq.",                // Name for debugging printouts
                 1024,                       // Stack size for this task
                 NULL,                       // Pointer to no parameters
                 9,                          // Priority
                 NULL);                      // Don't save task object pointer
    // Create a task which displays the data which has been recorded
    xTaskCreate (task_show_data,             // Task function
                 "Show Data",                // Name for debugging printouts
                 2048,                       // Stack size for this task
                 NULL,                       // Pointer to no parameters
                 3,                          // Priority
                 NULL);                      // Don't save task object pointer
    // Create a task controls when data acquisition begins
    xTaskCreate (task_control,               // Task function
                 "Control",                  // Name for debugging printouts
                 512,                        // Stack size for this task
                 NULL,                       // Pointer to no parameters
                 6,                          // Priority
                 NULL);                      // Don't save task object pointer
    // If using an STM32, we need to call the scheduler startup function now;
    // if using an ESP32, we need not, as it has already been called
    #if (defined STM32L4xx || defined STM32F4xx)
        vTaskStartScheduler ();
    #endif
*/
}
/** @brief   Arduino's low-priority loop function, which we don't use.
 *  @details A non-RTOS Arduino program runs all of its continuously running
 *           code in this function after @c setup() has finished. When using
 *           FreeRTOS, @c loop() implements a low priority task on most
 *           microcontrollers and crashes on some others, so we'll not use it.
 */
void loop () 
{
}