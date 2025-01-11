#include <bits/stdc++.h>
#define int long long
#define llmax 9223372036854775807
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define div 100000000

int input() { int t; cin >> t; return t;}
signed main()
{
    fastio
    int n = input();
    vector<int> in;
    int ans = 0;
    for(int i=0; i<n; i++) {
        int t = input();
        in.push_back(t);
        ans += t*(n-1);
    }
    sort(in.begin(), in.end());
    int add = 0;
    for(int i=0; i<n; i++) {
        add += (in.end() - lower_bound(in.begin(), in.end(), div-in[i]));
        if(in[i]*2>=div) add--;
    }
    cout << ans - add/2*div;
}