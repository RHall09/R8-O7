/** @file print_array.h
 *    This file contains an overloaded function that will take in arrays of types: {boolean, unsigned 8-bit integer, signed 8-bit integer, float}
 *    and print them as a python style array in the format  [1,2,3,4].
 *  @author Kai Quizon
 *  @date October 24, 2021 
 */

#include <Arduino.h>
#include <PrintStream.h>

/** Example string for formatting
 * void print_array (float* p_array, uint8_t size, Print& device = Serial);
 */


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

void print_array (bool* p_array, uint8_t size, Print& device) {
        
    device << "[" ;

    for(bool* p_inc = p_array; p_inc <= (p_inc+size); p_inc++)
        {
            device << *p_inc;
            if (p_inc != (p_inc+size)) {
                device << ",";
            }
        }

    device << "]" ;

}