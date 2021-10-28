/** @file   main.cpp
 *          This file serves as a main file to test and implement print_array.cpp & 
 *          print_array.h.
 *
 *  @author Anil Singh
 *  @author Kai Quizon
 *  @author Rick Hall
 *  @date   2020-25-Oct 
 */

#include <Arduino.h>
#include <PrintStream.h>
#include <print_array.h>

void setup() {
  // Setup code, runs once:
  Serial.begin (115200);
  delay (3000);
  Serial << endl << "Hello, I'm in ME507" << endl;
}

void loop() {
  // Main code, runs repeatedly:

Serial << "Random uint8_t's: " ;
uint8_t uint8_set_one[5] = {15, 0, 200, 123, 5};
print_array(uint8_set_one, 5) ;
Serial << endl << endl;
delay(1000);

Serial << "Random floats: " ;
float float_set_one[7] = { 0.001, -21.395, 0, 1e16, 1e3, 1e32, 1} ;
print_array(float_set_one, 7) ;  
Serial << endl << endl;
delay(1000);

Serial << "Random booleans: " ;
bool boolean_set_one[6] = {1, 1, 0, 1, 0, 0} ;
print_array(boolean_set_one, 6) ;
Serial << endl << endl;
delay(1000);

Serial << "Random int8_t's: " ;
int8_t int8_set_one[5] = {17, 0, -56, 17, 50} ;
print_array(int8_set_one, 5) ;
Serial << endl << endl;
delay(1000);

Serial << "Random uint8_t: " ;
uint8_t uint8_set_two[0] = {} ;
print_array(uint8_set_two, 0) ;
Serial << endl << endl;
delay(1000);

}