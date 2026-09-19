#include "functions.h"								// Include the created "functions.h" file
#include "IQmathLib.h"								// Include the "IQmathLib.h" file

float nlog_f32(float x) {                           // Natural log
    if (x > MAX_VAL_LN || x < MIN_VAL_LN) {         
        return 100.0f;                              // If the input is out of bounds, return an invalid output
    }

    int i;                                          // Declare iteration  counter variable
    float y = 1.0f - x;
    float y_old = y;
    float sum = 0.0f;
    float temp = y;
    
    for (i = 1; i < MAX_ITER; i++) {                // summation from 1 to 512 of -((1 - x)^i) / i
        sum = sum - temp;
        y_old = y_old * y;
        temp = y_old / (float) (i + 1);
    }
    
    return sum;                                     // Return the result
}

float sqrt_f32(float x) {                           // Square root
    if (x < MIN_VAL_SQRT || x > MAX_VAL_SQRT) {
        return -1.0f;                               // If the input is out of bounds, return an invalid output
    }

    int i;                                          // Declare iteration  counter variable
    float z = x - 1.0f;
    float sum = 1.0f;
    float sum_old = 1.0f;

    for (i = 1; i < MAX_ITER; i++) {                // summation from 1 to 512 of ((M + i - 1)^z) / i
        sum_old = sum_old * (M + (float) i - 1.0f) * z / (float) i;
        if (i%2 == 0) {
            sum = sum + sum_old;                    // In even iterations, we add the value
            
        } else {
            sum = sum - sum_old;                    // In odd iterations, we subtract the value
        }
    }

    return sum;                                     // Return the result
}

_iq nlog_iq(_iq x_iq) {                             // Natural log using IQ math
    if (x_iq > MAX_VAL_LN_IQ || x_iq < MIN_VAL_LN_IQ) {
        return 1677721600;                          // 100 * 2^(24) = 1677721600
    }

    int i;
    _iq y_iq = 16777216 - x_iq;
    _iq y_iq_old = y_iq;
    _iq sum_iq = 0;
    _iq temp_iq = y_iq;
    
    for (i = 1; i < MAX_ITER; i++) {
        sum_iq = sum_iq - temp_iq; 
        y_iq_old = _IQmpy(y_iq_old, y_iq);
        temp_iq = y_iq_old / (i + 1);               // why?
    }
    
    return sum_iq;                                  // Return the result
}

_iq sqrt_iq(_iq x_iq) {                             // Square root using IQ math
    if (x_iq < MIN_VAL_SQRT_IQ || x_iq > MAX_VAL_SQRT_IQ) {
        return -16777216;                           // -1 * 2^(24) = -16777216
    }

    int i;
    _iq z_iq = x_iq - 16777216;
    _iq sum_iq = 16777216;
    _iq sum_iq_old = 16777216;

    for (i = 1; i < MAX_ITER; i++) {                // summation from 1 to 512 of ((M + i - 1)^z) / i
        sum_iq_old = _IQmpy(sum_iq_old, M_IQ - 16777216 + _IQ(i));
        sum_iq_old = _IQmpy(sum_iq_old, z_iq) / i;  // why?
        
        if (i%2 == 0) {
            sum_iq = sum_iq + sum_iq_old;
        } else {
            sum_iq = sum_iq - sum_iq_old;
        }
    }

    return sum_iq;                                  // Return the result
}
