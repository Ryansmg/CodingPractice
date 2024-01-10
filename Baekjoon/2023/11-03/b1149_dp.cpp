#include <stdio.h>
#include <vector>
using namespace std;

//RGB거리

int min(int a, int b) { return (a>b)?b:a; }
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> r(n), g(n), b(n); //i번째 집을 r/g/b로 칠했을 때 1~i를 칠하는 최소 비용
    vector<int> rc, gc, bc; //i번째 집을 칠하는데 드는 비용
    for(int i=0; i<n; i++)
    {
        int a, b, c;
        scanf(" %d %d %d", &a, &b, &c);
        rc.push_back(a);
        gc.push_back(b);
        bc.push_back(c);
    }
    r[0] = rc[0];
    g[0] = gc[0];
    b[0] = bc[0];
    for(int i=1; i<n; i++)
    {
        r[i] = min(g[i-1], b[i-1]) + rc[i];
        b[i] = min(r[i-1], g[i-1]) + bc[i];
        g[i] = min(r[i-1], b[i-1]) + gc[i];
    }

    printf("%d", min(min(r[n-1], g[n-1]), b[n-1]));
}