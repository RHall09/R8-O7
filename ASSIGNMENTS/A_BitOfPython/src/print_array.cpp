/** @file print_array.h
 *    This file...
 *
 *  @author Rick Hall
 *  @date 2020-10-Oct 
 */

#include <Arduino.h>
#include <PrintStream.h>
#include <print_array.h>

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
void print_array (bool* p_array, uint8_t array_size, Print& device)
{
    if(array_size > 0)
    {
        device << "[ " ;
        
        bool* p_end_array = p_array + (--array_size) ;

        for(bool* p_print = p_array; p_print < p_end_array; p_print++)
        {
            if(*p_print)
            {
                device << "T" ;
            }
            else
            {
                device << "F" ;
            }
        }
        if(*p_end_array)
        {
            device << "T" << " ]" ;
        }
        else
        {
            device << "F" << " ]" ;
        }
    }
    else
    {
        device << "[ ]" ;
    }
}

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
void print_array (uint8_t* p_array, uint8_t array_size, Print& device)
{
    if(array_size > 0)
    {
        device << "[ " ;
        
        uint8_t* p_end_array = p_array + (--array_size) ;

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

/** @brief Prints an array of Signed 8-bit Integers
 *  @details This function prints each signed 8-bit integer in an array of a 
 *           specified size to the serial port (if device is not specified) or 
 *           to a user-specified device. 
 * 
 *  @param p_array The pointer to the first element of the array. The pointer type
 *                 must be specified for the function to operate correctly - in 
 *                 this case it should be a int8_t*.
 *  @param array_size The number of elements in the array, as an 8-bit unsigned 
 *                    integer. For arrays larger than 255 elements, use a 
 *                    different function.
 *  @param device The device through which the function should print the array. 
 *                This defaults to the Serial port, but may be specified as
 *                any other device capable of printing. 
 */
void print_array (int8_t* p_array, uint8_t array_size, Print& device)
{
    if(array_size > 0)
    {
        device << "[ " ;
        
        int8_t* p_end_array = p_array + (--array_size) ;

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

/** @brief Prints an array of Floating Point Numbers
 *  @details This function prints each float in an array of a specified size to 
 *           the serial port (if device is not specified) or to a user-specified
 *           device. 
 * 
 *  @param p_array The pointer to the first element of the array. The pointer type
 *                 must be specified for the function to operate correctly - in 
 *                 this case it should be a float*.
 *  @param array_size The number of elements in the array, as an 8-bit unsigned 
 *                    integer. For arrays larger than 255 elements, use a 
 *                    different function.
 *  @param device The device through which the function should print the array. 
 *                This defaults to the Serial port, but may be specified as
 *                any other device capable of printing. 
 */
void print_array (float* p_array, uint8_t array_size, Print& device)
{
    if(array_size > 0)
    {
        device << "[ " ;
        
        float* p_end_array = p_array + (--array_size) ;

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

