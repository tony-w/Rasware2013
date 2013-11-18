#include "LineSensor.h"
#include <RASLib/inc/linesensor.h>

tLineSensor *ls;
tBoolean lineSensorInitialized = false;
float line[8];

void initLineSensor(void) {
  ls = InitializeGPIOLineSensor(PIN_B5, PIN_D0, PIN_D1, PIN_D2, PIN_D3, PIN_E0, PIN_C6, PIN_C7);
	lineSensorInitialized = true;
}

tBoolean isBlack(int index) {
	// Each bit in lineSensorBits represents the value (0 or 1) of the corresponding sensor.
	return line[index] > LINE_SENSOR_THRESHOLD;
}

void setLineSensorArray(void) {
	if(!lineSensorInitialized) {
		initLineSensor();
	}
	LineSensorReadArray(ls, line);
	line[3] *= 2.6f;
}

tBoolean isSensingLineOnFarLeft(void) {
	return isBlack(0) || isBlack(1);
}

tBoolean isSensingLineOnLeft(void) {
	return isBlack(0) || isBlack(1) || isBlack(2);
}

tBoolean isSensingLineOnFarRight(void) {
	return isBlack(6) || isBlack(7);
}

tBoolean isSensingLineOnRight(void) {
	return isBlack(5) || isBlack(6) || isBlack(7);
}

tBoolean isSensingLineCenter(void) {
	return isBlack(3) || isBlack(4);
}
