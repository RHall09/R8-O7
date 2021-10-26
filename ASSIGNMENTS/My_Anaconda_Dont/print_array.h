/** @file   print_array.h
 *          This file serves as the header for the print_array.cpp file. 
 *
 *  @author Anil Singh
 *  @author Rick Hall
 *  @author Kai Quizon 
 *  @date   2020-25-Oct 
 */

#ifndef PRINT_ARRAY_H
#define PRINT_ARRAY_H

#include <Arduino.h>
#include <PrintStream.h>

/** @brief            This function prints a boolean array
 *  @details          This function prints each boolean array to the serial port 
 *                    or to a user-declared device. 
 * 
 *  @param p_array    The pointer to the first element of the boolean array. The pointer 
 *                    must be specified for the function to operate.
 *  @param array_size The number of elements in the array, as an 8-bit, unsigned 
 *                    integer.
 *  @param device     The device through which the function should print the array.
 */
void print_array (bool* p_array, uint8_t array_size, Print& device = Serial);

/** @brief            Prints a signed, 8-bit integer array
 *  @details          This function prints the signed 8-bit integer array
 *                    to the serial port or to a user-specified device. 
 * 
 *  @param p_array    The pointer to the first element of the signed, 8-bit integer array. 
 *                    The pointer type must be specified for the function to operate. 
 *  @param array_size The number of elements in the array, as an 8-bit signed 
 *                    integer.
 *  @param device     The device through which the function should print the array. 
 *
 */
void print_array (int8_t* p_array, uint8_t array_size, Print& device = Serial);

/** @brief            Prints an unsigned 8-bit integer array
 *  @details          This function prints the unsigned 8-bit integer array to the serial port 
 *                    or to a user-declared device. 
 * 
 *  @param p_array    The pointer to the first element of the unsigned, 8-bit integer array. 
 *                    The pointer type must be specified for the function to operate.
 *  @param array_size The number of elements in the array, as an 8-bit unsigned 
 *                    integer.
 *  @param device     The device through which the function should print the array. 
 */

void print_array (uint8_t* p_array, uint8_t array_size, Print& device = Serial);
/** @brief            Prints an array of floating point numbers
 *  @details          This function prints the float array of a specified size to 
 *                    the serial port or to a user-specified device. 
 * 
 *  @param p_array    The pointer to the first element of the array. The pointer type
 *                    must be specified for the function to operate.
 *  @param array_size The number of elements in the array, as a float.
 *  @param device     The device through which the function should print the array.  
 */
void print_array (float* p_array, uint8_t array_size, Print& device = Serial);

#endif