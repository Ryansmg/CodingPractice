#include <stdio.h>

int power(int a, int b);

int main()
{
    int n;
    scanf("%d", &n);
    int size = -1;
    while(power(10, ++size) <= n) {} //872, size=3
    for(int i=0; i<size; i++)
    {
        printf("%d", (n%power(10,i+1))/power(10,i));
    }
}

int power(int a, int b)
{
    int ans = 1;
    for(int i=0; i<b; i++) ans *= a;
    return ans;
}