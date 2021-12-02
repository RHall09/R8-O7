#include <Arduino.h>
#include <PrintStream.h>



void setup() {
  // put your setup code here, to run once:

  Serial.begin (115200);
  delay (2000);

  Serial << endl << "Hello, I'm in ME507" << " ...and I vote." << endl;
  pinMode(PA5, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(PA5, HIGH);

  delay(1000);

  digitalWrite(PA5, LOW);

  delay(1000);

}