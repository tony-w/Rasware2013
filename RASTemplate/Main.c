#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>

#define RED 0
#define BLUE 1

void toggleLed(int* currColor) {
	switch(*currColor) {
		// PIN_GREEN is actually blue.
		case RED:
			SetPin(PIN_GREEN, 1);
			SetPin(PIN_RED, 0);
			*currColor = BLUE;
			break;
		case BLUE:
			SetPin(PIN_GREEN, 0);
			SetPin(PIN_RED, 1);
			*currColor = RED;
			break;
	}
}

// The 'main' function is the entry point of the program
int main(void) {
	int currColor = 0;
  InitializeMCU();
  CallEvery(toggleLed, &currColor, 1.0f);
	while (1) {
	}
}
