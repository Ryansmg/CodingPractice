#pragma region options
#define USE_O3 0
#define USE_OFAST 0
#define USE_TARGET 0
#define USE_MMAP 0
#define LOCAL_FASTIO 1
#define LOCAL_INLINE 0
#define DISABLE_LOCAL 0
#pragma endregion

#pragma region C+++
//@formatter:off
#define CPPP98 250309
#include <bits/stdc++.h>
using namespace std;
#pragma region settings

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma ide diagnostic ignored "OCUnusedTypeAliasInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "UnreachableCallsOfFunction"
#pragma ide diagnostic ignored "UnusedLocalVariable"
#pragma ide diagnostic ignored "UnusedValue"
#ifdef LOCAL
#define LOCAL_DEFINED 1
#else
#define LOCAL_DEFINED 0
#if USE_TARGET
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif
#endif
#if DISABLE_LOCAL
#undef LOCAL
#endif
#if USE_OFAST
#pragma GCC optimize("Ofast,unroll-loops")
#elif USE_O3
#pragma GCC optimize("O3,unroll-loops")
#endif
#pragma endregion
#pragma region keywords
#define fun std::function
typedef long long i64;
typedef signed i32;
typedef __int128 i128;
typedef std::string str;
typedef long double f128;
typedef double f64;
typedef float f32;
#define vec vector
typedef vec<i64> vl;
typedef vec<bool> vb;
typedef vec<vec<i64>> v2l;
#define lim std::numeric_limits
#define ci64 const i64 &
#define ci32 const i32 &
#define cast static_cast
#define all(v_) (v_).begin(), (v_).end()
#define pb push_back
#define eb emplace_back
#define Tpl template <typename T>
#define Tpl64 template <typename T = long long>
#ifdef LOCAL
#define lassert assert

#if (!LOCAL_INLINE)
#define inline // preventing debugging issue
#endif
#else
#define lassert(...)
#endif
#define forn(name_, val_) for(long long name_ = 0; name_ < (val_); name_++)
#define forf(name_, start_, end_) for(long long name_ = (start_); name_ <= (end_); name_++)
#define forr(name_, start_, end_) for(long long name_ = (start_); name_ >= (end_); name_--)
/// foreach reverse
#define forer(...) for(__VA_ARGS__ | std::views::reverse)
#define rep(n_) forn(rep_mac_name_1_, n_)
#define rep2(n_) forn(rep_mac_name_2_, n_)
#define rep3(n_) forn(rep_mac_name_3_, n_)
#define loop while(true)

long long iR_v_, iR_v2_, iR_v5_;
#define inRep() input(iR_v_); forn(iR_v3_, iR_v_)
#define inRep2() input(iR_v2_); forn(iR_v4_, iR_v2_)
#define inRep3() input(iR_v2_); forn(iR_v4_, iR_v2_)
#define tcRep() input(iR_v5_); forf(TCN, 1, iR_v5_)
#pragma endregion
#pragma region constants
constexpr long long
        i64max = 9223372036854775807,    /// lim<i64>::max()
i64min = -9223372036854775807-1, /// lim<i64>::min()
lmax   = 9221557155715571557,    /// lmax + inf < i64max
INFIN  = 4001557155715570000,    /// INFIN * 2 < i64max
INF    = 1000000000000000000,    /// INF * 9 < i64max
inf    = 3000000000,             /// inf * inf < i64max
i32max = 2147483647,             /// lim<i32>::max()
i32min = -2147483648,            /// lim<i32>::min()
imax   = 2147481557,             /// imax + 1000 < i32max
iinf   = 2000000000,             /// iinf + 1e8 < i32max
mod1   = 1000000007,
        mod9   = 998244353;
constexpr long double
        PI = 3.141592653589793238462643383279502884L;
#pragma endregion
#pragma region algorithms
template <typename T> inline long long Size(const T& v_) { return static_cast<long long>(v_.size()); }

