/* Update : 2025-02-11 */

/// Persistent Segment Tree with Low Memory usage
/// implemented with std::shared_ptr, very slow in debug mode because of memory deallocation.
/// Does not guarantee low memory usage in general, can use more memory than Pst.

#include <vector>
#include <memory>

template <typename T = long long>
class PstLM {
    long long ln, rn;
    static inline long long m(long long s, long long e) { return s + (e - s) / 2; }
public:
    struct Node { std::shared_ptr<Node> l = nullptr, r = nullptr; T val = T(); };
    PstLM(long long leftBound, long long rightBound) : ln(leftBound), rn(rightBound) { }
    struct Iter {
        std::shared_ptr<Node> pos = nullptr; long long s = 1000000000000000000, e = -1000000000000000000;
        T operator*() { return pos->val; } bool null() { return !pos; }
        Iter left() { return {pos->l, s, (s+e)/2}; } Iter right() { return {pos->r, (s+e)/2+1, e}; }
    };
    struct Root {
        std::shared_ptr<Node> pos = nullptr, prvPos = nullptr; PstLM* ptr = nullptr;
        Root next() {
            Root ret; ret.pos = std::make_shared<Node>(pos->l, pos->r, pos->val); ret.prvPos = pos; ret.ptr = ptr;
            return ret;
        }
        Iter iter() { return {ptr, pos, ptr->ln, ptr->rn}; }
        /// @returns self
        Root& add(long long tar, const T& diff) { ptr->update(prvPos, pos, ptr->ln, ptr->rn, tar, diff, true); return *this; }
        /// @returns self
        Root& set(long long tar, const T& val) { ptr->update(prvPos, pos, ptr->ln, ptr->rn, tar, val, false); return *this; }
        /// must be called when the updates are finished
        Root& lock() { prvPos = nullptr; return *this; }
        T query(long long left, long long right) { return ptr->query(pos, ptr->ln, ptr->rn, left, right); }
    };
    friend Root; friend Iter; Root root() { return { std::make_shared<Node>(), nullptr, this }; }
    Root init(const std::vector<T>& arr) {
        assert(ln == 1 && rn == std::ssize(arr));
        Root ret = root(); init(ret, ln, rn, arr); return ret;
    }
private:
    void init(const std::shared_ptr<Node>& cur, long long s, long long e, const std::vector<T>& arr) {
        if(s == e) { cur->val = arr[s-1]; return; }
        cur->l = std::make_shared<Node>(); cur->r = std::make_shared<Node>();
        init(cur->l, s, m(s, e), arr); init(cur->R, m(s, e)+1, e, arr);
        cur->val = cur->l->val + cur->r->val;
    }
    void update(const std::shared_ptr<Node>& prv, const std::shared_ptr<Node>& cur, long long s, long long e, long long t, const T& d, bool isAdd) {
        if(s == e) { if(isAdd) { cur->val = cur->val + d; } else { cur->val = d; } return; }
        if(t <= m(s, e)) {
            if(!cur->l || (prv && cur->l == prv->l)) cur->l = prv && prv->l ? std::make_shared<Node>(prv->l->l, prv->l->r, prv->l->val) : std::make_shared<Node>();
            if(!cur->r && prv) cur->r = prv->r;
            update(prv ? prv->l : nullptr, cur->l, s, m(s, e), t, d, isAdd);
        } else {
            if(!cur->l && prv) cur->l = prv->l;
            if(!cur->r || (prv && cur->r == prv->r)) cur->r = prv && prv->r ? std::make_shared<Node>(prv->r->l, prv->r->r, prv->r->val) : std::make_shared<Node>();
            update(prv ? prv->r : nullptr, cur->r, m(s, e) + 1, e, t, d, isAdd);
        }
        cur->val = (cur->l ? cur->l->val : T()) + (cur->r ? cur->r->val : T());
    }
    T query(const std::shared_ptr<Node>& cur, long long s, long long e, long long ql, long long qr) {
        if(!cur || qr < s || e < ql) { return T(); } if(ql <= s && e <= qr) return cur->val;
        return query(cur->l, s, (s+e)>>1, ql, qr) + query(cur->r, ((s+e)>>1)+1, e, ql, qr);
    }
};

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
        PstLM tree(1, 100010);
        vector<PstLM<long long>::Root> psts(1, tree.root());
        for(long long i = 0; i < 100003; i++) {
            auto p = psts.back().next();
            for(long long j : queries[i]) p.add(j, 1);
            psts.push_back(p.lock());
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
