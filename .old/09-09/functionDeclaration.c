#include <stdio.h>

void switchInt(int *a, int *b);
int main()
{
    int a=10, b=20;
    printf("%d %d\n", a, b);
    switchInt(&a, &b);
    printf("%d %d", a, b);
}

void switchInt(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}