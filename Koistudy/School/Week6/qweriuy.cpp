#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll minn = -9223372036854775807;
    ll maxn = -9223372036854775807;
    ll n, l; cin >> l >> n;
    for(int i=0; i<n; i++) {
        ll a; cin >> a;
        minn = max(minn, min(a, l-a));
        maxn = max(maxn, max(a, l-a));
    }
    cout << minn << " " << maxn;
}
