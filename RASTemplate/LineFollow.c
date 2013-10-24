#include "LineFollow.h"
#include "Wheels.h"
#include <RASLib/inc/linesensor.h>

tLineSensor *ls;
tBoolean lineSensorInitialized = false;

void initLineSensor(void) {
	tI2C *bus = InitializeI2C(LINE_SENSOR_PIN1, LINE_SENSOR_PIN2);
  ls = InitializeLineSensor(bus, 0);
	lineSensorInitialized = true;
}

tBoolean isBlack(float lineSensorValue) {
	return lineSensorValue < LINE_SENSOR_THRESHOLD;
}

tBoolean isSensingLineOnLeft(float line[]) {
	//return isBlack(line[0]) || isBlack(line[1]) || isBlack(line[2]);
	return isBlack(line[0]) || isBlack(line[1]);
}

tBoolean isSensingLineOnRight(float line[]) {
	//return isBlack(line[5]) || isBlack(line[6]) || isBlack(line[7]);
	return isBlack(line[6]) || isBlack(line[7]);
}

void followLine(void) {
	float line[8];
	if(!lineSensorInitialized) {
		initLineSensor();
	}
	LineSensorReadArray(ls, line);
	if(isSensingLineOnLeft(line) && isSensingLineOnRight(line)) {
		drive(FORWARD);
	} else if(isSensingLineOnLeft(line)) {
		drive(LEFT);
	} else if(isSensingLineOnRight(line)) {
		drive(RIGHT);
	} else {
		drive(FORWARD);
	}
}
