#include "F28x_Project.h"
#include "functions.h"								// Include the created "functions.h" file

float x = 0.73f;									// Add a test variable
float result_f32 = 0.0f;							// Define a variable to store the result

void main(void)
{
	InitSysCtrl();									// Initialize the microcontroller

	EALLOW;
	GpioCtrlRegs.GPAGMUX2.bit.GPIO25 = 0;			// 
	GpioCtrlRegs.GPAMUX2.bit.GPIO25  = 0;  			// 
	GpioCtrlRegs.GPADIR.bit.GPIO25   = 1;			// Set direction as output
	EDIS;

	while(1) {
		// DELAY_US(100);								// Wait for 100 microseconds
		
		// GpioDataRegs.GPASET.bit.GPIO25 = 1;			// Set pin 6 to HIGH
		// result_f32 = nlog_f32(x);					// Compute ln(x)
		// GpioDataRegs.GPACLEAR.bit.GPIO25 = 1;		// Set pin 6 to LOW

		DELAY_US(100);								// Wait for 100 microseconds
		
		GpioDataRegs.GPASET.bit.GPIO25 = 1;			// Set pin 6 to HIGH
		result_f32 = sqrt_f32(x);					// Compute sqrt(x)
		GpioDataRegs.GPACLEAR.bit.GPIO25 = 1;		// Set pin 6 to LOW
	}
}
