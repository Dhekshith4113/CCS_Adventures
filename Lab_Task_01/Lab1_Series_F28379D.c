#include "F28x_Project.h"
#include "functions.h"

float x = 0.73f;
float result_f32 = 0.0f;

void main(void)
{
	InitSysCtrl();

	while(1) {
		DELAY_US(100);
		// result_f32 = nlog_f32(x);
		result_f32 = sqrt_f32(x);
	}
}
