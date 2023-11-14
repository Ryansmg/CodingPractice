#include <stdio.h>
char d[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int f(int n, int k)
{
    if(n<k) printf("%c", d[n]);
    else {f(n/k, k); printf("%c", d[n%k]);}
}
int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    f(n,k);
    return 0;
}