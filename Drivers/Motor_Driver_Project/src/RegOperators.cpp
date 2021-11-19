/** @file RegOperators.cpp
 *    This file contains a compilation of functions that may
 *    be used to set, clear, toggle, and check the bits of a 
 *    flag register in memory. All functions are overloaded for
 *    8 or 16 bit flag registers.
 *
 *  @author Rick Hall
 *  @date 2020-2-Nov
 */

#include <Arduino.h>
#include <RegOperators.h>

// 8-bit External --------------------------------------------------------
/** @brief Clears the bit
 *  @details This function clears the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
uint8_t bit_clr(uint8_t reg, uint8_t bit)
{
    return (reg & ~(1 << bit));
}

/** @brief Sets the bit
 *  @details This function sets the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
uint8_t bit_set(uint8_t reg, uint8_t bit)
{
    return (reg | (1 << bit));
}

/** @brief Toggles the bit
 *  @details This function toggles the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
uint8_t bit_tog(uint8_t reg, uint8_t bit)
{
    return (reg ^ ~(1 << bit));
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
bool bit_chk(uint8_t reg, uint8_t bit)
{
    return bool (reg >> bit & 1);
}

// 8-bit Internal --------------------------------------------------------
/** @brief Clears the bit
 *  @details This function clears the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
void bit_clr(uint8_t* p_reg, uint8_t bit)
{
    *p_reg = *p_reg & ~(1 << bit);
}

/** @brief Sets the bit
 *  @details This function sets the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
void bit_set(uint8_t* p_reg, uint8_t bit)
{
    *p_reg = *p_reg | (1 << bit);
}

/** @brief Toggles the bit
 *  @details This function toggles the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
void bit_tog(uint8_t* p_reg, uint8_t bit)
{
    *p_reg = *p_reg ^ ~(1 << bit);
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
bool bit_chk(uint8_t* p_reg, uint8_t bit)
{
    return bool (*p_reg >> bit & 1);
}

// 16-bit External --------------------------------------------------------
/** @brief Clears the bit
 *  @details This function clears the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
uint16_t bit_clr(uint16_t reg, uint8_t bit)
{
    return (reg & ~(1 << bit));
}

/** @brief Sets the bit
 *  @details This function sets the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
uint16_t bit_set(uint16_t reg, uint8_t bit)
{
    return (reg | (1 << bit));
}

/** @brief Toggles the bit
 *  @details This function toggles the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
uint16_t bit_tog(uint16_t reg, uint8_t bit)
{
    return (reg ^ ~(1 << bit));
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
bool bit_chk(uint16_t reg, uint8_t bit)
{
    return bool (reg >> bit & 1);
}

// 16-bit Internal --------------------------------------------------------
/** @brief Clears the bit
 *  @details This function clears the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
void bit_clr(uint16_t* p_reg, uint8_t bit)
{
    *p_reg = *p_reg & ~(1 << bit);
}

/** @brief Sets the bit
 *  @details This function sets the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
void bit_set(uint16_t* p_reg, uint8_t bit)
{
    *p_reg = *p_reg | (1 << bit);
}

/** @brief Toggles the bit
 *  @details This function toggles the bit specified by the BitBool object
 *           in the register provided.
 * 
 *  @param reg The register to be operated on
 * 
 *  @return The adjusted register
 */
void bit_tog(uint16_t* p_reg, uint8_t bit)
{
    *p_reg = *p_reg ^ ~(1 << bit);
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
bool bit_chk(uint16_t* p_reg, uint8_t bit)
{
    return bool (*p_reg >> bit & 1);
}