#include "LineSensor.h"
#include <RASLib/inc/linesensor.h>

tLineSensor *ls;
tBoolean lineSensorInitialized = false;

void initLineSensor(void) {
  ls = InitializeGPIOLineSensor(PIN_B5, PIN_D0, PIN_D1, PIN_D2, PIN_D3, PIN_E0, PIN_C6, PIN_C7);
	lineSensorInitialized = true;
}

tBoolean isBlack(float lineSensorValue) {
	// Values range from 0 to Vcc (3.3?), where 0 is white and Vcc is black.
	return lineSensorValue > LINE_SENSOR_THRESHOLD;
}

tBoolean isSensingOnLeft(float line[]) {
	//return isBlack(line[0]) || isBlack(line[1]) || isBlack(line[2]);
	return isBlack(line[0]) || isBlack(line[1]);
}

tBoolean isSensingOnRight(float line[]) {
	//return isBlack(line[5]) || isBlack(line[6]) || isBlack(line[7]);
	return isBlack(line[6]) || isBlack(line[7]);
}

tBoolean isSensingLineOnLeft(void) {
	float line[8];
	if(!lineSensorInitialized) {
		initLineSensor();
	}
	LineSensorReadArray(ls, line);
	return isSensingOnLeft(line);
}

tBoolean isSensingLineOnRight(void) {
	float line[8];
	if(!lineSensorInitialized) {
		initLineSensor();
	}
	LineSensorReadArray(ls, line);
	return isSensingOnRight(line);
}
