/** @file RegOperators.h
 *    This file contains a compilation of functions that may
 *    be used to set, clear, toggle, and check the bits of a 
 *    flag register in memory. All functions are overloaded for
 *    8 or 16 bit flag registers. All functions are overloaded for
 *    providing registers or pointers to registers.
 *
 *  @author Rick Hall
 *  @date 2020-2-Nov
 */

#ifndef REG_OPERATORS_H
#define REG_OPERATORS_H

#include <Arduino.h>

// 8-bit External -----------------
// Function to clear a bit
uint8_t bit_clr(uint8_t reg, uint8_t bit);
// Function to set a bit
uint8_t bit_set(uint8_t reg, uint8_t bit);
// Function to toggle a bit
uint8_t bit_tog(uint8_t reg, uint8_t bit);
// Function to check bit state
bool bit_chk(uint8_t reg, uint8_t bit);

// 8-bit Internal -----------------
// Function to clear a bit
void bit_clr(uint8_t* p_reg, uint8_t bit);
// Function to set a bit
void bit_set(uint8_t* p_reg, uint8_t bit);
// Function to toggle a bit
void bit_tog(uint8_t* p_reg, uint8_t bit);
// Function to check bit state
bool bit_chk(uint8_t* p_reg, uint8_t bit);

// 16-bit External ----------------
// Function to clear a bit
uint16_t bit_clr(uint16_t reg, uint8_t bit);
// Function to set a bit
uint16_t bit_set(uint16_t reg, uint8_t bit);
// Function to toggle a bit
uint16_t bit_tog(uint16_t reg, uint8_t bit);
// Function to check bit state
bool bit_chk(uint16_t reg, uint8_t bit);

// 16-bit Internal -----------------
// Function to clear a bit
void bit_clr(uint16_t* p_reg, uint8_t bit);
// Function to set a bit
void bit_set(uint16_t* p_reg, uint8_t bit);
// Function to toggle a bit
void bit_tog(uint16_t* p_reg, uint8_t bit);
// Function to check bit state
bool bit_chk(uint16_t* p_reg, uint8_t bit);

#endif

