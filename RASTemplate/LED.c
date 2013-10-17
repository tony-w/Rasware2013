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

void setLed(int color) {
	switch(color) {
		case RED:
			SetPin(PIN_RED, 1);
			SetPin(PIN_GREEN, 0);
			SetPin(PIN_BLUE, 0);
			break;
		case GREEN:
			SetPin(PIN_RED, 0);
			SetPin(PIN_GREEN, 1);
			SetPin(PIN_BLUE, 0);
			break;
		case BLUE:
			SetPin(PIN_RED, 0);
			SetPin(PIN_GREEN, 0);
			SetPin(PIN_BLUE, 1);
			break;
		case OFF:
			SetPin(PIN_RED, 0);
			SetPin(PIN_GREEN, 0);
			SetPin(PIN_BLUE, 0);
			break;
	}
}
