/**
 * \mainpage
 * 
 * @section sec_intro Introduction
 * Welcome to R8-07's documentation homepage. This documentation is tied to source
 * code located at:\n
 * https://github.com/RHall09/R8-O7 \n
 * \n 
 * This project set out to develop a “Crowd Interaction Bot” similar to those developed as free meandering animatronics in theme parks. 
 * The primary inspiration for this project lies in J4-K3, or Jake the Droid. J4-K3 is an autonomous, free-roaming, interactive animatronic 
 * that is capable of advanced crowd navigation, interaction, and avoidance. J4-K3 is a closed project and is no longer in action in Disneyland 
 * Park. \n 
 * \n 
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
 * This page has a bunch of discussion on software design 
 * 
 * @page page_Results Results 
 * This page documents the results of the project 
 * 
 */