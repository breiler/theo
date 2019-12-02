/*
 * UltrasonicLaserTrigger
 * 
 * Reads the distance from the Ultrasonic Sensor HC-SR04 and fires the
 * laser if an object is in range
 *
 * Connect the Ultrasonic sensor pins to the Arduino:
 *    VCC: +5v
 *    Trig: Pin 11
 *    Echo: Pin 12
 *    GND: GND
 *    
 * Connect the red wire from the laser module to pin 8 
 * and the black wire to any ground pin.
 */

// Variable for the laser pin
int laserPin = 8;

// Variables for the ultrasonic sensor
int triggerPin = 11;
int echoPin = 12;

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
}

/**
 * This will loop continously as long as there is power to the Arduino
 */
void loop() {
  // Gets the distance for the ultrasonic sensor
  int distance = getDistance();

  // Calculate if the object is in range for the laser (30cm)
  bool isTargetInRange = distance < 30;

  // Fire the laser if it's in range
  setLaser(isTargetInRange);

  // Wait 250ms before we try again
  delay(250);
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

/**
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
