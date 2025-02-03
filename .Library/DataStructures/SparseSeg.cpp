/* Update : 2025-01-24 */

#include <bits/stdc++.h>
using namespace std;

struct SpSumLazy;

/// requirements: (TreeType + TreeType), (LazyType + UpdateType), (TreeType + LazyIter&&), (LazyType + LazyIter&&)
/// <br> usage: node merge, node update, lazy update, lazy update
template <typename TreeType = long long, typename LazyType = SpSumLazy, typename UpdateType = long long>
class SparseSeg {
    vector<TreeType> tree; vector<LazyType> lazy; vector<signed> l, r; long long ln, rn;
    signed next() { tree.emplace_back(); lazy.emplace_back(); l.emplace_back(-1); r.emplace_back(-1); return ((long long) tree.size())-1; }
public:
    SparseSeg(long long li, long long ri) : ln(li), rn(ri) { next(); }
    /// tree & lazy are copied values, should not be modified
    struct iter {
        signed node, start, end; TreeType tree; LazyType lazy; SparseSeg* segPtr;
        iter left() {
            assert(segPtr->l[node] != -1);
            segPtr->push(segPtr->l[node], start, (start+end)>>1);
            return iter(segPtr->l[node], start, (start+end)>>1, segPtr->tree[segPtr->l[node]], segPtr->lazy[segPtr->l[node]], segPtr);
        }
        iter right() {
            assert(segPtr->r[node] != -1);
            segPtr->push(segPtr->r[node], ((start+end)>>1)+1, end);
            return iter(segPtr->r[node], ((start+end)>>1)+1, end, segPtr->tree[segPtr->r[node]], segPtr->lazy[segPtr->r[node]], segPtr);
        }
        bool leaf() { return start == end; }
    };
    void update(long long left, long long right, const UpdateType& val) { update(0, ln, rn, left, right, val); }
    TreeType query(long long tar) { return query(tar, tar); }
    TreeType query(long long left, long long right) { return query(0, ln, rn, left, right); }
    iter root() { push(0, ln, rn); return iter(0, ln, rn, tree[0], lazy[0], this); }
private:
    void push(long long p, long long s, long long e) {
        tree[p] = tree[p] + iter(p, s, e, tree[p], lazy[p], this);
        if(s != e) {
            if(l[p] == -1) l[p] = next();
            lazy[l[p]] = lazy[l[p]] + iter(p, s, e, tree[p], lazy[p], this);
            if(r[p] == -1) r[p] = next();
            lazy[r[p]] = lazy[r[p]] + iter(p, s, e, tree[p], lazy[p], this);
        }
        lazy[p] = LazyType();
    }
    TreeType& update(long long p, long long s, long long e, long long ql, long long qr, const UpdateType& v) {
        push(p, s, e);
        if(qr < s || e < ql) return tree[p];
        if(ql <= s && e <= qr) { lazy[p] = lazy[p] + v; push(p, s, e); return tree[p]; }
        long long m = (s + e) >> 1;
        return tree[p] = update(l[p], s, m, ql, qr, v) + update(r[p], m+1, e, ql, qr, v);
    }
    TreeType query(long long p, long long s, long long e, long long ql, long long qr) {
        push(p, s, e);
        if(qr < s || e < ql) return TreeType();
        if(ql <= s && e <= qr) return tree[p];
        long long m = (s + e) >> 1;
        return query(l[p], s, m, ql, qr) + query(r[p], m+1, e, ql, qr);
    }
};

struct SpSumLazy {
    long long v = 0;
    SpSumLazy operator+(long long i) const {
        return SpSumLazy(v + i);
    }
    SpSumLazy operator+(const SparseSeg<long long, SpSumLazy, long long>::iter& i) const {
        return SpSumLazy(v + i.lazy.v);
    }
};
long long operator+(long long a, const SparseSeg<long long, SpSumLazy, long long>::iter& b) {
    return a + (b.end - b.start + 1) * b.lazy.v;
}
