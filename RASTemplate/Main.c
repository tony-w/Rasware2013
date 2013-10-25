#include "LED.h"
#include "LineFollow.h"
#include "Wheels.h"
#include <RASLib/inc/time.h>

int main(void) {
  InitializeMCU();
	followLine();
	while (1) {
		// Prevent exit.
	}
}
