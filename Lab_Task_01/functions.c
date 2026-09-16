#include "functions.h"

float nlog_f32(float x) {
    if (x > MAX_VAL_LN || x < MIN_VAL_LN) {
        return 100.0f;
    }

    int i;
    float y = 1.0f - x;
    float y_old = y;
    float sum = 0.0f;
    float temp = y;
    
    for (i = 1; i < MAX_ITER; i++) {
        sum = sum - temp; 
        y_old = y_old * y;
        temp = y_old / (float) (i + 1);
    }
    
    return sum;
}

float sqrt_f32(float x) {
    if (x < MIN_VAL_SQRT || x > MAX_VAL_SQRT) {
        return -1.0f;
    }

    int i;
    float z = x - 1.0f;
    float sum = 1.0f;
    float sum_old = 1.0f;

    for (i = 1; i < MAX_ITER; i++) {
        if (i%2 == 0) {
            sum_old = sum_old * (M + i - 1) * z / i;
            sum = sum + sum_old;
            
        } else {
            sum_old = sum_old * (M + i - 1) * z / i;
            sum = sum - sum_old;
        }
    }

    return sum;
}
