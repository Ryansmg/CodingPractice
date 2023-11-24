#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

ll max(ll a, ll b) {
    return a>b?a:b;
}
int main() {
    ll n,m,a,b,c,d;
    cin >> n >> m >> a >> c >> b >> d;

    if(a>c&&b>d) {cout << 0; return 0;}
    if(a>c) {cout << (d-b) * (n*m/2); return 0;}
    if(b>d) {cout << n*m*(c-a); return 0;}

    if((c-a)*2 >= d-b) { //감자를 심는 게 이득
        cout << n * m * (c-a);
    }
    else { //옥수수를 심는 게 이득
        ll s=0;
        s += (d-b) * (n*m/2);
        s += n*m%2*(c-a);
        cout << s;
    }
}