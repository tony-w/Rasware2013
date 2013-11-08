#include "SquareDance.h"
#include "Wheels.h"
#include <RASLib/inc/time.h>

void squareDance(void) {
	timedDrive(FORWARD, STRAIGHT_TIME);
	Wait(WAIT_TIME);
	timedDrive(LEFT_IN_PLACE, TURN_TIME);
	Wait(WAIT_TIME);
	timedDrive(FORWARD, STRAIGHT_TIME);
	Wait(WAIT_TIME);
	timedDrive(LEFT_IN_PLACE, TURN_TIME + 0.04f);
	Wait(WAIT_TIME);
	timedDrive(FORWARD, STRAIGHT_TIME);
	Wait(WAIT_TIME);
	timedDrive(LEFT_IN_PLACE, TURN_TIME);
	Wait(WAIT_TIME);
	timedDrive(FORWARD, STRAIGHT_TIME);
}
