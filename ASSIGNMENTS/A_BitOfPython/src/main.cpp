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

Serial << "Here are some random booleans: " ;

bool what[6] = {0, 1, 0, 0, 0, 1} ;
print_array(what, 6) ;

Serial << endl << endl;
delay(1000);

Serial << "Here are some random floats: " ;

float why[7] = { 0.00001, -15.321, 0, 1e32, 1e7, 1e8, 1} ;
print_array(why, 7) ;  

Serial << endl << endl;
delay(1000);

}