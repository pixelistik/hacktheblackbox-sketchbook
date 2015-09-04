/**
 * A bot that hides in the dark
 */

#include <Servo.h> 

// The servo controller
Servo servo; 

// Which pins to use
const int sensorPin = A0;
const int servoPin = 8;

// Input and output variables
int sensorValue = 0;
int outputValue = 0;

// Variables for auto calibration
int knownSensorMax = 0;    // Init with lowest possible analog sensor max
int knownSensorMin = 1023; // Init with highest possible analog sensor min

void setup() {    
  // Initialise servo  
  servo.attach(servoPin);
}

void loop() 
{
  sensorValue = analogRead(sensorPin);

  // Update max if higher than known value
  if (sensorValue > knownSensorMax) {
    knownSensorMax = sensorValue;
  }

  // Update max if lower than known value
  if (sensorValue < knownSensorMin) {
    knownSensorMin = sensorValue;
  }

  // Dark = high resistance = high sensor value
  // Map sensor value to servo angle
  outputValue = map(sensorValue, knownSensorMin, knownSensorMax, 0, 180); 

  servo.write(outputValue);

  delay (10);
}

