#ifndef _LINE_SENSOR_H_
#define _LINE_SENSOR_H_

#include <RASLib/inc/adc.h>

#define LINE_SENSOR_THRESHOLD 0.6f

tBoolean isSensingLineOnLeft(void);
tBoolean isSensingLineOnRight(void);

#endif
