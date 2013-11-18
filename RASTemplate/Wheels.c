#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/time.h>
#include "Wheels.h"

tMotor *motors[12];
tBoolean wheelsInitialized = false;

void initWheels(void) {
	motors[LEFT_WHEEL_MOTOR] = InitializeMotor(LEFT_PIN1, LEFT_PIN2, true, false);
  motors[RIGHT_WHEEL_MOTOR] = InitializeMotor(RIGHT_PIN1, RIGHT_PIN2, true, false);
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
			setWheelMotors(SPEED-TURBO, SPEED-TURBO);
			break;
		case BACKWARD:
			setWheelMotors(1-SPEED, 1-SPEED);
			break;
		case BANKED_LEFT:
			setWheelMotors(SPEED+BANKED_TURN_COMPENSATION, SPEED-TURBO);
			break;
		case BANKED_RIGHT:
			setWheelMotors(SPEED-TURBO, SPEED+BANKED_TURN_COMPENSATION);
			break;
		case LEFT_IN_PLACE:
			setWheelMotors(1-(SPEED-TURN_IN_PLACE_TURBO), SPEED-TURN_IN_PLACE_TURBO);
			break;
		case RIGHT_IN_PLACE:
			setWheelMotors(SPEED-TURN_IN_PLACE_TURBO, 1-(SPEED-TURN_IN_PLACE_TURBO));
			break;
		default:
			setWheelMotors(STOP, STOP);
			break;
	}
}

void timedDrive(int direction, float seconds) {
	drive(direction);
	Wait(seconds);
	drive(NO_WHERE);
}
