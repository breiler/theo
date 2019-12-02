# Arduino experimental kit - Laser turrent

This is the source code for an arduino experimental kit for building a target finding laser turrent using:
 * Ardunio UNO
 * 5v laser module
 * Ultra sonic sensor HC-SR04
 * Servo motor

For more information, see https://www.arduino.cc/reference/en/

## Setting up tools
Start by downloading and installing the Arduino IDE from here: https://www.arduino.cc/en/Main/Software

* Open the IDE 
* Select the the example program Blink from "File > Examples > 01. Basics > Blink"
* Connect your Arduino
* Go to the menu "Tools > Boards" and select "Arduino Uno"
* Go to the menu "Tools > Port" and select the port for your Arduino
* Click on the button Upload and the program should be installed on your Arduino

## Installing the programs
* **Laser** - A simple program showing how to turn on and off the laser
* **ServoSweep** - A program showing how to control the servo motor
* **UltrasonicSensor** - A program describing how to read the distance using the HC-SR04 sensor
* **UltrasonicLaserTrigger** - A program showing how to use the sensor for triggering the laser module
* **LaserTurrent** - A program that will sweep the ultrasonic sensor for targets and firing the laser.
