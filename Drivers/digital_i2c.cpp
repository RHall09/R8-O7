/** @file digital_i2c.cpp
 *          This file acts a s a driver for the PCA9534 8-bit I2C-bus with 8 digital I/O pins.
 * @author Kai Quizon
 * @date   October 25, 2021
 **/

#ifdef ARDUINO
#include <Wire.h>
#include <Arduino.h>
#include <PrintStream.h>

/** @brief Class containing functions for interacting with digital i2c expansion bus.
 *  @details This function prints a boolean array to the specified device. True is represented with "T" and false is represented with "F" The device

 */

class i2cdig {

    // Declare class objects
    public:
    uint8_t address;  // the i2c address of the chip to be controlled by this class

/** @brief Default contructor that disables debugging printouts.
 */
    i2cdig() {
        bool debugflag = false;
        
    }
    
/** @brief Parameterized constructor that enables debugging prinouts if debugflag == True
 *  @param debugflag   A boolean that turns on debugging prinouts if true.
 */
    i2cdig(bool debugflag) {
        if (debugflag) {
            Serial.begin(115200);
            delay (200);
            Serial.print("Digital I2C Bus Class Initialized.\n");
            
        }
    }
/** @brief Join i2c bus to the specified address for this class object
 */
    void joini2c() {
        Wire.begin()
        if (debugflag) {
            Serial << "I2C bus joined to as master" << endl;
        }
    }

/** @brief Change the configuration of a single I/O port. If the existing configuration is specified, no change is made.
 *  @param portnum  The port to be configured.
 *  @param i_o      A boolean representing the state configuration desired. True for input, false for output.
 */
    void configport(uint8_t portnum, bool i_o) {
        uint8_t deforient = 0b11111111      // Since the default configuration is input, define a binary 255 as default
        for(int inc = 0; inc < 8; inc++) {
            if (inc != portnum) {

            }
        }
        Wire.beginTransmission(address)
        Wire.write()
    }

}

