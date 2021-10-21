//
// Created by Radosław Roszczyk on 04.10.2021.
//
#include <stdio.h>

int main(int argc, char* argv[])
{
   int i;
   printf("Program działa i wypisuje parametry wywołania\n");

   for (i = 0; i < argc; ++i)
   {  
      printf("%i: %s \n", i, argv[i]);
   }
   
   return 100;
}
