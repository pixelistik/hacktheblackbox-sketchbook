/**
 * https://www.arduino.cc/en/Reference/AttachInterrupt
 */

volatile int state = LOW;

void setup() {
  pinMode(9, INPUT);
  Serial.begin(9600);
  
  attachInterrupt(0, toggle, RISING);
}

void loop() {
  digitalWrite(8, state);
  
  Serial.println(digitalRead(2));
}

void toggle() {
  state = !state;
}

