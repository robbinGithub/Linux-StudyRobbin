#include <stdio.h>
#include <stdlib.h>

//char * g = "goods";
//char d1 = 'x';
//char d2 = 'y';

int main()
{
   int  c = 100;
   int *p =&c;
   printf("%p\n", p);
   printf("%p\n",*((void**)p));
   
}
