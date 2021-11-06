/** @file stat_tracker.cpp
 *          This file contains the declaration of a class that acts as a driver for the PCA9534 8-bit I2C-bus with 8 digital I/O pins.
 * @author Kai Quizon
 * @date   October 25, 2021
 **/


#include "stat_tracker.h"

/** @brief A constructor for the StatTracker class that initializes all data to zero
 */
StatTracker :: StatTracker() {
    sum = 0;
    total_points = 0;
    squared_sum = 0;
}

/** @brief This function is overloaded. Adds a float type datapoint to the set. The data point itself is not stored, only its effect on the set is.
 *  @param datapoint The datapoint to be added, in this case a float.
 */
void StatTracker :: add_data(float datapoint) {
    sum += datapoint;    // Since data types already match, just add to sum
    squared_sum += pow(datapoint, 2);  // Square the value and add it to the sum
    total_points++;     // Increment total points value
}

/** @brief This function is overloaded. Adds a 32 bit signed integer type datapoint to the set. The data point itself is not stored, only its effect on the set is.
 *  @param datapoint The datapoint to be added, in this case a 32 bit signed integer.
 */
void StatTracker :: add_data(int32_t datapoint) {
    sum += (float)datapoint;    // Explicitly convert the integer to a float to force sum to continue as a float
    squared_sum += pow((float)datapoint, 2);  // Explicity convert again
    total_points++;             // Increment total points value
}

/** @brief Adds a 32 bit unsigned integer type datapoint to the set. The data point itself is not stored, only its effect on the set is.
 *  @param datapoint The datapoint to be added, in this case an unsigned 32 bit integer.
 */
void StatTracker :: add_data(uint32_t datapoint) {
    sum += (float)datapoint;    // Explicitly convert the integer to a float to force sum to continue as a float
    squared_sum += pow((float)datapoint, 2);  // Explicity convert again
    total_points++;             // Increment total points value
}

/** @brief Return the number of currently active points in the set.
 *  @return The number of data points as an unisigned 32 bit integer
 */
uint32_t StatTracker :: num_points(void) {
    return total_points;
}

/** @brief Return the average of all currently active data points.
 *  @return The avearge of all the data points as a float
 */
float StatTracker :: average(void) {
    float aver = sum/total_points;
    return aver;
}

/** @brief Return the standard deviation of all the currently active data points in teh set.
 *  @return The standard deviation of the data set in the variable stddev as a float
 */
float StatTracker :: std_dev(void) {
    // There is an implicit conversion from a double to a float in this next line...most cmath commands deal with doubles.
    float stddev = sqrt((squared_sum/total_points) - (pow((sum/total_points), 2)));
    return stddev;
}

/** @brief Clear all data points such that the active points in the set is now zero.
 */
void StatTracker :: clear(void) {
    sum = 0;
    squared_sum = 0;
    total_points = 0;
}