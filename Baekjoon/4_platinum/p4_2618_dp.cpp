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
using iii = array<i64, 3>;
template <typename T> using lim = std::numeric_limits<T>;

template <typename T = i64> T input() {T t; cin >> t; return t;}
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

enum Null_{} nl_; enum cdbg_{ useCerr, useCout } cdbg=useCerr, cloc=useCout;
istream& operator>>(istream& i, const Null_&) { return i; } ostream& operator<<(ostream& i, const Null_&) { return i; }
template <typename T> cdbg_& operator<<(cdbg_& c, const T& t) {
    DEBUG_PRINT_
    return c;
}

template <class A, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_>
void input(A &a, B &b=nl_, C &c=nl_, D &d=nl_, E &e=nl_, F &f=nl_, G &g=nl_) {
    cin >> a >> b >> c >> d >> e >> f >> g;
}
template <class A=Null_, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_, class H=Null_, class I=Null_, class J=Null_>
void print(A a=nl_, B b=nl_, C c=nl_, D d=nl_, E e=nl_, F f=nl_, G g=nl_, H h=nl_, I i=nl_, J j=nl_) {
    cout << a << b << c << d << e << f << g << h << i << j;
}
template <class A=Null_, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_, class H=Null_, class I=Null_, class J=Null_>
void println(A a=nl_, B b=nl_, C c=nl_, D d=nl_, E e=nl_, F f=nl_, G g=nl_, H h=nl_, I i=nl_, J j=nl_) {
    print(a, b, c, d, e, f, g, h, i, j); cout << '\n';
}
template <typename T>
void printArr(const v<T> &v, const string &sep = " ", const string &end = "\n") {
    for(T i : v) cout << i << sep; cout << end;
}
//@formatter:on
#pragma endregion
struct ii {
    i64 a, b;
    ii()=default;
    ii(i64 c, i64 d) : a(c), b(d) {}
    i64 operator()(const ii &other) const {
        return abs(a-other.a)+abs(b-other.b);
    }
};

i32 main() {
    fastio;
    i64 n = input();
    i64 w = input();
    v<ii> v; i64 a, b;
    forn(i, w) {
        input(a, b); v.emplace_back(a, b);
    }
    v2l dp(w+2, vl(w+2, INF)); // [w]: 1, [w+1] : 2
    vector<vector<ii>> pre(w+2, vector<ii>(w+2, {INF, INF}));
    ii A(1, 1), B(n, n);
    dp[0][w+1] = A(v[0]); dp[w][0] = B(v[0]);
    pre[0][w+1] = {w, w+1}; pre[w][0] = {w, w+1};
    v.emplace_back(A); v.emplace_back(B);
    i64 ans = INF;
    forf(i, 1, w-1) {
        forn(j, w+2) {
            if(dp[i-1][j] != INF) {
                if(dp[i][j] > dp[i-1][j] + v[i-1](v[i])) {
                    dp[i][j] = dp[i-1][j] + v[i-1](v[i]);
                    pre[i][j] = {i-1, j};
                }
                if(dp[i-1][i] > dp[i-1][j] + v[j](v[i])) {
                    dp[i-1][i] = dp[i-1][j] + v[j](v[i]);
                    pre[i-1][i] = { i-1, j };
                }
            }
            if(dp[j][i-1] != INF) {
                if(dp[j][i] > dp[j][i-1] + v[i-1](v[i])) {
                    dp[j][i] = dp[j][i-1] + v[i-1](v[i]);
                    pre[j][i] = { j, i-1 };
                }
                if(dp[i][i-1] > dp[j][i-1] + v[i](v[j])) {
                    dp[i][i-1] = dp[j][i-1] + v[i](v[j]);
                    pre[i][i-1] = { j, i-1 };
                }
            }
        }
    }
    ii r(0, 0);
    forn(j, w+2) {
        ans = min(ans, dp[w-1][j], dp[j][w-1]);
        if(ans == dp[w-1][j]) r = {w-1, j};
        else if(ans == dp[j][w-1]) r = {j, w-1};
    }
    println(ans);
    stack<i64> st;
    for(; r.a != w || r.b != w+1; r = pre[r.a][r.b]) {
        if(pre[r.a][r.b].a == r.a) st.push(2);
        else st.push(1);
    }
    while(!st.empty()) {
        println(st.top()); st.pop();
    }
}
