#include "LED.h"
#include <RASLib/inc/time.h>

// The 'main' function is the entry point of the program
int main(void) {
	int currColor = GREEN;
  InitializeMCU();
  CallEvery(toggleLed, &currColor, 1.0f);
	while (1) {
		// Prevent exit.
	}
}
