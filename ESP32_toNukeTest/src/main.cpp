#include <Arduino.h>
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin();
  delay (2000);
  Serial.println("I am the master ESP32");
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(0x0F);
  Wire.write("Hello");
  Wire.endTransmission();
  Serial.println("Sent a string over I2C");

  delay(5000);
}