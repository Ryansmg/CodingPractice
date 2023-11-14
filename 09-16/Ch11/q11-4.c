#include <stdio.h>

int value(int m)
{
    return m*m;
}

void reference(int *p)
{
    *p = *p * *p;
}

int main()
{
    int n, ans1, ans2;
    scanf("%d", &n);
    ans1 = value(n);
    reference(&n);
    ans2 = n;

    printf("%d %d", ans1, ans2);
}