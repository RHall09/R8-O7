/** @file digital_i2c.h
 *  @brief        This file contains the declaration of a class that acts as a driver for the PCA9534 8-bit I2C-bus with 8 digital I/O pins. Member functions are contained in \ref digital_i2c.cpp.
 * @author Kai Quizon
 * @date   October 25, 2021
 * @copyright (c) 2021 by Kai Quizon, released under the LGPL 3.0.
 **/
#ifndef DIGITAL_I2C_H
#define DIGITAL_I2C_H
#include <Arduino.h>

/** @brief Class containing functions for interacting with digital i2c expansion bus.
 *  @details This class contains a variety of methods for interacting with the PCA9534 8-bit digital I2C-bus. First, the class may be
 *           initialized with or without a debugflag. If the debugflag is written to true, then debug statements will be printed to the
 *           default serial port by this class object. Further, the class contains methods to join the i2c bus, change the configuration of
 *           individual ports, read input ports, and set output ports. The class is built on boolean toggles.
 */

class i2cdig {
    // Declare class objects
    protected:   // Private objects related to register addresses
    /// The address of the input port which may be read from to determine the state of the attached peripheral inputs.
    uint8_t input_port = byte(0);
    /// The address of the output port which may be written to to apply logic HIGH and LOW values to the attached peripheral outputs.
    uint8_t output_port = byte(1);
    /// The address of the polarity port which may be written to to flip the polarity of a peripheral defined as an input.
    uint8_t pol_port = byte(2);
    /// The address of the configuration port which may be written to to change the configuration of a port to an input or output, it may also be read to determine the current configuration.
    uint8_t config_port = byte(3);
    /// The adress of the PCA9534 chip. Default is the address with all address pins grounded.
    uint8_t address = 0b0100000;  // the i2c address of the chip to be controlled by this class (8 bits!!!)
    /// The boolean flag controlling debug prints to the default serial port.
    bool debugflag;

    public:
    // Doxystrings are in the .cpp file. Yea I was weird back then.
    i2cdig();
    i2cdig(bool debugflag);
    void joini2c();
    void configport(uint8_t portnum, bool i_o);
    bool readinput(uint8_t portnum);
    void setoutput(uint8_t portnum, bool i_o);

};

#endif