/* Update : 2025-02-04 */

#include <bits/stdc++.h>


/// Persistent Segment Tree
template <typename T = long long>
class Pst {
    std::vector<T> tree; std::vector<signed> l, r; long long ln, rn;
    static inline long long m(long long s, long long e) { return (s + e) < 0 ? ((s + e) >> 1) - 1 : ((s + e) >> 1); }
    template <typename V> static inline long long Size(const V& v) { return static_cast<long long>(v.size()); }
public:
    Pst(long long leftBound, long long rightBound) : ln(leftBound), rn(rightBound) { for(signed i=0; i<2; i++) tree.emplace_back(), l.emplace_back(0), r.emplace_back(0); }
    // index = [1..n]
    explicit Pst(const std::vector<T>& arr) : ln(1), rn(Size(arr)) { tree.reserve(4*rn); for(signed i=0; i<2; i++) tree.emplace_back(), l.emplace_back(0), r.emplace_back(0);
        init(1, ln, rn, arr); }
    struct Iter {
        Pst* ptr = nullptr; signed pos = 0; long long s = 1000000000000000000, e = -1000000000000000000;
        T operator*() { return ptr->tree[pos]; } bool null() { return !pos; }
        Iter left() { return {ptr, ptr->l[pos], s, (s+e)/2}; } Iter right() { return {ptr, ptr->r[pos], (s+e)/2+1, e}; }
    };
    struct Root {
        signed pos = 0, prvPos = 0; Pst* ptr = nullptr;
        Root next() {
            Root ret; ret.pos = Size(ptr->tree); ret.prvPos = pos; ret.ptr = ptr;
            ptr->tree.emplace_back(ptr->tree[pos]); ptr->l.emplace_back(ptr->l[pos]); ptr->r.emplace_back(ptr->r[pos]);
            return ret;
        }
        Iter iter() { return {ptr, pos, ptr->ln, ptr->rn}; }
        /// @returns self
        Root& add(long long tar, const T& diff) { ptr->update(prvPos, pos, ptr->ln, ptr->rn, tar, diff, true); return *this; }
        /// @returns self
        Root& set(long long tar, const T& val) { ptr->update(prvPos, pos, ptr->ln, ptr->rn, tar, val, false); return *this; }
        T query(long long left, long long right) { return ptr->query(pos, ptr->ln, ptr->rn, left, right); }
    };
    friend Root; friend Iter; Root root() { return { 1, 0, this }; }
private:
    T& init(signed cur, long long s, long long e, const std::vector<T>& arr) {
        if(s == e) return tree[cur] = arr[s-1];
        l[cur] = Size(tree); r[cur] = Size(tree)+1; for(signed i=0; i<2; i++) tree.emplace_back(), l.emplace_back(0), r.emplace_back(0);
        return tree[cur] = init(l[cur], s, m(s, e), arr) + init(r[cur], m(s, e)+1, e, arr);
    }
    void update(signed prv, signed cur, long long s, long long e, long long t, const T& d, bool isAdd) {
        if(s == e) { if(isAdd) { tree[cur] = tree[cur] + d; } else { tree[cur] = d; } return; }
        if(t <= m(s, e)) {
            if(!l[cur] || l[cur] == l[prv]) l[cur] = Size(tree), tree.emplace_back(tree[l[prv]]), l.emplace_back(l[l[prv]]), r.emplace_back(r[l[prv]]);
            if(!r[cur]) r[cur] = r[prv];
            update(l[prv], l[cur], s, m(s, e), t, d, isAdd);
        } else {
            if(!l[cur]) l[cur] = l[prv];
            if(!r[cur] || r[cur] == r[prv]) r[cur] = Size(tree), tree.emplace_back(tree[r[prv]]), l.emplace_back(l[r[prv]]), r.emplace_back(r[r[prv]]);
            update(r[prv], r[cur], m(s, e) + 1, e, t, d, isAdd);
        }
        tree[cur] = tree[l[cur]] + tree[r[cur]];
    }
    T query(signed cur, long long s, long long e, long long ql, long long qr) {
        if(!cur || qr < s || e < ql) { return T(); } if(ql <= s && e <= qr) return tree[cur];
        return query(l[cur], s, (s+e)>>1, ql, qr) + query(r[cur], ((s+e)>>1)+1, e, ql, qr);
    }
};
using PstIter = Pst<long long>::Iter; using PstRoot = Pst<long long>::Root;


// Example : BOJ 11012. Egg
signed main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long tc; cin >> tc;
    for(long long tcn = 0; tcn < tc; tcn++) {
        vector<vector<long long>> queries(100010, vector<long long>());
        long long N, m; cin >> N >> m;
        for(long long i = 0; i < N; i++) {
            long long a, b; cin >> a >> b;
            queries[b].push_back(a + 1);
        }
        Pst tree(1, 100010);
        vector<PstRoot> psts(1, tree.root());
        for(long long i = 0; i < 100003; i++) {
            auto p = psts.back().next();
            for(long long j : queries[i]) p.add(j, 1);
            psts.push_back(p);
        }
        long long ans = 0;
        for(long long i = 0; i < m; i++) {
            long long l, r, b, t; cin >> l >> r >> b >> t;
            l++; r++; b++; t++;
            ans += psts[t].query(l, r) - psts[b-1].query(l, r);
        }
        cout << ans << '\n';
    }
}
