#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> in;
    for(ll i=0; i<n; i++) {
        ll a; cin >> a; in.push_back(a);
    }
    ll m = in[0];
    for(ll i : in) m = max(m, i);
    for(ll &i : in) i = m - i;
    if(!(k&1)) {
        m = in[0];
        for(ll i : in) m = max(m, i);
        for(ll &i : in) i = m - i;
    }
    for(ll i : in) cout << i << " ";
}