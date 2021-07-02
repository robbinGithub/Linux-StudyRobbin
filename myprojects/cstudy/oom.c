#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
  unsigned long long size =  4 * 1024 * 1024 * 1024;	
  char * p =  malloc(size);
  memset(p, 0, size);
  if(p == NULL) {
     printf("%s", "malloc error");
     exit(0);
  }
  *p = 56;
  sleep(100000000);
  printf("%s","END"); 
}
