#pragma region options
#define USE_O3 0
#define USE_OFAST 0
#define USE_TARGET 0
#define LOCAL_FASTIO 1
#define LOCAL_INLINE 0
#define DISABLE_LOCAL 0
#define NO_X86_INTRIN_H 0
#define NO_EXT_HEADERS 0
#pragma endregion

#pragma region C+++
//@formatter:off
#define CPPP 250708
#pragma region settings

#ifdef LOCAL
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma ide diagnostic ignored "OCUnusedTypeAliasInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "UnreachableCallsOfFunction"
#pragma ide diagnostic ignored "UnusedLocalVariable"
#pragma ide diagnostic ignored "UnusedValue"
#endif

#if DISABLE_LOCAL
#undef LOCAL
#endif
#ifdef LOCAL
#define LOCAL_DEFINED 1
#else
#define LOCAL_DEFINED 0
#if USE_TARGET
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif
#endif
#if USE_OFAST
#pragma GCC optimize("Ofast,unroll-loops")
#elif USE_O3
#pragma GCC optimize("O3,unroll-loops")
#endif
#pragma endregion
#pragma region headers
#if !NO_X86_INTRIN_H
#include <x86intrin.h>
#endif

#include <bits/stdc++.h>

#if !NO_EXT_HEADERS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#endif
#pragma endregion
#pragma region keywords
#define elif else if
#define strcc_(a, b) a##b
// C++ keywords without modification
/// io
using std::cin, std::cout, std::cerr, std::clog, std::endl, std::istream, std::ostream, std::ifstream, std::ofstream;
using std::stringstream, std::istringstream, std::ostringstream;
/// data structures
using std::array, std::list, std::tuple, std::get, std::tie, std::initializer_list, std::bitset, std::ssize, std::span;
/// math
using std::complex, std::polar, std::popcount;
using std::max, std::min, std::gcd, std::lcm, std::swap, std::abs, std::sin, std::cos, std::tan, std::asin;
using std::acos, std::atan, std::floor, std::ceil, std::round, std::sinh, std::cosh, std::tanh, std::atan2, std::sqrt;
using std::less, std::greater, std::less_equal, std::greater_equal;
/// algorithms
using std::iota, std::prev_permutation, std::next_permutation;
/// concepts
using std::is_integral_v, std::is_convertible_v, std::is_arithmetic_v, std::is_floating_point_v, std::is_same_v;

// C++ keywords with modification
// types
using i16 = short; using i32 = signed; using i64 = long long; using i128 = __int128;
using u16 = unsigned short; using u32 = unsigned; using u64 = unsigned long long; using u128 = unsigned __int128;
using f32 = float; using f64 = double; using f128 = long double;
using str = std::string;
template <typename T> using lim = std::numeric_limits<T>;
template <typename T> using fun = std::function<T>;
/// data structures
template <typename T = long long, typename Cmp = std::less<>> using set = std::set<T, Cmp>;
template <typename Key = long long, typename Value = long long, typename Cmp = std::less<>> using map = std::map<Key, Value, Cmp>;
template <typename T = long long, typename Cmp = std::less<>> using multiset = std::multiset<T, Cmp>;
template <typename Key = long long, typename Value = long long, typename Cmp = std::less<>> using multimap = std::multimap<Key, Value, Cmp>;
template <typename T = long long> using stack = std::stack<T, std::vector<T>>;
template <typename T = long long> using queue = std::queue<T, std::list<T>>;
template <typename T = long long> using deque = std::deque<T>;
template <typename T1 = long long, typename T2 = long long> using pair = std::pair<T1, T2>;
template <typename T = long long> using rope = __gnu_cxx::rope<T>;

template <typename T = long long, typename Compare = std::less<>> using pq = std::priority_queue<T, std::vector<T>, Compare>;
template <typename T = long long, typename T2 = long long> using umap = std::unordered_map<T, T2>;
template <typename T = long long, typename T2 = long long> using ummap = std::unordered_multimap<T, T2>;
template <typename T = long long> using uset = std::unordered_set<T>;
template <typename T = long long> using umset = std::unordered_multiset<T>;
template <typename T = long long> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename T = long long> using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename T = long long> using vector = std::vector<T>;
using lll = std::array<long long, 3>;
using ii = std::array<signed, 2>; using iii = std::array<signed, 3>;
/// miscellaneous
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

#define panic() (cerr << "panicked at line " << __LINE__ << "\n", exit(1683))
inline void do_nothing_() { }
#define do_nothing do_nothing_()

