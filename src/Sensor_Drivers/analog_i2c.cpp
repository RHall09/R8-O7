/** @file analog_i2c.cpp
 *  @brief        This file acts as a driver for the \b PCA9534 8-bit I2C-bus with 8 digital I/O pins.
 * @author Kai Quizon
 * @date   October 25, 2021
 * @copyright (c) 2021 by Kai Quizon, released under the LGPL 3.0.
 **/

#include <Wire.h>
#include <Arduino.h>
#include <PrintStream.h>
#include "analog_i2c.h"


/** @brief Default contructor that disables debugging printouts.
 */
i2cana::i2cana() {
    bool debugflag = false;
    
}

/** @brief Parameterized constructor that enables debugging prinouts if debugflag == True
 *  @param debugflag   A boolean that turns on debugging prinouts if true.
 */
i2cana::i2cana(bool debugflag) {
    if (debugflag) {
        Serial.begin(115200);
        delay (200);
        Serial.print("Analog I2C Bus Class Initialized.\n");
        
    }
}

/** @brief Join i2c bus as master
 */
void i2cana::joini2c() {
    Wire.begin()
    if (debugflag) {
        Serial << "I2C bus joined as master" << endl;
    }
}

/** @brief Read an analog pin from the expansion bus. Really want to speed this code up...
 * @param channel The desired channel to be read. (valid range 0-7). Performs no action if outside valid range.
 */
uint16_t i2cana::readinput(uint8_t channel) {
    uint8_t commands[] = {0b10001111, 0b10101111, 0b11001111, 0b10011111, 0b10101111, 0b11101111, 0b10111111, 0b11111111};
    uint8_t commandbyte = byte(commands[channel]);
    Wire.beginTransmission(address);
    Wire.write(commandbyte);
    Wire.endTransmission;

    Wire.requestFrom(address, 2);    // Request 2 bytes from the device

    whlie(Wire.available()) {
        uint16_t data = Wire.read();   // Read 2 bytes (hopefully) from device   
    }
    return data;
}
