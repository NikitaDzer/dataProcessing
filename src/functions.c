#include <stdio.h>
#include <math.h>
#include "../include/functions.h"

Error check(const float *const resistance, const size_t data_size,
            const float resistance_final, float *const p_meanDeviation)
{
   if (resistance == NULL || p_meanDeviation == NULL)
      return ARGUMENT_POINTER_NULL;
   
   size_t index = 0;
   float sum = 0;
   
   for (index = 0; index < data_size; index++)
      sum += resistance[index];
   
   *p_meanDeviation = (sum * 1000 - data_size * resistance_final) / data_size;
   
   return NOERR;
}

Error preparations(const char *const inputFile_path, float *const resistance, size_t *const p_data_size)
{
   if (inputFile_path == NULL)
      return INPUT_PATH_NULL;
   
   if (p_data_size == NULL)
      return ARGUMENT_POINTER_NULL;
   
   FILE *const inputFile = fopen(inputFile_path, "r");
   
   if (inputFile == NULL)
      return INPUT_FILE_NOT_OPENED;
   
   float voltage[DATA_MAX_SIZE],
           current[DATA_MAX_SIZE];
   size_t data_size = 0,
           index     = 0;
   
   while (fscanf(inputFile,"%f%*c%f", voltage + data_size, current + data_size) == 2)
      data_size++;
   
   for (index = 0; index < data_size; index++)
      resistance[index] = voltage[index] / current[index];
   
   *p_data_size = data_size;
   
   return NOERR;
}

Error result(float *resistance, size_t data_size,
             float *const p_resistance_final, float *const p_deviation)
{
   if (resistance == NULL || p_resistance_final == NULL || p_deviation == NULL)
      return ARGUMENT_POINTER_NULL;
   
   size_t index = 0;
   float resistance_final = 0,
           deviation        = 0,
           temp             = 0,
           sum              = 0;
   
   for (index = 0; index < data_size; index++)
      resistance_final += resistance[index];
   resistance_final /= data_size;
   
   for (index = 0; index < data_size; index++)
   {
      temp  = resistance[index] - resistance_final;
      sum  += temp * temp;
   }
   
   deviation = sqrt(sum) / data_size;
   
   *p_resistance_final = resistance_final * 1000;
   *p_deviation        = deviation * 1000;
   
   return NOERR;
}

static float calc_averange(float *const resistance, const size_t data_size)
{
   float sum = 0;
   int index = 0;
   
   for (index = 0; index < data_size; index++)
      sum += resistance[index];
   
   return sum / data_size;
}

static void delete_element(float *const resistance, const size_t data_size)
{
   size_t index = 0;
   for (index = 1; index <= data_size; index++)
      resistance[index - 1] = resistance[index];
   
   resistance[data_size - 1] = 0;
}

Error select(float *const resistance, size_t *const p_data_size)
{
   if (resistance == NULL || p_data_size == NULL)
      return ARGUMENT_POINTER_NULL;
   
   size_t index = 0;
   float averange = calc_averange(resistance, *p_data_size);
   
   for (index = 0; index < *p_data_size; index++)
      if (fabs((resistance[index] - averange) / averange) > 0.03)
         delete_element(resistance + index, (*p_data_size)-- - index);
   
   return NOERR;
}