#pragma endregion
#pragma region constants
constexpr long long
        i64max = 9223372036854775807,    /// lim<i64>::max()
        i64min = -9223372036854775807-1, /// lim<i64>::min()
        INFIN  = 4001557155715570000,    /// INFIN * 2 < i64max
        INF    = 1000000000000000000,    /// INF * 9 < i64max
        inf    = 3000000000,             /// inf * inf < i64max
        i32max = 2147483647,             /// lim<i32>::max()
        i32min = -2147483648,            /// lim<i32>::min()
        mod1   = 1000000007,
        mod9   = 998244353;
constexpr long double PI = 3.141592653589793238462643383279502884L;
#pragma endregion
#pragma region control_statements
#define forn(name_, val_) for(long long name_ = 0; name_ < (val_); name_++)
#define forf(name_, start_, end_) for(long long name_ = (start_); name_ <= (end_); name_++)
#define forr(name_, start_, end_) for(long long name_ = (start_); name_ >= (end_); name_--)
/// foreach reverse
#define forer(...) for(__VA_ARGS__ | std::views::reverse)

#define CONCAT_INNER_(x, y) x##y
#define CONCAT_(x, y) CONCAT_INNER_(x, y)
#define repeat_(n, i) for(long long i = 0; i < n; i++)
#define rep(n) repeat_(n, CONCAT_(rep_var_, __COUNTER__))

#define loop while(true)

long long iR_v_, iR_v2_, iR_v5_;
#define inRep() input(iR_v_); forn(iR_v3_, iR_v_)
#define inRep2() input(iR_v2_); forn(iR_v4_, iR_v2_)
#define tcRep() input(iR_v5_); forf(TCN, 1, iR_v5_)
#pragma endregion
#pragma region algorithms
template <typename T> inline long long Size(const T& v_) { return static_cast<long long>(v_.size()); }

