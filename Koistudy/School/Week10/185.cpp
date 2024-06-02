#include <bits/stdc++.h>
#define int long long
using namespace std;

map<pair<int, int>, int> dp;

int solve(int n, int r) {
    if(n==r || r==0) return 1;
    if(n<r) return 0;
    if(r==1) return n;
    auto f = dp.find({n, r});
    if(f != dp.end()) return f->second;
    int t = solve(n-1, r-1) + solve(n-1, r);
    dp.insert({{n, r}, t});
    return t;
}

signed main() {
    int n, r; cin >> n >> r; cout << solve(n, r);
}