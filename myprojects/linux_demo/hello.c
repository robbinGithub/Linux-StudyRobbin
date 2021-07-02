#include <stdio.h>

int g_a = 1;
int g_b = 2;

int main()
{
    int i = 5;
    int l_a = 5;
    int l_c = g_a + l_a + i;
    printf("%d\n", i);
    printf("hello world!\n");

}
