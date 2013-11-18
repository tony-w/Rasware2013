#include "LineFollow.h"
#include "SquareDance.h"
#include "WallFollow.h"
#include "Wheels.h"
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>

int main(void) {
  InitializeMCU();
	setWheelMotors(SPEED, SPEED);
	Wait(0.2);
	while (1) {
		followLine();
	}
}
