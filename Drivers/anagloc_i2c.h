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
    uint8_t input_port = byte(0);
    uint8_t output_port = byte(1);
    uint8_t pol_port = byte(2);
    uint8_t config_port = byte(3);

    public:
    uint8_t address;  // the i2c address of the chip to be controlled by this class
    uint8_t write_addr = byte(address<<1);
    uint8_t read_addr = byte(address<<1 +0b00000001);

    i2cana();
    i2cana(bool debugflag);

};

#endif