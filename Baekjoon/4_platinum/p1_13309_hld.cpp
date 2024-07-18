#pragma region macros
//@formatter:off
#define GCC_OPTIMIZE_ENABLE false

#include <bits/stdc++.h>
using namespace std;

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

using i16 = short;
using i32 = signed;
using i64 = long long;
using i128 = __int128;
using u16 = unsigned short;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using f32 = float;
using f64 = double;
using f128 = long double;

#define int i64
#define uint u64
//#define double long double
#define ci64 const i64 &
#define cint ci64
#define ci32 const i32 &

const long long llmax = 9223372036854775807; // 2^63-1
const long long INF = 1000000000000000000; // INF * INF > 2^63
const long long inf = 3000000000; // inf > 2^31, inf * inf < 2^63
const signed smax = 2147483647;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define pass {cout << "";} // do nothing

#ifndef ONLINE_JUDGE
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)
#else
#define filein cout << ""
#define fileout filein
#endif
#define fileio filein; fileout

template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<i64, 2>;
using iii = array<i64, 3>;

const i128 LINTMAX = ((i128(1)<<126)-1)*2+1;
__int128 operator ""_I(const char* str, size_t len) {
    __int128 t = 0; i64 st=0, sign=1; if(*str == '-') sign=-1, st=1;
    for(i64 i=st; i < len; i++) { t *= 10; t += (*(str + i) - '0'); }
    return t*sign;
}
istream &operator>>(istream &in, __int128 &l) {
    string s; in >> s; size_t len = s.size(); i64 sign = 1, st = 0; l=0;
    if(s[0]=='-') sign=-1, st=1; for(i64 i=st; i<len; i++) { l *= 10; l += s[i]-'0'; }
    l*=sign; return in;
}
ostream &operator<<(ostream &out,const __int128 &i) {
    __int128 t = i<0?-i:i; if(!t) out << 0; if(i<0) out << '-';
    stack<char> st; while(t) { st.push((char)((t%10)+'0')); t/=10; }
    while(!st.empty()){out<<st.top();st.pop();} return out;
}

template <typename T = i64> T input() {T t; cin >> t; return t;}

#define all(vec) (vec).begin(), (vec).end()
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

template <typename T> T pow_(T a, T b) { return pow_(a, b, numeric_limits<T>::max()); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }

template <typename T> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz)a.push_back(input()); return a; }
template <typename T> void inputArr(v<T> &arr, i64 sz) { forn(i,sz) arr.push_back(input()); }
template <typename T> v<T> sorted_copy(v<T> arr) { sort(all(arr)); return arr; }
template <typename T> v<T> compressed_copy(v<T> arr, const bool &autosort=true) { compress(arr, autosort); return arr; }

enum Null_{} null_;
istream& operator>>(istream& i, const Null_&) { return i; }
ostream& operator<<(ostream& i, const Null_&) { return i; }
template <typename T> bool isNull() { return typeid(T)==typeid(Null_); }
template <typename T> bool isNull(T) { return typeid(T)==typeid(Null_); }

template <class A, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_>
void input(A &a, B &b=null_, C &c=null_, D &d=null_, E &e=null_, F &f=null_, G &g=null_) {
    if(!isNull<G>()) cin >> a >> b >> c >> d >> e >> f >> g;
    else if(!isNull(f)) cin >> a >> b >> c >> d >> e >> f;
    else if(!isNull(g)) cin >> a >> b >> c >> d >> e;
    else if(!isNull(d)) cin >> a >> b >> c >> d;
    else if(!isNull(c)) cin >> a >> b >> c;
    else if(!isNull(b)) cin >> a >> b;
    else cin >> a;
}

template <class A=Null_, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_, class H=Null_, class I=Null_, class J=Null_>
void print(A a=null_, B b=null_, C c=null_, D d=null_, E e=null_, F f=null_, G g=null_, H h=null_, I i=null_, J j=null_) {
    if(!isNull(j)) cout << a << b << c << d << e << f << h << i << j;
    else if(!isNull(i)) cout << a << b << c << d << e << f << h << i;
    else if(!isNull(h)) cout << a << b << c << d << e << f << h;
    else if(!isNull(g)) cout << a << b << c << d << e << f << g;
    else if(!isNull(f)) cout << a << b << c << d << e << f;
    else if(!isNull(e)) cout << a << b << c << d << e;
    else if(!isNull(d)) cout << a << b << c << d;
    else if(!isNull(c)) cout << a << b << c;
    else if(!isNull(b)) cout << a << b;
    else cout << a;
}
template <class A=Null_, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_, class H=Null_, class I=Null_, class J=Null_>
void println(A a=null_, B b=null_, C c=null_, D d=null_, E e=null_, F f=null_, G g=null_, H h=null_, I i=null_, J j=null_) {
    print(a, b, c, d, e, f, g, h, i, j); cout << '\n';
}

//@formatter:on
#pragma endregion

// 트리
// #hld #segtree

class iterSeg {
public:
    v<int> tree; int n=-1;
    iterSeg() = default;
    explicit iterSeg(cint i) { tree = v<int>(i*4, 0); n = i; }
    /// 0 <= tar < n
    void update(int tar, int val) {
        assert(0 <= tar && tar < n);
        tree[n+tar] = val;
        for(int i = n+tar; i>1; i>>=1) tree[i>>1] = tree[i] + tree[i^1];
    }
    /// [l, r]
    int query(int left, int right) {
        assert(0 <= left && right <= n);
        right++;
        int l = n+left, r = n+right, ans = 0;
        for(; l<r; l>>=1, r>>=1) {
            if(l&1) ans += tree[l++];
            if(r&1) ans += tree[--r];
        }
        return ans;
    }
};

#pragma region disable c-style types
#define float
#undef int
#define int
#undef double
#define double
#pragma endregion

iterSeg seg;
v<i64> par, sz, in, out, top, dep;
v2<i64> con;
i64 ini = 0;

void dfs1(i64 v=1) {
    sz[v] = 1;
    for(i64 &i : con[v]) {
        dep[i] = dep[v] + 1;
        dfs1(i);
        sz[v] += sz[i];
        if(sz[con[v][0]] < sz[i])
            swap(i, con[v][0]);
    }
}

void dfs2(i64 v=1) {
    in[v] = ++ini;
    for(i64 &i : con[v]) {
        top[i] = i==con[v][0] ? top[v] : i;
        dfs2(i);
    }
    out[v] = ini;
}

bool query(i64 a, i64 b) {
    while(top[a] != top[b]) {
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        if (seg.query(in[top[a]], in[a])) return true;
        a = par[top[a]];
    }
    if(dep[a] > dep[b]) swap(a, b);
    return seg.query(in[a]+1, in[b]);
}

i32 main() {
    fastio;
    i64 n, q; input(n, q);
    par = sz = in = out = top = dep = v<i64>(n+1);
    con = v2<i64>(n+1, v<i64>());
    forf(i, 2, n) {
        i64 t = input();
        par[i] = t;
        con[t].push_back(i);
    }
    dep[1] = 0;
    dfs1(); dfs2();
    seg = iterSeg(n+1);
    forn(qi, q) {
        i64 b, c, d; input(b, c, d);
        if(!d) println(query(b, c) ? "NO" : "YES");
        else {
            if(query(b, c)) {
                println("NO");
                seg.update(in[c], 1);
            } else {
                println("YES");
                seg.update(in[b], 1);
            }
        }
    }
}
