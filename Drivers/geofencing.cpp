/** @file geofencing.cpp
 *          This file contains member functions of a class for return the shortest straight line distance from a point
 *          to the edge of a user define geofence.
 * @author Kai Quizon
 * @date   October 25, 2021
 **/

#include <cmath>
#include <Arduino.h>

#define PI 3.14159265

/** @brief Calculate the shortest distance from current position to geofence
 *  @details Taking in the structured KD Tree, perform the search for the nearest neighbors. Index the data
 *           and find its closest neighbors. Then calculate the closest distance to a point or line based on
 *           the Rickolas Solution.
 *  @param lat Updated lattitude value from the processed GPS data.
 *  @param longit Updated longitude value from the processed GPS data.
 *  @param p_arr_lat Pointer to an array of latitude floats containing the data that comprises the geofence.
 *  @param p_arr_long Pointer to an array of longitude floats containing the data that comprises the geofence.
 *  @param geofence_size An unsigned integer representing the number of points in the geofence array
 *  @return The distance from the current position to the nearest edge, and a heading in the form: distance, heading
 */
float geofencing(float lat, float longitude, float p_arr_lat, float p_arr_long, uint8_t geofence_size) {
    // Create empty array of length of geofence size
    float residuals_lat[geofence_size];
    float residuals_long[geofence_size];
    // First find the nearest point by testing all points and finding residuals
    // This method is particularly slow, and could be improved later.
    for(uint8_t count=0; count<geofence_size; count++) {
        residuals_lat[count] = p_arr_lat[count]-lat;
        residuals_long[count] = p_arr_long[count]-longitude;
    }
    // Find smallest value in each array by comparing them to the first value and incrementing
    float temp_lat = residuals_lat[0];
    uint8_t loc_lat = 0;
    float temp_long = residuals_long[0];
    uint8_t loc_long = 0;
    for(uint8_t i, i<geofence_size, i++) {
        if(temp_lat>residuals_lat[i]) {
            temp_lat = residuals_lat[i];
            loc_lat = i;
        }
        if(temp_long>residuals_long[i]) {
            temp_long = residuals_long[i];
            loc_long = i;
        }
    }
    // Grab the geofence point closest to the current location and its two neighbors
    float main_point_lat = p_arr_lat[loc_lat];
    float main_point_long = p_arr_long[loc_long];
    float low_point_lat = p_arr_lat[loc_lat-1];
    float low_point_long = p_arr_long[loc_long-1];
    float high_point_lat = p_arr_lat[loc_lat+1];
    float high_point_long = p_arr_long[loc_long+1];

    // Get the straight line distance between the main point and the bot point (called B)
    float B = (float) sqrt(pow(lat - main_point_lat, 2) + pow(longitude - main_point_long, 2) * 1.0);

    // Get the straight line distance between bot point and low point (called A)
    float A = (float) sqrt(pow(lat - low_point_lat, 2) + pow(longitude - low_point_long, 2) * 1.0);

    // Get the straight line distance between bot point and high point (called E)
    float E = (float) sqrt(pow(lat - high_point_lat, 2) + pow(longitude - high_point_long, 2) * 1.0);

    // Get the straight line distance between low point and main point (called C)
    float C = (float) sqrt(pow(main_point_lat - low_point_lat, 2) + pow(main_point_long - low_point_long, 2) * 1.0);

    // Get the straight line distance between high point and main point (called D)
    float D = (float) sqrt(pow(main_point_lat - high_point_lat, 2) + pow(main_point_long - high_point_long, 2) * 1.0);

    /*
    Now we apply the following logic to determine whether the closest distance to the point is the main point itself or a perpendicular to
    one of the geofence edges:
    Since the closest point is in the center when the main point is closest, all other triangle angles must be acute. Therefore, if the primary angle
    (a) is greater than 90 degrees, no perpendicular exists and length B is the closest distance. If the primary angle (a) is less than 90 degrees,
    then a perpendicular exists and is defined by the square root of B^2 times the sine of angle a.
    */
   float inter = (float) pow(B, 2) + pow(C, 2) - pow(A, 2);
   float param = inter/(2*B*C);
   float angle_a = (float) acos(param) * 180/PI;
   if (a > 90.0) {
       float distance = B;
   }
   else if (a <= 90.0) {
       float distance = B*sin(a);
   }

   return distance, a
}