#include "IQmathLib.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_ITER 512

///// Natural Logarithm /////
#define MAX_VAL_LN 1
#define MIN_VAL_LN 0.36788

float nlog_f32(float x);

///// Square Root /////
#define MAX_VAL_SQRT 1
#define MIN_VAL_SQRT 0
#define M -0.5f

float sqrt_f32(float x);

///// Natural Logarithm IQ/////
#define MAX_VAL_LN_IQ 16777216          // 1 * 2^(24) = 16777216
#define MIN_VAL_LN_IQ 6171993           // (1/e) * 2^(24) = 6171993

_iq nlog_iq(_iq x);

///// Square Root IQ/////
#define MAX_VAL_SQRT_IQ 16777216        // 1 * 2^(24) = 16777216
#define MIN_VAL_SQRT_IQ 0
#define M_IQ -8388608                   // -0.5 * 2^(24) = -8388608

_iq sqrt_iq(_iq x);

#endif
