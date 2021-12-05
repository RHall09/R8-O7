/** @headerfile analog_i2c.h ""
 *          This file contains the header for a class that acts as a driver for the \b ADS7828 8 Channel Analog I2C expansion bus. Member
 *          functions are contained in \ref analog_i2c.cpp
 * @author Kai Quizon
 * @date   October 25, 2021
 * @copyright (c) 2021 by Kai Quizon, released under the LGPL 3.0.
 **/

#ifndef ANALOG_I2C_H
#define ANALOG_I2C_H
#include <Arduino.h>

/** @brief Class containing functions for interacting with the \b ADS7828 Analog i2c expansion bus chip.
 *  @details This class allows for interaction with the \b ADS7828 Analog I2C Expansion Bus Chip. It contains methods for joining the i2c bus as a
 *           master and reading inputs from chip. The chip does not support outputs. There is also a method to configure the chip address if a different
 *           address is used via manipulation of the address pins.

 */

class i2cana {
    // Declare class objects
    protected:   // Private objects related to register addresses
    /// Default address of the \b ADS7828 chip. This address is used if all address pins are grounded. May be changed via the change_addr method.
    uint8_t address = 0b1001000;  // the i2c address of the chip to be controlled by this class
    /// Portion of each command necessary to leave internal reference on and appropriate filtering desired for mechatronics use case.
    uint8_t commandbyte = 0b100011; // Point at channel 0 with internal ref on as default.
    
    
    public:
    i2cana();
    i2cana(bool debugflag);
    void joini2c();
    uint16_t readinput(uint8_t channel);
};

#endif