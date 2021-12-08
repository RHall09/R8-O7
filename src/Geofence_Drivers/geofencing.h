/** @headerfile geofencing.h ""
 *          This file acts as a header for the geofencing function defined in \ref geofencing.cpp.
 * @author Kai Quizon
 * @date   November 26, 2021
 * @copyright (c) 2021 by Kai Quizon, released under the LGPL 3.0.
 **/

#ifndef GEOFENCE
#define GEOFENCE

#include <Arduino.h>
#include <cmath>

/** @brief Calculate the shortest distance from current position to geofence
 *  @details Taking in the structured KD Tree, perform the search for the nearest neighbors. Index the data
 *           and find its closest neighbors. Then calculate the closest distance to a point or line based on
 *           the Rickolas Solution.
 *  @param lat Updated lattitude value from the processed GPS data.
 *  @param longitude Updated longitude value from the processed GPS data.
 *  @param p_arr_lat Pointer to an array of latitude floats containing the data that comprises the geofence.
 *  @param p_arr_long Pointer to an array of longitude floats containing the data that comprises the geofence.
 *  @param geofence_size An unsigned integer representing the number of points in the geofence array
 *  @return The distance from the current position to the nearest edge, and a heading in the form: distance, heading
 **/
float geofencing(float lat, float longitude, float* p_arr_lat, float* p_arr_long, uint8_t geofence_size);


#endif