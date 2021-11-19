/** @file stat_tracker.h
 *    This file contains a class for tracking the average 
 *    and standard deviation of a set of data. It can accept
 *    new points as floats or 32-bit integers (signed or
 *    unsigned). This class does not retain points provided, 
 *    it merely tracks statistical values of the data set.
 *
 *  @author Rick Hall
 *  @date 2020-5-Nov
 */

#ifndef STAT_TRACKER_H
#define STAT_TRACKER_H

#include <Arduino.h>

/** @brief A class to track statistics of a dataset
 *  @details This class tracks the average and standard
 *           deviation of a set of data, provided to the
 *           object one point at a time. 
 */
class StatTracker
{
protected:

    /// Number of points provided
    uint32_t n_pts = 0;
    /// Sum of points provided 
    float sum = 0;
    /// Sum of (points provided squared)
    float sqrd_sum = 0;
    /// Most recently calculated average
    float avg = 0;
    /// Most recently calculated standard deviation
    float sdev = 0;
    /// Boolean flag to determine if avg and sdev are up-to-date
    bool new_points = false;


public:

    // StatTracker object constructor
    StatTracker(void);

    // Function to add data (for float type)
    void add_data(float new_pt);

    // Function to add data (for int32 type)
    void add_data(int32_t new_pt);

    // Function to add data (for uint32 type)
    void add_data(uint32_t new_pt);

    // Function check number of provided points
    uint32_t num_points (void);

    // Function check average of provided data
    float average(void);

    // Function check standard deviation of provided data
    float std_dev(void);

    // Function to clear all data and reset object
    void clear(void);

};

#endif