#include <stdio.h>
#include "../include/global.h"
#include "../include/preparations.h"
#include "../include/select.h"
#include "../include/result.h"
#include "../include/check.h"

int main() {
   const char inputFile_path[] = "../input.txt";
   float resistance[DATA_MAX_SIZE];
   float resistance_final = 0;
   size_t data_size = 0;
   
   preparations(inputFile_path, resistance, &data_size);
   
   data_size = DataSelect(data_size, resistance);
   
   MasOut(resistance, data_size);
   
   result(data_size, resistance, &resistance_final);
   
   
   check(data_size, resistance, resistance_final);
   
   return 0;
}
