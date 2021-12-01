
#include <Arduino.h>
#include <PrintStream.h>
#include <Encoder_Drivers/ESP32Encoder.h>
#include <Encoder_Drivers/InterruptEncoder.h>



void setup() 
{
    Serial.begin (115200);
    delay (2000);

    Serial << "Hi I'm working..." << endl;

    ESP32Encoder my_encoder;
    my_encoder.attachFullQuad(GPIO_NUM_26,GPIO_NUM_25);

    Serial << "Encoder Attached?" << endl;

    for(;;)
    {
        // put your main code here, to run repeatedly:
        Serial << (float)my_encoder.getCount() << endl;
    }
}

void loop() 
{

}