/** @file main.cpp
 *    This file contains source code for main.
 * 
 *  @author Anil Singh
 *  @date  2021-Nov-27 Original file
 */
#include "Arduino.h"
// #include "BluetoothSerial.h"

// #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
// #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
// #endif

// int dataIn[7] {0,0,0,0,0,0}; //array to store all the information. 255,button,X,Y.
// int in_byte = 0;
// int array_index = 0;
// BluetoothSerial SerialBT;
// void setup() {
//   Serial.begin(115200);
//   SerialBT.begin("ESP32test"); //Bluetooth device name
//   Serial.println("Device Initialized, Ready for Pairing");
//   delay(5000);
  
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   if (Serial.available() > 0) {  //recieve byte from phone
//     in_byte = Serial.read(); //store in byte into a variable
//     if (in_byte == (255)) { // if the variable is 0 sets the array inxed to 0. this will make sure that every number goes into the correct index
//       array_index = 0;
//     }
//     dataIn[array_index] = in_byte;  //store number into array
//     array_index = array_index +1;
//   }
//   //print the array
//   Serial.print (dataIn[0]);
//   Serial.print (", Geofence:");
//   Serial.print (dataIn[1]);
//   Serial.print (", Navigation:");
//   Serial.print (dataIn[2]);
//   Serial.print (", Sensor Array:");
//   Serial.print (dataIn[3]);
//   Serial.print (", X:");
//   Serial.print (dataIn[4]);
//   Serial.print (", Y:");
//   Serial.print (dataIn[5]);
//   Serial.print (", Emergency Stop:");
//   Serial.print (dataIn[6]);
//   Serial.print (",");
//   Serial.println (in_byte);

//   delay(5000);
// }




#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
Serial.begin(115200);
SerialBT.begin("ESP32test"); //Bluetooth device name
Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
if (Serial.available()) {
SerialBT.write(Serial.read());
}
if (SerialBT.available()) {
Serial.write(SerialBT.read());
}
delay(20);
}