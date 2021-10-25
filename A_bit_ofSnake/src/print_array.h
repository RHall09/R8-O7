/** @file print_array.h
 *    This file acts as a header for the print_array class which takes in one of four data types as an array and prints the array in "Python" style.
 *
 *  @author Kai Quizon
 *  @date October 24, 2021
 */

#define PRINT_ARRAY_H

#include <Arduino.h>
#include <PrintStream.h>

/** @brief Prints an array of Booleans
 *  @details This function prints each boolean in an array of a specified size to 
 *           the serial port (if device is not specified) or to a user-specified
 *           device. 
 * 
 *  @param p_array The pointer to the first element of the array. The pointer type
 *                 must be specified for the function to operate correctly - in 
 *                 this case it should be a bool*.
 *  @param array_size The number of elements in the array, as an 8-bit unsigned 
 *                    integer. For arrays larger than 255 elements, use a 
 *                    different function.
 *  @param device The device through which the function should print the array. 
 *                This defaults to the Serial port, but may be specified as
 *                any other device capable of printing. 
 */
void print_array (bool* p_array, uint8_t array_size, Print& device = Serial);

/** @brief Prints an array of Unsigned 8-bit Integers
 *  @details This function prints each unsigned 8-bit integer in an array of a 
 *           specified size to the serial port (if device is not specified) or 
 *           to a user-specified device. 
 * 
 *  @param p_array The pointer to the first element of the array. The pointer type
 *                 must be specified for the function to operate correctly - in 
 *                 this case it should be a uint8_t*.
 *  @param array_size The number of elements in the array, as an 8-bit unsigned 
 *                    integer. For arrays larger than 255 elements, use a 
 *                    different function.
 *  @param device The device through which the function should print the array. 
 *                This defaults to the Serial port, but may be specified as
 *                any other device capable of printing. 
 */