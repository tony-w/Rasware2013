#include "LED.h"
#include "LineFollow.h"
#include "Wheels.h"
#include <RASLib/inc/time.h>

int main(void) {
  InitializeMCU();
	setLed(OFF);
	timedDrive(NO_WHERE, 1.0);
	timedDrive(FORWARD, 5.0);
	while (1) {
		// Prevent exit.
	}
}
