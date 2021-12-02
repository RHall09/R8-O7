#include <Arduino.h>
#include <PrintStream.h>
#include <Motor.h>


void setup() {
  // put your setup code here, to run once:

  Serial.begin (115200);
  delay (2000);

  Motor my_motor(GPIO_NUM_13,GPIO_NUM_12,GPIO_NUM_11);
  my_motor.enable();

  Serial << endl << "Hello, I'm in ME507" << " ...and I vote." << endl;

  for(;;)
  {
    my_motor.set((int16_t)(-112));

    delay(1000);

    my_motor.stop();

    delay(1000);

    my_motor.set((int16_t)(112));

    delay(1000);

    my_motor.stop();

    delay (1000);

  }
}

void loop() {
  // put your main code here, to run repeatedly:

}