#ifndef _IR_SENSOR_H_
#define _IR_SENSOR_H_

#include <RASLib/inc/adc.h>

#define IR_SENSOR_0_PIN PIN_D0

// Keep a history of values to remove outliers.
#define NUM_ADC_VALUES 5

tBoolean IRLessThanThreshold(float threshold);
tBoolean IRGreaterThanThreshold(float threshold);

#endif
