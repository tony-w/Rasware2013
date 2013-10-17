#include "LED.h"
#include "Wheels.h"
#include <RASLib/inc/time.h>

int main(void) {
  InitializeMCU();
	initWheels();
	setLed(GREEN);
  drive(LEFT);
	Wait(2.0);
	drive(RIGHT);
	Wait(2.0);
	drive(NO_WHERE);
	setLed(RED);
	while (1) {
		// Prevent exit.
	}
}
