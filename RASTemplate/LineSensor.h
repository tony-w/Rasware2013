#ifndef _LINE_SENSOR_H_
#define _LINE_SENSOR_H_

#include <RASLib/inc/adc.h>

#define LINE_SENSOR_THRESHOLD 0.8f

char getLineSensorBits(void);
tBoolean isSensingLineOnFarLeft(char);
tBoolean isSensingLineOnLeft(char);
tBoolean isSensingLineOnFarRight(char);
tBoolean isSensingLineOnRight(char);
tBoolean isSensingLineCenter(char);

#endif
