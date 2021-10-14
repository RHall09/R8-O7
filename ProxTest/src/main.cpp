/** @file     main.cpp
 *                This will eventually contain the doxystring for this project...
 * @author    Kai Quizon
 * @date      October 13th, 2021
 * */

#include <Arduino.h>
#include <PrintStream.h>

int analogPin = A0; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read

void setup() {
  Serial.begin (115200);           //  setup serial
  Serial.print("I'm an ESP32 with a proximity sensor so boo to you! \n");
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  String valstr = String(val);
  if (val == 0) {
    Serial.print("You LOSER THERES NO DATA! \n");
  }
  else {
    Serial << "The reading is: " << valstr << endl;          // debug value
  }
  delay (1000);
}