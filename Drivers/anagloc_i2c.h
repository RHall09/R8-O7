// analog_i2c.h

#ifndef ANALOG_I2C_H
#define ANALOG_I2C_H
#include <Arduino.h>

/** @brief Class containing functions for interacting with digital i2c expansion bus.
 *  @details This function prints a boolean array to the specified device. True is represented with "T" and false is represented with "F" The device

 */

class i2cana {
    // Declare class objects
    private:   // Private objects related to register addresses


    public:
    uint8_t address = 0b1001000;  // the i2c address of the chip to be controlled by this class

    i2cana();
    i2cana(bool debugflag);
    void readinput(uint8_t channel);
    void disableref();
    void enableref();

};

#endif