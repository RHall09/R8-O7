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
            Serial << "I2C bus joined as master" << endl;
        }
    }

/** @brief Change the configuration of a single I/O port. If the existing configuration is specified, no change is made.
 *  @param portnum  The port to be configured.
 *  @param i_o      A boolean representing the state configuration desired. True for input, false for output.
 */
    void configport(uint8_t portnum, bool i_o) {
        // Read input register for current status
        Wire.beginTransmission((address<<1));     // Connect to this objects i2c device in read mode
        Wire.write(byte(0b00000011));             // Point to the configuration register
        Wire.endTransmission();                  // Send the bytes to the device and end transmission

        Wire.requestFrom((address<<1), 1);     // Request 1 byte from the device
 
        uint8_t deforient = Wire.read();      // Read the register and dump into deforientation
        }
        if (i_o) {
            uint8_t datawrite |= deforient << portnum;     // Set the bit at portnum to turn the port into an input
        }
        else {
            uint8_t datawrite &= ~(deforient << portnum);  // Clear the bit at portnum to turn the port into an output (when i_o) is false.
        }
        // uint8_t commandbyte = 0b00000011;
        Wire.beginTransmission((address<<1+0b00000001));   // Connect to this objects i2c device in write mode
        // Wire.write(byte(commandbyte));                     Point to the configuration register. Commented out since redundant from above
        Wire.write(byte(datawrite));
        Wire.endTransmission();
    }
/** @brief Read from a port configured as input. Do nothing if port is not configured as input.
 *  @param portnum  The port to be read.
 *  @return 
 */
    uint8_t readinput(uint8_t portnum) {

    }

}

