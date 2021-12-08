/** @file RegOperators.cpp
 *  @brief Some bit banger functions to simplify the toggling of bits.
 * @details   This file contains a compilation of functions that may
 *    be used to set, clear, toggle, and check the bits of a 
 *    flag register in memory. All functions are overloaded for
 *    8 or 16 bit flag registers.
 *
 *  @author Rick Hall
 *  @date 2020-2-Nov
 *  @copyright (c) 2021 by Rick Hall, released under the LGPL 3.0.
 */

#include <Arduino.h>
#include <Misc_Drivers/RegOperators.h>

// 8-bit External --------------------------------------------------------
/** @brief Clears the bit
 *  @details This function clears the specified bit in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @param bit The bit to be operated on (0 - 7)
 * 
 *  @return The adjusted register
 */
uint8_t bit_clr(uint8_t reg, uint8_t bit)
{
    return (reg & ~(1 << bit));
}

/** @brief Sets the bit
 *  @details This function sets the specified bit in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @param bit The bit to be operated on (0 - 7)
 * 
 *  @return The adjusted register
 */
uint8_t bit_set(uint8_t reg, uint8_t bit)
{
    return (reg | (1 << bit));
}

/** @brief Toggles the bit
 *  @details This function toggles the specified bit in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @param bit The bit to be operated on (0 - 7)
 * 
 *  @return The adjusted register
 */
uint8_t bit_tog(uint8_t reg, uint8_t bit)
{
    return (reg ^ ~(1 << bit));
}

/** @brief Checks the bit
 *  @details This function returns a boolean representing the current state
 *           of the bit specified in the register provided.
 * 
 *  @param reg The register to be checked
 * 
 *  @param bit The bit to be returned (0 - 7)
 * 
 *  @return A boolean representing the state of the bit.
 */
bool bit_chk(uint8_t reg, uint8_t bit)
{
    return bool (reg >> bit & 1);
}

// 8-bit Internal --------------------------------------------------------
/** @brief Clears the bit
 *  @details This function clears the specified bit in the register provided.
 * 
 *  @param p_reg The pointer to the register to be operated on
 * 
 *  @param bit The bit to be operated on (0 - 7)
 */
void bit_clr(uint8_t* p_reg, uint8_t bit)
{
    *p_reg = *p_reg & ~(1 << bit);
}

/** @brief Sets the bit
 *  @details This function sets the specified bit in the register provided.
 * 
 *  @param p_reg The pointer to the register to be operated on
 * 
 *  @param bit The bit to be operated on (0 - 7)
 */
void bit_set(uint8_t* p_reg, uint8_t bit)
{
    *p_reg = *p_reg | (1 << bit);
}

/** @brief Toggles the bit
 *  @details This function toggles the specified bit in the register provided.
 *  @param p_reg The pointer to the register to be operated on
 * 
 *  @param bit The bit to be operated on (0 - 7)
 */
void bit_tog(uint8_t* p_reg, uint8_t bit)
{
    *p_reg = *p_reg ^ ~(1 << bit);
}

/** @brief Checks the bit
 *  @details This function returns a boolean representing the current state
 *           of the bit specified  in the register located at the pointer 
 *           provided.
 * 
 *  @param p_reg The pointer to the register to be checked
 * 
 *  @param bit The bit to be returned (0 - 7)
 * 
 *  @return A boolean representing the state of the bit.
 */
bool bit_chk(uint8_t* p_reg, uint8_t bit)
{
    return bool (*p_reg >> bit & 1);
}

// 16-bit External --------------------------------------------------------
/** @brief Clears the bit
 *  @details This function clears the specified bit in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @param bit The bit to be operated on (0 - 7)
 * 
 *  @return The adjusted register
 */
uint16_t bit_clr(uint16_t reg, uint8_t bit)
{
    return (reg & ~(1 << bit));
}

/** @brief Sets the bit
 *  @details This function sets the specified bit in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @param bit The bit to be operated on (0 - 7)
 * 
 *  @return The adjusted register
 */
uint16_t bit_set(uint16_t reg, uint8_t bit)
{
    return (reg | (1 << bit));
}

/** @brief Toggles the bit
 *  @details This function toggles the specified bit in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @param bit The bit to be operated on (0 - 7)
 * 
 *  @return The adjusted register
 */
uint16_t bit_tog(uint16_t reg, uint8_t bit)
{
    return (reg ^ ~(1 << bit));
}

/** @brief Checks the bit
 *  @details This function returns a boolean representing the current state
 *           of the specified bit in the register provided.
 * 
 *  @param reg The register to be checked
 * 
 *  @param bit The bit to be returned (0 - 7)
 * 
 *  @return A boolean representing the state of the bit.
 */
bool bit_chk(uint16_t reg, uint8_t bit)
{
    return bool (reg >> bit & 1);
}

// 16-bit Internal --------------------------------------------------------
/** @brief Clears the bit
 *  @details This function clears the specified bit in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @param bit The bit to be operated on (0 - 7)
 */
void bit_clr(uint16_t* p_reg, uint8_t bit)
{
    *p_reg = *p_reg & ~(1 << bit);
}

/** @brief Sets the bit
 *  @details This function sets the specified bit in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @param bit The bit to be operated on (0 - 7)
 */
void bit_set(uint16_t* p_reg, uint8_t bit)
{
    *p_reg = *p_reg | (1 << bit);
}

/** @brief Toggles the bit
 *  @details This function toggles the specified bit in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @param bit The bit to be operated on (0 - 7)
 */
void bit_tog(uint16_t* p_reg, uint8_t bit)
{
    *p_reg = *p_reg ^ ~(1 << bit);
}

/** @brief Checks the bit
 *  @details This function returns a boolean representing the current state
 *           of the specified bit in the register provided.
 * 
 *  @param reg The register to be checked
 * 
 *  @param bit The bit to be returned (0 - 7)
 * 
 *  @return A boolean representing the state of the bit.
 */
bool bit_chk(uint16_t* p_reg, uint8_t bit)
{
    return bool (*p_reg >> bit & 1);
}