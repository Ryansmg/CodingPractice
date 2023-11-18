#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a=1, b=1, sum=2;
    for(int i=0; i<n; i++)
    {
        sum += a+b;
        int temp = a+b;
        a=b;
        b=temp;
    }
    printf("%d\n%d", sum, b);
}