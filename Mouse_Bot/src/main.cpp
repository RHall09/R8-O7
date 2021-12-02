#include <Arduino.h>
#include <STM32FreeRTOS.h>
#include <ME507_Support/taskshare.h>
#include <ME507_Support/taskqueue.h>
#include <shares.h>
#include <Misc_Drivers/PrintStream.h>
#include <baby_motor_task.h>
#include <navigation_task.h>
#include <geofence_task.h>



  Queue<float> fence_distance(1, "Fence Distance");
  //
  // Queue<float> fence_heading(1, "Fence Heading");

  Queue<int16_t> motorSet_A_q(1, "Left Motor PWM Setting");

  Queue<int16_t> motorSet_B_q(1, "Right Motor PWM Setting");

void setup() {
  // Start the serial port, wait a short time, then say hello. Use the
  // non-RTOS delay() function because the RTOS hasn't been started yet
  Serial.begin (115200);
  delay (2000);
  Serial << endl << endl << "Hello, I am an RTOS demonstration" << endl;

  // Create a task which prints a slightly disagreeable message
  xTaskCreate (baby_motor_task,
                "Motor Task",                          // Name for printouts
                256,                             // Stack size
                NULL,                            // Parameters for task fn.
                2,                               // Priority
                NULL);                           // Task handle

  xTaskCreate (navigation_task,
                "Navigation",                          // Name for printouts
                256,                             // Stack size
                NULL,                            // Parameters for task fn.
                1,                               // Priority
                NULL);                           // Task handle

  xTaskCreate (geofence_task,
                "Geofence",                          // Name for printouts
                256,                             // Stack size
                NULL,                            // Parameters for task fn.
                3,                               // Priority
                NULL);                           // Task handle


  // If using an STM32, we need to call the scheduler startup function now;
  // if using an ESP32, it has already been called for us
  #if (defined STM32L4xx || defined STM32F4xx)
      vTaskStartScheduler ();
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:
}