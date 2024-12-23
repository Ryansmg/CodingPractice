#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fastio cin.tie(0);cout.tie(0)->sync_with_stdio(0);
#define pb push_back
#define pf push_front
#define fs first
#define sc second
#define pii pair<int,int>
#define MP make_pair
#define fileio filein; fileout
#define filein freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\input.txt)", "r", stdin)
#define fileout freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "w", stdout)
using namespace std;
int main(){
    fastio; fileio;
    int t;
    cin >> t;;
    while(t--){
        ll n,m,k;
        cin >> n >> m >> k;
        vector<ll> v(n);
        ll sum = 0;
        for(int i = 0; i<n; i++){
            cin >> v[i];
            sum += v[i];
        }
        vector<ll> v1 = v;
        sort(v1.begin(),v1.end());
        ll ans = 0;
        for(int i = 0; i<n; i++){
            ll s = sum - v[i];

            ll a1 = s-m;
            ll a2 = s-k;

            int i1 = upper_bound(v1.begin(),v1.end(),min(a1,v1[n-2]))-v1.begin();
            int i2 = lower_bound(v1.begin(),v1.end(),max(a2,v1[0]))-v1.begin();

            // cout << a1 << ' ' << a2 << '\n';
            // cout << v1[i1] << ' ' << v1[i2] << '\n';
            // cout << '\n';
            if(v1[i1] > v[i] && v1[i2] <= v[i]){
                i2++;
            }
            ans += max(0,i1-i2);
        }
        cout << ans/2 << '\n';
    }
}