/** @file digital_i2c.cpp
 *          This file acts a s a driver for the PCA9534 8-bit I2C-bus with 8 digital I/O pins.
 * @author Kai Quizon
 * @date   October 25, 2021
 **/

#include <Wire.h>
#include <Arduino.h>
#include <PrintStream.h>
#include "digital_i2c.h"


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
    if (channel == 0) {
        commandbyte = 0b10001111;
    }
    else if (channel ==1) {
        commandbyte = 0b10101111;
    }
    else if (channel ==2) {
        commandbyte = 0b11001111;
    }
    else if (channel ==3) {
        commandbyte = 0b10011111;
    }
    else if (channel ==4) {
        commandbyte = 0b10101111;
    }
    else if (channel ==5) {
        commandbyte = 0b11101111;
    }
    else if (channel ==6) {
        commandbyte = 0b10111111;
    }
    else if (channel ==7) {
        commandbyte = 0b11111111;
    }
    else {
        return 0;
    }
    Wire.beginTransmission(address);
    Wire.write(commandbyte);
    Wire.endTransmission;

    Wire.requestFrom(address, 2);    // Request 2 bytes from the device

    whlie(Wire.available()) {
        uint16_t data = Wire.read();   // Read 2 bytes (hopefully) from device   
    }
    return data;
}
