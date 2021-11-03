/** @file bit_bool.cpp
 *    This file contains a class for setting and clearing
 *    single bit booleans in 8-bit flag registers while 
 *    maintaining an explicit name for the bit. This is 
 *    accomplished by creating bit objects of the contained
 *    class.
 *
 *  @author Rick Hall
 *  @date 2020-2-Nov
 */

#include <Arduino.h>
#include <PrintStream.h>
#include <bit_bool.h>


/** @brief Constructs an internal BitBool object
 *  @details This function creates an object that can be used to set and clear 
 *           individual bits in a register for use as boolean flags. This version
 *           of the overloaded function stores the memory location of the register
 *           and handles all operations internally.
 * 
 *  @param p_reg The pointer to the 8-bit register to be operated on.
 *  @param bit The bit location of the desired flag, indexed from 0-7.
 */
BitBool::BitBool(uint8_t* p_reg, uint8_t bit)
{
    // Store the specified register to edit in the object
    p_spec_reg = p_reg;

    // If the bit is not 0-7, throw exception
    if (bit > 8)
    {
        throw;
    }
    else
    {
        spec_bit = bit;
    }
}

/** @brief Constructs an external BitBool object
 *  @details This function creates an object that can be used to set and clear 
 *           individual bits in a register for use as boolean flags. This version
 *           of the overloaded function requires the register to be input and 
 *           will return the adjusted register after the operation is completed.
 * 
 *  @param bit The bit location of the desired flag, indexed from 0-7.
 * 
 *  @return The adjusted register.
 */
BitBool::BitBool(uint8_t bit)
{
    // Register will be accessed externally and fed in; pointer set to 0
    p_spec_reg = 0;

    // If the bit is not 0-7, throw exception
    if (bit > 8)
    {
        throw;
    }
    else
    {
        spec_bit = bit;
    }

    if (bit < 9)
    {
        spec_bit = bit;
    }
    else
    {
        spec_bit = 0;
    }
}


/** @brief Clears the bit
 *  @details This function clears the bit specified by the BitBool object
 *           in the register stored by the BitBool object. There are no
 *           parameters or returns.
 */
void BitBool::clr(void)
{
    *p_spec_reg &= ~(1UL << spec_bit);
}

/** @brief Sets the bit
 *  @details This function sets the bit specified by the BitBool object
 *           in the register stored by the BitBool object. There are no
 *           parameters or returns.
 */
void BitBool::set(void)
{
    *p_spec_reg |= (1UL << spec_bit);
}

/** @brief Toggles the bit
 *  @details This function toggles the bit specified by the BitBool object
 *           in the register stored by the BitBool object. There are no
 *           parameters or returns.
 */
void BitBool::tog(void)
{
    *p_spec_reg ^= ~(1UL << spec_bit);
}

/** @brief Checks the bit
 *  @details This function returns a boolean representing the current state
 *           of the bit specified in the BitBool object in the register 
 *           stored by the BitBool object.
 * 
 *  @return A boolean representing the state of the bit.
 */
bool BitBool::chk(void)
{
    return bool (*p_spec_reg >> spec_bit & 1U);
}

/** @brief Clears the bit
 *  @details This function clears the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
uint8_t BitBool::clr(uint8_t reg)
{
    return (reg & ~(1UL << spec_bit));
}

/** @brief Sets the bit
 *  @details This function sets the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
uint8_t BitBool::set(uint8_t reg)
{
    return (reg | (1UL << spec_bit));
}

/** @brief Toggles the bit
 *  @details This function toggles the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
uint8_t BitBool::tog(uint8_t reg)
{
    return (reg ^ ~(1UL << spec_bit));
}

/** @brief Checks the bit
 *  @details This function returns a boolean representing the current state
 *           of the bit specified in the BitBool object in the register 
 *           provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return A boolean representing the state of the bit.
 */
bool BitBool::chk(uint8_t reg)
{
    return bool (reg >> spec_bit & 1U);
}

