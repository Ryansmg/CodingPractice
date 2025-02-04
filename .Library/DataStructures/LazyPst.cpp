/* Update : 2025-02-04 */

#include <bits/stdc++.h>


/// Persistent Segment Tree with Lazy Propagation  // <br>
/// requirements : TreeType + TreeType             // node merge <br>
///                TreeType.update(LazyType, s, e) // range update <br>
///                LazyType.set(UpdateType)        // range update <br>
///                LazyType.update(LazyType, s, e) // propagation
template <typename TreeType, typename LazyType, typename UpdateType>
class LazyPst {
    std::vector<TreeType> tree; std::vector<LazyType> lazy; std::vector<bool> flag; std::vector<signed> l, r; long long ln, rn;
    static inline long long m(long long s, long long e) { return (s + e) < 0 ? ((s + e) >> 1) - 1 : ((s + e) >> 1); }
public:
    LazyPst(long long leftBound, long long rightBound) : ln(leftBound), rn(rightBound) { for(signed i=0; i<2; i++) tree.emplace_back(), lazy.emplace_back(), flag.emplace_back(0), l.emplace_back(0), r.emplace_back(0); }
    // index = [1..n]
    explicit LazyPst(const std::vector<TreeType>& arr) : ln(1), rn(std::ssize(arr)) { tree.reserve(4*rn); for(signed i=0; i<2; i++) tree.emplace_back(), lazy.emplace_back(), flag.emplace_back(0), l.emplace_back(0), r.emplace_back(0);
        init(1, ln, rn, arr); }
    struct Iter {
        LazyPst* ptr = nullptr; long signed pos = 0; long long s = 1000000000000000000, e = -1000000000000000000;
        TreeType operator*() { return ptr->tree[pos]; } bool null() { return !pos; }
        Iter left() {
            ptr->push(ptr->l[pos], s, m(s, e));
            return {ptr, ptr->l[pos], s, m(s, e)};
        }
        Iter right() {
            ptr->push(ptr->r[pos], m(s, e)+1, e);
            return {ptr, ptr->r[pos], m(s, e)+1, e};
        }
    };
    struct Root {
        long signed pos = 0, prvPos = 0; LazyPst* ptr = nullptr;
        Root next() {
            Root ret; ret.pos = std::ssize(ptr->tree); ret.prvPos = pos; ret.ptr = ptr;
            ptr->tree.emplace_back(ptr->tree[pos]); ptr->l.emplace_back(ptr->l[pos]); ptr->r.emplace_back(ptr->r[pos]);
            ptr->lazy.emplace_back(ptr->lazy[pos]); ptr->flag.emplace_back(ptr->flag[pos]);
            return ret;
        }
        Iter iter() { ptr->push(pos, ptr->ln, ptr->rn); return {ptr, pos, ptr->ln, ptr->rn}; }
        /// @returns self
        Root& update(long long left, long long right, const UpdateType& val) { ptr->update(prvPos, pos, ptr->ln, ptr->rn, left, right, val); return *this; }
        TreeType query(long long left, long long right) { return ptr->query(prvPos, pos, ptr->ln, ptr->rn, left, right); }
    };
    friend Root; friend Iter; Root root() { return { 1, 0, this }; }
private:
    void push(long signed cur, long long s, long long e) {
        if(!flag[cur]) return;
        tree[cur].update(lazy[cur], s, e);
        if(s != e) {
            tree.emplace_back(tree[l[cur]]), lazy.emplace_back(lazy[l[cur]]), flag.emplace_back(1), l.emplace_back(l[l[cur]]), r.emplace_back(r[l[cur]]), l[cur] = std::ssize(tree) - 1;
            lazy[l[cur]].update(lazy[cur], s, e);
            tree.emplace_back(tree[r[cur]]), lazy.emplace_back(lazy[r[cur]]), flag.emplace_back(1), l.emplace_back(l[r[cur]]), r.emplace_back(r[r[cur]]), r[cur] = std::ssize(tree) - 1;
            lazy[r[cur]].update(lazy[cur], s, e);
        }
        flag[cur] = false; lazy[cur] = LazyType();
    }
    TreeType& init(long signed cur, long long s, long long e, const std::vector<TreeType>& arr) {
        if(s == e) return tree[cur] = arr[s-1];
        l[cur] = std::ssize(tree); r[cur] = std::ssize(tree)+1; for(signed i=0; i<2; i++) tree.emplace_back(), lazy.emplace_back(), flag.emplace_back(0), l.emplace_back(0), r.emplace_back(0);
        return tree[cur] = init(l[cur], s, m(s, e), arr) + init(r[cur], m(s, e)+1, e, arr);
    }
    void update(long signed prv, long signed cur, long long s, long long e, long long left, long long right, const UpdateType& val) {
        push(cur, s, e);
        if(right < s || e < left) return;
        if(left <= s && e <= right) {
            lazy[cur].set(val); flag[cur] = true; push(cur, s, e); return;
        }
        if(!l[cur] || l[cur] == l[prv]) tree.emplace_back(tree[l[cur]]), lazy.emplace_back(lazy[l[cur]]), flag.emplace_back(flag[l[cur]]), l.emplace_back(l[l[cur]]), r.emplace_back(r[l[cur]]), l[cur] = std::ssize(tree) - 1;
        if(!r[cur] || r[cur] == r[prv]) tree.emplace_back(tree[r[cur]]), lazy.emplace_back(lazy[r[cur]]), flag.emplace_back(flag[r[cur]]), l.emplace_back(l[r[cur]]), r.emplace_back(r[r[cur]]), r[cur] = std::ssize(tree) - 1;

        update(l[prv], l[cur], s, m(s, e), left, right, val);
        update(r[prv], r[cur], m(s, e) + 1, e, left, right, val);
        tree[cur] = tree[l[cur]] + tree[r[cur]];
    }
    TreeType query(long signed prv, long signed cur, long long s, long long e, long long ql, long long qr) {
        push(cur, s, e);
        if(!cur || qr < s || e < ql) { return TreeType(); } if(ql <= s && e <= qr) return tree[cur];
        return query(l[prv], l[cur], s, m(s, e), ql, qr) + query(r[prv], r[cur], m(s, e) + 1, e, ql, qr);
    }
};
