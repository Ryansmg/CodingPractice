#pragma clang diagnostic push
#pragma ide diagnostic ignored "performance-unnecessary-value-param"
#include <bits/stdc++.h>
using namespace std;
using i64 = long long; using i32 = signed;
template <typename T> using v = vector<T>; using vi = v<i32>; using vl = v<i64>;
#define forn(i, n) for(i32 i=0; i<n; i++)
#define forf(i, a, b) for(i32 i=a; i<=b; i++)
#define all(v) (v).begin(), (v).end()
#define Size(v) i32(v.size())
#define pb push_back
#define eb emplace_back
auto idx = [](i32 v, const vi& comp) { return i32(lower_bound(all(comp), v) - comp.begin()); };

struct asdf { template <typename T> asdf& operator<<(const T&) { return *this; } } consume_operator_leftshift_;

#ifdef LOCAL
#define lout cout
#else
#define lout consume_operator_leftshift_
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#endif

i64 mod1 = 1000000007;

array<int, 2> roadwork(string S) {
    i32 n = (Size(S)+2)/2;
    // a : 1 ~ n, b : n+1 ~ n+n
    v<vi> child(2*n+1, vi());
    i32 root;
    if(S[0] == 'A') root = 1, child[1].eb(n+1);
    else root = n+1, child[n+1].eb(1);
    i32 preA = 1, preB = n+1;
    for(const char& c : S) {
        if(c == 'A') child[preA].eb(++preB);
        else child[preB].eb(++preA);
    }
    vi noCon(2*n+1, 0), ans(2*n+1, 0);
    vl dp0(2*n+1, 1), dp1(2*n+1, 1);
    function<void(i64)> f = [&](i64 node) {
        for(const i32& i : child[node]) f(i);
        vl l, r, d1;
        i32 idx = -1;
        vi cd, cdm;
        for(const i32& i : child[node]) { idx++;
            noCon[node] += ans[i];
            dp0[node] = (dp0[node] * dp1[i]) % mod1;
            if(noCon[i] == ans[i]) cd.eb(idx);
            if(noCon[i] == ans[i]-1) cdm.eb(idx);
            l.eb(dp1[i]);
            d1.eb(dp0[i]);
        }
        if(cd.empty()) {
            ans[node] = noCon[node], dp1[node] = dp0[node];
            if(!cdm.empty()) {
                r = l;
                i32 n = Size(child[node]);
                forf(i, 1, n-1) l[i] = (l[i-1] * l[i]) % mod1;
                for(i32 i = n-2; i >= 0; i--) r[i] = (r[i+1] * r[i]) % mod1;
                for(const i32& i : cd) {
                    dp1[node] += (i ? l[i-1] : 1) * (i < n-1 ? r[i+1] : 1) % mod1 * d1[i] % mod1;
                    dp1[node] %= mod1;
                }
            }
        }
        else {
            r = l; ans[node] = noCon[node]+1;
            i32 n = Size(child[node]);
            forf(i, 1, n-1) l[i] = (l[i-1] * l[i]) % mod1;
            for(i32 i = n-2; i >= 0; i--) r[i] = (r[i+1] * r[i]) % mod1;
            dp1[node] = 0;
            for(const i32& i : cd) {
                dp1[node] += (i ? l[i-1] : 1) * (i < n-1 ? r[i+1] : 1) % mod1 * d1[i] % mod1;
                dp1[node] %= mod1;
            }
        }
    };
    f(root);
    return {ans[root], i32(dp1[root])};
}

#pragma clang diagnostic pop
