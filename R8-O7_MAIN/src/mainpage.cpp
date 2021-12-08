/**
 * \mainpage
 * 
 * @section sec_intro Introduction
 * Welcome to R8-07's documentation homepage. This documentation is tied to source
 * code located at:\n
 * https://github.com/RHall09/R8-O7 \n
 * \n 
 * @image html J4K3.png "J4-K3, Jake the Droid Interacting with Two Young Guests, courtesy of Orange County Register."
 * This project set out to develop a “Crowd Interaction Bot” similar to those developed as free meandering animatronics in theme parks. 
 * The primary inspiration for this project lies in J4-K3, or Jake the Droid. J4-K3 is an autonomous, free-roaming, interactive animatronic 
 * that is capable of advanced crowd navigation, interaction, and avoidance, as seen above.. J4-K3 is a closed project and is no longer in action in Disneyland 
 * Park. \n 
 * \n 
 * @image html R807.png "R8-07 in his current glory"
 * Using J4-K3’s premise of crowd interaction with a focus on safety, we set out to build a bot that could be contained within a user defined 
 * digital fence, avoid obstacles and people, and identify moments for interactions (called “ShowSense” moments). Pulling from our team’s 
 * involvement with the Mustang Marching Band, we further clarified the desired use case to Mustang Band performances.
 * We decided to base the appearance of the bot on the R5 Units from the Star Wars franchise, like the one shown in Figure 2.
 * The application of this particular bot is intended to be limited to open, outdoor areas similar to the University Union. 
 * However, with higher quality hardware, geofencing could be performed even in indoor or more limited areas.
 * While this iteration is not intended for commercialization outside of the collegiate atmosphere, the structure 
 * defined within may, one day, be expanded to allow for more complex operations and ShowSense moments. \n 
 * 
 * @section sec_directory Directory
 * 
 * 1. \ref page_Hardware
 * 2. \ref page_Software
 * 3. \ref page_Results
 * 
 * @section sec_references References
 * This project was completed under the guidance of Dr. John Ridgely, Professor of Mechatronics
 * at Cal Poly SLO. \n
 * 
 * The project was a joint effort between three designers:\n
 * --Kai Quizon \n
 * --Rick Hall \n
 * --Anil Singh \n
 * 
 * @page page_Hardware Hardware Design
 * @section Hardware_Decisions Major Design Decisions
 * The first major decision we made was the microcontroller. Primarily driven by the ESP32’s built in Bluetooth and Wi-Fi modules, the ESP32 was selected. 
 * Further, we decided to use Adafruit’s HUZZAH32 Feather as it is compatible with a commercially available GPS breakout board. 
 * This board does present one major restriction: the general lack of GPIO pins. This became a major design factor. Initially, 
 * we considered using a secondary MCU to govern ShowSense behaviors connected to the main ESP32 via I2C. This consideration was 
 * ultimately disregarded as we decided to limit ShowSense moments to very simplistic rotations at this phase. \n 
 * \n
 * We then decided on the method of containing the bot within a digital fence. This can be accomplish by a variety of methods, 
 * but outside of GPS coordinates, all those methods rely on an external device. Initially, we considered tethering the bot to a 
 * user phone and limiting the distance the bot is allowed to travel from the phone, however this violated the desire for true 
 * autonomous behavior. This then required a GPS based solution. The most commonly used formed of GPS containment is geofencing. 
 * As such, we utilized a geofencing based approach with a predefined fence of latitude and longitude points. \n 
 * \n
 * 
 * @section section_electronics Sensors, Actuators, and Electronics
 * The specifications require that R8-07 is capable of reliably avoiding collision with humans in crowded situations. 
 * This requires a sensor suite capable of sensing moving, human obstacles reliably in a variety of settings collectively 
 * referred to as the “Safety Sensor Suite.” This specification drove the selection of three independent distance sensors 
 * capable of sensing objects and their distance from the sensor: \n
 * •	Ultrasonic Sensors (HC-SR04): These sensors reliable sense objects via the reflection of sound waves. They are generally 
 * reliable but may be impacted by sonically absorptive material. \n
 * •	Laser-based Time of Flight Sensors: These sensors measure distance by tracking the time a laser is in flight and reflected 
 * to the sensor. They are highly reliable but may be undermined by particularly light absorbent material. \n
 * •	Infrared Sensors: These sensors function similar to the laser-based time of flight sensors but use infrared light instead of 
 * laser reflections. They are less reliable than their laser counterparts but are undermined by a different spectrum of absorptivity than the lasers. \n
 * 
 * <INSERT GRAPHIC OF SAFETY SENSOR SUITE LAYOUT HERE>
 * The sensors were laid out according to FIGURE. This arrangement creates a double redundancy on R8-07’s main heading while using two 
 * ultrasonic sensors to develop a cone of information. This allows R8-07 to make intelligent decisions regarding turning directions if in a dense crowd. \n
 * Further, according to the specification regarding foot collisions, three additional distance sensors are required to ensure that the wheel base is clear 
 * for the maneuvers it is undertaking. These are angled at 22.5⁰ pointing approximately four inches in front of the pinch point for each wheel. This is accomplished 
 * using the angled blocks seen below. The main point is equipped with an additional laser-based time of flight sensor, while each of the drive wheels is equipped 
 * with an additional ultrasonic distance sensor. \n
 * \n 
 * <INSERT FIGURE OF ANGLED BLOCKS>
 * For this initial phase, only two drive motors are used to drive R8-07. No additional actuators are used. Maximum estimates of R8-07’s laden weight with all 
 * attached peripherals totaled 50 pounds. As such, motors were selected to handle this load according to the calculations shown in APPENDIX A. Motors meeting these 
 * qualifications were sourced from Pololu (item number 4694). Characteristics of the motor are shown below. \n
 * @image html MotorSpecs.png "Pololu Provided Specifications of item number 4694" 
 * A motor driver capable of reliably carrying 24V was then selected based off availability. The MD L6205D chip was selected. This chip and its 
 * necessary associated components were mounted on an expansion board designed around the HUZZAH32 feather. The motor driver chip and its components 
 * are outlined in blue in the board rendering below. \n 
 * \n 
 * The hardware design of R8-07 is built around the HUZZAH32 Feather from Adafruit. Most of the decisions regarding the expansion board for the feather 
 * were driven by the pin limitations of the feather board. Because of the relatively low number of GPIO pins on the feather and the high demand for GPIO 
 * pins from the required sensor suite, two GPIO expansion buses, one analog and one digital, were added to the expansion board, highlighted in red in the 
 * board rendering below. To limit communication protocols and take advantage of the daisy chaining capabilities of the I2C protocol, we sought out I2C capable 
 * expansion buses. We selected the PCA9534 8-bit I2C bus I/O port with interrupt for the digital expansion. This chip was selected because of its interrupt 
 * capabilities and setup in order to easily accommodate typical ultrasonic distance setups. We then selected the ADS7828 chip for the analog expansion bus. 
 * The 12-bit resolution and built-in analog to digital converter made it optimum for easy integration with minimal GPIO usage. \n 
 * 
 * @image html BoardwSections.png "Custom Expansion Board with Highlighted Segments" 
 * 
 * Highlighted in orange in the board rendering are three additional components designed to ease testing and assembly operations. First, a set of screw terminals 
 * linked to the I2C bus was included to easily expand devices using the I2C communication protocol. This proved useful for the inclusion of the laser time of 
 * flight breakout boards, which communicated over I2C. Two user pushbuttons and two LEDs were also included in this section, primarily for testing purposes. 
 * Jumpers toggled the use of the LED or the pushbutton. The set of push buttons facilitated testing of the I2C expansion chips, as pushing a button could be 
 * used to trigger an output attached to the chip. The LEDs also proved useful during testing of the roaming bot, as they could serve as a visual indicator of 
 * where in the program the bot currently was. \n 
 * 
 * @section section_MechanicalDesign Mechanical Design
 * 
 * R8-07’s mechanical structure design was driven by two key limitations: position safety sensors and building a frame for scenic elements to mimic the R5 
 * structure. To ease this process and allow for continued focus on the electronics design, open-source designs of an R5 unit were downloaded and modified 
 * from the R2 Building community Astromech.net. Under their open-source licenses, these files were available to use for noncommercial operation of the unit. 
 * The license also allowed for modifications that proved necessary for ease of function. \n 
 * \n 
 * There were two major modifications to the open-source files necessary. First and foremost, the files needed to be modified to easily house the sensor suite 
 * at an appropriate level to avoid both adults and children. The body frame, shown below, was modified to allow for these sensors to all be housed on the 
 * same plane. The files were also modified to accommodate for the change in build materials. The files were designed to be made from 3mm polystyrene plastic. 
 * However, polystyrene cannot be laser cut as it releases toxic styrene gas. As such, we pivoted to using quarter inch plywood to form the skeleton. This 
 * necessitated some adjustments in the various file sizes to account for the tolerance buildup as the bot was built. \n 
 * @image html BodyFrame.png "Unmodified Rendering of Body Frame from Astromech.net"
 * 
 * While the files for building a full R5 unit have been adjusted, only the body and legs are currently in use. Further, motors were temporarily mounted on 
 * an adjoining strut for testing purposes at this time. 
 * 
 * @page page_Software Software Design 
 * R8-07’s software was designed as a main-brain style Real Time Operating System program. This means that a majority of data during normal operation is fed 
 * into a single task where it is interpreted and distilled. That “main-brain” task then makes decisions based on the information garnered from the various 
 * sensor tasks and commands the operator tasks. This layout is illustrated in the task diagram shown in FIGURE. Here, the main brain is the Navigation Task 
 * which takes information from the Sensor Suite Task and the Geofence Task to determine the appropriate PWM signal to send to the motor driver task. \n
 * 
 * @image html TaskDiagram.png "Task Diagram for R8-07's governing program"
 * 
 * @section section_Geofence Geofence Algorithm
 * To ensure the robot remains within the prescribed area, an appropriate algorithm was developed to determine the distance and bearing of the closest edge 
 * (or point) of the geofence. While many basic geofence algorithms use the polygon method to constrain the robot, we determined that a simple inside/outside 
 * geofence return was insufficient for our goals of relatively natural movement. While the polygon method operates on the principle of intersection of lines 
 * in the geofence (if a horizontal line emitted to one side of the robot has an odd number of intersects, it is in the polygon geofence), our algorithm operates 
 * off of a geometric computation using the closest point on the geofence along with the two adjacent points. \n 
 * 
 * @image html GeofenceTriangles.png "Geometric Setup of Geofencing Algorithm"
 * 
 * As seen in the figure above, the robot’s location and the location of the aforementioned three points is sufficient to determine geometrically if there is a 
 * perpendicular distance to either of the geofence lines, which is necessarily the closest distance to the robot. The bearing to the fence is also returned as 
 * an angle relative to the horizontal +x axis as defined by the coordinate frame of the GPS readings. \n 
 * \n 
 * To determine the closest point, at this point we use a simplistic “halving” algorithm. This sorting algorithm enters the data set at the median value of the 
 * data set. It then determines if the query value is greater than or less than the median value of the entire set. If the value is greater, the upper half of 
 * the data set is considered. If the value is less than the median, the lower half the data set is considered. This is repeated until the data can no longer be 
 * halved. It is time and calculation intensive, but for the number of points comprising the geofence definitions, is sufficient for this implementation. \n 
 * \n 
 * The geofence task runs any time the sensor suite task outputs new GPS data. It runs the geofence calculations, then outputs them to the navigation task.
 * 
 * @section section_motorcontrol Motor Control System
 * To prevent the motors from bogging down or accelerating on hills, a simple PID control system was developed for the motors. The control systems are contained 
 * within a class, allowing simple programming of the motor task with control system objects. While the motors could be operated exclusively by the control system 
 * class, the class was designed to take the motor object pointer as an input, allowing the motor tasks to operate the motors directly, if necessary. The control 
 * system takes inputs in the form of the encoder velocity and the desired setpoint, then sets the provided motor accordingly. \n 
 * \n 
 * To operate the encoders, an open-source ESP32 encoder class was utilized. The operation of the encoders using this class was placed in a task separate from 
 * the motor task to ensure consistent timing between encoder reads, to improve the accuracy of the control system. \n 
 * \n 
 * Each motor task runs only if either the corresponding encoder updates or the navigation task provides a new setpoint. When the task runs, it uses an object 
 * of the motorCS class to run the control system and operate the motor. If the control system is not enabled, it runs the motors directly. \n 
 * 
 * @section section_sensorsuite Sensor Suite
 * The Sensor Suite task is dependent on both the i2c GPIO expansion bus chip drivers and the external Adafruit VL53L1x. It drives all the safety critical 
 * sensors mounted about R8-07. This is the highest priority task and as such runs all of the code linearly. First, if data is available, the GPS string is 
 * updated. The NMEA string is decoded via the TinyGPS++ library utilized under the open source license. Next, the primary time of flight sensor is updated, 
 * followed by the three ultrasonic sensors mounted on the safety sensor suite. The code for the ultrasonic sensors is blocking, as precise timing of the 
 * trigger pin and reading of the echo pin is necessary for accurate readings of the sensors. As such, this is the highest priority task and does not allow 
 * interrupts during this process. After data is collected from the safety sensor suite, the task checks each of the three collision sensors ahead of the wheels. 
 * To facilitate simpler navigation, the sensor suite task handles some of the processing surrounding this data. The sensor suite task checks the data to see if 
 * it meets a minimum threshold, and if collision is imminent based on this check, a Boolean share is toggled to stop the motors. \n 
 * 
 * @section section_Navigation Navigation Algorithm
 * The navigation algorithm, in its current form, only implements natural avoidance of the geofence. To accomplish this, it uses the distance and bearing to the 
 * geofence, the bearing of the robot, and a pre-defined minimum distance to the fence to turn the robot in a manner inversely proportional to the distance to the 
 * geofence and the relative bearing from the robot to the fence. The geometric principle utilized is illustrated in the figure below. \n 
 * 
 * @image Curvaturefromfence.png "Geometry of Naturally Avoiding Geofence with a curve"
 * 
 * Using these computations, the navigation task computes the desired speed and turn rate of the robot, then converts those values into setpoint PWM values to be output to the motor task.
 * 
 * @section section_Bluetooth Bluetooth Control
 * The Bluetooth module was designed to provide an interface between R-8O7 and a smartphone-based application in order to enable the user to remotely control the 
 * robot, as well as toggle various functions. The image below illustrates the GUI presented to the user when the application is launched from a smartphone. \n
 * 
 * @image BluetoothGUI.png "Bluetooth App GUI for Remote Control" 
 * 
 * The user is able to first connect to R-8O7 via Bluetooth using the ‘Bluetooth Connect’ button. They are presented with a list of paired devices from their phone, 
 * one of which is the built in Bluetooth module on the ESP32. The user is then able to use the joystick on the screen to control the throttle and direction of the 
 * robot, utilize the three toggles to turn on and off the geofence, navigation, and sensor suite, and bring the robot to a stop in case of emergency. When the user 
 * wishes to disconnect from R-8O7, they can do so via the disconnect button. MITAppinventor was used to synthesize the application, and the block code for the program 
 * can be seen below. \n 
 * 
 * @image "MITCode.png" "Overview of Block Code Structure for Bluetooth App"
 * 
 * The block code sets up the Bluetooth interface on the app, controls the function and reset of the joystick, initializes button and switch states to default states 
 * upon application launch, and manages the way through which the app sends data to the ESP32 over the Bluetooth serial port. \n 
 * \n 
 * On the C++ side, the module is designed to receive this data from the application over the Bluetooth serial port and process it into useable data by the other tasks. 
 * For example, the joystick position is constantly checked and updated to send X and Y axis coordinates over the serial port. By interpreting these X and Y coordinates 
 * as throttle and direction amounts, the module then converts these values into pulse width modulation signals that can be read by the motor driver in order to control 
 * the motors manually. Furthermore, the button and switch states return either a 1 or 0, allowing for easy toggles on their corresponding tasks. 
 * 
 * 
 * @page page_Results Results 
 * 
 *
 * Near the end of the project, we began the final integration of the microcontroller into the assembled hardware for R8-O7. During this process, we ran tests of several 
 * of our primary software systems to verify integration with our constructed hardware. Unfortunately, during the testing of the motor driver and control system, the motor 
 * driver chip on the PCB burnt out after prolonged testing, despite operating notably under the current limit for the chip. The chip was replaced with a backup, however 
 * upon connecting the backup to 24V power it immediately burnt out, leaving us without the ability to drive the 24V motors. \n 
 * \n 
 * fter the malfunction of the motor driver chips, we were not able to use the full frame of R8-O7 for testing of our software, to which the primary safety sensor suite was 
 * attached. In an attempt to verify functionality of our code, we loaded a heavily modified version of our program onto a small testing bot (occasionally referred to as BabyBot) 
 * that we had used for preliminary single-sensor object avoidance testing. Due to significant differences in the operation of the motors and the lack of the primary sensor suite, 
 * neither the object avoidance algorithm nor the motor control system were utilized in the testing bot. \n 
 * @image BabyBot.png "BabyBot :)"
 * With the test bot, we were able to define a geofence for testing within the tennis courts located on Cal Poly campus and test the geofence algorithm, to mixed results. 
 * The geofence algorithm worked as intended, however the GPS module of the ESP32 HUZZAH was not as accurate as we had hoped. The navigation algorithm for the bot had two 
 * primary avoidance tactics – a turn value added to the bot’s forward velocity inversely proportional to the distance to the fence and an immediate stop-and-turn algorithm 
 * should the bot pass a minimum distance threshold. The distant avoidance algorithm worked as intended, with unanticipated fluctuations due to the low repeatability of the 
 * GPS. The stop-and-turn algorithm, in contrast, was only effective in about half of cases; the inconsistency of the GPS often had the bot stopping either several feet short 
 * of the geofence or several feet past. Had the larger robot been functional, this likely could have been rectified by increasing the minimum distance to the fence to a value 
 * significantly larger than the repeatability error of the GPS, and defining a geofence in a larger area. \n 
 * \n 
 * Overall, many of the elements of our software were tested, to varying extents, but the lack of functionality of the full R8-O7 robot prevented us from testing the software 
 * as a unit or fixing errors in the interaction between software segments. With regards to our specific design specifications, the testing results are summarized in the table below.
 * @image Parameters.png
 * 
 * While the full program could not properly run without the motor driver chip and proper attachment of the sensor array, basic functionality of many of the components has been 
 * verified such that it may be tested upon replacement of the PCB. Further, the laser-cut structure of R8-O7 remains incomplete. Given proper time and availability of resources, 
 * this project could easily be resumed, building off of our current hardware and software. To that end, it is our intention to, if possible, pass R8-O7 on to willing engineering 
 * students within Mustang Band. Though our contribution to the project has had mixed results, we are hopeful that R8-O7 may be completed at a later date. 
 * 
 * 
 */