#include "LineFollow.h"
#include <RASLib/inc/linesensor.h>

tLineSensor *ls;
tBoolean lineSensorInitialized = false;

void initLineSensor(void) {
	tI2C *bus = InitializeI2C(LINE_SENSOR_PIN1, LINE_SENSOR_PIN2);
  ls = InitializeLineSensor(bus, 0);
	lineSensorInitialized = true;
}

void followLine(void) {
	float line[8];
	LineSensorReadArray(ls, line);
	// TODO
}
