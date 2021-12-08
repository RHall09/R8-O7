/** @file geofencing.cpp
 *          This file contains a single function for returning the shortest straight line distance from a point
 *          to the edge of a user define geofence. The geofence must be built as two arrays (one of lattitude points
 *          and one of longitude points) that have matching dimensions. This dimension must be contained as an unsigned 8-bit
 *          integer. Thereby, in this configuration the maximum geofence point definition is 255 pairs of lattitude longitude points.
 *          The sorting algorithm used to determine the nearest matching geofence point is calculation intensive. Optimization may be
 *          necessary if larger geofences are required. This file is dependent on the Arduino framework and the Arduino cmath header.
 * @author Kai Quizon
 * @date   October 25, 2021
 * @copyright (c) 2021 by Kai Quizon, released under the LGPL 3.0.
 **/

#include <cmath>
#include <Arduino.h>

/// A constant to represent pi easily.
#define PI 3.14159265

float geofencing(float lat, float longitude, float* p_arr_lat, float* p_arr_long, uint8_t geofence_size) {
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

    for(uint8_t i = 0; i<geofence_size; i++) 
    {
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
   float distance = 0;
   if (angle_a > 90.0) 
   {
       float distance = B;
   }
   else if (angle_a <= 90.0) 
   {
       float distance = B*sin(angle_a);
   }

   return distance, angle_a;
}