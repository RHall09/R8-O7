/** @file main.cpp
 *    A basic testing file for the Stat Tracker class
 *
 *  @author Rick Hall
 *  @date 2020-5-Nov
 */

#include <Arduino.h>
#include <PrintStream.h>
#include <stat_tracker.h>

// initialize the stat_tracker object
StatTracker track_pts;


#define array_length 11

/// A manually inserted array to test. Make sure to update array_length appropriately
int32_t point_array[array_length] = {4,-7, 3, 2, -4, 7, 4, -8, 9, 12, 1};

void setup() {
  // put your setup code here, to run once:

  Serial.begin (115200);
  delay (2000);

  Serial << endl << "Initiating StatTracker testing program ... " << endl;

}

void loop() {

  // Indicate the beginning of the array
  Serial << "Array Begin -----------------------------" << endl << endl;

  // For each point, add it to the StatTracker object and display current stats
  for(uint8_t counter = 0; (counter < array_length); counter++ )
  {
    track_pts.add_data(point_array[counter]);
    
    Serial << track_pts.num_points() << " points have been provided." << endl
          << "The current average is: " << track_pts.average() << endl
          << "The current stdev is:   " << track_pts.std_dev() << endl << endl;

    delay(2000);

  }

  // Indicate the end of the array
  Serial << "Array End -------------------------------" << endl << endl;
  
  // Clear StatTracker object before restarting.
  track_pts.clear();

  delay(2000);

}