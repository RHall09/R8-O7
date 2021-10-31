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

Serial << "Here are some random uint8_t: " ;

uint8_t is[5] = {12, 0, 100, 255, 66} ;
print_array(is, 5) ;

Serial << endl << endl;
delay(1000);

Serial << "Here are some random int8_t: " ;

int8_t going[5] = {12, 0, -100, 127, -128} ;
print_array(going, 5) ;

Serial << endl << endl;
delay(1000);

Serial << "Here are some random floats: " ;

float on[7] = { 0.00001, -15.321, 0, 1e32, 1e7, 1e8, 1} ;
print_array(on, 7) ;  

Serial << endl << endl;
delay(1000);

Serial << "Here are some random uint8_t: " ;

uint8_t killmenow[0] = {} ;
print_array(killmenow, 0) ;

Serial << endl << endl;
delay(1000);

}