#include <stdio.h>
#include <math.h>
#include "../include/result.h"

float result (int K, float *resistance)
{
   float resistance_final = 0, devitation = 0;
   
   int i = 0;
   for(i = 0; i < K; i++)
      resistance_final += resistance[i];
   resistance_final /= K;
   
   
   float sum = 0;
   for(i = 0; i < K; i++)
      sum += (resistance[i]-resistance_final) * (resistance[i]-resistance_final);
   devitation = sqrt(sum) / K;
   
   printf("%7.5f +- %7.5f", resistance_final, devitation);
   
   return resistance_final;
}