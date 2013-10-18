#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>
#include "Wheels.h"

tMotor *motors[12];
tBoolean wheelsInitialized = false;

void initWheels(void) {
	motors[LEFT_WHEEL_MOTOR] = InitializeMotor(LEFT_PIN1, LEFT_PIN2, true, false);
  motors[RIGHT_WHEEL_MOTOR] = InitializeMotor(RIGHT_PIN1, RIGHT_PIN2, true, true);
	wheelsInitialized = true;
}

void setWheelMotors(float leftSpeed, float rightSpeed) {
	SetMotor(motors[LEFT_WHEEL_MOTOR], leftSpeed);
	SetMotor(motors[RIGHT_WHEEL_MOTOR], rightSpeed);
}

void drive(int direction) {
	if(!wheelsInitialized) {
		initWheels();
	}
	switch(direction) {
		case FORWARD:
			setWheelMotors(SPEED, SPEED);
			break;
		case BACKWARD:
			setWheelMotors(-SPEED, -SPEED);
			break;
		case LEFT:
			setWheelMotors(-TURN_SPEED, TURN_SPEED);
			break;
		case RIGHT:
			setWheelMotors(TURN_SPEED, -TURN_SPEED);
			break;
		default:
			setWheelMotors(STOP, STOP);
			break;
	}
}
