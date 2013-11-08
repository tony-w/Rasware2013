#include "IRSensor.h"
#include "WallFollow.h"
#include "Wheels.h"

void followWall(void) {
	// Turn toward wall if it is too far away;
	// Turn away from the wall if it is too close;
	// Otherwise continue straight.
	if(IRLessThanThreshold(ADC_LEFT_THRESHOLD)) {
		drive(LEFT);
	} else if (IRGreaterThanThreshold(ADC_RIGHT_THRESHOLD)) {
		drive(RIGHT);
	} else {
		drive(FORWARD);
	}
}
