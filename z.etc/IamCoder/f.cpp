#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

struct tri{
    ll a, b, c;
    tri(){}
    tri(ll x, ll y, ll z) {
        a=x;b=y;c=z;
    }
};

bool cmp(ll a, ll b) {
    return a>b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<tri> walls;
    int n;
    cin >> n;
    ll ta, tb, tc;
    for(int i=0; i<n; i++) {
        cin >> ta >> tb >> tc;
        walls.emplace_back(ta, tb, tc);
    }
    int m;
    ll px, py;
    cin >> m; //1
    for(int i=0; i<m; i++) {
        cin >> px >> py;
    }
    if(n==0) cout << py;
    if(n==0) return 0;
    vector<ll> wp;
    for(tri as : walls) {
        if(as.a <= px && px <= as.b && py > as.c) wp.push_back(as.c);
    }
    sort(wp.begin(), wp.end(), cmp);
    ll ans = 0;
    ans += py - wp[0];
    ll time = 2;
    ll wpsz = wp.size();
    for(ll i = 0; i<wpsz-1; i++) {
        ans += wp[i+1] - wp[i];
    }
    ans += wp[wp.size()-1] * time;
    cout << ans;
}
