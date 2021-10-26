#include <Arduino.h>
#include <print_array.h>
#include <PrintStream.h>

void setup() {
  
  Serial.begin(115200);
  delay(2000);
  Serial.print("Hey I'm gonna print some crap, watch out.");
}

void loop() {
  
  bool newname[5] = {1,"Null",1,"A","This is false."};
  
  uint8_t intarray[] = {72,13,15,255,0};

  int8_t signedarray[] = {-1,-100,100,0,-55};

  float floatarray[] = {2.1519, -13.74, 1000.01, 1.1, 3.14159};

  print_array(intarray, 5);
  Serial.print('\n');
  print_array(signedarray, 5);
  Serial.print('\n');
  print_array(floatarray,5);
  Serial.print('\n');
  delay(1200);
}