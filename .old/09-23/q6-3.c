#include <stdio.h>

int main()
{
    int a, sum=0;
    for(a=10; a>=1; a--)
        sum+=(a*(11-a))*(a*(11-a));
    printf("%d", sum);
}