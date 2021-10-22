//
// Created by User on 22.10.2021.
//

#include <stdio.h>
#include "../include/check.h"

float check (int K, float resistance[], float resistance_final)
{
   int i;
   float sum = 0;
   for (i=0; i<K; i++){
      sum += resistance[i];
   }
   float rez;
   rez = (sum - K * resistance_final)/K;
   
   printf("\n%f", rez);
   
   return rez;
}