#include <bits/stdc++.h>
#define int long long
#define llmax 9223372036854775807
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
int input() { int t; cin >> t; return t;}

int getlen(int i) {
    int t=1, ans=0;
    while(t<=i) { t*=10; ans++; }
    return t;
}

signed main()
{
    fastio
    int n = input(), div = 998244353;
    vector<int> in, w(n,0);
    __int128 ans = 0;
    for(int i=0; i<n; i++) in.push_back(input());
    reverse(in.begin(), in.end());
    for(int i=0; i<n-1; i++)
        w[i+1] += getlen(in[i]);
    for(int i=1; i<n; i++)
        w[i] += w[i-1];
    for(int i=0; i<n; i++)
        w[i] += n-i-1;
    for(int i=0; i<n; i++) {
        ans = (ans + ((__int128)in[i] * w[i]));
    }
    cout << (long long)(ans % div);
}
