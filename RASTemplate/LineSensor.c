#include "LineSensor.h"
#include <RASLib/inc/linesensor.h>

tLineSensor *ls;
tBoolean lineSensorInitialized = false;

void initLineSensor(void) {
  ls = InitializeGPIOLineSensor(PIN_B5, PIN_D0, PIN_D1, PIN_D2, PIN_D3, PIN_E0, PIN_C6, PIN_C7);
	lineSensorInitialized = true;
}

tBoolean isBlack(char lineSensorBits, int bit) {
	// Each bit in lineSensorBits represents the value (0 or 1) of the corresponding sensor.
	return lineSensorBits & (1 << bit);
}

char getLineSensorBits(void) {
	if(!lineSensorInitialized) {
		initLineSensor();
	}
	return LineSensorRead(ls, LINE_SENSOR_THRESHOLD);
}

tBoolean isSensingLineOnFarLeft(char lineSensorBits) {
	return isBlack(lineSensorBits, 0) || isBlack(lineSensorBits, 1);
}

tBoolean isSensingLineOnLeft(char lineSensorBits) {
	return isBlack(lineSensorBits, 0) || isBlack(lineSensorBits, 1) || isBlack(lineSensorBits, 2);
}

tBoolean isSensingLineOnFarRight(char lineSensorBits) {
	return isBlack(lineSensorBits, 6) || isBlack(lineSensorBits, 7);
}

tBoolean isSensingLineOnRight(char lineSensorBits) {
	return isBlack(lineSensorBits, 5) || isBlack(lineSensorBits, 6) || isBlack(lineSensorBits, 7);
}

tBoolean isSensingLineCenter(char lineSensorBits) {
	return isBlack(lineSensorBits, 3) || isBlack(lineSensorBits, 4);
}
