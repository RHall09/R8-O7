#include <Arduino.h>
#include <PrintStream.h>
#include <Wire.h>

void receiveEvent(int howMany) {
  char c;
  while (0 < Wire.available()) {
    c = Wire.read();
    Serial.print(c);
    Serial.println();
  }
  if (c) {
    digitalWrite(PA5, HIGH);
  }
  else {
    digitalWrite(PA5, LOW);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
  delay(5000);
  // Serial.println ();
  // Serial.println ("I2C scanner. Scanning ...");
  // byte count = 0;
  
  // Wire.begin();
  // for (byte i = 1; i < 120; i++)
  // {
  //   Wire.beginTransmission (i);
  //   if (Wire.endTransmission () == 0)
  //     {
  //     Serial.print ("Found address: ");
  //     Serial.print (i, DEC);
  //     Serial.print (" (0x");
  //     Serial.print (i, HEX);
  //     Serial.println (")");
  //     count++;
  //     delay (1);  // maybe unneeded?
  //     } // end of good response
  // } // end of for loop
  // Serial.println ("Done.");
  // Serial.print ("Found ");
  // Serial.print (count, DEC);
  // Serial.println (" device(s).");

  Wire.begin(0x0F);
  Wire.onReceive(receiveEvent);

  
  pinMode(PA5, OUTPUT);
  digitalWrite(PA5, LOW);

  // pinMode(PC8, INPUT);

  Serial.print("Initialized\n");
}

void loop() {
  // put your main code here, to run repeatedly:
  // delay(5000);
  // digitalWrite(PA5, HIGH);
  // Serial.print("HIGH\n");
  // Serial << digitalRead(PC8) << endl;
  // delay(5000);
  // digitalWrite(PA5, LOW);
  // Serial.print("LOW\n");
  // Serial << digitalRead(PC8) << endl;
  delay(100);
  Serial.println("Nothin yet");

}

