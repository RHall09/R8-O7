#include <Arduino.h>
#include <Wire.h>

uint32_t data_send;
bool data;

bool bad;
bool very_bad;

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

void requestEvent() {
  // Handle if there is anything to be afraid of our pass the a-ok on
  if (data) {
    Wire.write("Yes");
  }
  else {
    if (bad) {
      Wire.write("bad");
    }
    else if (very_bad) {
      Wire.write("Stop");
    }
    else {
      Wire.write("Warn");
    }
  }
  
}

void setup() {
  Wire.begin(0x0F);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}

void loop() {
}