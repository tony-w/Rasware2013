#include "LineFollow.h"
#include "LineSensor.h"
#include "Wheels.h"


int direction = FORWARD;
void followLine(void) {
	if((isSensingLineOnLeft() && isSensingLineOnRight()) || isSensingLineCenter()) {
		direction = FORWARD;
	} else if (isSensingLineOnFarLeft()) {
			direction = LEFT_IN_PLACE;
	} else if(isSensingLineOnLeft()) {
		direction = BANKED_LEFT;
	} else if(isSensingLineOnFarRight()) {
		direction = RIGHT_IN_PLACE;
	} else if(isSensingLineOnRight()) {
		direction = BANKED_RIGHT;
	}
	drive(direction);
}
