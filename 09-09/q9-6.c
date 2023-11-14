#include <stdio.h>

int gcm(int x, int y)
{
    int max = (x>y) ? x : y, i;
    for(i=max; i>=1; i--)
    {
        if(x%i==0 && y%i==0) return i;
    }
}

int lcm(int x, int y)
{
    return x * y / gcm(x,y);
}

int main()
{
    int a=8, b=12;
    printf("%d\n", gcm(a,b));
    printf("%d", lcm(a,b));
}