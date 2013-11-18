#include "LineFollow.h"
#include "SquareDance.h"
#include "WallFollow.h"
#include "Wheels.h"
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>

int main(void) {
  InitializeMCU();
	timedDrive(FORWARD, 0.2f);
	while (1) {
		followLine();
	}
}
