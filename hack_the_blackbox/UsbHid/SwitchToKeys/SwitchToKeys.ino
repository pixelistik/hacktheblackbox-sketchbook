// From http://mitchtech.net/arduino-usb-hid-keyboard/
/* Arduino USB HID Keyboard Demo
 * Random Key/Random Delay
 */

/* Keyboard report buffer */
uint8_t buf[8] = { 0 };	

const int LOWEST_PIN = 2;
const int HIGHEST_PIN = 12;

int keyMap[HIGHEST_PIN + 1] = {
  0,
  0,
  0x04, // 2 = a
  0x05, // 3 = b
  0x06, // 4 = c
  0x07, // 5 = d
  0x08, // 6 = e
  0x09, // 7 = f 
  0x0B, // 8 = h
  0x0D, // 9 = j
  0x12, // 10 = o
  0x14, // 11 = q
  0x17 //  12 = t
  
};

int pinState;

int pinStatePrevious[HIGHEST_PIN + 1];

void setup() 
{
  Serial.begin(9600);
  
  for(int i = LOWEST_PIN; i <= HIGHEST_PIN; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  
  delay(200);
}

void loop() 
{
  
  for(int i = LOWEST_PIN; i <= HIGHEST_PIN; i++) {
    pinState = digitalRead(i);
    
    if (pinStatePrevious[i] == 1 && pinState == 0) {
      buf[2] = keyMap[i];
      
      // Serial.println(keyMap[i]);
      	  
      Serial.write(buf, 8);	// Send keypress
      
    }
    
    if (pinStatePrevious[i] == 0 && pinState == 1) {
      releaseKey();
    }
    
    pinStatePrevious[i] = pinState;
  }
  delay(50);
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key  
}
