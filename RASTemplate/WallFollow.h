#ifndef _WALL_FOLLOW_H_
#define _WALL_FOLLOW_H_

#define IR_SENSOR_0_PIN PIN_D0

#define NUM_ADC_VALUES 5

#define ADC_RIGHT_THRESHOLD 0.6f
#define ADC_LEFT_THRESHOLD 0.4f

void followWall(void);

#endif
