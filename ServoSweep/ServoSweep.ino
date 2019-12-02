/*
 * ServoSweep
 * 
 * Guide for moving a servo motor. This will make the servo sweep from side to side. 
 * 
 * Connect the white wire to pin 9, the black wire to ground and the red wire to +5v.
 * 
 * Check out the language refrence for more information:
 * https://www.arduino.cc/reference/en/
 */

#include <Servo.h>

// Create servo object to control a servo
Servo myServo;  

// Variable to store the servo position
int pos = 0;

void setup() {
  // Attaches the servo on pin 9 to the servo object
  myServo.attach(9); 
}

void loop() {

  // A loop that will start at 0 and count up to 180 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    // Tell the servo to go to position in variable 'pos'
    myServo.write(pos);

    // Waits 15ms for the servo to reach the position
    delay(15);
  }

    // A loop that will start at 180 and count down to 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) {
    // Tell the servo to go to position in variable 'pos'
    myServo.write(pos);

    // Waits 15ms for the servo to reach the position
    delay(15);
  }
}
