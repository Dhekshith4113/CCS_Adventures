#include "F28x_Project.h"

void main(void)
{
   InitSysCtrl();					      				// Initialize the microcontroller
   
   EALLOW;
   GpioCtrlRegs.GPAGMUX2.bit.GPIO31 = 0;        //
   GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;         //
   GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;				// Set direction as output

   GpioCtrlRegs.GPBGMUX1.bit.GPIO34 = 0;        //
   GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;         //
   GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;				// Set direction as output
   EDIS;

   for(;;) {
      GpioDataRegs.GPASET.bit.GPIO31 = 1;		   // Set pin 31 to HIGH
      DELAY_US(500000);								   // Wait for 0.5 sec
		GpioDataRegs.GPACLEAR.bit.GPIO31 = 1;		// Set pin 31 to LOW
      DELAY_US(1000000);   							// Wait for 1 sec

      GpioDataRegs.GPBSET.bit.GPIO34 = 1;		   // Set pin 34 to HIGH
      DELAY_US(500000);								   // Wait for 0.5 sec
		GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;		// Set pin 34 to LOW
      DELAY_US(1000000);   							// Wait for 1 sec
   }
}
