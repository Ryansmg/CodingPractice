#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    i64 n, m;
    cin >> n >> m;
    vector<i64> endTime(n, 0);
    vector<vector<i64>> ans(n);
    for(int i = 1; i <= m; i++) {
        i64 idx = -1, minTime = 2147481557, a;
        cin >> a;
        for(int j = 0; j < n; j++) if(endTime[j] < minTime) idx = j, minTime = endTime[j];
        ans[idx].push_back(i);
        endTime[idx] += a;
    }
    for(int i = 0; i < n; i++) {
        for(i64 j : ans[i]) cout << j << " ";
        cout << "\n";
    }
}