#include <stdio.h>

int main()
{
    int a, n, sum;
    printf("a = ");
    scanf("%d", &a);
    printf("n = ");
    scanf( "%d", &n);

    sum = a;

    for(int i=0; i<n-1; i++){
        a *= 3;
        sum += a;
    }

    printf("s = %d", sum);
}