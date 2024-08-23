#include <bits/stdc++.h>
using namespace std;
#define int long long

// 2 3 5 7 10 : a
// 0 2 3 5 7 : x
// 2 1 2 2 3 : b
// a[0] = b[0]
// a[1] = b[1] + max(a[0])
// a[2] = b[2] + max(a[0], a[1])

signed main()
{
    int n; cin >> n;
    vector<int> b;
    for(int i=0; i<n; i++) {
        int t; cin >> t; b.push_back(t);
    }
    vector<int> a; int maxn = b[0];
    a.push_back(b[0]);
    for(int i=1; i<n; i++) {
        maxn = max(maxn, a[i-1]);
        a.push_back(b[i] + maxn);
    }
    for(int i : a) cout << i << " ";
}