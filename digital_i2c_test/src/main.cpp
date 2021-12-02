#include <Arduino.h>
#include <digital_i2c.h>
#include <PrintStream.h>
#include <Wire.h>


i2cdig digbus;


void setup() {
  Serial.begin(115200);
  delay(2000);
  // Serial.print("Started program\n");
  // digbus.joini2c();
  // Serial.print("Joined I2C\n");
  // bool i_o = false;
  // digbus.configport(1, i_o);
  // Serial.print("Configured port as output\n");

  pinMode(13, INPUT);

  // Wire.begin();

  // Wire.beginTransmission(0b0100000);
  // Wire.write(byte(3));
  // Wire.endTransmission();
  // Serial.print("We attemped to point at the configuration port.\n");

    Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;
  
  Wire.begin();
  for (byte i = 1; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
      {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);  // maybe unneeded?
      } // end of good response
  } // end of for loop
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
}  // end of setup



void loop() {
  bool yes = true;
  bool no = false;
  // digbus.setoutput(1, yes);
  // Serial.println(digitalRead(13));
  // Serial.print("High\n");
  // delay(5000);
  // digbus.setoutput(1, no);
  // Serial.println(digitalRead(13));
  // Serial.print("Low\n");
  // delay(5000);

}