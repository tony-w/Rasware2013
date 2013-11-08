#include "LineFollow.h"
#include "LineSensor.h"
#include "Wheels.h"

void followLine(void) {
	if(isSensingLineOnLeft() && isSensingLineOnRight()) {
		drive(FORWARD);
	} else if(isSensingLineOnLeft()) {
		drive(LEFT_IN_PLACE);
	} else if(isSensingLineOnRight()) {
		drive(RIGHT_IN_PLACE);
	} else {
		drive(FORWARD);
	}
}
