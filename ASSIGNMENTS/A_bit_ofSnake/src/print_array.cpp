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

void print_array (bool* p_array, uint8_t size, Print& device) {
        
    device.print("[") ;

    for(bool* p_inc = p_array; p_inc < (p_array+size); p_inc++)
        {
            if(*p_inc) {
                device.print("T");
            }
            else {
                device.print("F");
            }
            if (p_inc != (p_array+size-1)) {
                device.print(",");
            }
        }

    device << "]" ;

}

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

void print_array (uint8_t* p_array, uint8_t size, Print& device) {
        
    device.print("[") ;

    for(uint8_t* p_inc = p_array; p_inc < (p_array+size); p_inc++)
        {
            device.print(*p_inc);
            if (p_inc != (p_array+size-1)) {
                device.print(",");
            }
        }

    device << "]" ;

}

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

void print_array (int8_t* p_array, uint8_t size, Print& device) {
        
    device.print("[") ;

    for(int8_t* p_inc = p_array; p_inc < (p_array+size); p_inc++)
        {
            device.print(*p_inc);
            if (p_inc != (p_array+size-1)) {
                device.print(",");
            }
        }

    device << "]" ;

}

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
 */

void print_array (float* p_array, uint8_t size, Print& device) {
        
    device.print("[") ;

    for(float* p_inc = p_array; p_inc < (p_array+size); p_inc++)
        {
            device.print(*p_inc);
            if (p_inc != (p_array+size-1)) {
                device.print(",");
            }
        }

    device << "]" ;

}