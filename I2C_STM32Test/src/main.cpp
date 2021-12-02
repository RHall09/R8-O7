#include <Arduino.h>





pinMode(PA5, OUTPUT);
digitalWrite(PA5, LOW);

void setup() {
  Serial.begin(115200);
  delay(3000);
  Serial.print("We have printed on Nucleo");
  // Wire.begin(0x10);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("LOW\n");
  digitalWrite(PA5, LOW);
  delay(5000);
  Serial.print("HIGH\n");
  digitalWrite(PA5, HIGH);
  delay(5000);
}