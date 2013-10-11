#include <RASLib/inc/gpio.h>
#include "LED.h"

void toggleLed(int* currColor) {
	switch(*currColor) {
		case GREEN:
			SetPin(PIN_BLUE, 1);
			SetPin(PIN_GREEN, 0);
			*currColor = BLUE;
			break;
		case BLUE:
			SetPin(PIN_BLUE, 0);
			SetPin(PIN_GREEN, 1);
			*currColor = GREEN;
			break;
	}
}
