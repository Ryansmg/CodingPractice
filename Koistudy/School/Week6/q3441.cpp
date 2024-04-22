#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    int q, w, e2, r, t, y; cin >> q >> w >> e2 >> r >> t >> y;
    int n1 = (a<<5)+(b<<4)+(c<<3)+(d<<2)+(e<<1)+f;
    int n2 = (q<<5)+(w<<4)+(e2<<3)+(r<<2)+(t<<1)+y;
    int tt = 5;
    if(n1+n2>=64) tt++;
    for(int i = tt; i>=0; i--) {
        cout << (((n1+n2)&(1<<i))?1:0);
    }
}