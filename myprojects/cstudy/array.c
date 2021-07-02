#include <stdio.h>
#include <stdlib.h>

int main()
{
   /*int a = 1;
   a = a + 2;
   a = a -2;

   int b = 2;
   int c = a + b;*/

   int arr[] = {1,2,3,4};
   printf("%x\n", arr);
   
   int *p = arr;
   printf("%x", p);
   //p = p + 1;
   //printf("%d\n", *p);
   return 0;
}