template <typename Arr, typename T> inline auto lb(const Arr& arr_, const T& v_) { return std::lower_bound(arr_.begin(), arr_.end(), v_); }
template <typename Arr, typename T, typename Cmp> inline auto lb(const Arr& arr_, const T& v_, const Cmp& cmp_) { return std::lower_bound(arr_.begin(), arr_.end(), v_, cmp_); }
template <typename Arr, typename T> inline auto ub(const Arr &arr_, const T& v_) { return std::upper_bound(arr_.begin(), arr_.end(), v_); }
template <typename Arr, typename T, typename Cmp> inline auto ub(const Arr &arr_, const T& v_, const Cmp& cmp_) { return std::upper_bound(arr_.begin(), arr_.end(), v_, cmp_); }

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
template <typename T> inline T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T modInv(T a, const T& m, bool chkGcd = true) { // by @kuhyaku
    T b = m, u = 1, v = 0; if(chkGcd) assert(std::gcd(a, m) == 1);
    while (b) { T t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
    u %= m; if (u < 0) {u += m;} return u;
}
inline long long pow(long long a, long long b, long long mod) {return pow_(b < 0 ? modInv(a, mod) : a, std::abs(b), mod);}
inline long long pow(long long a, long long b) { long long ans=1;while(b){if(b&1)ans=ans*a;b>>=1;a=a*a;} return ans; }
template <typename T> requires (!is_same_v<T, long long> && !is_convertible_v<T, long long>)
inline T pow(T a, long long b) { assert(b); b--; T ans=a; while(b){if(b&1)ans=ans*a;b>>=1;a=a*a;} return ans; }
template <typename T> inline T pow(T a, T b) { T ans=1;while(b){if(b&1)ans=ans*a;b>>=1;a=a*a;} return ans; }

template <typename T> inline T gcd_(T a, T b) { if(a < b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
template <typename T> inline T max(const std::vector<T>& v_) { T ret = v_.empty() ? std::numeric_limits<T>::min() : v_[0]; for(const T &t_ : v_) { ret = std::max(ret, t_); } return ret; }
template <typename T> inline T min(const std::vector<T>& v_) { T ret = v_.empty() ? std::numeric_limits<T>::max() : v_[0]; for(const T &t_ : v_) { ret = std::min(ret, t_); } return ret; }
inline long long max(long long a, long long b) { return a > b ? a : b; } inline long long min(long long a, long long b) { return a < b ? a : b; }
template <typename T> inline T lcm_(const T& a, const T& b) { return a / gcd_(a, b) * b; } template <typename T> inline T sq_(const T& i) { return i * i; }
template <typename T> inline T sum(const std::vector<T>& v_) { T s_ = T(); {for(const T& i_ : v_) s_ += i_;} return s_; }
template <typename T> inline T gcd(const std::initializer_list<T>& l_) { auto iter = l_.begin(); T ret = *iter; long long sz_ = l_.size();
    for(long long i_ = 1; i_ <= sz_-1; i_++) { ret = std::gcd(ret, *(++iter)); } return ret; }
template <typename T> inline T lcm(const std::initializer_list<T>& l_) { auto iter = l_.begin(); T ret = *iter / gcd(l_); long long sz_ = l_.size();
    for(long long i_ = 1; i_ <= sz_-1; i_++) { ret *= *(++iter); } return ret; }

namespace pRho {
    template <typename T> inline T pw_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
    std::vector<__int128>base={2,3,5,7,11,13,17,19,23,29,31,37,41};std::mt19937 gen=std::mt19937(std::random_device()());std::uniform_int_distribution<long long>dis;
    bool _isPrime(__int128 n,__int128 a){if(a%n==0){return true;}__int128 d=n-1;while(true){__int128 t=pRho::pw_(a,d,n);if(t==n-1){return true;}
            if(d%2==1){return(t==1||t==n-1);}d/= 2;}}
    template <typename T> inline T gcd(T a,T b){if(a<b)swap(a,b);while(b){T r=a%b;a=b;b=r;}return a;}
}
bool isPrime(long long n){if(n<=1)return false;for(const __int128&a:pRho::base){if(!pRho::_isPrime(n, a))return false;}return true;}
long long factorize(long long n){assert(n>=2);if(n%2==0){return 2;}if(isPrime(n)){return n;}__int128 x=pRho::dis(pRho::gen)%(n-2)+2,y=x,
            c=pRho::dis(pRho::gen)%10+1,g=1;while(g==1){x=(x*x%n+c)%n;y=(y*y%n+c)%n;y=(y*y%n+c)%n;g=pRho::gcd(x-y>0?x-y:y-x,(__int128)n);
        if(g==n)return factorize(n);}if(isPrime((long long)g)){return (long long)g;} return factorize((long long)g);}
std::vector<long long> getPrimes(long long n) { std::vector<long long> r; while(n != 1) { long long p = factorize(n); r.emplace_back(p); n /= p; } return r; }

inline signed popcount(long long v) { return std::popcount((unsigned long long) v); }
inline auto clz(long long v) { return __builtin_clzll(v); } /// count leading zeros (000010 => 4)
inline signed lmb(long long v) { return 63 - clz(v); } /// left most bit (000100 => 2)

std::random_device mrdvce_; std::mt19937 m1gn_(mrdvce_());
std::uniform_int_distribution<long long> uni3i64_(0, 9223372036854775807);
#define rand rand_
inline long long randl() { return uni3i64_(m1gn_); }
inline long long rand_(long long l_, long long r_) { return randl() % (r_ - l_ + 1) + l_; } /// inclusive
inline long long rand_(long long n_) { return rand_(0, n_-1); }

template <typename Iter> void shuffle(Iter first, Iter last) {
    if (first == last) return;
    for (Iter i = first + 1; i != last; ++i)
        std::iter_swap(i, first + rand(int(i - first) + 1));
}
template <typename T> void shuffle(T& arr) { shuffle(arr.begin(), arr.end()); }


/// log_a(b)
long long log(long long a, long long b) {
    assert(a > 1 && b > 0);
    __int128 t = a;
    long long ans = 0;
    while(t < b) ans++, t *= a;
    if(t == b) return ans;
    return ans - 1;
}


constexpr signed dx4[4] = { 0, 1, 0, -1 }; constexpr signed dy4[4] = { -1, 0, 1, 0 };
#pragma endregion
#pragma region custom_types_1
struct ll {
    long long first = 0, second = 0;
    inline auto operator<=>(const ll& b) const { return first == b.first ? second <=> b.second : first <=> b.first; }
    inline bool operator==(const ll&) const = default;
    inline long long& operator[](signed i) { return i ? second : first; }
    inline const long long& operator[](signed i) const { return i ? second : first; }
    friend istream& operator>>(istream& in, ll& t) { in >> t.first >> t.second; return in; }
};
#pragma endregion
#pragma region I/O
#pragma region iosets
#ifdef LOCAL
#define fileio filein; fileout
#define filein freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\input.txt)", "r", stdin)
#define fileout freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "w", stdout)
#define inputout freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\input.txt)", "w", stdout)
#define outputin freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "r", stdin)
#define ansout freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\ans.txt)", "w", stdout)
#else
#define fileio do_nothing
#define filein do_nothing
#define fileout do_nothing
#define inputout do_nothing
#define outputin do_nothing
#define ansout do_nothing
#endif // LOCAL

#if (!LOCAL_DEFINED) || LOCAL_FASTIO
struct enable_fastio_ {
    enable_fastio_() { std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); }
} efio_;
#endif
#pragma endregion
#pragma region input
template <typename T = long long> inline T input() { T t; std::cin >> t; return t; }
template <typename ...T> inline void input(T&... a_) { (std::cin >> ... >> a_); }

template <typename T = long long> inline T get() { T t; std::cin >> t; return t; }
template <typename ...T> inline void get(T&... a_) { (std::cin >> ... >> a_); }

#define in64(...) long long __VA_ARGS__; input(__VA_ARGS__)
#define in32(...) signed __VA_ARGS__; input<signed>(__VA_ARGS__)
#define instr(...) std::string __VA_ARGS__; input<std::string>(__VA_ARGS__)

inline std::string inStr() { std::string t; std::cin >> t; return t; }

#ifndef cin
inline std::string readline() {
    char c = '\n'; while(c == '\n') cin.get(c);
    std::string s; std::getline(cin, s);
    s = c + s; return s;
}
#endif

std::vector<long long> qin_data_;
short qin_t_ = 0, qin_c_ = 0;
long long qin_h_(long long idx, long long n) {
    if(!qin_c_) { qin_t_ = (short) n; qin_data_.resize(n);
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
#pragma region output

template <typename... Args> void cprintf(const Args&... args) { printf(args...); }

#define defIsChild(name, abbv) template <typename> struct is##name##Struct_ : std::false_type {};\
                               template <typename T> struct is##name##Struct_< abbv <T>> : std::true_type {};\
                               template <typename T> concept is##name = is##name##Struct_<T>::value;
template <typename T> using vector2_ = std::vector<std::vector<T>>;
defIsChild(Vector_, std::vector) defIsChild(Vector2_, vector2_) defIsChild(Span, std::span)
template <typename T> concept isVector1_ = (isVector_<T> && !isVector2_<T>) || isSpan<T>;
std::string tostr(const __int128&);

struct Printf {
    std::string sep = " ", end; signed prec = -1, width = -1; char fill = ' '; bool exit = false, local = false, flush = false;
    inline void operator()() const {
#ifndef LOCAL
        if(local) return;
#endif
        std::cout << end;
        if(exit) std::exit(0);
        if(flush) cout.flush();
    }
    template <typename ...T> requires (sizeof...(T) > 0) inline void operator()(const T&... v_) {
#ifdef LOCAL
        pr_(v_...);
        if(exit) std::exit(0);
        if(flush) cout.flush();
#else
        if(!local) {
            pr_(v_...);
            if(exit) std::exit(0);
            if(flush) cout.flush();
        }
#endif
    }
    Printf& appendEnd(const std::string& end_) { end += end_; return *this; }
    Printf& setExit() { exit = true; return *this; }
    Printf& setLocal() { local = true; return *this; }
    Printf& setFlush() { flush = true; return *this; }
private:
    // ReSharper disable once CppDFAUnreachableFunctionCall
    inline void preset_() const {
        std::cout << std::fixed;
        if(prec != -1) std::cout.precision(prec);
        if(width != -1) std::cout << std::setw(width) << std::setfill(fill);
    }
    void pr_(const ll& v_) const {
        preset_(); std::cout << v_.first << sep;
        preset_(); std::cout << v_.second << end;
    }
    template <typename T> void pr_(const T& v_) const { preset_(); std::cout << v_ << end; }
    template <isVector1_ T> void pr_(const T& v_) const { long long len_ = Size(v_);
        for(long long i = 0; i < len_ - 1; i++) { preset_(); std::cout << v_[i] << sep; }
        if(len_) preset_(), std::cout << v_[len_-1] << end;
    }
    template <isVector2_ T> void pr_(const T& arr) {
        for(const auto& v_ : arr) pr_(v_);
    }
    template <typename T1, typename ...T2> void pr_(const T1& _, const T2&... b_) const {
        preset_(); std::cout << _ << sep; pr_(b_...);
    }
    template <isVector1_ T1, typename ...T2> void pr_(const T1& _, const T2&... b_) const {
        for(const auto& v_ : _) { preset_(); std::cout << v_ << sep; } pr_(b_...);
    }
    template <isVector2_ T1, typename ... T2> void pr_(const T1& arr, const T2&... b_) const {
        pr_(arr); pr_(b_...);
    }
} PrfDef_print_, PrfDef_println_(" ", "\n"), PrfDef_rprint_("", ""), PrfDef_rprintln_("", "\n"), PrfDef_printes_(" ", " ");
#define printf(...) Printf({__VA_ARGS__})
#define printfln(...) printf(__VA_ARGS__).appendEnd("\n")
#define printfExit(...) printfln(__VA_ARGS__).setExit()
#define printExit(...) printfln().setExit()(__VA_ARGS__)
#define print(...) PrfDef_print_(__VA_ARGS__)
#define println(...) PrfDef_println_(__VA_ARGS__)
#define rprint(...) PrfDef_rprint_(__VA_ARGS__)
#define rprintln(...) PrfDef_rprintln_(__VA_ARGS__)
#define printes(...) PrfDef_printes_(__VA_ARGS__)
#define flprintln(...) printfln().setFlush()(__VA_ARGS__)

#ifdef LOCAL
#define lprintf(...) Printf({__VA_ARGS__}).setLocal()
#define lprintfln(...) printfln(__VA_ARGS__).setLocal()
#define lprint(...) printf().setLocal()(__VA_ARGS__)
#define lprintln(...) printfln().setLocal()(__VA_ARGS__)
#define lprintes(...) printf().setLocal().appendEnd(" ")(__VA_ARGS__)
#else
#define lprintf(...) do_nothing_
#define lprintfln(...) do_nothing_
#define lprint(...) do_nothing_()
#define lprintln(...) do_nothing_()
#define lprintes(...) do_nothing_()
#endif

#ifdef LOCAL
#define lprintvar(...) lprintvar_(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args> void lprintvar_(const std::string& names_, Args... args) {
    // ReSharper disable once CppDFAUnreadVariable
    size_t pos = 0; std::string delim = ",", name, names = names_;
    auto print_each = [&](auto&& value) {
        pos = names.find(delim); name = (pos == std::string::npos) ? names : names.substr(0, pos);
        while(name[0] == ' ') {name = name.substr(1);} while(name.back() == ' ') {name.pop_back();}
        std::cout << name << ": "; print(value); std::cout << (pos == std::string::npos ? "\n" : ", ");
        if (pos != std::string::npos) names = names.substr(pos + delim.length());
    };
    (print_each(args), ...);
}
#else
#define lprintvar(...) do_nothing_()
#endif // LOCAL
#if __cplusplus >= 202300
#define fprint(...) (std::cout << std::format(__VA_ARGS__))
#define fprintln(...) (std::cout << std::format(__VA_ARGS__) << "\n")
#endif
#pragma endregion
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

template <typename T, typename T2, typename T3> inline T replace_if(const T& origin, const T2& cond, const T3& replacement)
requires std::is_convertible_v<T2, T> && std::is_convertible_v<T3, T> {
    return origin == static_cast<T>(cond) ? static_cast<T>(replacement) : origin;
}
#define rplf replace_if

template <typename T, typename T2> inline void setMin(T& tar, const T2& val) requires std::is_convertible_v<T2, T> {
    if(static_cast<T>(val) < tar) tar = static_cast<T>(val);
}
template <typename T, typename T2, typename... T3> requires (sizeof...(T3) > 0)
inline void setMin(T& tar, const T2 &val, const T3&... arr) { setMin(tar, val); setMin(tar, arr...); }

template <typename T, typename T2> inline void setMax(T& tar, const T2& val) requires std::is_convertible_v<T2, T> {
    if(static_cast<T>(val) > tar) tar = static_cast<T>(val);
}
template <typename T, typename T2, typename... T3> requires (sizeof...(T3) > 0)
inline void setMax(T& tar, const T2 &val, const T3&... arr) { setMax(tar, val); setMax(tar, arr...); }

inline void setAbs(auto& v) { if(v < 0) v *= -1; }

str Yn[] = {"No", "Yes"}, YN[] = {"NO", "YES"};
#pragma endregion
#pragma region custom_types_2

#pragma region data_structures

template <typename T = long long>
class vec : public std::vector<T> {
public:
    vec() = default;
    explicit vec(unsigned size) : std::vector<T>(size) {}
    explicit vec(const std::vector<T>& arr) : std::vector<T>(arr) {}
    vec(unsigned size, const T& value) : std::vector<T>(size, value) {}
    vec(std::initializer_list<T> l) : std::vector<T>(l) {}
    template <typename InputIterator, typename = std::_RequireInputIter<InputIterator>>
    vec(InputIterator first, InputIterator last) : std::vector<T>(first, last) {}
    vec(unsigned size, std::istream& in) requires (!std::is_same_v<T, std::istream>)
            : std::vector<T>(size) { for(T& i : *this) in >> i; }

    inline T& operator[](long long idx) { return this->at(idx); }
    inline const T& operator[](long long idx) const { return this->at(idx); }
    vec& init() {
#ifdef CPPP
        if constexpr(isVector_<T>) {
            for(auto& a : *this) a.init();
        } else
#endif
        { for(auto& a : *this) std::cin >> a; }
        return *this;
    }
    inline T operator()(long long idx, const T& ifError = T()) const {
        if(idx < 0 || idx >= sz()) return ifError;
        return this->at(idx);
    }
    inline vec& fill(const T& v) { forn(i, sz()) operator[](i) = v; return *this; }
    template <typename Cmp> inline void sort(const Cmp& cmp) { std::sort(this->begin(), this->end(), cmp); }
    inline vec& sort() { sort(std::less<T>()); return *this; }
    template <typename Cmp> inline vec sorted(const Cmp& cmp) const { vec r = *this; r.sort(cmp); return r; }
    inline vec sorted() const { return sorted(std::less<T>()); }
    inline vec& reverse() { std::reverse(this->begin(), this->end()); return *this; }
    inline vec reversed() const { vec r = *this; r.reverse(); return r; }
    inline T pop() {
        if(mt()) [[unlikely]] {
            std::cerr << "vec::EmptyPop\n"; exit(43302);
        }
        T r = this->back(); this->pop_back(); return r;
    }
    inline vec& unique() { this->erase(std::unique(this->begin(), this->end()), this->end()); return *this; }
    template <typename Cmp> inline vec& compress(const Cmp& cmp) { sort(cmp); return unique(); }
    inline vec& compress() { return compress(std::less<T>()); }
    template <typename Cmp> inline vec compressed(const Cmp& cmp) const { vec r = *this; r.compress(cmp); return r; }
    inline vec compressed() const { return compressed(std::less<T>()); }
    template <typename Cmp> inline auto lb(const T& v, const Cmp& cmp) const {
        return std::lower_bound(this->begin(), this->end(), v, cmp);
    }
    inline auto lb(const T& v) const { return lb(v, std::less<T>()); }
    template <typename Cmp> inline auto lower_bound(const T& v, const Cmp& cmp) const { return lb(v, cmp); }
    inline auto lower_bound(const T& v) const { return lb(v); }
    template <typename Cmp> inline auto ub(const T& v, const Cmp& cmp) const {
        return std::upper_bound(this->begin(), this->end(), v, cmp);
    }
    inline auto ub(const T& v) const { return ub(v, std::less<T>()); }
    template <typename Cmp> inline auto upper_bound(const T& v, const Cmp& cmp) const { return ub(v, cmp); }
    inline auto upper_bound(const T& v) const { return ub(v); }


    template <typename Cmp> inline auto lb(const T& v, const Cmp& cmp) {
        return std::lower_bound(this->begin(), this->end(), v, cmp);
    }
    inline auto lb(const T& v) { return lb(v, std::less<T>()); }
    template <typename Cmp> inline auto lower_bound(const T& v, const Cmp& cmp) { return lb(v, cmp); }
    inline auto lower_bound(const T& v) { return lb(v); }
    template <typename Cmp> inline auto ub(const T& v, const Cmp& cmp) {
        return std::upper_bound(this->begin(), this->end(), v, cmp);
    }
    inline auto ub(const T& v) { return ub(v, std::less<T>()); }
    template <typename Cmp> inline auto upper_bound(const T& v, const Cmp& cmp) { return ub(v, cmp); }
    inline auto upper_bound(const T& v) { return ub(v); }

    inline signed idx(const T& v) const { return lb(v) - this->begin(); }
    template <typename Cmp> inline signed idx(const T& v, const Cmp& cmp) const { return lb(v, cmp) - this->begin(); }
    inline long long sz() const { return this->size(); }
    inline bool mt() const { return this->empty(); }
    inline bool contains(const T& v) const { auto it = lb(v); return it != this->end() && *it == v; }
    template <typename T2> vec<T2> to() {
        vec<T2> ret; for(const auto& t : *this) ret.emplace_back(t);
        return ret;
    }
    static vec<T> iota(long long size, long long offset = 0) {
        vec<T> ret(size); for(long long i = 0; i < size; i++) ret[i] = offset + i;
        return ret;
    }
    vec& concat(const std::vector<T>& v) { for(const T& t : v) this->push_back(t); return *this; }
    vec& accumulate() { for(long long i = 1; i < sz(); i++) this->operator[](i) += this->operator[](i-1); return *this; }
    vec& revAccumulate() { for(long long i = sz()-2; i >= 0; i--) this->operator[](i) += this->operator[](i+1); return *this; }
};
template<> class vec<bool> : public std::vector<bool> {
public:
    vec() = default;
    explicit vec(unsigned size) : std::vector<bool>(size) {}
    vec(unsigned size, bool value) : std::vector<bool>(size, value) {}
    explicit vec(const std::vector<bool>& arr) : std::vector<bool>(arr) {}
    vec(std::initializer_list<bool> l) : std::vector<bool>(l) {}
    template <typename InputIterator> vec(InputIterator first, InputIterator last) : std::vector<bool>(first, last) {}
    vec(unsigned size, std::istream& in) : std::vector<bool>(size) {
        for(signed i = 0; i < ((long long) this->size()); i++) { bool b; in >> b; this->begin()[i] = b; }
    }
    void init() {
        for(long long i = 0; i < ((long long) this->size()); i++) { bool b; std::cin >> b; this->begin()[i] = b; }
    }
    inline long long sz() const { return (long long) this->size(); }
    inline bool mt() const { return this->empty(); }
    template <typename T2> vec<T2> to() {
        vec<T2> ret; for(const bool t : *this) ret.emplace_back(t);
        return ret;
    }
    inline void reverse() { std::reverse(this->begin(), this->end()); }
    inline vec reversed() const { vec r = *this; r.reverse(); return r; }
    inline bool pop() {
        if(mt()) [[unlikely]] { std::cerr << "vec::EmptyPop\n"; exit(43302); }
        bool r = this->back(); this->pop_back(); return r;
    }
    inline auto operator[](long long idx) { return this->at(idx); }
    inline auto operator[](long long idx) const { return this->at(idx); }
};

#pragma region VEC_IF_CPPP
#ifdef CPPP
template <typename T> struct isVector_Struct_<vec<T>> : std::true_type {};
template <typename T> struct isVector2_Struct_<vec<vec<T>>> : std::true_type {};
template <typename T = long long> using vec2 = vec<vec<T>>;
template <typename T = long long> using v2 = vec2<T>;
using vl = vec<long long>; using vi = vec<signed>; using vb = vec<bool>;
using v2l = vec<vec<long long>>; using v2i = vec<vec<signed>>; using v2b = vec<vec<bool>>;

template <typename T = long long> inline vec<T> inVec(long long sz) {
    vec<T> a;
    for(long long i = 0; i<sz; i++) { T t; std::cin >> t; a.push_back(t); }
    return a;
}
template <typename T = long long> inline void inVec(vec<T> &arr, long long sz, bool clear = false) {
    if(clear) arr.clear();
    for(long long i = 0; i < sz; i++) { T t; std::cin >> t; arr.push_back(t); }
}
template <typename T = long long> inline vec<T> inVec() { return inVec<T>(input()); }
#define inArr inVec
#endif
#pragma endregion

/// requirements: (T + T), add -> (T += AddType)
/// 1-based index (for default)
template <typename T = long long, typename AddType = T>
struct segtree {
    std::vector<T> tree; signed n = -1; signed offset = 1;
    explicit segtree(const std::vector<T> &arr) {
        n = signed(arr.size()); tree = std::vector<T>(2 * n, T());
        for(signed i = n, j = 0; i < 2 * n; i++, j++) tree[i] = arr[j];
        for(signed i = n - 1; i > 0; i--) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    segtree() = default;
    explicit segtree(signed i) { tree = std::vector<T>(i * 2, T()); n = i; }
    segtree(signed lBound, signed rBound) {
        n = rBound - lBound + 1; offset = lBound;
        tree = std::vector<T>(n * 2, T());
    }
    void add(signed tar, const AddType& val) { tar -= offset;
        tree[n + tar] += val;
        for(signed i = (n + tar) >> 1; i; i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    void set(signed tar, const T &val) { tar -= offset;
        tree[n + tar] = val;
        for(signed i = (n + tar) >> 1; i; i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    template <typename T2> requires (!std::is_convertible_v<T2, T>)
    inline void set(signed tar, const T2& val) { set(tar, T(val)); }
    template <typename T2, typename... T3> requires (sizeof...(T3) > 0)
    inline void set(signed tar, const T2& val, const T3&... arr) { set(tar, T(val, arr...)); }
    T query(signed left, signed right) { left -= offset; right -= offset;
        signed l = n + left, r = n + right + 1;
        T ansL, ansR;
        bool lSet = false, rSet = false;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) {
                if(!lSet) lSet = true, ansL = tree[l++];
                else ansL = ansL + tree[l++];
            }
            if(r & 1) {
                if(!rSet) rSet = true, ansR = tree[--r];
                else ansR = tree[--r] + ansR;
            }
        }
        if(!lSet) return ansR;
        if(!rSet) return ansL;
        return ansL + ansR;
    }
    inline T query(signed tar) { return tree[n + tar - offset]; }
    std::span<T> getLeafs() { return std::span<T>(tree.begin() + n, tree.begin() + 2 * n); }
};

#pragma endregion // data_structures

#pragma region modified_integers
template <const long long mod = 1000000007>
struct ModInt {
    long long v = 0;
    ModInt() = default;
    // ReSharper disable once CppNonExplicitConvertingConstructor
    inline ModInt(long long val) : v(val % mod) { // NOLINT(*-explicit-constructor)
        if(v < 0) v += mod;
    }
    template <typename T> inline explicit operator T() requires std::is_integral_v<T> { return v; }
    inline ModInt& operator=(const ModInt& b) = default;
    inline ModInt operator-() const { return { -v }; }
    inline ModInt& operator++() { v = (v + 1) % mod; return *this; }
    inline ModInt operator++(signed) { ModInt ret = *this; v = (v + 1) % mod; return ret; }
    inline ModInt& operator--() { v = (v - 1 + mod) % mod; return *this; }
    inline ModInt operator--(signed) { ModInt ret = *this; v = (v - 1 + mod) % mod; return ret; }
    inline ModInt operator+(const ModInt& b) const { ModInt ret = *this; ret += b.v; return ret; }
    inline ModInt operator-(const ModInt& b) const { ModInt ret = *this; ret -= b.v; return ret; }
    inline ModInt operator*(const ModInt& b) const { return { v * b.v % mod }; }

    inline ModInt& operator+=(const ModInt& b) {
        v += b.v;
        if(v >= mod) v -= mod;
        return *this;
    }

    inline ModInt& operator+=(const ModInt&& b) {
        v += b.v;
        if(v >= mod) v -= mod;
        return *this;
    }

    inline ModInt& operator-=(const ModInt& b) {
        v -= b.v;
        if(v < 0) v += mod;
        return *this;
    }

    inline ModInt& operator-=(const ModInt&& b) {
        v -= b.v;
        if(v < 0) v += mod;
        return *this;
    }

    inline ModInt& operator*=(const ModInt& b) { v = v * b.v % mod; return *this; }
    inline friend std::istream& operator>>(std::istream& in, ModInt& t) {
        in >> t.v; t.v = t.v % mod;
        if(t.v < 0) t.v += mod;
        return in;
    }
    inline friend std::ostream& operator<<(std::ostream& out, const ModInt& t) { out << t.v; return out; }
    inline friend ModInt operator+(long long a, const ModInt& b) { a = (a % mod + mod) % mod; return {(b.v + a) % mod}; }
    inline friend ModInt operator-(long long a, const ModInt& b) { a = (a % mod + mod) % mod; return {(b.v - a + mod) % mod}; }
    inline friend ModInt operator*(long long a, const ModInt& b) { a = (a % mod + mod) % mod; return {(b.v * a) % mod}; }
};

#pragma endregion // modified_integers

#pragma endregion
#pragma region ext

v2l adj_list(int n, int m) {
    v2l adj(n+1);
    rep(m) { in64(u, v); adj[u].pb(v); adj[v].pb(u); }
    return adj;
}

vb sieve(int n) {
    vb r(n+1, true); r[0] = r[1] = false;
    forf(i, 2, n) if(r[i]) for(i64 j = i+i; j<=n; j+=i) r[j] = false;
    return r;
}

vi prime_list(int n) {
    vb s = sieve(n); vi ret; forf(i, 2, n) if(s[i]) ret.push_back((signed)i);
    return ret;
}

#pragma endregion
#ifdef LOCAL
#pragma clang diagnostic pop
#endif
//@formatter:on
#pragma endregion

i64 I = 1'000'000'000;

i32 main() {
    tcRep() {
        in64(n);

        // (-I, -I)
        i64 minD1 = 2147483647, x1 = 0, y1 = 0, c1 = 0;
        i64 minD2 = 2147483647, x2 = 0, y2 = 0, c2 = 0;

        // (-I, I)
        rep(n) {
            in64(a, b);
            i64 d = abs(-I - a) + abs(-I - b);
            if(d < minD1) c1 = 1, x1 = a, y1 = b, minD1 = d;
            elif(d == minD1) c1++;

            d = abs(-I - a) + abs(I - b);
            if(d < minD2) c2 = 1, x2 = a, y2 = b, minD1 = d;
            elif(d == minD2) c2++;
        }

        assert(c1 == 1 || c2 == 1);

        if(c1 == 1) {
            i64 dy = -3 * I, dx = -3 * I;
            rep(3) flprintln("move L", I);
            rep(3) flprintln("move D", I);
        }
    }
}

// 99999 ~ 50000
// 25000 49999 25000
// 25000 49998 25000
// ...
// 25000 1 25000
// 25000 25000


