#ifndef _WHEELS_H_
#define _WHEELS_H_

#define FORWARD 0
#define LEFT 1
#define RIGHT 2
#define BACKWARD 3

#define SPEED 1.0

/**
* Drive in one of the directions with speed SPEED:
*		FORWARD
*		LEFT
*		RIGHT
*		BACKWARD
*/
void drive(int direction);

#endif