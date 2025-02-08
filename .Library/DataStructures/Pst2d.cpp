/* Update : 2025-02-04 */

#include <bits/stdc++.h>


/// Persistent Segment Tree
template <typename T = long long>
class Pst {
    std::vector<T> tree; std::vector<signed> l, r; long long ln, rn;
    static inline long long m(long long s, long long e) { return s + (e - s) / 2; }
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


/// 2D Persistent Segment Tree
class Pst2d {
    static inline long long m(long long s, long long e) { return s + (e - s) / 2; }
    std::vector<PstRoot> tree; std::vector<signed> l, r; long long ln, rn;
    Pst<long long> pst;
    template <typename V> static inline long long Size(const V& v) { return static_cast<long long>(v.size()); }
public:
    Pst2d(long long yLeftBound, long long yRightBound, long long xLeftBound, long long xRightBound)
            : ln(yLeftBound), rn(yRightBound), pst(xLeftBound, xRightBound){
        tree.emplace_back(pst.root()), l.emplace_back(0), r.emplace_back(0);
        tree.emplace_back(pst.root().next()), l.emplace_back(0), r.emplace_back(0);
    }
    // index = [1..n]
    struct Iter {
        Pst2d* ptr = nullptr; signed pos = 0; long long s = 1000000000000000000, e = -1000000000000000000;
        PstRoot& operator*() const { return ptr->tree[pos]; } bool null() const { return !pos; }
        Iter left() { return {ptr, ptr->l[pos], s, (s+e)/2}; } Iter right() { return {ptr, ptr->r[pos], (s+e)/2+1, e}; }
    };
    struct Root {
        signed pos = 0, prvPos = 0; Pst2d* ptr = nullptr;
        Root next() const {
            Root ret; ret.pos = Size(ptr->tree); ret.prvPos = pos; ret.ptr = ptr;
            ptr->tree.emplace_back(ptr->tree[pos].next()); ptr->l.emplace_back(ptr->l[pos]); ptr->r.emplace_back(ptr->r[pos]);
            return ret;
        }
        Iter iter() { return {ptr, pos, ptr->ln, ptr->rn}; }
        /// @returns self
        Root& add(long long y, long long x, const long long& diff) { ptr->update(prvPos, pos, ptr->ln, ptr->rn, y, x, diff, true); return *this; }
        /// @returns self
        Root& set(long long y, long long x, const long long& val) { ptr->update(prvPos, pos, ptr->ln, ptr->rn, y, x, val, false); return *this; }
        std::vector<PstRoot> query(long long yl, long long yr) const { ptr->queryRet.clear(); ptr->query(pos, ptr->ln, ptr->rn, yl, yr); return ptr->queryRet; }
    };
    friend Root; friend Iter; Root root() { return { 1, 0, this }; }
private:
    std::vector<PstRoot> queryRet;
    void update(signed prv, signed cur, long long s, long long e, long long yt, long long xt, long long d, bool isAdd) {
        if(isAdd) { tree[cur].add(xt, d); } else { tree[cur].set(xt, d); }
        if(s == e) return;
        if(yt <= m(s, e)) {
            if(!l[cur] || l[cur] == l[prv]) l[cur] = Size(tree), tree.emplace_back(tree[l[prv]].next()), l.emplace_back(l[l[prv]]), r.emplace_back(r[l[prv]]);
            if(!r[cur]) r[cur] = r[prv];
            update(l[prv], l[cur], s, m(s, e), yt, xt, d, isAdd);
        } else {
            if(!l[cur]) l[cur] = l[prv];
            if(!r[cur] || r[cur] == r[prv]) r[cur] = Size(tree), tree.emplace_back(tree[r[prv]].next()), l.emplace_back(l[r[prv]]), r.emplace_back(r[r[prv]]);
            update(r[prv], r[cur], m(s, e) + 1, e, yt, xt, d, isAdd);
        }
    }
    void query(signed cur, long long s, long long e, long long ql, long long qr) {
        if(!cur) return;
        if(qr < s || e < ql) { return; } if(ql <= s && e <= qr) { queryRet.push_back(tree[cur]); return; }
        query(l[cur], s, m(s, e), ql, qr); query(r[cur], m(s, e)+1, e, ql, qr);
    }
};
using Pst2dIter = Pst2d::Iter; using Pst2dRoot = Pst2d::Root;


// Example : BOJ 17960. 3차원 점과 쿼리
template <typename T> inline long long idx(const T &val, const std::vector<T> &compressed) {
    return std::ranges::lower_bound(compressed, val) - compressed.begin();
}
signed main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n, q; cin >> n >> q;
    vector<array<long long, 3>> points; vector<long long> x, y, z;
    for(int i=0; i<n; i++) {
        long long a, b, c; cin >> a >> b >> c;
        points.push_back({a, b, c}); x.push_back(a); y.push_back(b); z.push_back(c);
    }
    ranges::sort(x); ranges::sort(y); ranges::sort(z);
    x.erase(ranges::unique(x).begin(), x.end());
    y.erase(ranges::unique(y).begin(), y.end());
    z.erase(ranges::unique(z).begin(), z.end());
    for(auto &[a, b, c] : points) a = idx(a, x) + 1, b = idx(b, y), c = idx(c, z);
    ranges::sort(points);
    Pst2d seg(0, ssize(z), 0, ssize(y));
    vector<Pst2dRoot> psts(1, seg.root());
    long long prvX = 0;
    for(int i=0; i<n; i++) {
        if(prvX != points[i][0]) {
            assert(points[i][0] == prvX + 1); prvX++;
            psts.push_back(psts.back().next());
        }
        psts.back().add(points[i][2], points[i][1], 1);
    }
    long long s = 0;
    constexpr long long mod = 1000000001;
    for(int i=0; i<q; i++) {
        long long a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
        long long lx = (a ^ s) % mod, ly = (b ^ s) % mod, lz = (c ^ s) % mod,
                  rx = (d ^ s) % mod, ry = (e ^ s) % mod, rz = (f ^ s) % mod;
        if(lx > rx) swap(lx, rx);
        if(ly > ry) swap(ly, ry);
        if(lz > rz) swap(lz, rz);
        if(lx > x.back() || ly > y.back() || lz > z.back() || rx < x[0] || ry < y[0] || rz < z[0]) {
            cout << 0 << '\n'; continue;
        }
        lx = idx(lx, x) + 1; ly = idx(ly, y); lz = idx(lz, z);
        rx = prev(ranges::upper_bound(x, rx)) - x.begin() + 1;
        ry = prev(ranges::upper_bound(y, ry)) - y.begin();
        rz = prev(ranges::upper_bound(z, rz)) - z.begin();
        long long cans = 0;
        for(auto& p : psts[rx].query(lz, rz)) cans += p.query(ly, ry);
        for(auto& p : psts[lx-1].query(lz, rz)) cans -= p.query(ly, ry);
        s += cans; cout << cans << '\n';
    }
}
