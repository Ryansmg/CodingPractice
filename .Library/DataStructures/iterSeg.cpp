/* Update : 2025-01-23 */

#include <bits/stdc++.h>
using namespace std;

/// requirements: (T + T), add -> (T += long long)
template <typename T = long long>
struct iterSeg {
    vector<T> tree; signed n=-1;
    explicit iterSeg(const vector<T> &arr) { n = signed(arr.size()); tree = vector<T>(2*n+10, T());
        for(signed i=n, j=0; i<2*n; i++, j++) tree[i] = arr[j];
        for(signed i=n-1; i>0; i--) tree[i] = tree[i<<1] + tree[i<<1|1];  }
    explicit iterSeg(signed i) { tree = vector<T>(i*2+10, T()); n = i; }
    void add(signed tar, long long val) { tar--; tree[n+tar]+=val; for(signed i=n+tar; i>1; i>>=1) tree[i>>1]=tree[i]+tree[i^1]; }
    void set(signed tar, long long val) { tar--; tree[n+tar]=val; for(signed i=n+tar; i>1; i>>=1) tree[i>>1]=tree[i]+tree[i^1]; }
    T query(signed left, signed right) { left--; long long l = n+left, r = n+right; T ans = T();
        for(; l<r; l>>=1, r>>=1) { if(l&1) { ans = ans + tree[l++]; } if(r&1) { ans = ans + tree[--r]; } } return ans; }
};

// Example : BOJ 2042. 구간 합 구하기
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    iterSeg seg(arr);
    for(int i = 0; i < m + k; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) seg.set(b, c);
        else cout << seg.query(b, c) << '\n';
    }
}