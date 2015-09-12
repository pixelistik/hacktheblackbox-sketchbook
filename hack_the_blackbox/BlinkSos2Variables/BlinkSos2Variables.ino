/*
  Blink SOS, using variables for durations
 */

int longBlinkDuration = longBlinkDuration;
int shortBlinkDuration = longBlinkDuration;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(13, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  // S
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(shortBlinkDuration); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(shortBlinkDuration);               // wait for a second
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(shortBlinkDuration); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(shortBlinkDuration);
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(shortBlinkDuration); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(shortBlinkDuration); 
  
  // O
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(longBlinkDuration); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(longBlinkDuration);               // wait for a second
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(longBlinkDuration); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(longBlinkDuration);
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(longBlinkDuration); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(longBlinkDuration);
  
  // S
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(shortBlinkDuration); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(shortBlinkDuration);               // wait for a second
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(shortBlinkDuration); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(shortBlinkDuration);
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(shortBlinkDuration); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(shortBlinkDuration);
  
  delay(2000);
}

