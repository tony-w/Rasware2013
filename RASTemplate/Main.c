#include "LED.h"
#include <RASLib/inc/time.h>

// The 'main' function is the entry point of the program
int main(void) {
  InitializeMCU();
  setLed(GREEN);
	Wait(5.0);
	setLed(OFF);
	while (1) {
		// Prevent exit.
	}
}
