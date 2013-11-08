#include "LineFollow.h"
#include "LineSensor.h"
#include "Wheels.h"

void followLine(void) {
	if(isSensingLineOnLeft() && isSensingLineOnRight()) {
		drive(FORWARD);
	} else if(isSensingLineOnLeft()) {
		drive(LEFT);
	} else if(isSensingLineOnRight()) {
		drive(RIGHT);
	} else {
		drive(FORWARD);
	}
}
