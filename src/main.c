#include <stdio.h>
#include "../include/functions.h"

int main() {
   const char inputFile_path[] = "../Test1.txt";
   size_t data_size = 0;
   float resistance[DATA_MAX_SIZE] = {},
         resistance_final          = 0,
         deviation                 = 0,
         meanDeviation             = 0; 
   
   preparations(inputFile_path, resistance, &data_size);
   
   select(resistance, &data_size);
   
   result(resistance, data_size, &resistance_final, &deviation);
   
   check(resistance, data_size, resistance_final, &meanDeviation);

   printf("| R = (%.4f +- %.4f) Om; sigma = %.4f |\n",
          resistance_final, deviation, meanDeviation);
   
   return 0;
}
