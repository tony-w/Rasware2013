#include "LED.h"
#include "LineFollow.h"
#include "WallFollow.h"
#include "Wheels.h"
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>

int main(void) {
	float STRAIGHT_TIME = 2.94f;
	float TURN_TIME = 0.555f;
	float WAIT_TIME = 0.5f;
  InitializeMCU();
	Wait(1.0);
	timedDrive(FORWARD, STRAIGHT_TIME);
	Wait(WAIT_TIME);
	timedDrive(LEFT_IN_PLACE, TURN_TIME);
	Wait(WAIT_TIME);
	timedDrive(FORWARD, STRAIGHT_TIME);
	Wait(WAIT_TIME);
	timedDrive(LEFT_IN_PLACE, TURN_TIME + 0.04f);
	Wait(WAIT_TIME);
	timedDrive(FORWARD, STRAIGHT_TIME + 0.04f);
	Wait(WAIT_TIME);
	timedDrive(LEFT_IN_PLACE, TURN_TIME);
	Wait(WAIT_TIME);
	timedDrive(FORWARD, STRAIGHT_TIME);
	while (1) {
		//followWall();
		//drive(FORWARD);
	}
}
