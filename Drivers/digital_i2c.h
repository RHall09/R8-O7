// digital_i2c.h

#ifndef DIGITAL_I2C_H
#define DIGITAL_I2C_H
#include <Arduino.h>

/** @brief Class containing functions for interacting with digital i2c expansion bus.
 *  @details This function prints a boolean array to the specified device. True is represented with "T" and false is represented with "F" The device

 */

class i2cdig {
    // Declare class objects
    protected:   // Private objects related to register addresses
    uint8_t input_port = byte(0);
    uint8_t output_port = byte(1);
    uint8_t pol_port = byte(2);
    uint8_t config_port = byte(3);

    public:
    uint8_t address = 0b0100000;  // the i2c address of the chip to be controlled by this class (8 bits!!!)

    i2cdig();
    i2cdig(bool debugflag);
    void joini2c();
    void configport(uint8_t portnum, bool i_o);
    bool readinput(uint8_t portnum);
    void setoutput(uint8_t portnum, bool i_o);

};

#endif