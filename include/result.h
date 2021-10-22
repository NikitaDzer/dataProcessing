#ifndef RESULT_H
#define RESULT_H

#include "global.h"

Error result(float *resistance, size_t data_size,
             float *const p_resistance_final, float *const p_deviation);

#endif // RESULT_H