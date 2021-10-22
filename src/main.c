#include <stdio.h>
#include "../include/global.h"
#include "../include/preparations.h"
#include "../include/select.h"
#include "../include/result.h"
#include "../include/check.h"

int main() {
   const char inputFile_path[] = "../Test4.txt";
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
