#include <Arduino.h>
#include <Wire.h>
#include "Printstream.h"

void setup() {

  // Print a header for the table
  Serial.begin(115200);
  while (!Serial) {
    delay (1);
  }

  Serial.print("I am going to try my best to do some things here\n");

  Serial << "    0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F" << hex 
          << endl;
  for (uint8_t row = 0x00; row <= 0x70; row += 0x10)      // Rows are 16's
  {
      Serial << row << " ";                              // Columns are 1's
      for (uint8_t col = 0; col <= 0x0F; col++)
      {
          if (row == 0 && col < 8)                        // Don't do these
          {
              Serial << "   ";
          }
          else
          {
              Wire.beginTransmission (row | col);
              uint8_t error = Wire.endTransmission ();
              if (error == 0)                    Serial << " @ ";
              else if (error == 1)               Serial << " t ";
              else if (error == 2 or error == 3) Serial << " - ";
              else                               Serial << " ? ";
          }
      }
      Serial << endl;
  }
  Serial << dec;
}


void loop() {
  // put your main code here, to run repeatedly:
}