#include <Arduino.h>
#include <print_array.h>
#include <PrintStream.h>

void setup() {
  
  Serial.begin(115200);
  delay(2000);
  Serial.print("Hey I'm gonna print some crap, watch out.");
}

void loop() {
  
  bool newname[5] = {1,0,1,0,1};

  print_array(newname, 5);

  Serial.print('\n');
  delay(1200);
}