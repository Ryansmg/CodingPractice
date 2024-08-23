#pragma region macros
//@formatter:off
#include <bits/stdc++.h>
using namespace std;
using i16 = short; using i32 = signed; using i64 = long long; using i128 = __int128;
#define int i64
#define ci64 const i64 &
#define cint ci64
const long long llmax = 9223372036854775807, INF = 1000000000000000000, inf = 3000000000;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define all(vec) (vec).begin(), (vec).end()
template <typename T> using v = vector<T>; template <typename T> using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>;
template <typename T = i64> T input() {T t; cin >> t; return t;}
//@formatter:on
#pragma endregion

static const i64 n = 100010;
struct pst {
    pst *l = nullptr, *r = nullptr;
    bool dl = false, dr = false;
    i64 val = 0;
    pst() = default;
    ~pst() { if(dl) delete l; if(dr) delete r; }
    explicit pst(pst *prev) : pst() {
        l = prev->l; r = prev->r;
    }
    void init(vl *arr = nullptr) {
        init(this, 1, n, arr);
    }
    void add(pst *prv, i64 t, i64 d, i64 s = 1, i64 e = n) {
        if (s == e) { val += d; return; }
        i64 m = (s + e) >> 1;
        if (t <= m) {
            if (!l || l == prv->l) {
                l = new pst(); dl = true;
                l->val = prv->l->val;
            }
            if (!r) r = prv->r;
            l->add(prv->l, t, d, s, m);
        } else {
            if (!l) l = prv->l;
            if (!r || r == prv->r) {
                r = new pst(); dr = true;
                r->val = prv->r->val;
            }
            r->add(prv->r, t, d, m + 1, e);
        }
        val = l->val + r->val;
    }
    i64 query(i64 L, i64 R, i64 s = 1, i64 e = n) const {
        if (R < s || e < L) return 0;
        if (L <= s && e <= R) return val;
        i64 m = (s + e) >> 1;
        return l->query(L, R, s, m) + r->query(L, R, m + 1, e);
    }
    static void init(pst *node, i64 s, i64 e, vl *arr) {
        if (s == e) {
            node->val = arr ? (*arr)[s - 1] : 0;
            return;
        }
        i64 m = (s + e) >> 1;
        node->l = new pst(); node->r = new pst();
        node->dl = node->dr = true;
        init(node->l, s, m, arr);
        init(node->r, m + 1, e, arr);
        node->val = node->l->val + node->r->val;
    }
};

// 11012. Egg
// #pst (퍼시스턴트 세그먼트 트리)

v2<int> queries = v2<int>(100010, v<int>());

signed main() {
    fastio;
    int T = input();
    forn(tci, T) {
        for (auto &q: queries) q.clear();
        int N, m, a, b;
        cin >> N >> m;
        forn(i, N) {
            cin >> a >> b;
            queries[b].push_back(a + 1);
        }
        v<pst*> psts;
        pst* temp = new pst(); temp->init();
        psts.emplace_back(temp);
        forn(i, 100003) {
            pst* p = new pst(psts.back());
            for (int j: queries[i]) p->add(psts.back(), j, 1);
            psts.emplace_back(p);
        }
        int ans = 0;
        forn(i, m) {
            int l, r, t;
            cin >> l >> r >> b >> t;
            l++; r++; b++; t++;
            ans += psts[t]->query(l, r) - psts[b - 1]->query(l, r);
        }
        cout << ans << '\n';
    }
}
