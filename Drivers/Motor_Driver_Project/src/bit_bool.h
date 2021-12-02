/** @file bit_bool.h
 *    This file contains a class for setting and clearing
 *    single bit booleans in 8-bit flag registers while 
 *    maintaining an explicit name for the bit. This is 
 *    accomplished by creating bit objects of the contained
 *    class.
 *
 *  @author Rick Hall
 *  @date 2020-2-Nov
 */

#ifndef BIT_BOOL_H
#define BIT_BOOL_H

#include <Arduino.h>
#include <PrintStream.h>

// BitBool class declaration
class BitBool
{

protected:
    
    // Pointer to specified register
    uint8_t* p_spec_reg = 0;
    // Specified bit of Bool object
    uint8_t spec_bit = 0;
    // Format Correct Boolean
    bool bit_valid = 0;

public:
    // Constructor function for register in main memory
    BitBool(uint8_t* p_reg, uint8_t bit);

    // Constructor function for external register
    BitBool(uint8_t bit);

    // Constructor function for unspecified register
    BitBool(void);

// Setup Functions
    // Set Register
    void set_reg(uint8_t* p_reg);
    // Set Bit
    void set_bit(uint8_t bit);

// Internal Register
    // Function to clear a bit
    void clr(void);
    // Function to set a bit
    void set(void);
    // Function to toggle a bit
    void tog(void);
    // Function to check bit state
    bool chk(void);

// External Register
    // Function to clear a bit
    uint8_t clr(uint8_t reg);
    // Function to set a bit
    uint8_t set(uint8_t reg);
    // Function to toggle a bit
    uint8_t tog(uint8_t reg);
    // Function to check bit state
    bool chk(uint8_t reg);

};

#endif

