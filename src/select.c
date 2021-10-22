#include <stdio.h>
#include <math.h>
#include "../include/select.h"

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
