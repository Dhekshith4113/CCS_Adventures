#include "F28x_Project.h"
#include "functions.h"								// Include the created "functions.h" file
#include "IQmathLib.h"								// Include the "IQmathLib.h" file

float x = 0.59f;									// Add a test variable
float result_float = 0.0f;							// Define a variable to store the result
_iq x_iq;
_iq result_iq;

void main(void)
{
	InitSysCtrl();									// Initialize the microcontroller

    x_iq = _IQ(x);                              	// Convert the test variable to IQ24 format

    EALLOW;
	GpioCtrlRegs.GPAGMUX1.bit.GPIO6 = 0;            // 
	GpioCtrlRegs.GPAMUX1.bit.GPIO6  = 0;  			// 
	GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;				// Set direction as output
	EDIS;

	while(1) {
		DELAY_US(100);								// Wait for 100 microseconds

        GpioDataRegs.GPATOGGLE.bit.GPIO6 = 1;		// Set pin 6 to HIGH
		result_iq = nlog_iq(x_iq);					// Compute ln(x) using IQ math
		result_float = _IQtoF(result_iq);			// Convert result to float 
        GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;		// Set pin 6 to LOW

		// DELAY_US(100);								// Wait for 100 microseconds
        
        // GpioDataRegs.GPATOGGLE.bit.GPIO6 = 1;		// Set pin 6 to HIGH
		// result_iq = sqrt_iq(x_iq);					// Compute sqrt(x) using IQ math
		// result_float = _IQtoF(result_iq);			// Convert result to float 
        // GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;		// Set pin 6 to LOW
	}
}
