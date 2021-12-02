#include <Arduino.h>
#include <PrintStream.h>
#include <Motor.h>
#include <MotorCS.h>
#include <ESP32Encoder.h>

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  delay(2000);

  Serial << "I hope this works" << endl;
  delay(2000);

    // pinMode(13, OUTPUT);
    // digitalWrite(13, HIGH);

    // ledcAttachPin(12, 0);
    // ledcSetup(0, 30000, 8);
    // ledcWrite(0, 0);

    // // pinMode(11, OUTPUT);
    // // digitalWrite(11, LOW);
    // ledcAttachPin(27, 1);
    // ledcSetup(1, 30000, 8);
    // ledcWrite(1, 0);

  Motor my_motor(13,12,27, Motor_0);
  my_motor.enable();

  ESP32Encoder my_encoder;
  my_encoder.attachFullQuad(GPIO_NUM_26,GPIO_NUM_25);

  MotorCS the_motor_CS(1, 0, 0);
  the_motor_CS.startCS();

  Serial << "The motor should be enabled?" << endl;
  delay(2000);

  int16_t set = 0;

  float current_count = 0;
  float last_count = 0;

  int16_t enc_vel = 0;

  for(;;)
  {
    if(set < 255)
    {
      set = set + 1;
    }
    else
    {
      set = 0;
    }

    current_count = (float)my_encoder.getCount();
    enc_vel = (int16_t)round(current_count - last_count);
    last_count = current_count;

    the_motor_CS.newSetpoint(set);
    the_motor_CS.run(my_motor, enc_vel);

    Serial << "The current setpoint is: " << set << endl;
    delay(10);


  }
}

void loop() {
  // put your main code here, to run repeatedly:
}