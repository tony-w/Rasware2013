#include "IRSensor.h"
#include <RASLib/inc/adc.h>

tADC *adc[1];
tBoolean IRSensorInitialized = false;
float ADCValues[NUM_ADC_VALUES];

void initIRSensor(void) {
	adc[0] = InitializeADC(IR_SENSOR_0_PIN);
	ADCValues[0] = ADCValues[1] = ADCValues[2] = 0.5;
	IRSensorInitialized = true;
}

void readIRSensor(void) {
	int i = 0;
	if(!IRSensorInitialized) {
			initIRSensor();
		}
	for(; i<NUM_ADC_VALUES-1; i++) {
		ADCValues[i] = ADCValues[i+1];
	}
	ADCValues[NUM_ADC_VALUES-1] = ADCRead(adc[0]);
}

tBoolean allLessThanThreshold(float pastIRValues[], float threshold) {
	int i=0;
	for(; i<NUM_ADC_VALUES; i++) {
		if (pastIRValues[i] >= threshold) {
			return false;
		}
	}
	return true;
}

tBoolean allGreaterThanThreshold(float pastIRValues[], float threshold) {
	int i=0;
	for(; i<NUM_ADC_VALUES; i++) {
		if (pastIRValues[i] <= threshold) {
			return false;
		}
	}
	return true;
}

tBoolean IRLessThanThreshold(float threshold) {
	readIRSensor();
	return allLessThanThreshold(ADCValues, threshold);
}

tBoolean IRGreaterThanThreshold(float threshold) {
	readIRSensor();
	return allGreaterThanThreshold(ADCValues, threshold);
}
