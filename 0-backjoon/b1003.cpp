#include <stdio.h>

int main()
{
    int t;
    int ans0[41];
    int ans1[41];
    ans0[0] = 1; ans0[1] = 0;
    ans1[0] = 0; ans1[1] = 1;
    for(int i=2; i<41; i++)
    {
        ans0[i] = ans0[i-1] + ans0[i-2];
        ans1[i] = ans1[i-1] + ans1[i-2];
    }
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        int a;
        scanf(" %d", &a);
        printf("%d %d\n", ans0[a], ans1[a]);
    }
}