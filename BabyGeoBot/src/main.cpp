/** @file     main.cpp
 *                This will eventually contain the doxystring for this project...
 * @author    Kai Quizon
 * @date      October 13th, 2021
 * */

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);

// Initiate analog pin for proximity sensor
int analogPin = A0;   // Proximity sensor is located on Pin A0

int reading = 0;   // Reading is initialized with initial value of zero

int mindist = 10;  // Needs calibrating off of proximity sensor, minimum distance allowed for babybot to be from object

int dancecount = 0; //Initialize a "dance counter" to let BabyBot do something fun every now and again

// Function Declarations
void forward();
void forback();
void stop();
void coldetected();



void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  leftMotor->setSpeed(100);
  rightMotor->setSpeed(100); 
}

void loop() {
  // put your main code here, to run repeatedly:
  // Read the analog pin
  reading = analogRead(analogPin);

  // Break looping if too close to an object
  if (reading <= mindist) {
    coldetected();
  }
  else {
    forward();
  }

  if (dancecount >= 1000) {
    forback();
    coldetected();
    forback();
    coldetected();
    dancecount = 0;
  }

  dancecount = dancecount + 1;


}

void forward() {
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
}
void forback() {
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  delay (5000);
  leftMotor->run(BACKWARD);
  rightMotor->run(BACKWARD);
  delay(5000);
}

void stop() {
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
}

void coldetected() {
  stop();
  delay(1000);
  leftMotor->run(FORWARD);
  rightMotor->run(BACKWARD);
  delay(200);
}