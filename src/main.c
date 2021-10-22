#include <stdio.h>
#include "../include/global.h"
#include "../include/preparations.h"

int main() {
   const char inputFile_path[] = "../input.txt";
   float resistance[DATA_MAX_SIZE];
   size_t data_size = 0;
   
   preparations(inputFile_path, resistance, &data_size);
   
   return 0;
}
