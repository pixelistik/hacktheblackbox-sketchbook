/**
 * Find out if any audio is playing on a Line level cable
 *
 * A very simple way to find out if any audio is currently
 * playing, by reading the voltage from the cable. Line level
 * audio signals are much lower than 5V, so turn up the volume.
 *
 * Connect Ground and 1 Stero channel to the Arduino's GND and A0 pins.
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;

int sensorValue = 0;
int sum;
int average;

int buffer[20];
int bufferPosition = 0;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);            
        
  // Write the current value into the current
  // ring buffer position
  buffer[bufferPosition] = sensorValue;
  
  bufferPosition++;
  if (bufferPosition > 20) bufferPosition = 0;

  // Calculate the average from the last 20 readings
  sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += buffer[i];
  }  
  average = sum / 20;

  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t avg = ");      
  Serial.print(average);
  Serial.print("\t abs = ");
  Serial.print(abs(512-average));
  if (abs(512-average) > 0) {
    Serial.print("\tAudio is playing");
  }
  Serial.println();

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);                     
}
