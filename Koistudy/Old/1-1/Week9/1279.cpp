#include <bits/stdc++.h>

int f(int i) {
    int ans = 1;
    while(i>1 && ans++)
        i = (i&1) ? 3*i+1 : i/2;
    return ans;
}

void g(int &a, int &b)  // reference를 이용한 전달
{
    int t;
    t = a;
    a = b;
    b = t;
}

int get_max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int a, b, ans = 0;
    scanf("%d%d", &a, &b);
    if( a > b )
        g(a, b);

    for(int i = a ; i <= b ; i++ )
        ans = get_max( ans, f(i) );

    printf("%d", ans);
    return 0;
}