#include "WallFollow.h"
#include "Wheels.h"
#include <RASLib/inc/adc.h>

tADC *adc[1];
tBoolean IRSensorInitialized = false;
float ADCValue;

void initIRSensor(void) {
	adc[0] = InitializeADC(IR_SENSOR_0_PIN);
	IRSensorInitialized = true;
}

void followWall(void) {
	if(!IRSensorInitialized) {
		initIRSensor();
	}
	ADCValue = ADCRead(adc[0]);
	// Turn toward wall if it is too far away;
	// Turn away from the wall if it is too close;
	// Otherwise continue straight.
	if(ADCValue > ADC_HIGH_THRESHOLD) {
		drive(LEFT);
	} else if (ADCValue < ADC_LOW_THRESHOLD) {
		drive(RIGHT);
	} else {
		drive(FORWARD);
	}
}
