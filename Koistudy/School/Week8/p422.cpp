#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    vector<int> ans(21, 0);
    vector<int> ans2(21, 0);
    int n; cin >> n;
    int t; cin >> t; ans[t] = 1;
    for(int i=1; i<n-1; i++) {
        cin >> t;
        for(int j=0; j<21; j++) {
            if(j-t>=0) ans2[j] += ans[j-t];
            if(j+t<21) ans2[j] += ans[j+t];
        }
        ans = ans2;
        vector<int> zero(21, 0);
        ans2 = zero;
    }
    cin >> t;
    cout << ans[t];
}
