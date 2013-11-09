#include "LineFollow.h"
#include "LineSensor.h"
#include "Wheels.h"


void followLine(void) {
	int direction = FORWARD;
	if((isSensingLineOnLeft() && isSensingLineOnRight()) || isSensingLineCenter()) {
		direction = FORWARD;
	} else if(isSensingLineOnLeft()) {
		direction = LEFT_IN_PLACE;
	} else if(isSensingLineOnRight()) {
		direction = RIGHT_IN_PLACE;
	} 
	drive(direction);
}
