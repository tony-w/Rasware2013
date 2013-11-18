#include "LineFollow.h"
#include "LineSensor.h"
#include "Wheels.h"


int direction = FORWARD;
void followLine(void) {
	char lineSensorBits = getLineSensorBits();
	if((isSensingLineOnLeft(lineSensorBits)
		&& isSensingLineOnRight(lineSensorBits))
		|| isSensingLineCenter(lineSensorBits)) {
		direction = FORWARD;
	} else if (isSensingLineOnFarLeft(lineSensorBits)) {
			direction = LEFT_IN_PLACE;
	} else if(isSensingLineOnLeft(lineSensorBits)) {
		direction = BANKED_LEFT;
	} else if(isSensingLineOnFarRight(lineSensorBits)) {
		direction = RIGHT_IN_PLACE;
	} else if(isSensingLineOnRight(lineSensorBits)) {
		direction = BANKED_RIGHT;
	}
	drive(direction);
}
