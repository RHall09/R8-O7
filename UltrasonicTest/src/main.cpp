#include <Arduino.h>
#include <HCSR04.h>
#include <PrintStream.h>

HCSR04 hc(2,3);//initialisation class HCSR04 (trig pin , echo pin)

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print(hc.dist());
}