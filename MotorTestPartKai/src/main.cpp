#include <Arduino.h>
#include <PrintStream.h>
#include <Motor.h>
#include <analogWrite.h>


void setup() {
  // put your setup code here, to run once:

  Serial.begin (115200);
  delay (2000);

  //pinMode(13, OUTPUT);
  //digitalWrite(13, HIGH);

  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  // digitalWrite(11, LOW);

  Motor my_motor(GPIO_NUM_13,GPIO_NUM_12,GPIO_NUM_11);
  my_motor.enable();

 // Motor my_motor(13,12,11);
  // my_motor.enable();

  Serial << endl << "Hello, I'm in ME507" << " ...and I am a failure in life, but ya know." << endl;

  for(;;)
  {
    

    Serial.println("Fore");

    

    my_motor.set(100);

    delay(5000);

    

    Serial.println("Stop");


    my_motor.stop();

    delay(2000);

    Serial.println("Back");

    my_motor.set(-100);

    delay(5000);

    Serial.println("Stop");

    my_motor.stop();

    delay(1000);


  }
}

void loop() {
  // put your main code here, to run repeatedly:

}