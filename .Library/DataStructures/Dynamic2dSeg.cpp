/* Update : 2025-02-04 */

#include <bits/stdc++.h>

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

template <typename T = long long>
class Dynamic2dSeg {
    long long lx, rx, ly, ry; std::vector<DynamicSeg<T>> tree; std::vector<signed> l, r;
public:
    Dynamic2dSeg(long long lxi, long long rxi, long long lyi, long long ryi) : lx(lxi), rx(rxi), ly(lyi), ry(ryi) { tree.emplace_back(ly, ry); l.emplace_back(-1); r.emplace_back(-1); }
    void add(long long tx, long long ty, const T& val) { add(0, lx, rx, tx, ty, val); }
    void set(long long tx, long long ty, const T& val) { set(0, lx, rx, tx, ty, val); }
    T query(long long left_x, long long right_x, long long left_y, long long right_y) { return query(0, lx, rx, left_x, right_x, left_y, right_y); }
private:
    void add(signed p, long long sx, long long ex, long long tx, long long ty, const T& val) {
        tree[p].add(ty, val); if(sx == ex) { return; }
        long long mx = (sx + ex) / 2;
        if(tx <= mx) {
            if(l[p] == -1) l[p] = signed(tree.size()), tree.emplace_back(ly, ry), l.emplace_back(-1), r.emplace_back(-1);
            add(l[p], sx, mx, tx, ty, val);
        } else {
            if(r[p] == -1) r[p] = signed(tree.size()), tree.emplace_back(ly, ry), l.emplace_back(-1), r.emplace_back(-1);
            add(r[p], mx+1, ex, tx, ty, val);
        }
    }
    void set(signed p, long long sx, long long ex, long long tx, long long ty, const T& val) {
        tree[p].set(ty, val); if(sx == ex) { return; } long long mx = (sx + ex) / 2;
        if(tx <= mx) { if(l[p] == -1) l[p] = signed(tree.size()), tree.emplace_back(ly, ry), l.emplace_back(-1), r.emplace_back(-1);
            set(l[p], sx, mx, tx, ty, val); } else { if(r[p] == -1) r[p] = signed(tree.size()), tree.emplace_back(ly, ry), l.emplace_back(-1), r.emplace_back(-1);
            set(r[p], mx+1, ex, tx, ty, val); }
    }
    T query(signed p, long long sx, long long ex, long long qlx, long long qrx, long long qly, long long qry) {
        if(p == -1 || ex < qlx || qrx < sx) return T();
        if(qlx <= sx && ex <= qrx) return tree[p].query(qly, qry);
        return query(l[p], sx, (sx+ex)/2, qlx, qrx, qly, qry) + query(r[p], (sx+ex)/2+1, ex, qlx, qrx, qly, qry);
    }
};

