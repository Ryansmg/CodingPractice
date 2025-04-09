#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    i64 n, m; cin >> n >> m;
    vector<i64> ans(n, 2147438647);
    for(int i = 0; i < m; i++) {
        int t; cin >> t; ans[t-1] = 1;
    }
    for(int i = 1; i < n; i++)
        ans[i] = min(ans[i], ans[i-1] + 1);
    for(int i = n-2; i >= 0; i--)
        ans[i] = min(ans[i], ans[i+1] + 1);
    for(int i : ans) cout << i << " ";
}
