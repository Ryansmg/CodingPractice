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
const i64 llmax = 9223372036854775807, INF = 1000000000000000000, inf = 3000000000;

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

namespace FFT {
    using cpl = complex<f64>;
#define sz(v) ((i32)v.size())
    void fft(v<cpl>& a) {
        i32 n = sz(a), L = 31 - __builtin_clz(n);
        static vector<complex<f128>> R(2, 1);
        static v<cpl> rt(2, 1); // (^ 10% faster if double)
        for(i32 k = 2; k < n; k *= 2) {
            R.resize(n); rt.resize(n);
            auto x = polar(1.0L, acos(-1.0L) / k);
            for(i32 i = k; i < k + k; i++) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
        }
        vi rev(n);
        for(i32 i = 0; i < n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
        for(i32 i = 0; i < n; i++) if(i < rev[i]) swap(a[i], a[rev[i]]);
        for(i32 k = 1; k < n; k *= 2) {
            for(i32 i = 0; i < n; i += 2 * k)
                for(i32 j = 0; j < k; j++) {
                    //complex_t z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled) /// include-line
                    auto x = (double *) &rt[j + k], y = (double *) &a[i + j + k]; /// exclude-line
                    cpl z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]); /// exclude-line
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] += z;
                }
        }
    }
    template <typename T>
    v<T> operator*(const v<T>& a, const v<T>& b) {
        if(a.empty() || b.empty()) return {};
        v<T> res(sz(a) + sz(b) - 1);
        i32 L = 32 - __builtin_clz(sz(res)), n = 1 << L;
        v<cpl> in(n), out(n);
        copy(all(a), begin(in));
        for(i32 i = 0; i < sz(b); i++) in[i].imag(b[i]);
        fft(in);
        for(cpl &x: in) x *= x;
        for(i32 i = 0; i < n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
        fft(out);
        for(i32 i = 0; i < sz(res); i++) {
            res[i] = static_cast<T>(imag(out[i]) / (4 * n) +
                                    (is_integral_v<T> ? (imag(out[i]) > 0 ? 0.5 : -0.5) : 0));
        }
        return res;
    }
    template <typename T>
    v<T>& operator*=(v<T>& a, const v<T>& b) {
        if(a.empty() || b.empty()) return a = {};
        v<T> res(sz(a) + sz(b) - 1);
        i32 L = 32 - __builtin_clz(sz(res)), n = 1 << L;
        v<cpl> in(n), out(n);
        copy(all(a), begin(in));
        for(i32 i = 0; i < sz(b); i++) in[i].imag(b[i]);
        fft(in);
        for(cpl &x: in) x *= x;
        for(i32 i = 0; i < n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
        fft(out);
        for(i32 i = 0; i < sz(res); i++) {
            res[i] = static_cast<T>(imag(out[i]) / (4 * n) +
                                    (is_integral_v<T> ? (imag(out[i]) > 0 ? 0.5 : -0.5) : 0));
        }
        a = res;
        return a;
    }
}
using namespace FFT;

void to01(vl &a) { for(i64 &i : a) i=i?1:0; }

vl pow_(vl a, i64 b) {
    vl ans = a; b--;
    while(b) {
        if(b&1) ans *= a;
        to01(ans);
        b >>= 1;
        a *= a;
        to01(a);
    }
    return ans;
}

// 13575. 보석 가게
// #fft

i32 main() {
    fastio;
    i64 n = In, k = In;
    vl arr(1010, 0);
    forn(i, n) arr[input()]++;
    vl a = pow_(arr, k);
    forn(i, a.size()) if(a[i]) print(i, ' ');
}
