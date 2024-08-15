#pragma region macros
//@formatter:off
#define GCC_OPTIMIZE_ENABLE false

#include <bits/stdc++.h>
using namespace std;
#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#ifdef LOCAL
#define DEBUG_PRINT_ if(c==cdbg) cerr << t; else cout << t;
#define lfastio print()
#else
#define DEBUG_PRINT_
#define lfastio fastio
#endif
using i16 = short; using i32 = signed; using i64 = long long; using i128 = __int128;
using u16 = unsigned short; using u32 = unsigned; using u64 = unsigned long long; using u128 = unsigned __int128;
using f32 = float; using f64 = double; using f128 = long double;
#define int i64
#define uint u64
#define ci64 const i64 &
#define cint ci64
#define ci32 const i32 &
const long long llmax = 9223372036854775807, INF = 1000000000000000000, inf = 3000000000;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define all(vec) (vec).begin(), (vec).end()
template <typename T> using v = vector<T>; template <typename T> using v2 = v<v<T>>;
template <typename T, typename T2=v<T>, typename T3=less<>> using pq = priority_queue<T, T2, T3>;
using ii = array<i64, 2>; using iii = array<i64, 3>;
template <typename T> using lim = std::numeric_limits<T>;

template <typename T = i64> T input() {T t; cin >> t; return t;}
template <typename T> T::value_type fpop(T &que) { auto t = que.front(); que.pop(); return t; }
template <typename T> T::value_type tpop(T &st) { auto t = st.top(); st.pop(); return t; }
template <typename T> void sort(v<T> &v) { sort(all(v)); }
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
template <typename T> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz)a.push_back(input<T>()); return a; }
template <typename T> void inputArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.push_back(input<T>()); }
template <typename T> v<T> sorted_copy(v<T> arr) { sort(all(arr)); return arr; }
template <typename T> v<T> compressed_copy(v<T> arr, const bool &autosort=true) { compress(arr, autosort); return arr; }
template <typename T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <typename T> T min(T a, T b, T c, T d, T e=lim<T>::max(), T f=lim<T>::max()) { return min(min(a, b), min(c, d), min(e, f)); }
template <typename T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <typename T> T max(T a, T b, T c, T d, T e=lim<T>::min(), T f=lim<T>::min()) { return max(max(a, b), max(c, d), max(e, f)); }

enum Null_{} null_; enum cdbg_{ useCerr, useCout } cdbg=useCerr, cloc=useCout;
istream& operator>>(istream& i, const Null_&) { return i; } ostream& operator<<(ostream& i, const Null_&) { return i; }
template <typename T> cdbg_& operator<<(cdbg_& c, const T& t) {
    DEBUG_PRINT_
    return c;
}

template <class A, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_>
void input(A &a, B &b=null_, C &c=null_, D &d=null_, E &e=null_, F &f=null_, G &g=null_) {
    cin >> a >> b >> c >> d >> e >> f >> g;
}
template <class A=Null_, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_, class H=Null_, class I=Null_, class J=Null_>
void print(A a=null_, B b=null_, C c=null_, D d=null_, E e=null_, F f=null_, G g=null_, H h=null_, I i=null_, J j=null_) {
    cout << a << b << c << d << e << f << g << h << i << j;
}
template <class A=Null_, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_, class H=Null_, class I=Null_, class J=Null_>
void println(A a=null_, B b=null_, C c=null_, D d=null_, E e=null_, F f=null_, G g=null_, H h=null_, I i=null_, J j=null_) {
    print(a, b, c, d, e, f, g, h, i, j); cout << '\n';
}
template <typename T>
void printArr(const v<T> &v, const string &sep = " ", const string &end = "\n") {
    for(T i : v) cout << i << sep; cout << end;
}
//@formatter:on
#pragma endregion

// 13517. 트리와 쿼리 8
// #pst #lca

