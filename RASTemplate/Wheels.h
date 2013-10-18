#ifndef _WHEELS_H_
#define _WHEELS_H_

#define FORWARD 0
#define BACKWARD 1
#define LEFT 2
#define RIGHT 3
#define NO_WHERE 4

#define SPEED 0.3
#define TURN_SPEED 0.3
#define STOP 0.0

#define LEFT_PIN1 PIN_B7
#define LEFT_PIN2 PIN_B6
#define RIGHT_PIN1 PIN_F4
#define RIGHT_PIN2 PIN_F1
#define LEFT_WHEEL_MOTOR 0
#define RIGHT_WHEEL_MOTOR 1

/**
* Initialize wheel motors
*/
void initWheels(void);

/**
* Helper method to set left and right wheel motor speeds
*/
void setWheelMotors(float leftSpeed, float rightSpeed);

/**
* Drive in one of the directions with speed SPEED:
*		FORWARD
*		LEFT
*		RIGHT
*		BACKWARD
*/
void drive(int direction);

/**
* Drive in the given direction for specified number of seconds.
*/
void timedDrive(int direction, float seconds);

#endif
