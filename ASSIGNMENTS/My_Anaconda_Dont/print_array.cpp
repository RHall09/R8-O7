/** @file   print_array.cpp
 *          This file is designed to print C arrays in a python
 *          list format, where data is enclosed in a linear line 
 *          horizontally, encolsed by brackets and separated by 
 *          commas. 
 *
 *  @author Anil Singh
 *  @author Rick Hall
 *  @author Kai Quizon 
 *  @date   2020-25-Oct 
 */

#include <Arduino.h>
#include <PrintStream.h>
#include <print_array.h>

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
void print_array (bool* p_array, uint8_t array_size, Print& device)
{
    if(array_size > 0)
    {
        device << "[ " ;
        bool* p_end_array = p_array + array_size ;
        for(bool* p_print = p_array; p_print < p_end_array; p_print++)
        {
            if(*p_print)
            {
                device << "True, ";
            }
            else
            {
                device << "False, ";
            }
        }
        if(*p_end_array)
        {
            device << "True" << " ]";
        }
        else
        {
            device << "False" << " ]";
        }
    }
    else
    {
        device << "[ ]" ;
    }
}

/** @brief            Prints a signed, 8-bit integer array
 *  @details          This function prints the signed 8-bit integer array
 *                    to the serial port or to a user-specified device. 
 * 
 *  @param p_array    The pointer to the first element of the unsigned, 8-bit integer array. 
 *                    The pointer type must be specified for the function to operate. 
 *  @param array_size The number of elements in the array, as an 8-bit signed 
 *                    integer.
 *  @param device     The device through which the function should print the array. 
 *
 */
void print_array (int8_t* p_array, uint8_t array_size, Print& device)
{
    if(array_size > 0)
    {
        device << "[ " ;      
        int8_t* p_end_array = p_array + array_size ;
        for(int8_t* p_print = p_array; p_print < p_end_array; p_print++)
        {
            device << *p_print << ", " ;
        }
        device << *p_end_array << " ]" ;
    }
    else
    {
        device << "[ ]" ;
    }
}

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
void print_array (uint8_t* p_array, uint8_t array_size, Print& device)
{
    if(array_size > 0)
    {
        device << "[ " ;      
        uint8_t* p_end_array = p_array + array_size ;
        for(uint8_t* p_print = p_array; p_print < p_end_array; p_print++)
        {
            device << *p_print << ", " ;
        }
        device << *p_end_array << " ]" ;
    }
    else
    {
        device << "[ ]" ;
    }
}
/** @brief            Prints an array of floating point numbers
 *  @details          This function prints the float array of a specified size to 
 *                    the serial port or to a user-specified device. 
 * 
 *  @param p_array    The pointer to the first element of the array. The pointer type
 *                    must be specified for the function to operate.
 *  @param array_size The number of elements in the array, as an unsigned 8-bit integer.
 *  @param device     The device through which the function should print the array.  
 */
void print_array (float* p_array, uint8_t array_size, Print& device)
{
    if(array_size > 0)
    {
        device << "[ " ;        
        float* p_end_array = p_array + array_size ;
        for(float* p_print = p_array; p_print < p_end_array; p_print++)
        {
            device << *p_print << ", " ;
        }
        device << *p_end_array << " ]" ;
    }
    else
    {
        device << "[ ]" ;
    }
}