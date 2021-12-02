/** @file     main.cpp
 *                This will eventually contain the doxystring for this project...
 * @author    Kai Quizon
 * @date      October 13th, 2021
 * */

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include "TinyGPS++.h"
#include <time.h>

// Adafruit MotorFeatherWing Initialization
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);

// GPS Initialization
// TinyGPSPlus gps;     // Start the TinyGPS++ module
// #define GPSSerial Serial1    // Define the serial port with the gps featherwing attached

// Initiate analog pin for proximity sensor
int analogPin = A0;   // Proximity sensor is located on Pin A0

int reading = 2500;   // Reading is initialized with initial value of zero

int mindist = 1700;  // Needs calibrating off of proximity sensor, minimum distance allowed for babybot to be from object. ONLY for IR sensor

int dancecount = 0; //Initialize a "dance counter" to let BabyBot do something fun every now and again

int randnum = 0; //Random number holder

int delaytim = 0; //Delay time holder

int avoiddist = 700;   // Value to "avoid" with natural movement techniques. ONLY for IR sensor

// Speed variables for natural avoid

int speed1 = 0;    // First of two speed variables

int speed2 = 0;    // Second of two speed variables

bool natflag = false;  // Boolflag to properly exit natavoid if path is free of obstruction




// Averaging variables

const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
uint16_t average = 0;                // the average



// Some time variables for use with nonblocking natural collision avoidance
// remember that these are NOT integers and are NOT valid for normal arithmetic. Use difftime() instead.
time_t inittime;
time_t curr_time;
time_t runtime;
time_t extratime;

// Function Declarations
void forward();
void forback();
void stop();
void coldetected();
void natavoid(uint16_t averageread, bool natflag);

/** @brief A doxystring for the setup function
 * 
 * */

void setup() {
  // put your setup code here, to run once:
  // wait for hardware serial to appear
  while (!Serial);

  // 9600 baud is the default rate for the Ultimate GPS
  //GPSSerial.begin(9600);

  AFMS.begin();
  leftMotor->setSpeed(150);
  rightMotor->setSpeed(150); 
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

/** @brief A doxystring for the loop function
 * 
 * */


void loop() {
  // Update Current Time
  time(&curr_time);
  
  // grab GPS data and feed to TinyGPS++
  // gps.encode(GPSSerial.read());

  // This code snippet is for testing purposes. It prints GPS data to the serial port, however it doesn't really serve a purpose when BabyBot is running.
  // if (GPSSerial.available()) {
  //   char c = GPSSerial.read();
  //   Serial.write(c);
  // }

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
  average = 2500;


  // Break looping if too close to an object
  if (average >= mindist) {
    coldetected();
  }
  else if (average >= avoiddist) {
    natavoid(average, natflag);
    natflag = false;
  }
  else {
    natflag = true;
    natavoid(average, natflag);
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

void natavoid(uint16_t averageread, bool natflag) {

  if (inittime) {
    if (difftime(curr_time, inittime)>=runtime) {
      leftMotor->setSpeed(255);
      rightMotor->setSpeed(255);
      inittime = NULL;
    }
  }
  else if (natflag == false) {
    time(&inittime);
    randnum = random(10);
    if (randnum <= 5) {
      speed1 = 75;
      speed2 = 175;
    }
    else {
    speed1 = 175;
    speed2 = 75;
    }
    if (average >= 900) {
        // Speed up turn if distance is still closing
        speed1 += 25;
        speed2 += 25;
    }
    leftMotor->setSpeed(speed1);
    rightMotor->setSpeed(speed2);
  }
  if (natflag) {
    leftMotor->setSpeed(150);
    rightMotor->setSpeed(150);
    inittime = NULL;
  }

}