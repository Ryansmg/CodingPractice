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
using u16 = unsigned short;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using i128 = __int128;
using f32 = float;
using f64 = double;
using f128 = long double;

#define int i64
#define uint u64
//#define double long double
#define cint ci32
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

#ifndef int
#define intmax 2147483647
#else
#define intmax llmax
#endif

#pragma region lint
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
#pragma endregion

template <typename T = i64> T input() {T t; cin >> t; return t;}

#define all(vec) (vec).begin(), (vec).end()
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

template <typename T> T pow_(T a, T b) { return pow_(a, b, intmax); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }

template <typename T> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz)a.push_back(input()); return a; }
template <typename T> v<T> sorted_copy(v<T> arr) { sort(all(arr)); return arr; }

template <typename T> void print(T t) { cout << t; }
template <typename T> void println(T t) { cout << t << '\n'; }
void print() {} void println() { cout << '\n'; }

template <class A> void in(A &a) { cin >> a; }
template <class A, class B> void in(A &a, B &b) { cin >> a >> b; }
template <class A, class B, class C> void in(A &a, B &b, C &c) { cin >> a >> b >> c; }
template <class A, class B, class C, class D> void in(A &a, B &b, C &c, D &d) { cin >> a >> b >> c >> d; }
template <class A, class B, class C, class D, class E> void in(A &a, B &b, C &c, D &d, E &e) { cin >> a >> b >> c >> d >> e; }
template <class A, class B, class C, class D, class E, class F> void in(A &a, B &b, C &c, D &d, E &e, F &f) { cin >> a >> b >> c >> d >> e >> f; }
template <class A> void out(const A &a) { cout << a; }
template <class A, class B> void out(const A &a, const B &b) { cout << a << b; }
template <class A, class B, class C> void out(const A &a, const B &b, const C &c) { cout << a << b << c; }
template <class A, class B, class C, class D> void out(const A &a, const B &b, const C &c, const D &d) { cout << a << b << c << d; }
template <class A, class B, class C, class D, class E> void out(const A &a, const B &b, const C &c, const D &d, const E &e) { cout << a << b << c << d << e; }
template <class A, class B, class C, class D, class E, class F> void out(const A &a, const B &b, const C &c, const D &d, const E &e, const F &f) { cout << a << b << c << d << e << f; }

//@formatter:on
#pragma endregion

class iterSeg {
public:
    v<int> tree; int n;
    explicit iterSeg(const v<int> &arr) { n = (int) arr.size(); init(arr); }
    explicit iterSeg(cint i) { tree = v<int>(i*4, 0); n = i; }
    void inputInit() { tree = v<int>(4*n, 0); forf(i, n, 2*n-1) cin >> tree[i]; init(); }
    /// 0 <= tar < n
    void update(int tar, int val) {
        assert(0 <= tar && tar < n);
        tree[n+tar] = val;
        for(int i = n+tar; i>1; i>>=1) tree[i>>1] = tree[i] + tree[i^1];
    }
    /// [l, r)
    int query(int left, int right) {
        assert(0 <= left && right <= n);
        int l = n+left, r = n+right, ans = 0;
        for(; l<r; l>>=1, r>>=1) {
            if(l&1) ans += tree[l++];
            if(r&1) ans += tree[--r];
        }
        return ans;
    }
private:
    void init() { for(int i=n-1; i>0; i--) tree[i] = tree[i<<1] + tree[i<<1|1]; }
    void init(const v<int> &arr) {
        tree = v<int>(4*n, 0);
        for(int i=n, j=0; i<2*n; i++, j++) tree[i] = arr[j];
        init();
    }
};

signed main() {
    fastio;
    i32 T = input<i32>();
    while(T--) {
        i64 n = input();
        pq<ii> q; // { val, idx }
        v<i64> r; // val
        v<set<i64>> con(n, set<i64>());
        forn(i, n) {
            i64 j = input();
            q.push({j, i});
            r.push_back(j);
        }
        iterSeg seg(r);
        forn(i, n-1) {
            int x, y; in(x, y);
            con[x-1].insert(y-1);
            con[y-1].insert(x-1);
        }
        i64 ans = 0;
        while(!q.empty()) {
            ans += seg.query(0, n);

        }
        println(ans);
    }
}
