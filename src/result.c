#include <stdio.h>
#include <math.h>
#include "../include/result.h"

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