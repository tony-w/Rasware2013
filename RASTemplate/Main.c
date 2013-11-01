#include "LED.h"
#include "LineFollow.h"
#include "WallFollow.h"
#include "Wheels.h"
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>

int main(void) {
  InitializeMCU();
	Wait(1.0);
	while (1) {
		followWall();
	}
}
