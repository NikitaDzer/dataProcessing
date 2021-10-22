#include <stdio.h>
#include <math.h>
#include "../include/result.h"

enum Error result (int K, float *resistance, float *resistance_final)
{
   if (resistance != NULL || resistance_final != NULL)
   {
      float resistance_finally = 0;
   
      int i = 0;
      for(i = 0; i < K; i++)
         resistance_finally += resistance[i];
      resistance_finally /= K;
      
      float devitation = 0, sum = 0;
      for(i = 0; i < K; i++)
         sum += (resistance[i]-resistance_finally) * (resistance[i]-resistance_finally);
      devitation = sqrt(sum) / K;
      
      printf("%7.5f +- %7.5f", resistance_finally * 1000, devitation * 1000);
      
      *resistance_final = resistance_finally;
      
      return NOERR;
   }
   else
      return ARGUMENT_POINTER_NULL;
}