#define lb(arr_, ...) (std::lower_bound(arr_.begin(), arr_.end(), __VA_ARGS__))
#define ub(arr_, ...) (std::upper_bound(arr_.begin(), arr_.end(), __VA_ARGS__))

template <typename T, typename Compare> inline T pop(std::priority_queue<T, std::vector<T>, Compare> &pq_) { T t_ = pq_.top(); pq_.pop(); return t_; }
template <typename T> inline T pop(std::stack<T> &st_) { T t_ = st_.top(); st_.pop(); return t_; }
template <typename T> inline T pop(std::stack<T, std::vector<T>> &st_) { T t_ = st_.top(); st_.pop(); return t_; }
template <typename T> inline T pop(std::queue<T> &q_) { T t_ = q_.front(); q_.pop(); return t_; }
template <typename T> inline T pop(std::queue<T, std::list<T>> &q_) { T t_ = q_.front(); q_.pop(); return t_; }
template <typename T> inline T pop(std::vector<T> &arr_) { T t_ = arr_.back(); arr_.pop_back(); return t_; }

template <typename T> inline void reverse(T& v_) { std::reverse(v_.begin(), v_.end()); }
template <typename T> inline T reversed(T v_) { reverse(v_); return v_; }
template <typename T> inline void sort(T& v_) { std::sort(v_.begin(), v_.end()); }
template <typename T, typename Cmp> inline void sort(T& v_, const Cmp& cmp) { std::sort(v_.begin(), v_.end(), cmp); }
template <typename T> inline T sorted(T v_) { std::sort(v_.begin(), v_.end()); return v_; }
template <typename T, typename Cmp> inline T sorted(T v_, const Cmp& cmp) { std::sort(v_.begin(), v_.end(), cmp); return v_; }

template <typename T> inline void compress(T &v_, const bool& autosort = true) { if(autosort) std::sort(v_.begin(), v_.end()); v_.erase(std::unique(v_.begin(), v_.end()), v_.end()); }
template <typename T> inline T compressed(T v_, const bool &autosort = true) { compress(v_, autosort); return v_; }
/// @returns >= 0
template <typename T> inline long long cidx(const T &val, const std::vector<T> &compressed) { return std::lower_bound(compressed.begin(), compressed.end(), val) - compressed.begin(); }
/// min(arr) == 1, max(arr) <= Size(arr)
template <typename T> inline void autoCompress(T &v_) { auto comp_ = compressed(v_); for(auto& t : v_) t = cidx(t, comp_) + 1; }
/// min(arr) == 0, max(arr) <= Size(arr)
template <typename T> inline void autoCompress0(T &v_) { auto comp_ = compressed(v_); for(auto& t : v_) t = cidx(t, comp_); }
template <typename T> inline T autoCompressed(T v_) { autoCompress(v_); return v_; }
template <typename T> inline T autoCompressed0(T v_) { autoCompress0(v_); return v_; }

