#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    vector<ll> a(1,0), b(1,0);
    int an, bn; cin >> an;
    ll temp; cin >> temp; a.push_back(temp);
    for(int i=1; i<an; i++) {
        cin >> temp; a.push_back(a.back() + temp);
    }
    cin >> bn;
    cin >> temp; b.push_back(temp);
    for(int i=1; i<bn; i++) {
        cin >> temp; b.push_back(b.back() + temp);
    }
    vector<ll> as, bs;
    for(int i=0; i<=an; i++) {
        for(int j=i+1; j<=an; j++) as.push_back(a[j] - a[i]);
    }
    for(int i=0; i<=bn; i++) {
        for(int j=i+1; j<=bn; j++) bs.push_back(b[j] - b[i]);
    }
    sort(bs.begin(), bs.end());
    ll ans = 0, size = as.size();
    for(int i=0; i<size; i++) {
        ll target = t - as[i];
        ll n = upper_bound(bs.begin(), bs.end(), target) - lower_bound(bs.begin(), bs.end(), target);
        ans += n;
    }
    cout << ans;
}