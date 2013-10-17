#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>
#include "Wheels.h"

tMotor *motors[12];

void initWheels(void) {
	motors[LEFT_WHEEL_MOTOR] = InitializeMotor(LEFT_PIN1, LEFT_PIN2, true, false);
  motors[RIGHT_WHEEL_MOTOR] = InitializeMotor(RIGHT_PIN1, RIGHT_PIN2, true, false);
}

void drive(int direction) {
	float leftSpeed = STOP, rightSpeed = STOP;
	switch(direction) {
		case FORWARD:
			rightSpeed = SPEED;
			leftSpeed = SPEED;
			break;
		case BACKWARD:
			rightSpeed = -SPEED;
			leftSpeed = -SPEED;
			break;
		case LEFT:
			rightSpeed = TURN_SPEED;
			leftSpeed = -TURN_SPEED;
			break;
		case RIGHT:
			rightSpeed = -TURN_SPEED;
			leftSpeed = TURN_SPEED;
			break;
		default:
			rightSpeed = leftSpeed = STOP;
			break;
	}
	SetMotor(motors[LEFT_WHEEL_MOTOR], leftSpeed);
	SetMotor(motors[RIGHT_WHEEL_MOTOR], rightSpeed);
}
