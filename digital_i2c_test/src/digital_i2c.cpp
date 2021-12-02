/** @file digital_i2c.cpp
 *          This file contains the member functions of a class that acts as a driver for the PCA9534 8-bit I2C-bus with 8 digital I/O pins.
 * @author Kai Quizon
 * @date   October 25, 2021
 **/

#include <Wire.h>
#include <Arduino.h>
#include <PrintStream.h>
#include "digital_i2c.h"


/** @brief Default contructor that disables debugging printouts.
 */
i2cdig::i2cdig() {
    bool debugflag = false;
    
}

/** @brief Parameterized constructor that enables debugging prinouts if debugflag == True
 *  @param debugflag   A boolean that turns on debugging prinouts if true.
 */
i2cdig::i2cdig(bool debugflag) {
    if (debugflag) {
        Serial.begin(115200);
        delay (200);
        Serial.print("Digital I2C Bus Class Initialized.\n");
        
    }
}
/** @brief Join i2c bus as a master.
 */
void i2cdig::joini2c() {
    Wire.begin();
    if (debugflag) {
        Serial << "I2C bus joined as master" << endl;
    }
}

/** @brief Change the configuration of a single I/O port. If the existing configuration is specified, no change is made.
 *  @param portnum  The port to be configured.
 *  @param i_o      A boolean representing the state configuration desired. True for input, false for output.
 */
void i2cdig::configport(uint8_t portnum, bool i_o) {
    // Read input register for current status
    Wire.beginTransmission(address);     // Connect to this objects i2c device in read mode
    Wire.write(config_port);             // Point to the configuration register
    Wire.endTransmission();                  // Send the bytes to the device and end transmission
    if (debugflag) {
        Serial.print("Pointing to configuration port \n");
    }
    Wire.requestFrom(address, 1);     // Request 1 byte from the device

    uint8_t deforient = Wire.read();      // Read the register and dump into deforientation
    if (debugflag) {
        Serial << "The current cofiguration is: " << deforient << endl;
    }
    uint8_t datawrite;
    if (i_o) {
        datawrite |= deforient << portnum;     // Set the bit at portnum to turn the port into an input
    }
    else {
        datawrite &= ~(deforient << portnum);  // Clear the bit at portnum to turn the port into an output (when i_o) is false.
    }
    // uint8_t commandbyte = 0b00000011;
    Wire.beginTransmission((address));   // Connect to this objects i2c device in write mode
    Wire.write(byte(config_port));           // Point to Configuration Register
    Wire.write(byte(datawrite));            // Write to configuration port data desired
    Wire.endTransmission();                 // Send data
}
/** @brief Read from a port configured as input. Do nothing if port is not configured as input.
 *  @param portnum  The port to be read.
 *  @return 
 */
bool i2cdig::readinput(uint8_t portnum) {
    Wire.beginTransmission(address);  // Connect to device address in write mode
    Wire.write(input_port);              // Point to the input port
    Wire.endTransmission();              // Send Data
    if (debugflag) {
        Serial.print("Pointing to input port \n");
    }

    Wire.requestFrom(address, 1);             // Request 1 byte from device

    uint8_t inputconfig = Wire.read();           // Read a byte from the register
    int bit = (inputconfig >> portnum) & 1;     // Locate the bit in question
    if (bit >= 1) {                             // This value may need to be calibrated if pull-down resistors are not present
        return true;
    }
    else {
        return false;
    }
}

/** @brief Change the status of a port configured as an output. No change will be made to ports configured as inputs.
 *  @param portnum  The port to be configured.
 *  @param i_o      A boolean representing the state desired. True for logic high, false for logic low.
 */
void i2cdig::setoutput(uint8_t portnum, bool i_o) {
    Wire.beginTransmission(address);       // Connect to device address in write mode
    Wire.write(output_port);                  // Point to the output register
    Wire.endTransmission();                    // Send Data

    if (debugflag) {
        Serial.print("Pointing to output port \n");
    }
    Wire.requestFrom((address<<1), 1);     // Request 1 byte from the device

    uint8_t deforient = Wire.read();      // Read the register and dump into deforientation
    if (debugflag) {
        Serial << "The current output cofiguration is: " << deforient << endl;
    }
    uint8_t datawrite;
    if (i_o) {
        datawrite |= deforient << portnum;     // Set the bit at portnum to turn the port on (logic 1)
    }
    else {
        datawrite &= ~(deforient << portnum);  // Clear the bit at portnum to turn the port off (logic 0)
    }
    // uint8_t commandbyte = 0b00000011;
    Wire.beginTransmission((address));   // Connect to this objects i2c device in write mode
    Wire.write(output_port);          // Point to the output register
    Wire.write(byte(datawrite));
    Wire.endTransmission();
    if (debugflag) {
        Serial.print("Wrote to output port");
    }

};
