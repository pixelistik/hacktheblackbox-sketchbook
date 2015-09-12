#include <Conceptinetics.h>

int lightChannels[] = {
	1,
	2
};

int sensorPins[] = {
	8,
	9
};

const int CHANNEL_COUNT = sizeof(sensorPins) / sizeof(int);

int sensorValues[CHANNEL_COUNT];
int sensorValuesPrevious[CHANNEL_COUNT];
bool sensorCoveredStates[CHANNEL_COUNT];

const int SENSOR_THRESHOLD = 500;

DMX_Master dmx_master(100, 2); // 100 = channels, 2 = enabling jumper, fixed value

int randomLightIndex() {
	return random(CHANNEL_COUNT);
}

int randomLightIndexExcept(int exceptLightIndex) {
	int index;
	do {
		index = random(CHANNEL_COUNT);
	} while (index == exceptLightIndex);

	return index;
}

void switchOn(int lightIndex) {
	dmx_master.setChannelValue(lightChannels[lightIndex], 255);
}

void switchOff(int lightIndex) {
	dmx_master.setChannelValue(lightChannels[lightIndex], 0);
}

void readSensorValues() {
	for (int i = 0; i < CHANNEL_COUNT; i++) {
		sensorValues[i] = analogRead(sensorPins[i]);
	}
}

/**
 * Determine which sensors have been covered since the
 * previous check
 */
void updateSensorCoveredStates() {
	for (int i = 0; i < CHANNEL_COUNT; i++) {
		sensorCoveredStates[i] =
			sensorValuesPrevious[i] <= SENSOR_THRESHOLD &&
			sensorValues[i] > SENSOR_THRESHOLD;
	}
}

void setup() {
	dmx_master.enable();
	dmx_master.setChannelRange(2, 25, 127);

	switchOn(randomLightIndex());

	readSensorValues();
}

void loop() {
	memcpy(sensorValuesPrevious, sensorValues, sizeof(sensorValues));
	readSensorValues();
	updateSensorCoveredStates();

	for (int i = 0; i < CHANNEL_COUNT; i++) {
		if (sensorCoveredStates[i]) {
			switchOff(i);
			switchOn(randomLightIndexExcept(i));
		}
	}
}

