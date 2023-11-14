#include <stdio.h>

int main()
{
    int n, ans = -1;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int a, b, c, score;
        scanf(" %d %d %d", &a, &b, &c);
        if(a==b && b==c) score = 10000 + a*1000;
        else if(a==b) score = 1000 + a*100;
        else if(b==c) score = 1000 + b*100;
        else if(c==a) score = 1000 + c*100;
        else {
            int max = (a>b) ? a : b;
            max = (max > c) ? max : c;
            score = max * 100;
        }
        if(score > ans) ans = score;
    }
    printf("%d", ans);
}