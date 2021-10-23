#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stddef.h>

#define DATA_MAX_SIZE 100

typedef enum {
   NOERR,
   INPUT_PATH_NULL,
   INPUT_FILE_NOT_OPENED,
   ARGUMENT_POINTER_NULL,
} Error;

Error check(const float *const resistance, const size_t data_size,
            const float resistance_final, float *const p_meanDeviation);

Error result(float *resistance, size_t data_size,
             float *const p_resistance_final, float *const p_deviation);

Error select(float *const resistance, size_t *const p_data_size);

Error preparations(const char *const inputFile_path, float *const resistance, size_t *const data_size);


#endif // FUNCTIONS_H
