/**
 * Patch to translate button presses to keys sent via USB keyboard
 *
 * Required the Arduino's device firmware to be changed to a special
 * firmware, see http://mitchtech.net/arduino-usb-hid-keyboard/
 */

bool SERIAL_DEBUG_PRINT = false;

// Keyboard report buffer
uint8_t buf[8] = { 0 };

int pins[] = {    2,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,   A0,   A1,   A2,   A3,   A4,   A5 };
int keys[] = { 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0B, 0x0D, 0x12, 0x14, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E };
//                a     b     c     d     e     f     h     j     o     q     t     u     v,    w,    x,    y,    z,    1
// See http://www.freebsddiary.org/APC/usb_hid_usages.php for USB Keyboard codes

const int pinCount = sizeof(pins) / sizeof(int);

int pinState;

int pinStatePrevious[pinCount];

void setup() {
  Serial.begin(9600);

  for(int i = 0; i <= pinCount; i++) {
	pinMode(pins[i], INPUT_PULLUP);
  }

  delay(200);
}

void pressKey(int key) {
	if (SERIAL_DEBUG_PRINT) {
		Serial.println(key);
	} else {
		buf[2] = key;
		Serial.write(buf, 8);
	}
}

void releaseKey() {
	if(!SERIAL_DEBUG_PRINT) {
		buf[0] = 0;
		buf[2] = 0;

		// Release key
		Serial.write(buf, 8);
	}
}

void loop() {
	for(int i = 0; i <= pinCount; i++) {
		pinState = digitalRead(pins[i]);

		if (pinStatePrevious[i] == 1 && pinState == 0) {
			pressKey(keys[i]);
		}

		if (pinStatePrevious[i] == 0 && pinState == 1) {
			releaseKey();
		}

		pinStatePrevious[i] = pinState;
	}
	delay(50);
}

