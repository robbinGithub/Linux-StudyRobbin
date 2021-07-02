#include <stdio.h>
#include <stdlib.h>

//char * g = "goods";
//char d1 = 'x';
//char d2 = 'y';

int main()
{
   char * c = "abcd";
   char a[] = {'A', 'B', 'C', 'D'};
   printf("%c\n",*(a+1));
   char * cn = "中国";
   char * end = "abcd";

   int arr[] = {1,2,3,4};
   //arr = (int *) (arr + 1);
   int *p = arr;
   p = p + 1;
   printf("%d\n", *p);


   int arr1 [100] = {};
   //int arr2 [100] = malloc(sizeof(int) * 100);
   int * arr3 = (int *)malloc(sizeof(int) * 100);
   arr3 = arr3 + 1;
   printf("arr3 + 1 value:%d\n", *arr3);

   //c = "cdef";
   //char *p = c;
   //*(p + 1) ='a';
   printf("%s\n",cn);
}

