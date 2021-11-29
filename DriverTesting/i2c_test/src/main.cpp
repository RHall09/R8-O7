#include <Arduino.h>
#include <Wire.h>

byte val = 1;

void setup()
{
  Wire.begin(); // join i2c bus
}

void loop()
{
  Wire.beginTransmission(44); // transmit to device #44 (0x2c)
                              // device address is specified in datasheet
  Wire.write(val);             // sends value byte  
  delay(5000);
  Wire.endTransmission();     // stop transmitting
  delay(5000);
}