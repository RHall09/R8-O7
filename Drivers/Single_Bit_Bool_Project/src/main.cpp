#include <Arduino.h>
#include <PrintStream.h>


void setup() {
  // put your setup code here, to run once:

  Serial.begin (115200);
  delay (2000);

  Serial << endl << "Hello, I'm in ME507" << " ...and I vote." << endl;
}

void loop() {
  // put your main code here, to run repeatedly:



}