class pst {
public:
    class pnd {
    public:
        pnd *l = nullptr, *r = nullptr;
        bool deleteL = false, deleteR = false;
        int val = 0;
        pnd()=default;
        pnd(bool ldel, bool rdel) : deleteL(ldel), deleteR(rdel) {}
        ~pnd(){ if(deleteL) delete l; if(deleteR) delete r; }
    };
    explicit pst(cint treeSize) : pst() {
        n = treeSize;
        init(cur, 1, n);
        end_update();
    }
    pst(cint treeSize, const v<int> &arr) : pst() {
        n = treeSize;
        assert(arr.size() == treeSize);
        init(cur, 1, n, arr);
        end_update();
    }
    ~pst() {
        for(auto &p : root) delete p;
    }
    void update(cint tar, cint val) const {
        assert(tar>0);
        update(pre, cur, 1, n, tar, val);
    }
    void update(pnd *prev, pnd *now, cint tar, cint val) const {
        update(prev, now, 1, n, tar, val);
        if(!now->l) { now->l = prev->l; now->deleteL = false; now->val += now->l->val; }
        if(!now->r) { now->r = prev->r; now->deleteR = false; now->val += now->r->val; }
    }
    void singleUpdate(cint tar, cint val) { update(tar, val); end_update(); }
    void end_update() {
        if(!cur->l) { cur->l = pre->l; cur->deleteL = false; cur->val += cur->l->val; }
        if(!cur->r) { cur->r = pre->r; cur->deleteR = false; cur->val += cur->r->val; }
        pre = cur; cur = new pnd();
        root.push_back(cur); treeCnt++;
    }
    int query(cint rootN, cint left, cint right) {
        assert(0<=rootN && rootN<treeCnt); assert(left <= right && left > 0);
        return query(root[rootN], 1, n, left, right);
    }
    pst() {
        root.push_back(new pnd());
        pre = nullptr; cur = root[0];
    }
    pnd *pre, *cur;
private:
    v<pnd*> root; int n = -1, treeCnt = 0;
    void init(pnd *node, int start, int end, const v<int> &arr) {
        if(start == end) { node->val = arr[start-1]; return; }
        node->l = new pnd(); node->r = new pnd();
        node->deleteL = true; node->deleteR = true;
        init(node->l, start, (start+end)/2, arr);
        init(node->r, (start+end)/2+1, end, arr);
        node->val = node->l->val + node->r->val;
    }
    void init(pnd *node, int start, int end) {
        if(start == end) { node->val = 0; return; }
        node->l = new pnd(); node->r = new pnd();
        node->deleteL = true; node->deleteR = true;
        init(node->l, start, (start+end)/2);
        init(node->r, (start+end)/2+1, end);
        node->val = node->l->val + node->r->val;
    }
    static void update(pnd *prev, pnd *now, int start, int end, cint tar, cint val) {
        if(start==end) { now->val += val; return; }
        if(tar <= (start+end)/2) {
            if(!now->l || now->l == prev->l) {
                now->l = new pnd();
                now->l->val = prev->l->val;
            }
            if(!now->r) now->r = prev->r;
            now->deleteL = true;
            update(prev->l, now->l, start, (start+end)/2, tar, val);
        } else {
            if(!now->l) now->l = prev->l;
            if(!now->r || now->r == prev->r) {
                now->r = new pnd();
                now->r->val = prev->r->val;
            }
            now->deleteR = true;
            update(prev->r, now->r, (start+end)/2+1, end, tar, val);
        }
        now->val = now->l->val + now->r->val;
    }
    static int query(pnd *node, int start, int end, cint left, cint right) {
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return node->val;
        return query(node->l, start, (start+end)/2, left, right) +
               query(node->r, (start+end)/2+1, end, left, right);
    }
};

i64 n, m, treeHeight, logH;
v<i64> weights(1, -INF), compressedWeights;
v2<i64> conRaw, con, par;
v<i64> depth;
v<pst::pnd*> psts;

void makeTree(ci64 v = 1, ci64 dep = 1) {
    depth[v] = dep;
    treeHeight = max(treeHeight, dep);
    for(ci64 i : conRaw[v]) {
        if(!par[i].empty()) continue;
        par[i].push_back(v);
        con[v].push_back(i);
        makeTree(i, dep + 1);
    }
}

void makePar() { forn(i, logH+1) forf(v, 1, n) par[v].push_back(par[par[v][i]][i]); }

i64 lca(i64 a, i64 b) {
    if(depth[a] > depth[b]) swap(a, b);
    i64 depDiff = depth[b] - depth[a];
    for(i64 i = logH; depDiff && i >= 0; i--)
        if(depDiff & (1<<i)) b = par[b][i], depDiff -= (1<<i);

    for(i64 i = logH; i >= 0; i--)
        if(par[a][i] != par[b][i])
            a = par[a][i], b = par[b][i];

    if(a == b) return a;
    return par[a][0];
}

pst seg(100010);

void initPst(i64 v, i64 p) {
    if(v != 1) {
        psts[v] = new pst::pnd();
        seg.update(psts[p], psts[v], idx(weights[v], compressedWeights), 1);
    }
    for(ci64 i : con[v]) initPst(i, v);
}

i64 query(pst::pnd *x, pst::pnd *y, pst::pnd *a, pst::pnd *pa, i64 k, i64 start, i64 end) {
    if(start == end) return start;
    i64 ix = 0, iy = 0, ia = 0, ipa = 0;
    if(x && x->l) ix = x->l->val;
    if(y && y->l) iy = y->l->val;
    if(a && a->l) ia = a->l->val;
    if(pa && pa->l) ipa = pa->l->val;
    i64 cnt = ix + iy - ia - ipa;
    i64 mid = (start+end)/2;
    if(k <= cnt) return query(x?x->l:nullptr, y?y->l:nullptr, a?a->l:nullptr, pa?pa->l:nullptr, k, start, mid);
    else return query(x?x->r:nullptr, y?y->r:nullptr, a?a->r:nullptr, pa?pa->r:nullptr, k-cnt, mid+1, end);
}

i32 main() {
    fastio;
    cin >> n;
    inputArr(weights, n, false);
    compressedWeights = weights; compress(compressedWeights);
    conRaw = con = par = v2<i64>(n+1, v<i64>());
    depth = v<i64>(n+1); psts = v<pst::pnd*>(n+1);
    forn(i, n-1) {
        i64 a, b; cin >> a >> b;
        conRaw[a].push_back(b);
        conRaw[b].push_back(a);
    }
    par[1].push_back(1);
    makeTree();
    logH = (i64) log2(treeHeight);
    makePar();
    seg.singleUpdate(idx(weights[1], compressedWeights), 1);
    psts[1] = seg.pre;
    initPst(1, -1);
    cin >> m;
    forn(qi, m) {
        i64 x, y, k; cin >> x >> y >> k;
        if(x == y) {
            println(weights[x]);
            continue;
        }
        i64 a = lca(x, y);
        pst::pnd *ipa = a==1?nullptr:psts[par[a][0]];
        println(compressedWeights[query(psts[x], psts[y], psts[a], ipa, k, 1, 100010)]);
    }
}
