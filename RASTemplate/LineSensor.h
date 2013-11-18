#ifndef _LINE_SENSOR_H_
#define _LINE_SENSOR_H_

#include <RASLib/inc/adc.h>

#define LINE_SENSOR_THRESHOLD 0.8f

/**
* Sets the line sensor array.
* Needs to be used before reading values.
*/
void setLineSensorArray(void);

tBoolean isSensingLineOnFarLeft(void);
tBoolean isSensingLineOnLeft(void);
tBoolean isSensingLineOnFarRight(void);
tBoolean isSensingLineOnRight(void);
tBoolean isSensingLineCenter(void);

#endif
