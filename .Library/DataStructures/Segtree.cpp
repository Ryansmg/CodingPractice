/* Update : 2025-02-04 */

#include <bits/stdc++.h>

/// requirements: operator+(T, T)
template <typename T = long long>
class Segtree {
    std::vector<T> tree; signed n;
public:
    Segtree() : n(0) {}
    explicit Segtree(signed treeSize) { tree = std::vector<T>(4*treeSize, T()); n = treeSize; }
    explicit Segtree(const std::vector<T> &a) { n = std::ssize(a); tree = vector<T>(4*n, T()); init(a, 1, 1, n); }
    void set(signed tar, const T& val) { set(1, tar, 1, n, val); }
    void add(signed tar, const T& diff) { update(1, tar, 1, n, diff); }
    void update(signed tar, const T& diff) { update(1, tar, 1, n, diff); }
    T query(signed left, signed right) { if(left > right) { return T(); } return query(1, left, right, 1, n); }
    T query(signed tar) { return query(tar, tar); }
    struct iter {
        signed node, start, end; T value; Segtree<T>* segPtr;
        bool leaf() const { return start == end; }
        iter left() const { return iter(node<<1, start, (start+end)>>1, segPtr->tree[node<<1], segPtr); }
        iter right() const { return iter(node<<1|1, ((start+end)>>1)+1, end, segPtr->tree[node<<1|1], segPtr); }
    };
    iter root() { return iter(1, 1, n, tree[1], this); }
    // ret[i] == query(i+1)
    std::vector<T> getLeafs() { std::vector<T> ret(n);
        std::function<void(long long, long long, long long)> f = [&](long long p, long long s, long long e) {
            if(s == e) ret[s-1] = tree[p];
            else f(p<<1, s, (s+e)>>1), f(p<<1|1, ((s+e)>>1)+1, e); };
        f(1, 1, n); return ret; }

    /// [1..i] 범위 합이 val 이하인 최대의 i를 리턴
    iter binSearch(T val) {
        iter cur = root();
        while(!cur.leaf()) { iter l = cur.left();
            if(val <= l.value) cur = l;
            else val = val - l.value, cur = cur.right(); }
        return cur;
    }
protected:
    T& init(const std::vector<T> &a, signed node, signed start, signed end) {
        if(start==end) return tree[node] = a[start-1];
        else return tree[node] = init(a, node<<1, start, (start+end)>>1) + init(a, node<<1|1, ((start+end)>>1)+1, end);
    }
    T& update(signed node, signed tar, signed start, signed end, const T& diff) { if(end < tar || tar < start) return tree[node];
        if(start == end) return tree[node] = tree[node] + diff;
        return tree[node] = update(node<<1, tar, start, (start+end)>>1, diff) + update(node<<1|1, tar, ((start+end)>>1)+1, end, diff);
    }
    T& set(signed node, signed tar, signed start, signed end, const T& val) { if(end < tar || tar < start) return tree[node];
        if(start == end) return tree[node] = val;
        return tree[node] = set(node<<1, tar, start, (start+end)>>1, val) + set(node<<1|1, tar, ((start+end)>>1)+1, end, val);
    }
    T query(signed node, signed left, signed right, signed start, signed end) { if(right < start || end < left) return T();
        if(left <= start && end <= right) return tree[node];
        return query(node<<1, left, right, start, (start+end)>>1) + query(node<<1|1, left, right, ((start+end)>>1)+1, end);
    }
};

// Example : BOJ 2243. 사탕상자
int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    Segtree seg(1000000);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if(a == 1) {
            int ans = seg.binSearch(b).start;
            cout << ans << '\n';
            seg.add(ans, -1);
        }
        else {
            int c; cin >> c;
            seg.add(b, c);
        }
    }
}