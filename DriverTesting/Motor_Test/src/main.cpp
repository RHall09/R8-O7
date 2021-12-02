#include <Arduino.h>
#include <analogWrite.h>
#include <PrintStream.h>
#include <Motor.h>

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  delay(2000);

  Serial << "I hope this works" << endl;
  delay(2000);

  Motor my_motor(GPIO_NUM_13,GPIO_NUM_12,GPIO_NUM_11, 0);
  my_motor.enable();

  Serial << "The motor should be enabled?" << endl;
  delay(2000);

  for(;;)
  {
    my_motor.set(100);
    Serial << "Motor on" << endl;

    delay(1000);

    my_motor.stop();
    Serial << "Motor off" << endl;

    delay(1000);

    my_motor.set(-100);
    Serial << "Motor on" << endl;

    delay(1000);

    my_motor.stop();
    Serial << "Motor off" << endl;

    delay(1000);

  }
}

void loop() {
  // put your main code here, to run repeatedly:
}