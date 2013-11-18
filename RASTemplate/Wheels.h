#ifndef _WHEELS_H_
#define _WHEELS_H_

#define FORWARD 0
#define BACKWARD 1
#define BANKED_LEFT 2
#define BANKED_RIGHT 3
#define NO_WHERE 4
#define LEFT_IN_PLACE 5
#define RIGHT_IN_PLACE 6

#define SPEED 0.35f
#define TURBO 0.10f
#define TURN_IN_PLACE_TURBO 0.28f
#define BANKED_TURN_COMPENSATION 0.25f
#define STOP 0.5f

#define LEFT_PIN1 PIN_C4
#define LEFT_PIN2 PIN_C5
#define RIGHT_PIN1 PIN_B6
#define RIGHT_PIN2 PIN_B7
#define LEFT_WHEEL_MOTOR 0
#define RIGHT_WHEEL_MOTOR 1

/**
* Drive the given direction based on the constants defined above.
*/
void drive(int direction);

/**
* Drive in the given direction for specified number of seconds.
*/
void timedDrive(int direction, float seconds);

#endif
