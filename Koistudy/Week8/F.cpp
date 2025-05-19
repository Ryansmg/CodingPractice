#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using f64 = double;
#define forn(i, n) for(i64 i = 0; i < n; i++)
#define forf(i, a, b) for(i64 i = a; i <= b; i++)
#define all(v) (v).begin(), (v).end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define in ([]()->i64{i64 a;cin>>a;return a;}())

struct sq {
    int arr[100010]{}, bucket[185]{};
    int q = 600;
    void add(int pos, int val) {
        arr[pos] += val; bucket[pos/q] += val;
    }
    i64 query(int l, int r) {
        i64 ret = 0;
        for(; l % q && l <= r; l++) ret += arr[l];
        for(; (r + 1) % q && l <= r; r--) ret += arr[r];
        for(; l <= r; l += q) ret += bucket[l / q];
        return ret;
    }
};

int main() {
    i64 n = in;
    i64 p1 = in, p2 = in, p3 = in, p4 = in;
    vector<pair<i64, i64>> ps;
    vector<i64> x, y;
    forn(i, n) {
        int a = in, b = in;
        ps.emplace_back(a, b);
        x.push_back(a); y.push_back(b);
    }
    sort(all(x)), x.erase(unique(all(x)), x.end());
    sort(all(y)), y.erase(unique(all(y)), y.end());
    for(auto& p : ps) {
        p.first = lower_bound(all(x), p.first) - x.begin() + 1;
        p.second = lower_bound(all(y), p.second) - y.begin();
    }
    vector<vector<i64>> arr(y.size());
    sq up, down;
    i64 ans = -9223372036854775808;
    for(const auto& p : ps) arr[p.second].push_back(p.first), up.add(p.first, 1);
    forn(i, int(y.size())) {
        for(i64 x : arr[i]) up.add(x, -1);

        for(i64 x : arr[i]) {
            i64 c1 = up.query(x + 1, 100001);
            i64 c2 = up.query(0, x - 1);
            i64 c3 = down.query(0, x - 1);
            i64 c4 = down.query(x + 1, 100001);
            ans = max(ans, c1 * p1 + c2 * p2 + c3 * p3 + c4 * p4);
        }

        for(i64 x : arr[i]) down.add(x, 1);
    }
    cout << ans << '\n';
}
