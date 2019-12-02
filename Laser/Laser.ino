
/*
 * Laser
 * 
 * Guide for firing laser. Connect the red wire from the laser module to pin 8 
 * and the black wire to any ground pin.
 * 
 * Open the Serial Monitor to view the print output.
 * 
 * Check out the language refrence for more information:
 * https://www.arduino.cc/reference/en/
 */

// This is a variable for the pin that will be connected to the laser
int laserPin = 8; 

/*
 * Set up, this is a method that will be called once when the Arduino is starting.
 * Add stuff here for initializing pins and other stuff.
 */
void setup() {
  // For writing text to the serial monitor
  Serial.begin (9600);

  // Makes the laser pin an output
  pinMode(laserPin, OUTPUT);
}

/**
 * This will loop continously as long as there is power to the Arduino
 */
void loop() {
  // Turns off the laser
  Serial.println("Turning off laser");
  digitalWrite(laserPin, LOW);

  // Wait for 5000 milliseconds
  Serial.println("Waiting");
  delay(5000);

  // Turns on the laser
  Serial.println("Turning on laser");
  digitalWrite(laserPin, HIGH);

  // Wait for 5000 milliseconds
  Serial.println("Waiting again");
  delay(5000);
}
