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

const int bufferLength = 80;
int buffer[bufferLength];
int bufferPosition = 0;

void setup() {    
  Serial.begin(9600);
  
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
  
  sensorValue = sensorHistoryAvg(sensorValue);

  // Dark = high resistance = high sensor value
  // Map sensor value to servo angle
  outputValue = map(sensorValue, knownSensorMin, knownSensorMax, 0, 45);

  servo.write(outputValue);

  delay (10);
}

int sensorHistoryAvg(int latestValue) {
  Serial.print("Storing value ");
  Serial.print(latestValue);
  Serial.print(" at position ");
  Serial.print(bufferPosition);
  
  buffer[bufferPosition] = latestValue;
  
  bufferPosition++;
  if (bufferPosition >= bufferLength) bufferPosition = 0;

  // Calculate the average from the last readings
  long sum = 0;
  
  for (int i = 0; i < bufferLength; i++) {
    sum += buffer[i];
  }  
  Serial.print(sum);
  int average = sum / bufferLength;
  
  Serial.print(", average is ");
  Serial.print(average);
  Serial.println("");
  return average;
}
