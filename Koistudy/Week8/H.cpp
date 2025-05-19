#include <bits/stdc++.h>
using namespace std;
using i16 = short; using i32 = signed; using i64 = long long; using i128 = __int128;
constexpr i64 llmax = 9223372036854775807, INF = 1000000000000000000, inf = 3000000000;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define rep(n) forn(bit_Ly_S, n)

#define all(vec) (vec).begin(), (vec).end()
using vl = vector<i64>;
#define pb push_back
#define eb emplace_back
template <typename Signature> using func = function<Signature>;

template <typename T> void sort(vector<T> &v) { sort(all(v)); }
template <typename T> void compress(vector<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const vector<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> void println(const T& v) { cout << v << "\n"; }

namespace PST {
    constexpr i64 n = 100010;
    constexpr i32 null = 0;
    i64 avail = 1;
    using ptr = i32;
    struct pnd { ptr l = null, r = null; i64 val = 0; };
    pnd mem[15000000];

    class pst {
    public:
        ptr pos = null;
        pst() : pos(avail++) {}
        static pst newFrom(const pst &prev) {
            pst t;
            mem[t.pos].l = mem[prev.pos].l;
            mem[t.pos].r = mem[prev.pos].r;
            return t;
        }
        void init(vl *arr = nullptr) const {
            init(pos, 1, n, arr);
        }
        void add(pst prv, i64 t, i64 d) const {
            add(prv.pos, t, d);
        }
        void add(ptr prv, i64 t, i64 d) const {
            add(prv, pos, t, d, 1, n);
        }
        i64 query(i64 l, i64 r) const {
            return query(pos, l, r, 1, n);
        }
    private:
        static void add(ptr prv, ptr cur, i64 t, i64 d, i64 s, i64 e) {
            if(s == e) {
                mem[cur].val += d;
                return;
            }
            i64 m = (s + e) >> 1;
            if(t <= m) {
                if(!mem[cur].l || mem[cur].l == mem[prv].l) {
                    mem[cur].l = avail++;
                    mem[mem[cur].l].val = mem[mem[prv].l].val;
                }
                if(!mem[cur].r) mem[cur].r = mem[prv].r;
                add(mem[prv].l, mem[cur].l, t, d, s, m);
            } else {
                if(!mem[cur].l) mem[cur].l = mem[prv].l;
                if(!mem[cur].r || mem[cur].r == mem[prv].r) {
                    mem[cur].r = avail++;
                    mem[mem[cur].r].val = mem[mem[prv].r].val;
                }
                add(mem[prv].r, mem[cur].r, t, d, m+1, e);
            }
            mem[cur].val = mem[mem[cur].l].val + mem[mem[cur].r].val;
        }
        static i64 query(ptr cur, i64 l, i64 r, i64 s, i64 e) {
            if(r < s || e < l) return 0;
            if(l <= s && e <= r) return mem[cur].val;
            i64 m = (s + e) >> 1;
            return query(mem[cur].l, l, r, s, m) + query(mem[cur].r, l, r, m+1, e);
        }
        static void init(ptr node, i64 s, i64 e, vl *arr) {
            if (s == e) {
                mem[node].val = arr ? (*arr)[s-1] : 0;
                return;
            }
            i64 m = (s + e) >> 1;
            mem[node].l = avail++;
            mem[node].r = avail++;
            init(mem[node].l, s, m, arr);
            init(mem[node].r, m+1, e, arr);
            mem[node].val = mem[mem[node].l].val + mem[mem[node].r].val;
        }
    };
}
using pst = PST::pst;
using ptr = PST::ptr;
using PST::mem;

i32 main() {
    fastio;
    i64 n, m, a, b, c; cin >> n >> m;
    vl comp; vl arr;
    rep(n) cin >> a, comp.pb(a), arr.pb(a);
    compress(comp);
    for(i64 &i : arr) i = idx(i, comp) + 1;
    vector<pst> psts(1, pst());
    forn(i, n) {
        pst p = pst::newFrom(psts.back());
        p.add(psts.back(), arr[i], 1);
        psts.eb(p);
    }
    func<i64(ptr, ptr, i64, i64, i64)> q = [&](ptr l, ptr r, i64 s, i64 e, i64 k) -> i64 {
        if(s == e) return s;
        i64 lcnt = 0;
        lcnt -= mem[mem[l].l].val;
        lcnt += mem[mem[r].l].val;
        i64 m = (s+e)>>1;
        if(k <= lcnt) return q(mem[l].l, mem[r].l, s, m, k);
        else return q(mem[l].r, mem[r].r, m+1, e, k-lcnt);
    };
    rep(m) cin >> a >> b >> c, println(comp[q(psts[a-1].pos, psts[b].pos, 1, 100010, c)-1]);
}
