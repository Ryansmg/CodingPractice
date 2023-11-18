#include <stdio.h>
#include <math.h>

int main()
{
    int m,n,x,answer;
    printf("두 수(M, N) = ");
    scanf("%d, %d", &m, &n);
    printf("자리수(X) = ");
    scanf("%d", &x);

    printf("계산값 = ");
    printf("%d.", m/n);

    for(int i=0; i<x; i++)
    {
        m = (m%n)*10;
        printf("%d", m/n);
    }
}