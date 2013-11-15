#include "LineFollow.h"
#include "LineSensor.h"
#include "Wheels.h"


int direction = FORWARD;
void followLine(void) {
	if((isSensingLineOnLeft() && isSensingLineOnRight()) || isSensingLineCenter()) {
		direction = FORWARD;
	} else if(isSensingLineOnLeft()) {
		direction = LEFT_IN_PLACE;
	} else if(isSensingLineOnRight()) {
		direction = RIGHT_IN_PLACE;
	}
	drive(direction);
}
