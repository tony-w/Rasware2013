#include "WallFollow.h"
#include "Wheels.h"
#include <RASLib/inc/adc.h>

tADC *adc[1];
tBoolean IRSensorInitialized = false;
float ADCValues[NUM_ADC_VALUES];

void initIRSensor(void) {
	adc[0] = InitializeADC(IR_SENSOR_0_PIN);
	ADCValues[0] = ADCValues[1] = ADCValues[2] = 0.5;
	IRSensorInitialized = true;
}

tBoolean allLessThanThreshold(float ADCValues[], float threshold) {
	int i=0;
	for(; i<NUM_ADC_VALUES; i++) {
		if (ADCValues[i] >= threshold) {
			return false;
		}
	}
	return true;
}

tBoolean allGreaterThanThreshold(float ADCValues[], float threshold) {
	int i=0;
	for(; i<NUM_ADC_VALUES; i++) {
		if (ADCValues[i] <= threshold) {
			return false;
		}
	}
	return true;
}

void followWall(void) {
	int i=0;
	if(!IRSensorInitialized) {
		initIRSensor();
	}
	for(; i<NUM_ADC_VALUES-1; i++) {
		ADCValues[i] = ADCValues[i+1];
	}
	ADCValues[NUM_ADC_VALUES-1] = ADCRead(adc[0]);
	// Turn toward wall if it is too far away;
	// Turn away from the wall if it is too close;
	// Otherwise continue straight.
	if(allLessThanThreshold(ADCValues, ADC_LEFT_THRESHOLD)) {
		drive(LEFT);
	} else if (allGreaterThanThreshold(ADCValues, ADC_RIGHT_THRESHOLD)) {
		drive(RIGHT);
	} else {
		drive(FORWARD);
	}
}
