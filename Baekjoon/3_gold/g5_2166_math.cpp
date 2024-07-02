#include <iostream>
#define ll long long
#define ld long double
using namespace std;

ld ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll c = (x2-x1) * (y3-y1) - (x3-x1) * (y2-y1);
    return c / 2.0L;
}

int main()
{
    ll n;
    cin >> n;
    ll sx, sy;
    cin >> sx >> sy;
    ld ans = 0;
    ll prex, prey;
    cin >> prex >> prey;
    for(int i=2; i<n; i++) {
        ll nowx, nowy;
        cin >> nowx >> nowy;
        ans += ccw(sx, sy, prex, prey, nowx, nowy);
        prex = nowx;
        prey = nowy;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(ans);
}