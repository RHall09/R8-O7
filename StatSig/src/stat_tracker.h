/** @file stat_tracker.h
 *          This file contains the declaration of a class that acts as a driver for the PCA9534 8-bit I2C-bus with 8 digital I/O pins.
 * @author Kai Quizon
 * @date   October 25, 2021
 **/

#ifndef STATTRACKER
#define STATTRACKER
#include <Arduino.h>
#include <cmath>

/** @brief 
 *  @details
 */

class StatTracker {
    // Declare class objects
    protected:   // Initialized Variables for sums and number of points
    float sum;  // Sum of all currently added points
    uint32_t total_points;  // Total number of points
    float squared_sum;      // Squared Sum of all points (for std. dev.)
    

    public:

    StatTracker();    // Default constructor initializes zero data set.
    // Overloaded function to add different data types to set
    void add_data(float datapoint);
    void add_data (int32_t datapoint);
    void add_data (uint32_t datapoint);
    // Return the number of points in the data set at present
    uint32_t num_points();
    // Return statistical values
    float average();
    float std_dev();
    // Clear all data points currently in set
    void clear();

};

#endif