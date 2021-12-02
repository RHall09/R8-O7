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
 *  @details This function prints a boolean array to the specified device. True is represented with "T" and false is represented with "F" The device
 *           must have a clarified "print" operator. The array is printed in the "Python"
 *           fashion of [1,2,3,4]. 
 * 
 *  @param p_array The pointer defining the array object (pointing to first entry). The data type must be properly
 *                 declared (ex: bool*)
 *  @param size The number of elements in the array, as an 8-bit unsigned 
 *                    integer. If your array is larger than 255 elements, I will find you. and I will not debug your code.
 *  @param device The device through which the function should print the array. 
 *                Defaults to the serial port, but can be specified to other objects
 *                as long as they have an appropriately defined "print" function.
 */
void print_array (bool* p_array, uint8_t array_size, Print& device = Serial);

/** @brief Prints an array of unsigned 8 bit integers
 *  @details This function prints an unsigned 8 bit integer array to the specified device. The device
 *           must have a clarified "print" operator. The array is printed in the "Python"
 *           fashion of [1,2,3,4]. 
 * 
 *  @param p_array The pointer defining the array object (pointing to first entry). The data type must be properly
 *                 declared (ex: uint8_t*)
 *  @param size The number of elements in the array, as an 8-bit unsigned 
 *                    integer. If your array is larger than 255 elements, I will find you. and I will not debug your code.
 *  @param device The device through which the function should print the array. 
 *                Defaults to the serial port, but can be specified to other objects
 *                as long as they have an appropriately defined "print" function.
 */
void print_array (uint8_t* p_array, uint8_t array_size, Print& device = Serial);

/** @brief Prints an array of signed 8 bit integers
 *  @details This function prints a signed 8 bit integer array to the specified device. The device
 *           must have a clarified "print" operator. The array is printed in the "Python"
 *           fashion of [1,2,3,4]. 
 *  @param p_array The pointer defining the array object (pointing to first entry). The data type must be properly
 *                 declared (ex: int8_t*)
 *  @param size The number of elements in the array, as an 8-bit unsigned 
 *                    integer. If your array is larger than 255 elements, I will find you. and I will not debug your code.
 *  @param device The device through which the function should print the array. 
 *                Defaults to the serial port, but can be specified to other objects
 *                as long as they have an appropriately defined "print" function.
 */
void print_array (int8_t* p_array, uint8_t array_size, Print& device = Serial);

/** @brief Prints an array of floats
 *  @details This function prints a float array to the specified device. The device
 *           must have a clarified "print" operator. The array is printed in the "Python"
 *           fashion of [1,2,3,4]. 
 *  @param p_array The pointer defining the array object (pointing to first entry). The data type must be properly
 *                 declared (ex: float*)
 *  @param size The number of elements in the array, as an 8-bit unsigned 
 *                    integer. If your array is larger than 255 elements, I will find you. and I will not debug your code.
 *  @param device The device through which the function should print the array. 
 *                Defaults to the serial port, but can be specified to other objects
 *                as long as they have an appropriately defined "print" function.
 */          any other device capable of printing. 
 */
void print_array (float* p_array, uint8_t array_size, Print& device = Serial);