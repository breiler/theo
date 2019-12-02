/*
 * LaserTurrent
 * 
 * Sweeps the servo motor until it finds a target in range using the ultra sonic 
 * sensor and then fires the laser.
 *
 * Connect the Ultrasonic sensor pins to the Arduino:
 *    VCC: +5v
 *    Trig: Pin 11
 *    Echo: Pin 12
 *    GND: GND
 *    
 * Connect Laser module, red wire to pin 8 and the black wire to any ground pin.
 * 
 * Connect Servo, the white wire to pin 9, the black wire to ground and the red wire to +5v.
 */
#include <Servo.h>

// Variable for the laser pin
int laserPin = 8;

// Variables for the ultrasonic sensor
int triggerPin = 11;
int echoPin = 12;

// Variables for the servo
int servoPin = 9;
Servo turrentServo;
int currentPosition = 0;
boolean direction = true; // true for positive direction, false for negative

/*
 * Set up, this is a method that will be called once when the Arduino is starting.
 * Add stuff here for initializing pins and other stuff.
 */
void setup() {
  // Makes the laser pin an output
  pinMode(laserPin, OUTPUT);

  // Makes the Ultrasonic pins inputs and outputs
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Attaches the servo on pin 9 to the servo object
  turrentServo.attach(servoPin); 
}

/**
 * This will loop continously as long as there is power to the Arduino
 */
void loop() {
  
  // Gets the distance for the ultrasonic sensor
  int distance = getDistance();

  // Calculate if the object is in range for the laser (30cm)
  bool isTargetInRange = distance < 30;

  // Fire laser if target is in range else scan for targets
  if(isTargetInRange) {
    setLaser(true);
  } else {
    setLaser(false);
    moveTurrentServo();
  }

  // Wait 250ms before we try again
  delay(50);
}

/*
 * Function for activate/deactivate the laser
 * 
 * @param active, set to true to activate laser
 */
void setLaser(boolean active) {
  if(active) {
    digitalWrite(laserPin, HIGH);
  } else {
    digitalWrite(laserPin, LOW);    
  }
}

/*
 * Get the distance for the Ultrasonic sensor
 * 
 * @returns the distance in centimeters
 */
int getDistance() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  long duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  return (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
}

/*
 * Function for moving the turrent servo. If the servo reaches the limit (0 to 180) 
 * it is reversed.
 */
void moveTurrentServo() {
  // Figure out which direction we should step, negative or positive
  int step = 5;
  if(!direction) {
    step = -5;
  }

  // Calculate the new current position
  currentPosition = currentPosition + step;

  // Make sure we don't exceed the servo limits, and change direction if we do
  if(currentPosition >= 180) {
    direction = !direction;
    currentPosition = 180;
  } else if (currentPosition <= 0) {
    direction = !direction;
    currentPosition = 0;
  }

  // Move the servo to the new position
  turrentServo.write(currentPosition);
}
