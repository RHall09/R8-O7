/** @file stat_tracker.cpp
 *    This file contains a class for tracking the average 
 *    and standard deviation of a set of data. It can accept
 *    new points as floats or 32-bit integers (signed or
 *    unsigned). This class does not retain points provided, 
 *    it merely tracks statistical values of the data set.
 *
 *  @author Rick Hall
 *  @date 2020-5-Nov
 */


#include <Arduino.h>
#include <stat_tracker.h>

/** @brief The constructor for StatTracker
 *  @details This function constructs an empty StatTracker object
 */
StatTracker::StatTracker(void)
{
    n_pts = 0;
    sum = 0;
    sqrd_sum = 0;
    avg = 0;
    sdev = 0;
    new_points = false;
}

/** @brief Adds a point of float-type data to the tracker
 *  @details This function adds the provided datapoint to
 *           the sum and incriments the number of datapoints.
 * 
 *  @param new_pt The float-type datapoint to be added
 */
void StatTracker::add_data(float new_pt)
{
    sum += new_pt;
    sqrd_sum += pow(new_pt, 2);

    new_points = true;
    ++n_pts;
}

/** @brief Adds a point of int32-type data to the tracker
 *  @details This function adds the provided datapoint to
 *           the sum and incriments the number of datapoints.
 * 
 *  @param new_pt The int32-type datapoint to be added
 */
void StatTracker::add_data(int32_t new_pt)
{
    sum += (float)new_pt;
    sqrd_sum += pow((float)new_pt, 2);

    new_points = true;
    ++n_pts;
}

/** @brief Adds a point of uint32-type data to the tracker
 *  @details This function adds the provided datapoint to
 *           the sum and incriments the number of datapoints.
 * 
 *  @param new_pt The uint32-type datapoint to be added
 */
void StatTracker::add_data(uint32_t new_pt)
{
    sum += (float)new_pt;
    sqrd_sum += pow((float)new_pt, 2);

    new_points = true;
    ++n_pts;
}

/** @brief Outputs the number of points that have been provided
 * 
 *  @return The number of points that have been provided
 */
uint32_t StatTracker::num_points (void)
{
    return n_pts;
}

/** @brief Returns average of the datapoints provided
 *  @details This function computes the average of the
 *           data provided using the sum of data points
 *           and the number of points provided. The 
 *           calculation will only be run if a new point
 *           has been added since the calculation was 
 *           last run. 
 * 
 *  @return The average of provided points
 */
float StatTracker::average(void)
{
    if(new_points)
    {
        avg = sum/(float)n_pts;
        sdev = sqrt( (sqrd_sum/(float)n_pts) - pow(avg, 2)  );
        new_points = false;
    }

    return avg;
}

/** @brief Returns standard deviation of the datapoints provided
 *  @details This function computes the standard deviation
 *           of the data provided using the sum of data 
 *           points, the sum of data points squared, 
 *           and the number of points provided. The 
 *           calculation will only be run if a new point
 *           has been added since the calculation was 
 *           last run. 
 * 
 *  @return The standard deviation of provided points
 */
float StatTracker::std_dev(void)
{
    if(new_points)
    {
        avg = sum/(float)n_pts;
        sdev = sqrt( (sqrd_sum/(float)n_pts) - pow(avg, 2)  );
        new_points = false;
        return 1;
    }
    
    return sdev;
}

/** @brief Clears and resets the StatTracker
*/
void StatTracker::clear(void)
{
    n_pts = 0;
    sum = 0;
    sqrd_sum = 0;
    avg = 0;
    sdev = 0;
    new_points = false;

}