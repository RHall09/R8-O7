#include <Arduino.h>
#include "TinyGPS++.h"

// what's the name of the hardware serial port?
#define GPSSerial Serial1

// Setup for TinyGPS++
TinyGPSPlus gps;

void setup() {
  // wait for hardware serial to appear
  while (!Serial);

  // make this baud rate fast enough to we aren't waiting on it
  Serial.begin(115200);

  // 9600 baud is the default rate for the Ultimate GPS
  GPSSerial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    GPSSerial.write(c);
  }
  while (GPSSerial.available()>0) {
    gps.encode(GPSSerial.read());
    // Serial.println("Tiny GPS updated");
  }

  if (gps.location.isUpdated()) {
    Serial.println(gps.location.lat());
    Serial.println(gps.location.lng());
  }

  else {
    // Serial.println(gps.location.isUpdated());
    Serial.print("No data\n");
  }

  delay(5000);
}