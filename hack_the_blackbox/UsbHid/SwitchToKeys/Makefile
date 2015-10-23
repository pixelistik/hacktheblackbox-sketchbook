ARDUINO_PORT = /dev/ttyACM0
ARDUINO_LIBS =
ARDUINO_DIR = /usr/share/arduino
include /usr/share/arduino/Arduino.mk

.PHONY: flash-serial flash-keyboard

flash-serial:
	dfu-programmer atmega16u2 flash ../firmwares/Arduino-usbserial-uno.hex

flash-keyboard:
	dfu-programmer atmega16u2 flash ../firmwares/Arduino-keyboard-0.3.hex

