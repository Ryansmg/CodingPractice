#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define llmax 9223372036854775807
ll input() {
    ll t; cin >> t; return t;
}

int main()
{
    ll n; cin >> n;
    ll ans = -1;
    vector<ll> pre(1,0);
    for(int i=0; i<n; i++) {
        vector<ll> now;
        for(int j=0; j<=i; j++) now.push_back(input());
        for(int j=0; j<=i; j++) {
            if(j==0) {
                now[j] += pre[0];
            }
            else if(j==i) {
                now[j] += pre[j-1];
            }
            else {
                now[j] += max(pre[j], pre[j-1]);
            }
            ans = max(now[j], ans);
        }
        pre = now;
    }
    cout << ans;
}