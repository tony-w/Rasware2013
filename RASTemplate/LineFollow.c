#include "LineFollow.h"
#include "LineSensor.h"
#include "Wheels.h"

void followLine(void) {
	int lastDirection = FORWARD;
	if((isSensingLineOnLeft() && isSensingLineOnRight()) || isSensingLineCenter()) {
		lastDirection = FORWARD;
	} else if(isSensingLineOnLeft()) {
		lastDirection = LEFT_IN_PLACE;
	} else if(isSensingLineOnRight()) {
		lastDirection = RIGHT_IN_PLACE;
	}
	drive(lastDirection);
}
