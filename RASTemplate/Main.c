#include "LineFollow.h"
#include "SquareDance.h"
#include "WallFollow.h"
#include "Wheels.h"
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>

int main(void) {
  InitializeMCU();
	// Drive at a slower (not turbo boosted) speed
	// for a short period to prevent too fast of
	// an acceleration at the start of the match.
	setWheelMotors(SPEED, SPEED);
	Wait(0.2);
	// Follow the line and cross your fingers.
	while (1) {
		followLine();
	}
}
