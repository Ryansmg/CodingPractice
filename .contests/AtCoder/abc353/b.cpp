#include <bits/stdc++.h>
#define int long long
#define llmax 9223372036854775807
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int input() { int t; cin >> t; return t;}

signed main()
{
    //fastio
    int n, k; cin >> n >> k;
    int l = k;
    int ans = 0;
    for(int i=0; i<n; i++) {
        int t = input();
        if(l>=t) l-=t;
        else {
            ans++;
            l=k-t;
        }
    }
    if(l!=k) ans++;
    cout << ans;
}