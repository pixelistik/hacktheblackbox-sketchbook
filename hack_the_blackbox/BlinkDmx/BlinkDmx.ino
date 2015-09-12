/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
#include <Conceptinetics.h>
DMX_Master dmx_master(100, 2);

// the setup routine runs once when you press reset:
void setup() {                
  dmx_master.enable(); 
  dmx_master.setChannelRange(2, 25, 127);  
}

// the loop routine runs over and over again forever:
void loop() {
  dmx_master.setChannelValue(1, 255);
  delay(1000);               // wait for a second

  dmx_master.setChannelValue(1, 0);
  delay(1000);               // wait for a second
}

