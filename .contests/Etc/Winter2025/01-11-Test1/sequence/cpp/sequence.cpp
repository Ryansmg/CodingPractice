#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define forn(i, n) for(i64 i=0; i<n; i++)
#define forf(i, a, b) for(i64 i = a; i <= b; i++)
template <typename T> using v = vector<T>;

// range max update, range min query
struct lazyprop {
    v<int> tree, lazy; i64 n;
    explicit lazyprop(i64 N) : tree(4*N, 0), lazy(4*N, -1), n(N) {}
    void push(i64 p, i64 s, i64 e) {
        tree[p] = max(tree[p], lazy[p]);
        if(s != e) {
            lazy[p*2] = max(lazy[p*2], lazy[p]);
            lazy[p*2+1] = max(lazy[p*2+1], lazy[p]);
        }
        lazy[p] = -1;
    }
    v<int> getLeafs() {
        v<int> ret(n, 0);
        function<void(i64, i64, i64)> f = [&](i64 p, i64 s, i64 e) {
            push(p, s, e);
            if(s == e) { ret[s-1] = tree[p]; return; }
            f(p<<1, s, (s+e)>>1);
            f(p<<1|1, ((s+e)>>1)+1, e);
        };
        f(1, 1, n);
        return ret;
    }
    void update(i64 l, i64 r, i64 v) { update(1, 1, n, l+1, r+1, v); }
    i64 query(i64 l, i64 r) { return query(1, 1, n, l+1, r+1); }
    void update(i64 p, i64 s, i64 e, i64 l, i64 r, i64 v) {
        push(p, s, e);
        if(r < s || e < l) return;
        if(l <= s && e <= r) {
            lazy[p] = v;
            push(p, s, e);
            return;
        }
        i64 m = (s + e) >> 1;
        update(p<<1, s, m, l, r, v);
        update(p<<1|1, m+1, e, l, r, v);
        tree[p] = min(tree[p<<1], tree[p<<1|1]);
    }
    i64 query(i64 p, i64 s, i64 e, i64 l, i64 r) {
        push(p, s, e);
        if(r < s || e < l) return 9223372036854775000;
        if(l <= s && e <= r) return tree[p];
        i64 m = (s + e) >> 1;
        return min(query(p<<1, s, m, l, r), query(p<<1|1, m+1, e, l, r));
    }
};

#define rep(f) f(2) f(3) f(5) f(7) f(11) f(13)

v<int> find_sequence(int N, v<int> L, v<int> R, v<int> X) {
	int M = L.size();
    v<int> fail(N, 0);
    lazyprop lp2(N), lp3(N), lp5(N), lp7(N), lp11(N), lp13(N);
    forn(i, M) {
        #define c(k) if(X[i] % k == 0) {\
            i64 cnt = 0, cur = X[i];\
            while(cur % k == 0) cnt++, cur/=k;\
            lp##k.update(L[i], R[i], cnt);\
        }
        rep(c)
    }
    v<int> ans(N, 1);
    forn(i, M) {
        i64 cnt2 = 0, cnt3 = 0, cnt5 = 0, cnt7 = 0, cnt11 = 0, cnt13 = 0;
        i64 cur = X[i];
        #define f(k) while(cur % k == 0) { cnt##k++; cur /= k; }
        rep(f)
        #define q(k) i64 q##k = lp##k.query(L[i], R[i]);
        rep(q)
        if(cnt2 != q2 || cnt3 != q3 || cnt5 != q5 || cnt7 != q7 || cnt11 != q11 || cnt13 != q13) return fail;
    }
    v<int> temp;
    #define g(k) temp = lp##k.getLeafs(); \
                 forn(i, N) forn(j, temp[i]) ans[i] *= k;
    rep(g)
    return ans;
}
