/** @file analog_i2c.cpp
 *          This file contains the header for a class that acts as a driver for the ADS7828 8 Channel Analog I2C expansion bus.
 * @author Kai Quizon
 * @date   October 25, 2021
 **/

#ifndef ANALOG_I2C_H
#define ANALOG_I2C_H
#include <Arduino.h>

/** @brief Class containing functions for interacting with digital i2c expansion bus.
 *  @details This function prints a boolean array to the specified device. True is represented with "T" and false is represented with "F" The device

 */

class i2cana {
    // Declare class objects
    protected:   // Private objects related to register addresses
    uint8_t address = 0b1001000;  // the i2c address of the chip to be controlled by this class
    uint8_t commandbyte = 0b100011; // Point at channel 0 with internal ref on as default.
    
    
    public:
    i2cana();
    i2cana(bool debugflag);
    void joini2c();
    uint16_t readinput(uint8_t channel);
};

#endif