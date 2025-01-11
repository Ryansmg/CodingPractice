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
using vl = v<i64>; using v2l = v2<i64>;
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

i64 n, m, treeHeight, logH;
v2l conRaw, con, par;
vl depth, d(1, -1);
vl s, e, ca, len;
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

bool lenCmp(i64 a, i64 b) { return len[a] < len[b]; }
vl path1, path2;
void makePath1(i64 a) {
    path1.clear();
    i64 cur = s[a];
    while(cur != ca[a]) {
        path1.push_back(d[cur]);
        cur = par[cur][0];
    }
    path1.push_back(d[cur]);
    stack<i64> st;
    cur = e[a];
    while(cur != ca[a]) {
        st.push(cur);
        cur = par[cur][0];
    }
    while(!st.empty()) path1.push_back(d[tpop(st)]);
}
void makePath2(i64 a) {
    path2.clear();
    i64 cur = s[a];
    while(cur != ca[a]) {
        path2.push_back(d[cur]);
        cur = par[cur][0];
    }
    path2.push_back(d[cur]);
    stack<i64> st;
    cur = e[a];
    while(cur != ca[a]) {
        st.push(cur);
        cur = par[cur][0];
    }
    while(!st.empty()) path2.push_back(d[tpop(st)]);
}
bool pathCmp(i64 a, i64 b) {
    makePath1(a);
    makePath2(b);
    i64 sz = (i64) path1.size();
    assert(path2.size() == sz);
    forn(i, sz) if(path1[i] != path2[i]) return path1[i] < path2[i];
    return a < b;
}

i32 main() {
    fastio;
    cin >> n >> m;
    inputArr(d, n, false);
    depth = vl(n+1);
    conRaw = con = par = v2l(n+1, vl());
    forn(i, n-1) {
        i64 u, v; cin >> u >> v;
        conRaw[u].push_back(v);
        conRaw[v].push_back(u);
    }
    par[1].push_back(1);
    makeTree();
    logH = (i64) log2(treeHeight);
    makePar();
    s = e = ca = len = vl(m+1);
    forf(i, 1, m) cin >> s[i] >> e[i];
    forf(i, 1, m) ca[i] = lca(s[i], e[i]);
    forf(i, 1, m) len[i] = depth[s[i]] + depth[e[i]] - 2*depth[ca[i]] + 1;
    vl ps(m); iota(all(ps), 1);
    sort(all(ps), lenCmp);
    i64 pre = 0, cur = 0;
    while(cur < m) {
        while (cur < m && len[ps[pre]] == len[ps[cur]]) cur++;
        sort(ps.begin() + pre, ps.begin() + cur, pathCmp);
        forf(i, pre, cur-1) {
            cout << ps[i] << '\n';
        }
        pre = cur;
    }
}
