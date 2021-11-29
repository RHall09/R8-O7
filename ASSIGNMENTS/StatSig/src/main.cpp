#include <Arduino.h>
#include "stat_tracker.h"
#include "PrintStream.h"

StatTracker mystats;

void setup() {
  // Setup the serial port
  Serial.begin(115200);
  delay (2000);
  Serial.print("Hello there. I'll spit out some stastisstics in a bit here. \n");
  delay (1000);
  mystats.add_data(-10);
  mystats.add_data(-10);
  mystats.add_data(-10);
  Serial << mystats.num_points() << endl;
  Serial << mystats.average() << endl;
  Serial << mystats.std_dev() << endl;
  mystats.clear();
  Serial << mystats.num_points() << endl;
}

void loop() {
  // put your main code here, to run repeatedly:
}