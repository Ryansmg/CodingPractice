#pragma region macros
//@formatter:off
#define GCC_OPTIMIZE_ENABLE false
#define ENABLE_CPP20_MACRO true

#include <bits/stdc++.h>
using namespace std;
#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#ifdef LOCAL
#define lfastio print()
#else
#define lfastio fastio
#endif
using i16 = short; using i32 = signed; using i64 = long long; using i128 = __int128;
using u16 = unsigned short; using u32 = unsigned; using u64 = unsigned long long; using u128 = unsigned __int128;
using f32 = float; using f64 = double; using f128 = long double; using F128 = __float128;
using str = string;
#define int i64
#define uint u64
#define ci64 const i64 &
#define cint ci64
#define ci32 const i32 &
constexpr i64 llmax = 9223372036854775807, INF = 1000000000000000000, inf = 3000000000;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define forr(name, start, end) for(i64 name = start; name >= end; name--)
#define rep(n) forn(bit_Ly_S, n)
#define rep2(n) forn(la_sh_Discord, n)

i64 inRep_var_, inRep_var_2_;
#define inRep() input(inRep_var_); forn(inRep_var_3_, inRep_var_)
#define inRep2() input(inRep_var_2_); forn(inRep_var_4_, inRep_var_2_)

#define all(vec) (vec).begin(), (vec).end()
template <typename T> using v = vector<T>; template <typename T> using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>; using vi = v<i32>;
#define pb push_back
#define eb emplace_back
using ii = array<i64, 2>; using iii = array<i64, 3>;
template <typename T> using lim = std::numeric_limits<T>;

template <typename T = i64> T input() {T t; cin >> t; return t;} template <typename T = i64> T in() {T t; cin >> t; return t;}
#define In (in())
#if ENABLE_CPP20_MACRO
template <typename T, typename T2=v<T>, typename T3=less<>> using pq = priority_queue<T, T2, T3>;
template <typename T> T::value_type fpop(T &que) { auto t = que.front(); que.pop(); return t; }
template <typename T> T::value_type tpop(T &st) { auto t = st.top(); st.pop(); return t; }
#endif
template <typename T> void reverse(v<T> &v) { reverse(all(v)); }
template <typename T> void sort(v<T> &v) { sort(all(v)); }
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
template <typename T = i64> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz) a.push_back(input<T>()); return a; }
template <typename T> void inputArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.push_back(input<T>()); }
template <typename T> v<T> sorted_copy(v<T> arr) { sort(all(arr)); return arr; }
template <typename T> v<T> compressed_copy(v<T> arr, const bool &autosort=true) { compress(arr, autosort); return arr; }

enum Nl_{} nl_; istream& operator>>(istream& i, const Nl_&) { return i; } ostream& operator<<(ostream& i, const Nl_&) { return i; }

template <class A, class B=Nl_, class C=Nl_, class D=Nl_, class E=Nl_, class F=Nl_, class G=Nl_>
void input(A &a, B &b=nl_, C &c=nl_, D &d=nl_, E &e=nl_, F &f=nl_, G &g=nl_) { cin >> a >> b >> c >> d >> e >> f >> g; }
template <class A=Nl_, class B=Nl_, class C=Nl_, class D=Nl_, class E=Nl_, class F=Nl_, class G=Nl_, class H=Nl_, class I=Nl_, class J=Nl_>
void print(A a=nl_, B b=nl_, C c=nl_, D d=nl_, E e=nl_, F f=nl_, G g=nl_, H h=nl_, I i=nl_, J j=nl_) { cout << a << b << c << d << e << f << g << h << i << j; }
template <class A=Nl_, class B=Nl_, class C=Nl_, class D=Nl_, class E=Nl_, class F=Nl_, class G=Nl_, class H=Nl_, class I=Nl_, class J=Nl_>
void println(A a=nl_, B b=nl_, C c=nl_, D d=nl_, E e=nl_, F f=nl_, G g=nl_, H h=nl_, I i=nl_, J j=nl_) { print(a, b, c, d, e, f, g, h, i, j); cout << '\n'; }
template <typename T>
void printArr(const v<T> &v, const string &sep = " ", const string &end = "\n") { for(const T &i : v) cout << i << sep; cout << end; }
//@formatter:on
#pragma endregion

namespace NTT {
    // 3, 998244353
    // 3, 2281701377
    void ntt(vl &f, bool inv, i64 w, i64 mod){
        i64 n = f.size();
        for(i64 i=1, j=0; i<n; i++) {
            i64 bit = (n >> 1);
            while(j >= bit) { j -= bit; bit >>= 1; }
            j += bit;
            if(i < j) swap(f[i], f[j]);
        }
        vl root(n >> 1);
        i64 wp = pow_(w, (mod - 1) / n, mod); if(inv) wp = pow_(wp, mod - 2, mod);
        root[0] = 1; for(i64 i=1; i < (n >> 1); i++) root[i] = root[i-1] * wp % mod;
        for(i64 i=2; i<=n; i<<=1){
            i64 step = n / i;
            for(i64 j=0; j<n; j+=i){
                for(i64 k=0; k < (i >> 1); k++){
                    i64 u = f[j | k], v = f[j | k | i >> 1] * root[step * k] % mod;
                    f[j | k] = (u + v) % mod;
                    f[j | k | i >> 1] = (u - v) % mod;
                    if(f[j | k | i >> 1] < 0) f[j | k | i >> 1] += mod;
                }
            }
        }
        i64 t = pow_(n, mod - 2, mod);
        if(inv) forn(i, n) f[i] = f[i] * t % mod;
    }

    vl multiply(const vl &_a, const vl &_b, i64 w, i64 mod){
        vl a(all(_a)), b(all(_b));
        i64 n = 2;
        while(n < a.size() + b.size()) n <<= 1;
        a.resize(n); b.resize(n);
        ntt(a, false, w, mod); ntt(b, false, w, mod);
        forn(i, n) a[i] = a[i] * b[i] % mod;
        ntt(a, true, w, mod);
        return a;
    }

}
using namespace NTT;

// 11385. 씽크스몰
// #fft #crt

i32 main() {
    fastio;
    i64 n, m; input(n, m);
    vl a = inputArr(n+1), b = inputArr(m+1);
    i64 p1 = 998244353, p2 = 2281701377;
    vl c = multiply(a, b, 3, p1), d = multiply(a, b, 3, p2);
    i64 ans = 0;
    i128 crt1 = pow_(p2, p1-2, p1), crt2 = pow_(p1, p2-2, p2);
    i64 M = p1 * p2;
    forn(i, c.size()) {
        ans ^= (p2*crt1%M*c[i]%M + p1*crt2%M*d[i]%M)%M;
    }
    println(ans);
}
