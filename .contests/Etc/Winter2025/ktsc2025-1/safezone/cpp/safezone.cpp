#include <bits/stdc++.h>
using namespace std; using i64 = long long; using i32 = signed;
template <typename T> using v = vector<T>; using vi = v<i32>; using vl = v<i64>;
#define forn(i, n) for(i32 i=0; i<n; i++)
#define all(v) (v).begin(), (v).end()
#define Size(v) i32(v.size())
#define eb emplace_back
auto idx = [](i32 v, const vi& comp) { return i32(lower_bound(all(comp), v) - comp.begin()); };
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
vi g, endX, x, y;
i32 find(i32 i) { if(g[i] == i) {return i;} return g[i] = find(g[i]); }
void merge(i32 a, i32 b) { if(find(a) != find(b)) g[find(a)] = find(b); }
using pq = priority_queue<array<i32, 2>, v<array<i32, 2>>, greater<>>;
struct Seg {
    v<pq> low; vi high;
    Seg()=default;
    explicit Seg(i32 bound) : low(bound*4, pq()), high(bound*4, -1) {}
    void add(i32 p, i32 s, i32 e, i32 lx, i32 rx, i32 ly, i32 ry, i32 v) {
        if(ry < s || e < ly) return;
        if(endX[high[p]] < lx) high[p] = -1;
        if(high[p] != -1) merge(v, high[p]);
        if(ly <= s && e <= ry) {
            low[p].push({rx, v});
            while(!low[p].empty() && low[p].top()[0] < lx) low[p].pop();
            while(Size(low[p]) > 1) merge(v, low[p].top()[1]), low[p].pop();
            if(!low[p].empty()) merge(v, low[p].top()[1]);
            if(high[p] == -1) high[p] = v;
            else high[p] = endX[v] > endX[high[p]] ? v : high[p];
            return;
        }
        while(!low[p].empty() && low[p].top()[0] < lx) low[p].pop();
        low[p].push({rx, v});
        add(p*2, s, (s+e)/2, lx, rx, ly, ry, v);
        add(p*2+1, (s+e)/2+1, e, lx, rx, ly, ry, v);
    }
} seg;

struct query {
    i32 id, lx, rx, ly, ry;
    bool operator<(const query& b) const { if(lx != b.lx) {return lx < b.lx;} return rx < b.rx; }
};

#define compress(v) sort(all(v)); v.erase(unique(all(v)), v.end())

v<int> find_union(int N, v<int> A, v<int> B, v<int> C, v<int> D) {
    g.resize(N); forn(i, N) g[i] = i, x.eb(A[i]), y.eb(B[i]), x.eb(C[i]), y.eb(D[i]);
    compress(x); compress(y);
    forn(i, N) A[i] = idx(A[i], x) + 1, B[i] = idx(B[i], y) + 1, C[i] = idx(C[i], x) + 1, D[i] = idx(D[i], y) + 1;
    endX.resize(N); forn(i, N) endX[i] = C[i];
    v<query> qrs; forn(i, N) qrs.eb(i, A[i], C[i], B[i], D[i]);
    sort(all(qrs)); seg = Seg(Size(y));
    forn(i, N) seg.add(1, 1, Size(y), qrs[i].lx, qrs[i].rx, qrs[i].ly, qrs[i].ry, qrs[i].id);
    vi ans; forn(i, N) ans.eb(find(i));
    vi comp = ans; compress(comp);
    forn(i, N) ans[i] = idx(ans[i], comp);
    return ans;
}
