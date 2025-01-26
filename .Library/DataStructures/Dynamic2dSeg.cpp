/* Update : 2025-01-24 */

#include <bits/stdc++.h>
using namespace std;

template <typename T> class DynamicSeg; // from DynamicSeg.cpp

template <typename T = long long>
class Dynamic2dSeg {
    long long lx, rx, ly, ry; vector<DynamicSeg<T>> tree; vector<signed> l, r;
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
