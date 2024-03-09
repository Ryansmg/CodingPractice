#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll max(ll a, ll b) {
    return a>b?a:b;
}
int main() {
    ll n, ans=0;
    cin >> n;
    ll pre, now = 1, maxlen = 0;
    for(ll i=0; i<n; i++) {
        ll a; cin >> a;
        pre=now; now=a;
        maxlen = max(maxlen, now-pre);
    }
    ll m; cin >> m;
    for(ll i=0; i<m; i++) {
        ll a; cin >> a;
        if(a>=maxlen) ans++;
    }
    cout << ans;

}