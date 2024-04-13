#include <bits/stdc++.h>
using namespace std;
#define u unsigned
#define l long
#define ll l l
#define ull u ll

int main()
{
    vector<ll> a;
    ll n; cin >> n;
    for(ll i=0; i<n; i++){
        ll asdf; cin >> asdf; a.push_back(asdf);
    }
    ll b, c;
    cin >> b >> c;
    c /= b;
    ll ans=0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++) {
                if(a[i]+a[j]+a[k]<=c) ans++;
            }
        }
    }
    cout << ans;
}