template <typename T> inline std::vector<T> merge(const std::vector<T>&a, const std::vector<T>&b) {
    std::vector<T> ret(a.size()+b.size()); std::merge(a.begin(), a.end(), b.begin(), b.end(), ret.begin()); return ret;
}
#pragma endregion
#pragma region math
template <typename T> inline T gcd(T a, T b) { if(a < b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
template <typename T> inline T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T modInv(T a, const T& m, bool chkGcd = true) { // by @kuhyaku
    T b = m, u = 1, v = 0; if(chkGcd) assert(gcd(a, m) == 1);
    while (b) { T t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
    u %= m; if (u < 0) {u += m;} return u;
}
inline long long pow(long long a, long long b, long long mod) {return pow_(b < 0 ? modInv(a, mod) : a, std::abs(b), mod);}

template <typename T> inline T max(const std::vector<T>& v_) { T ret = v_.empty() ? std::numeric_limits<T>::min() : v_[0]; for(const T &t_ : v_) { ret = std::max(ret, t_); } return ret; }
template <typename T> inline T min(const std::vector<T>& v_) { T ret = v_.empty() ? std::numeric_limits<T>::max() : v_[0]; for(const T &t_ : v_) { ret = std::min(ret, t_); } return ret; }
inline long long max(long long a, long long b) { return a > b ? a : b; } inline long long min(long long a, long long b) { return a < b ? a : b; }
template <typename T> inline T lcm_(const T& a, const T& b) { return a / gcd_(a, b) * b; } template <typename T> inline T sq_(const T& i) { return i * i; }
template <typename T> inline T sum(const std::vector<T>& v_) { T s_ = T(); {for(const T& i_ : v_) s_ += i_;} return s_; }
template <typename T> inline T gcd(const std::initializer_list<T>& l_) { auto iter = l_.begin(); T ret = *iter; long long sz_ = l_.size();
    for(long long i_ = 1; i_ <= sz_-1; i_++) { ret = gcd(ret, *(++iter)); } return ret; }
template <typename T> inline T lcm(const std::initializer_list<T>& l_) { auto iter = l_.begin(); T ret = *iter / gcd(l_); long long sz_ = l_.size();
    for(long long i_ = 1; i_ <= sz_-1; i_++) { ret *= *(++iter); } return ret; }

inline signed popcount(long long v) { return __builtin_popcountll((unsigned long long) v); }
inline signed lmb(long long v) { return 63 - __builtin_clzll(v); } /// left most bit (000100 => 2)

std::random_device mrdvce_; std::mt19937 m1gn_(mrdvce_());
std::uniform_int_distribution<signed> uni3i32_(0, 2147483647); std::uniform_int_distribution<long long> uni3i64_(0, 9223372036854775807);
#define rand rand_
inline signed randi() { return uni3i32_(m1gn_); } inline long long randl() { return uni3i64_(m1gn_); }
inline long long rand_(long long l_, long long r_) { return randl() % (r_ - l_ + 1) + l_; } /// inclusive
constexpr signed dx4[4] = { 0, 1, 0, -1 }; constexpr signed dy4[4] = { -1, 0, 1, 0 };
#pragma endregion
#pragma region I/O

#if (!LOCAL_DEFINED) || LOCAL_FASTIO
struct enable_fastio_ {
    enable_fastio_() { std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); }
} efio_;
#endif

struct consumer_ {
    inline friend istream& operator>>(istream& in, const consumer_&) { return in; }
    inline friend ostream& operator<<(ostream& out, const consumer_&) { return out; }
};
constexpr consumer_ cs_;

inline void print() {}
template <typename T1, typename T2 = const consumer_, typename T3 = const consumer_,
        typename T4 = const consumer_, typename T5 = const consumer_, typename T6 = const consumer_, typename T7 = const consumer_>
inline void print(const T1& a, const T2& b = cs_, const T3& c = cs_, const T4& d = cs_, const T5& e = cs_, const T6& f = cs_, const T7& g = cs_) {
    cout << a << b << c << d << e << f << g;
}

template <typename... T>
inline void println(const T&... t) {
    print(t...); cout << '\n';
}
inline void println() { cout << '\n'; }

template <typename T = i64> inline T input() { T t; cin >> t; return t; }
template <typename T1, typename T2 = const consumer_, typename T3 = const consumer_,
        typename T4 = const consumer_, typename T5 = const consumer_, typename T6 = const consumer_, typename T7 = const consumer_>
inline void input(T1& a, T2& b = cs_, T3& c = cs_, T4& d = cs_, T5& e = cs_, T6& f = cs_, T7& g = cs_) {
    cin >> a >> b >> c >> d >> e >> f >> g;
}
template <typename T> void vecInput(std::vector<T>& arr) {
    for(T& i : arr) cin >> i;
}

#define in64(...) i64 __VA_ARGS__; input(__VA_ARGS__)

std::vector<long long> qin_data_;
short qin_t_ = 0, qin_c_ = 0;
long long qin_h_(long long idx, long long n) {
    if(!qin_c_) { qin_t_ = n; qin_data_.resize(n);
        for(long long i = 0; i < n; i++) std::cin >> qin_data_[i]; }
    if(++qin_c_ == qin_t_) qin_t_ = qin_c_ = 0;
    return qin_data_[idx];
}
inline long long QIN_H_() { long long t; std::cin >> t; return t; } // qin() support
#define EXPAND_(x) x
#define QIN_H1_(n) qin_h_(0, n)
#define QIN_H2_(n) QIN_H1_(n), qin_h_(1, n)
#define QIN_H3_(n) QIN_H2_(n), qin_h_(2, n)
#define QIN_H4_(n) QIN_H3_(n), qin_h_(3, n)
#define QIN_H5_(n) QIN_H4_(n), qin_h_(4, n)
#define QIN_H6_(n) QIN_H5_(n), qin_h_(5, n)
#define QIN_H7_(n) QIN_H6_(n), qin_h_(6, n)
#define QIN_H8_(n) QIN_H7_(n), qin_h_(7, n)
#define qin(n) EXPAND_(QIN_H##n##_(n))


#pragma endregion
#pragma region qol
template <typename T> inline std::string tostr(const T &t) { return std::to_string(t); }
inline std::string tostr(const std::string &t) { return t; }
inline std::string tostr(const __int128 &i) {std::string ret,bs;if(i==lim<i128>::min())return tostr(i/10)+"8";
    if(!i){return"0";}if(i<0)return"-"+tostr(-i);__int128 t=1;forn(as,18)t*=10;__int128 a=i/(t*t);if(a){ret+=tostr((long long)a);
        bs=tostr((long long)(i/t%(t*10)+t));forn(j,18)ret+=bs[j+1];bs=tostr((long long)((i%t)+t));forn(j,18)ret+=bs[j+1];
    }else{__int128 b=i/t%(t*10);if(b){ret+=tostr((long long)b);bs=tostr((long long)((i%t)+t));
            forn(j,18) ret+=bs[j+1];}else{ret+=tostr((long long)(i%t));}}return ret;}
#define mac_conv_(name, type, sh) template <typename T> inline type to##name(const T &t) { return static_cast<type>(t); } \
                                                        inline type to##name(const std::string &t) { return sto##sh(t); }
template <typename T> inline __int128 toi128(const T &t) { return static_cast<__int128>(t); }
inline __int128 toi128(const std::string &t) { return static_cast<__int128>(stoull(t)); }
mac_conv_(i64, long long, ll) mac_conv_(i32, signed, i) mac_conv_(u64, unsigned long long, ull)
mac_conv_(f32, float, f) mac_conv_(f64, double, d) mac_conv_(f128, long double, ld)

template <typename T, typename T2, typename T3> inline T replace_if(const T& origin, const T2& cond, const T3& replacement) {
    return origin == static_cast<T>(cond) ? static_cast<T>(replacement) : origin;
}
#define rplf replace_if

template <typename T, typename T2> inline void setMin(T& tar, const T2& val) {
    if(static_cast<T>(val) < tar) tar = static_cast<T>(val);
}
template <typename T, typename T2, typename... T3>
inline void setMin(T& tar, const T2 &val, const T3&... arr) { setMin(tar, val); setMin(tar, arr...); }

template <typename T, typename T2> inline void setMax(T& tar, const T2& val)  {
    if(static_cast<T>(val) > tar) tar = static_cast<T>(val);
}
template <typename T, typename T2, typename... T3>
inline void setMax(T& tar, const T2 &val, const T3&... arr) { setMax(tar, val); setMax(tar, arr...); }

template <typename T> inline void setAbs(T& v) { if(v < 0) v *= -1; }
#pragma endregion
#pragma endregion


i32 main() {
    vec<i64> st;
    in64(n);
    i64 ans = -1, ans2 = -1;
    forn(i, n) {
        in64(x);
        while(!st.empty() && st.back() <= x) st.pop_back();
        if(ans2 < Size(st)) ans2 = Size(st), ans = i+1;
        st.pb(x);
    }
    println(ans, " ", ans2);
}
