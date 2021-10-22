#include "../include/select.h"
#include <stdio.h>
#include <math.h>



//R - resistance
float Averange(int Num, float R[])
{
   if (R == NULL)
      return 0;
   
   float Sum = 0;
   int i = 0;
   
   for (i = 0; i < Num; i++)
      Sum += R[i];
   
   return Sum/Num;
}

void DeletEl(float R[], int Num)
{
   if(R == NULL)
      return;
   
   int i = 0;
   
   for (i = 1; i < Num; i++)
      R[i - 1] = R[i];
   
   R[Num - 1] = 0;
}


int DataSelect(int Num, float R[])
{
   if(R == NULL)
      return 0;
   
   int i = 0, K = 0;
   float averange = Averange(Num, R);
   
   for (i = 0; i < Num; i++)
      if(fabs((R[i] - averange)/averange) > 0.03)
      {
         DeletEl(&(R[i]), Num - i - 1);
         K++;
      }
   
   return Num - K;
}

void MasOut (float *a, int Size)
{
   if (a == NULL)
      return;
   
   int i = 0;
   for(i = 0; i < Size; i++)
      printf("%.5lf  ", a[i]);
   printf("\n");
}
