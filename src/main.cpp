/** @file main.cpp
 *  @brief This file contains the main loop of R8-07.
 *  @details This file contains the queue and share declarations, task declarations,
 *            and intialization of the FreeRTOS task scheduler to allow for multitasking.
 *            In this configuration, debuggings are disabled so there are minimal printouts
 *            to the Serial port.
 * 
 *  @author Kai Quizon
 *  @date   2021-Nov-27 Original file 
 *  @copyright (c) 2021 by Kai Quizon, released under the LGPL 3.0.
 */
#include <Arduino.h>
#include <shares.h>
#include <encoder_A_task.h>
#include <encoder_A_task.h>
#include <motor_CS_A_task.h>
#include <motor_CS_B_task.h>
#include <sensor_suite_task.h>
#include <geofence_task.h>

/**
 *  @brief   The basic setup task from arduino, contains all task declarations for FreeRTOS.
 */
void setup () 
{
  // Start the serial port, wait a short time, then say hello. Use the
  // non-RTOS delay() function because the RTOS hasn't been started yet
  Serial.begin (115200);
  delay (2000);
  Serial << endl << endl << "Hello, I am R8-07." << endl;
  // Create a task which prints a slightly disagreeable message
  xTaskCreate (encoder_A_task,
                "Encoder A",                          // Name for printouts
                256,                             // Stack size
                NULL,                            // Parameters for task fn.
                5,                               // Priority
                NULL);                           // Task handle

  xTaskCreate (encoder_B_task,
                "Encoder B",                          // Name for printouts
                256,                             // Stack size
                NULL,                            // Parameters for task fn.
                5,                               // Priority
                NULL);                           // Task handle

  xTaskCreate (motor_CS_A_task,
                "Motor A",                          // Name for printouts
                256,                             // Stack size
                NULL,                            // Parameters for task fn.
                3,                               // Priority
                NULL);                           // Task handle

  xTaskCreate (motor_CS_B_task,
                "Motor B",                          // Name for printouts
                256,                             // Stack size
                NULL,                            // Parameters for task fn.
                3,                               // Priority
                NULL);                           // Task handle

  xTaskCreate (sensor_suite_task,
                "Sensor Suite",                          // Name for printouts
                256,                             // Stack size
                NULL,                            // Parameters for task fn.
                1,                               // Priority
                NULL);                           // Task handle

  xTaskCreate (navigation_task,
                "Navigation",                          // Name for printouts
                256,                             // Stack size
                NULL,                            // Parameters for task fn.
                2,                               // Priority
                NULL);                           // Task handle

  xTaskCreate (geofence_task,
                "Geofence",                          // Name for printouts
                256,                             // Stack size
                NULL,                            // Parameters for task fn.
                2,                               // Priority
                NULL);                           // Task handle


  // If using an STM32, we need to call the scheduler startup function now;
  // if using an ESP32, it has already been called for us
  #if (defined STM32L4xx || defined STM32F4xx)
      vTaskStartScheduler ();
  #endif
}

/**
 *  @brief   A function that is sitting in the corner doing nothing, trying to keep out existential dread.
 */
void loop() {
  // Ignore this stupid function. Its sitting in the corner thinking about its actions.
}