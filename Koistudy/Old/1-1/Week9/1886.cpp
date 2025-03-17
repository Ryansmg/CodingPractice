#include <cstdio>
#include <algorithm>

int n, k, d[1010];

int upper_bound(int a) {
    return (int)(std::upper_bound(d+1, d+1+n, a) - d);
}

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d", &d[i]);

    scanf("%d", &k);

    printf("%d\n", lower_bound(k));
}