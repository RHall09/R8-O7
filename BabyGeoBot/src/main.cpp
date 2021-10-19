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

int mindist = 1700;  // Needs calibrating off of proximity sensor, minimum distance allowed for babybot to be from object

int dancecount = 0; //Initialize a "dance counter" to let BabyBot do something fun every now and again

int randnum = 0; //Random number holder

int delaytim = 0; //Delay time holder




// Averaging variables

const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

// Function Declarations
void forward();
void forback();
void stop();
void coldetected();

/** @brief A doxystring for the setup function
 * 
 * */

void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  leftMotor->setSpeed(255);
  rightMotor->setSpeed(255); 
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

/** @brief A doxystring for the loop function
 * 
 * */


void loop() {
  // put your main code here, to run repeatedly:
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(analogPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;


  // Break looping if too close to an object
  if (average >= mindist) {
    coldetected();
  }
  else {
    forward();
  }

  /*if (dancecount >= 10000) {
    forback();
    coldetected();
    forback();
    coldetected();
    dancecount = 0;
  }
  */
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
  randnum = random(5);
  if (randnum <=3) {
    delaytim = 300;
  }
  else {
    delaytim = 600;
  }
  leftMotor->run(FORWARD);
  rightMotor->run(BACKWARD);
  delay(delaytim);
}