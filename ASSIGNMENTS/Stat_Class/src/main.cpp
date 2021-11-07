#include <Arduino.h>
#include <PrintStream.h>
#include <stat_tracker.h>

StatTracker track_pts;

#define array_length 11
int32_t point_array[array_length] = {4,-7, 3, 2, -4, 7, 4, -8, 9, 12, 1};

void setup() {
  // put your setup code here, to run once:

  Serial.begin (115200);
  delay (2000);

  Serial << endl << "Hello, I'm in ME507" << " ...and I vote." << endl;

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial << "Array Begin -----------------------------" << endl << endl;

  for(uint8_t counter = 0; (counter < array_length); counter++ )
  {
    track_pts.add_data(point_array[counter]);
    
    Serial << track_pts.num_points() << " points have been provided." << endl
          << "The current average is: " << track_pts.average() << endl
          << "The current stdev is:   " << track_pts.std_dev() << endl << endl;

    delay(2000);

  }

  track_pts.clear();

}