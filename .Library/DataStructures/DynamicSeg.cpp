/* Update : 2025-02-04 */

#include <bits/stdc++.h>\

template <typename T = long long>
class DynamicSeg {
    inline long long m(long long s, long long e) { return (s+e)>=0 ? (s+e)>>1 : ((s+e)>>1)-1; }
    std::vector<T> tree; long long ln, rn; std::vector<signed> l, r;
    signed next() { tree.emplace_back(); l.emplace_back(-1); r.emplace_back(-1); return ((long long)tree.size())-1; }
public:
    explicit DynamicSeg(long long li, long long ri) : ln(li), rn(ri) { next(); }
    void add(long long tar, const T& val) { add(0, ln, rn, tar, val); }
    void set(long long tar, const T& val) { set(0, ln, rn, tar, val); }
    T query(long long left, long long right) { return query(0, ln, rn, left, right); }
private:
    T& add(signed p, long long s, long long e, long long t, const T& v) {
        if(s == e) return tree[p] = tree[p] + v;
        if(t <= (s + e) / 2) {
            if(l[p] == -1) l[p] = next();
            return tree[p] = add(l[p], s, m(s, e), t, v) + (r[p] == -1 ? T() : tree[r[p]]);
        }
        if(r[p] == -1) r[p] = next();
        return tree[p] = (l[p] == -1 ? T() : tree[l[p]]) + add(r[p], m(s, e)+1, e, t, v);
    }
    T& set(signed p, long long s, long long e, long long t, const T& v) {
        if(s == e) return tree[p] = v;
        if(t <= (s + e) / 2) {
            if(l[p] == -1) l[p] = next();
            return tree[p] = set(l[p], s, m(s, e), t, v) + (r[p] == -1 ? T() : tree[r[p]]);
        }
        if(r[p] == -1) r[p] = next();
        return tree[p] = (l[p] == -1 ? T() : tree[l[p]]) + set(r[p], m(s, e)+1, e, t, v);
    }
    T query(signed p, long long s, long long e, long long ql, long long qr) {
        if(p == -1 || qr < s || e < ql) return T();
        if(ql <= s && e <= qr) return tree[p];
        return query(l[p], s, m(s, e), ql, qr) + query(r[p], m(s, e)+1, e, ql, qr);
    }
};
