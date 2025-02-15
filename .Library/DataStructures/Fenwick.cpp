/* Update : 2025-02-11 */

#include <vector>

/// 1-based index
template <typename T = long long> struct Fenwick {
    std::vector<T> tree; signed n;
    explicit Fenwick(signed treeSize) { n = treeSize; tree = std::vector<T>(treeSize+10, T()); }
    inline void add(signed tar, const T& val) { if(tar <= 0) { return; } for(; tar<=n; tar+=tar&-tar) tree[tar] += val; }
    /// [l, r]
    inline T query(signed left, signed right) { if(left > right) { return T(); } left = std::max(left, 1); return query(right) - query(left-1); }
    /// [1, tar]
    inline T query(signed tar) { T ans = T(); for(; tar; tar-=(tar&-tar)) ans += tree[tar]; return ans; }
};

// Example : BOJ 2042. 구간 합 구하기
#include <iostream>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long n, m, k, t; cin >> n >> m >> k;
    Fenwick seg(n);
    for(int i = 1; i <= n; i++) {
        cin >> t; seg.add(i, t);
    }
    for(int i = 0; i < m + k; i++) {
        long long a, b, c; cin >> a >> b >> c;
        if(a == 1) seg.add(b, c - seg.query(b, b));
        else cout << (long long) seg.query(b, c) << '\n';
    }
}
