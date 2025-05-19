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
    i64 arr[100010]{}, bucket[180]{};
    int q = 600;
    void add(int pos, i64 val) {
        arr[pos] += val; bucket[pos/q] = max(bucket[pos/q], val);
    }
    i64 query(int l, int r) {
        i64 ret = 0;
        for(; l % q && l <= r; l++) ret = max(ret, arr[l]);
        for(; (r + 1) % q && l <= r; r--) ret = max(ret, arr[r]);
        for(; l <= r; l += q) ret = max(ret, bucket[l / q]);
        return ret;
    }
};

#define idx(x, A) (lower_bound(all(A), x) - A.begin())

int main() {
    int n = in;
    vector<pair<int, int>> ps;
    vector<int> A, B;
    forn(i, n) {
        int a = in, b = in;
        ps.emplace_back(a, b);
        A.push_back(a); B.push_back(b);
    }
    sort(all(A)), A.erase(unique(all(A)), A.end());
    sort(all(B)), B.erase(unique(all(B)), B.end());
    vector<int> s(n);
    for(const auto& p : ps)
        s[idx(p.first, A)] = idx(p.second, B) + 1;
    int ans = 0;
    sq q;
    for(int i : s) {
        int c = q.query(0, i-1);
        ans = max(ans, c + 1);
        q.add(i, c + 1);
    }
    cout << n - ans;
}
