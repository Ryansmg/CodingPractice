/* Update : 2025-07-02 */

#include <vector>


/// Persistent Segment Tree
template <typename T = long long>
class Pst {
    struct Node { T val = T(); signed l = 0, r = 0; };
    std::vector<Node> tree; long long ln, rn;
    static inline long long m(long long s, long long e) { return s + (e - s) / 2; }
    template <typename V> static inline long long Size(const V& v) { return static_cast<long long>(v.size()); }
public:
    Pst(long long leftBound, long long rightBound) : ln(leftBound), rn(rightBound) { for(signed i=0; i<2; i++) tree.emplace_back(); }
    // index = [1..n]
    explicit Pst(const std::vector<T>& arr) : ln(1), rn(Size(arr)) { tree.reserve(4*rn); for(signed i=0; i<2; i++) tree.emplace_back();
        init(1, ln, rn, arr); }
    struct Iter {
        Pst* ptr = nullptr; signed pos = 0; long long s = 1000000000000000000, e = -1000000000000000000;
        T operator*() { return ptr->tree[pos].val; } bool null() const { return !pos; }
        Iter left() { return {ptr, ptr->tree[pos].l, s, m(s, e)}; } Iter right() { return {ptr, ptr->tree[pos].r, m(s, e)+1, e}; }
    };
    struct Root {
        signed pos = 0, prvPos = 0; Pst* ptr = nullptr;
        Root next() {
            Root ret; ret.pos = Size(ptr->tree); ret.prvPos = pos; ret.ptr = ptr;
            ptr->tree.emplace_back(ptr->tree[pos]);
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
    void reserve(long long capacity) { tree.reserve(capacity); }
private:
    T& init(signed cur, long long s, long long e, const std::vector<T>& arr) {
        if(s == e) return tree[cur] = arr[s-1];
        tree[cur].l = Size(tree); tree[cur].r = Size(tree)+1; for(signed i=0; i<2; i++) tree.emplace_back();
        return tree[cur] = init(tree[cur].l, s, m(s, e), arr) + init(tree[cur].r, m(s, e)+1, e, arr);
    }
    void update(signed prv, signed cur, long long s, long long e, long long t, const T& d, bool isAdd) {
        if(s == e) { if(isAdd) { tree[cur].val = tree[cur].val + d; } else { tree[cur].val = d; } return; }
        if(t <= m(s, e)) {
            if(!tree[cur].l || tree[cur].l == tree[prv].l) tree[cur].l = Size(tree), tree.emplace_back(tree[tree[prv].l]);
            if(!tree[cur].r) tree[cur].r = tree[prv].r;
            update(tree[prv].l, tree[cur].l, s, m(s, e), t, d, isAdd);
        } else {
            if(!tree[cur].l) tree[cur].l = tree[prv].l;
            if(!tree[cur].r || tree[cur].r == tree[prv].r) tree[cur].r = Size(tree), tree.emplace_back(tree[tree[prv].r]);
            update(tree[prv].r, tree[cur].r, m(s, e) + 1, e, t, d, isAdd);
        }
        tree[cur].val = tree[tree[cur].l].val + tree[tree[cur].r].val;
    }
    T query(signed cur, long long s, long long e, long long ql, long long qr) {
        if(!cur || qr < s || e < ql) { return T(); } if(ql <= s && e <= qr) return tree[cur].val;
        return query(tree[cur].l, s, m(s, e), ql, qr) + query(tree[cur].r, m(s, e) + 1, e, ql, qr);
    }
};
using PstIter = Pst<>::Iter; using PstRoot = Pst<>::Root;


// Example : BOJ 11012. Egg
#include <iostream>

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
