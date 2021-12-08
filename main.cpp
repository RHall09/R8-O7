#include <Arduino.h>
#include <shares.h>
#include <encoder_A_task.h>
#include <encoder_A_task.h>
#include <motor_CS_A_task.h>
#include <motor_CS_B_task.h>
#include <sensor_suite_task.h>
#include <geofence_task.h>

void setup () 
{
  // Start the serial port, wait a short time, then say hello. Use the
  // non-RTOS delay() function because the RTOS hasn't been started yet
  Serial.begin (115200);
  delay (2000);
  Serial << endl << endl << "Hello, I am an RTOS demonstration" << endl;
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

void loop() {
  // Ignore this stupid function. Its sitting in the corner thinking about its actions.
}