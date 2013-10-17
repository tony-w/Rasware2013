#include "LED.h"
#include "Wheels.h"
#include <RASLib/inc/time.h>

int main(void) {
  InitializeMCU();
	initWheels();
	setLed(GREEN);
  drive(LEFT);
	Wait(2.0);
	setLed(BLUE);
	drive(RIGHT);
	Wait(2.0);
	setLed(GREEN);
	drive(FORWARD);
	Wait(2.0);
	setLed(BLUE);
	drive(BACKWARD);
	Wait(2.0);
	setLed(RED);
	drive(NO_WHERE);
	while (1) {
		// Prevent exit.
	}
}
