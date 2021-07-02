#include <stdio.h>
#include <stdlib.h>

void func1(int ** pp2)

{
   int * m  = (int *) malloc(4);
   *m = 10;
   *pp2 = m;
}


int main()
{   
	int * p1;
        int **pp2 = &p1;
//int *p1;
//	const int n = 13;
//	pp2 = &p1; // allowed, but const qualifier disregarded
//	*pp2 = &n; // valid, both const, but sets p1 to point at n
//	*p1 = 10; // valid, but tries to change const n
	func1(pp2);
	printf("n:%d", **pp2);
	free(p1);
	return 0;
}




int main_02()
{
   const int n = 13;
   int *p = &n;
   *p  = 10;
   printf("%d", *p);
   return 0;
}
