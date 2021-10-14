#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);

void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  leftMotor->setSpeed(100);
  rightMotor->setSpeed(100); 
}

void loop() {
  // put your main code here, to run repeatedly:
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  delay (5000);
}