#include <Arduino.h>
#include <PrintStream.h>
#include <print_array.h>

void setup() {
  // put your setup code here, to run once:

  Serial.begin (115200);
  delay (2000);

  Serial << endl << "Hello, I'm in ME507" << " ...and I vote." << endl;
}

void loop() {
  // put your main code here, to run repeatedly:
Serial << "A random array of booleans is:     ";

float why[7] = { 8.777, -15.321, 0, 255, 12, 88, 147} ;

print_array(why, 7) ;  

delay(1000);

Serial << "..." << endl;

}