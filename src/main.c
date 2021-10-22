#include <stdio.h>
#include "../include/global.h"
#include "../include/preparations.h"
#include "../include/select.h"

int main() {
   const char inputFile_path[] = "../input.txt";
   float resistance[DATA_MAX_SIZE];
   size_t data_size = 0;
   
   preparations(inputFile_path, resistance, &data_size);
   
   data_size = DataSelect(data_size, resistance);
   
   
   
   return 0;
}
