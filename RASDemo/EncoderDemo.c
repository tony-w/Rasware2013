#include "RASDemo.h"

#include <RASLib/inc/common.h>
#include <RASLib/inc/encoder.h>
#include <RASLib/inc/motor.h>

tMotor *motorsenc[2];
tEncoder *demoEncoder[2];

void initEncoders(void) {
    demoEncoder[0] = InitializeEncoder(PIN_D7, PIN_D6, false);
    demoEncoder[1] = InitializeEncoder(PIN_D2, PIN_D3, false);
}

void initMotorsEncoder(void) {
    motorsenc[0] = InitializeMotor(PIN_B7, PIN_B6, true, false);
    motorsenc[1] = InitializeMotor(PIN_C4, PIN_C5, true, false);
}

void encoderDemo(void) {
    Printf("Press:\nany key-read encoder values\n");
    Printf("any key after read begins-quit\n");
	
		initMotorsEncoder();
    
    ResetEncoder(demoEncoder[0]);
    ResetEncoder(demoEncoder[1]);

    while(!KeyWasPressed()) {
			    SetMotor(motorsenc[0], 0.0f);
					SetMotor(motorsenc[1], 0.0f);
        Printf("enc0:%d  enc1:%d\r",
                    GetEncoder(demoEncoder[0]),
                    GetEncoder(demoEncoder[1]));
				
    }
    
    Printf("\n");
}
