/*
 * UltrasonicSensor
 * 
 * Reads the distance from the Ultrasonic Sensor HC-SR04
 *
 * Connect the Ultrasonic sensor pins to the Arduino:
 *    VCC: +5v
 *    Trig: Pin 11
 *    Echo: Pin 12
 *    GND: GND
 */
int triggerPin = 11;
int echoPin = 12;
long duration = 0;
int distance = 0;

/*
 * Set up, this is a method that will be called once when the Arduino is starting.
 * Add stuff here for initializing pins and other stuff.
 */
void setup() {
  Serial.begin (9600);

  // Define inputs and outputs
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

/**
 * This will loop continously as long as there is power to the Arduino
 */
void loop() {
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
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  distance = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343

  // Write the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
}
