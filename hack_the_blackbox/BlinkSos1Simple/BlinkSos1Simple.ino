/*
  Blink SOS
 */
 

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(13, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  // S
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
  
  // O
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  
  // S
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500); 
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
  
  delay(2000);
}

