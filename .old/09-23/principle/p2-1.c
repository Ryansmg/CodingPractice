#include <stdio.h>

int main()
{
    int a, b, ab, gcd;
    scanf("%d %d", &a, &b);
    ab = a*b;
    while(a!=0 && b!=0)
    {
        if(a>b) a -= b;
        if(b>=a) b -= a;
    }
    gcd = (a==0) ? b : a;
    printf("%d %d", gcd, ab/gcd);
}
