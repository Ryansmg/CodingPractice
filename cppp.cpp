#define ENABLE_O3 false
#define ENABLE_MMAP false

#pragma region C+++
//@formatter:off
#pragma region settings
#define ENABLE_OFAST false

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma ide diagnostic ignored "OCUnusedTypeAliasInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "UnreachableCallsOfFunction"
#pragma ide diagnostic ignored "UnusedLocalVariable"
#pragma ide diagnostic ignored "UnusedValue"


#if ENABLE_OFAST
#ifndef LOCAL
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif
#pragma GCC optimize("Ofast,unroll-loops")
#elif ENABLE_O3
#ifndef LOCAL
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif
#pragma GCC optimize("O3,unroll-loops")
#endif
#pragma endregion
#pragma region headers
#include <cassert>
#include <climits>
#include <cstdarg>
#include <cstddef>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <bitset>
#include <functional>
#include <limits>
#include <memory>
#include <new>
#include <numeric>
#include <utility>
#include <array>
#include <initializer_list>
#include <tuple>
#include <bit>
#include <concepts>
#include <ranges>
#include <complex>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma endregion
#define CPPP 250204
#pragma region MMAP
#ifndef LOCAL
#if ENABLE_MMAP
#include <sys/stat.h>
#include <sys/mman.h>
#define fastio mmi_.init(); std::ios_base::sync_with_stdio(false); std::cout.tie(nullptr)
#define cin mmi_
class MmapInput_ {
    struct stat st{}; char* data = nullptr; bool initCalled = false;
    inline void skipBlank() {
        assert(initCalled);
        while(data && (*data == ' ' || *data == '\n')) data++;
    }
public:
    inline void init() {
        fstat(0, &st); initCalled = true;
        data = (char*) mmap(nullptr, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
        assert(data != MAP_FAILED);
    }
    inline char get() { return *(data++); }
    MmapInput_& operator>>(char& v) { skipBlank(); v = *(data++); return *this; }
    MmapInput_& operator>>(long long& v) {
        long long sign = 1; v = 0;
        skipBlank(); if(*data == '-') sign = -1, data++;
        while('0' <= *data && *data <= '9') v = v * 10 + *data - '0', data++;
        v *= sign;
        return *this;
    }
    MmapInput_& operator>>(__int128& v) {
        long long sign = 1; v = 0;
        skipBlank(); if(*data == '-') sign = -1, data++;
        while('0' <= *data && *data <= '9') v = v * 10 + *data - '0', data++;
        v *= sign;
        return *this;
    }
    MmapInput_& operator>>(signed& v) { long long t; *this >> t; v = static_cast<signed>(t); return *this; }
    MmapInput_& operator>>(std::string& v) {
        skipBlank(); v.clear();
        while(*data != ' ' && *data != '\n') v.push_back(*(data++));
        return *this;
    }
} mmi_;
#endif // ENABLE_MMAP
#endif // ifndef LOCAL
#pragma endregion
#pragma region keywords
#define elif else if
#define strcc_(a, b) a##b
// C++ keywords without modification
/// io
#ifndef cin
using std::cin;
#endif
using std::cout, std::cerr, std::clog, std::endl, std::istream, std::ostream, std::ifstream, std::ofstream;
using std::stringstream, std::istringstream, std::ostringstream;
/// data structures
using std::array, std::list, std::tuple, std::get, std::tie, std::initializer_list, std::bitset;
using std::ssize;
/// math
using std::complex, std::polar, std::popcount;
using std::max, std::min, std::gcd, std::lcm, std::pow, std::swap, std::abs, std::sin, std::cos, std::tan, std::asin;
using std::acos, std::atan, std::floor, std::ceil, std::round, std::sinh, std::cosh, std::tanh, std::atan2, std::sqrt;
using std::less, std::greater, std::less_equal, std::greater_equal;
/// algorithms
using std::iota, std::prev_permutation, std::next_permutation, std::ranges::reverse;
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
template <typename T = long long> using set = std::set<T>;
template <typename Key = long long, typename Value = long long> using map = std::map<Key, Value>;
template <typename T = long long> using multiset = std::multiset<T>;
template <typename Key = long long, typename Value = long long> using multimap = std::multimap<Key, Value>;
template <typename T = long long> using stack = std::stack<T>;
template <typename T = long long> using queue = std::queue<T>;
template <typename T = long long> using deque = std::deque<T>;
template <typename T1 = long long, typename T2 = long long> using pair = std::pair<T1, T2>;

template <typename T = long long, typename Compare = std::less<>> using pq = std::priority_queue<T, std::vector<T>, Compare>;
template <typename T = long long, typename T2 = long long> using umap = std::unordered_map<T, T2>;
template <typename T = long long, typename T2 = long long> using ummap = std::unordered_multimap<T, T2>;
template <typename T = long long> using uset = std::unordered_set<T>;
template <typename T = long long> using umset = std::unordered_multiset<T>;
template <typename T = long long> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename T = long long> using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename T = long long> using vec = std::vector<T>;
template <typename T = long long> using vec2 = std::vector<std::vector<T>>;
using vl = std::vector<long long>; using vi = std::vector<signed>; using vb = std::vector<bool>;
using v2l = std::vector<std::vector<long long>>; using v2i = std::vector<std::vector<signed>>; using v2b = std::vector<std::vector<bool>>;
using ll = std::array<long long, 2>; using lll = std::array<long long, 3>; using ii = std::array<signed, 2>; using iii = std::array<signed, 3>;
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
#else
#define lassert(...)
#endif
#pragma endregion
#pragma region constants
constexpr long long
        i64max = 9223372036854775807, /// lim<i64>::max()
lmax   = 9221557155715571557, /// lmax + inf < i64max
INFIN  = 4001557155715570000, /// INFIN * 2 < i64max
INF    = 1000000000000000000, /// INF * 9 < i64max
inf    = 3000000000,          /// inf * inf < i64max
i32max = 2147483647,          /// lim<i32>::max()
imax   = 2147481557,          /// imax + 1000 < i32max
iinf   = 2000000000,          /// iinf + 1e8 < i32max
mod1   = 1000000007,
        mod9   = 998244353;
constexpr long double
        PI = 3.141592653589793238462643383279502884L;
#pragma endregion
#pragma region control_statements
#define forn(name_, val_) for(long long name_ = 0; name_ < (val_); name_++)
#define forf(name_, start_, end_) for(long long name_ = (start_); name_ <= (end_); name_++)
#define forr(name_, start_, end_) for(long long name_ = (start_); name_ >= (end_); name_--)
/// foreach reverse
#define forer(...) for(__VA_ARGS__ | std::views::reverse)
#define rep(n_) forn(rep_mac_name_1_, n_)
#define rep2(n_) forn(rep_mac_name_2_, n_)

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
template <typename T> inline T pop(std::queue<T> &q_) { T t_ = q_.front(); q_.pop(); return t_; }
template <typename T> inline T pop(std::vector<T> &arr_) { T t_ = arr_.back(); arr_.pop_back(); return t_; }

template <typename T> inline T reversed(T v_) { std::ranges::reverse(v_); return v_; }
template <typename T> inline void sort(T& v_) { std::sort(v_.begin(), v_.end()); }
template <typename T, typename Cmp> inline void sort(T& v_, const Cmp& cmp) { std::sort(v_.begin(), v_.end(), cmp); }
template <typename T> inline T sorted(T v_) { std::sort(v_.begin(), v_.end()); return v_; }
template <typename T, typename Cmp> inline T sorted(T v_, const Cmp& cmp) { std::sort(v_.begin(), v_.end(), cmp); return v_; }

template <typename T> inline void compress(T &v_, const bool& autosort = true) { if(autosort) std::sort(v_.begin(), v_.end()); v_.erase(std::unique(v_.begin(), v_.end()), v_.end()); }
template <typename T> inline T compressed(T v_, const bool &autosort = true) { compress(v_, autosort); return v_; }
template <typename T> inline long long cidx(const T &val, const std::vector<T> &compressed) { return std::lower_bound(compressed.begin(), compressed.end(), val) - compressed.begin(); }
/// min(arr) == 1, max(arr) <= Size(arr)
template <typename T> inline void autoCompress(T &v_) { auto comp_ = compressed(v_); for(auto& t : v_) t = cidx(t, comp_) + 1; }
/// min(arr) == 0, max(arr) <= Size(arr)
template <typename T> inline void autoCompress0(T &v_) { auto comp_ = compressed(v_); for(auto& t : v_) t = cidx(t, comp_); }
template <typename T> inline T autoCompressed(T v_) { autoCompress(v_); return v_; }
template <typename T> inline T autoCompressed0(T v_) { autoCompress0(v_); return v_; }

template <typename T2, typename T1> inline std::vector<T2> castVec(const T1& arr) { std::vector<T2> ret; for(const auto& t : arr) { ret.emplace_back(t); } return ret; }
#pragma endregion
#pragma region math
template <typename T> inline T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
inline long long pow(const long long& a, const long long& b, const long long& mod) { return pow_(a, b, mod); }

template <typename T> inline T gcd_(T a, T b) { if(a < b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
template <typename T> inline T max(const std::vector<T>& v_) { T ret = v_.empty() ? std::numeric_limits<T>::min() : v_[0]; for(const T &t_ : v_) { ret = max(ret, t_); } return ret; }
template <typename T> inline T min(const std::vector<T>& v_) { T ret = v_.empty() ? std::numeric_limits<T>::max() : v_[0]; for(const T &t_ : v_) { ret = min(ret, t_); } return ret; }
inline long long max(const long long& a, const long long& b) { return a > b ? a : b; } inline long long min(const long long& a, const long long& b) { return a < b ? a : b; }
template <typename T> inline T lcm_(const T& a, const T& b) { return a / gcd_(a, b) * b; }
template <typename T> inline T sq_(const T& i) { return i * i; }
template <typename T> inline T sum(const std::vector<T>& v_) { T s_ = T(); {for(const T& i_ : v_) s_ += i_;} return s_; }

template <typename T> inline T gcd(const std::initializer_list<T>& l_) { auto iter = l_.begin(); T ret = *iter; long long sz_ = l_.size();
    for(long long i_ = 1; i_ <= sz_-1; i_++) { ret = std::gcd(ret, *(++iter)); } return ret; }
template <typename T> inline T lcm(const std::initializer_list<T>& l_) { auto iter = l_.begin(); T ret = *iter / gcd(l_); long long sz_ = l_.size();
    for(long long i_ = 1; i_ <= sz_-1; i_++) { ret *= *(++iter); } return ret; }

std::random_device mrdvce_; std::mt19937 m1gn_(mrdvce_());
std::uniform_int_distribution<signed> uni3i32_(0, 2147483647);
std::uniform_int_distribution<long long> uni3i64_(0, 9223372036854775807);
#define rand rand_
inline signed randi() { return uni3i32_(m1gn_); } inline long long randl() { return uni3i64_(m1gn_); }
inline long long rand_(const long long& l_, const long long& r_) { return randl() % (r_ - l_ + 1) + l_; } /// inclusive

#pragma endregion
#pragma region I/O
// settings
#ifdef LOCAL
#define lfastio print()
#else
#define lfastio fastio
#endif
#ifndef fastio
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
#endif
#ifdef LOCAL
#define fileio filein; fileout
#define filein freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\input.txt)", "r", stdin)
#define fileout freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "w", stdout)
#define inputout freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\input.txt)", "w", stdout)
#define outputin freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "r", stdin)
#define ansout freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\ans.txt)", "w", stdout)
#else
#define fileio print()
#define filein print()
#define fileout print()
#define inputout print()
#define outputin print()
#define ansout print()
#endif // LOCAL

// input
#ifndef cin
using std::cin;
#endif
template <typename T = long long> inline T input() { T t; cin >> t; return t; }

template <typename ...T> inline void input(T&... a_) { (cin >> ... >> a_); }
#define in64(...) long long __VA_ARGS__; input(__VA_ARGS__)

inline std::string inStr() { std::string t; cin >> t; return t; }
template <typename T = long long> inline std::vector<T> inArr(long long sz) {
    std::vector<T> a;
    for(long long i = 0; i<sz; i++) { T t; cin >> t; a.push_back(t); }
    return a;
}

template <typename T = long long> inline void inArr(std::vector<T> &arr, long long sz, bool clear = false) {
    if(clear) arr.clear();
    for(long long i = 0; i < sz; i++) { T t; cin >> t; arr.push_back(t); }
}
template <typename T = long long> inline std::vector<T> inArr() { return inArr<T>(input()); }
#ifndef cin
inline std::string readline() {
    char c = '\n';
    while(c == '\n') cin.get(c);
    std::string s; std::getline(cin, s);
    s = c + s; return s;
}
#endif

std::vector<long long> qin_data_;
short qin_t_ = 0, qin_c_ = 0;
long long qin_h_(const long long& idx, const long long& n) {
    if(!qin_c_) { qin_t_ = n; qin_data_.resize(n);
        for(long long i = 0; i < n; i++) cin >> qin_data_[i]; }
    if(++qin_c_ == qin_t_) qin_t_ = qin_c_ = 0;
    return qin_data_[idx];
}
long long QIN_H_() { long long t; cin >> t; return t; } // qin() support
#define EXPAND_(x) x
#define QIN_H1_(n) qin_h_(0, n)
#define QIN_H2_(n) QIN_H1_(n), qin_h_(1, n)
#define QIN_H3_(n) QIN_H2_(n), qin_h_(2, n)
#define QIN_H4_(n) QIN_H3_(n), qin_h_(3, n)
#define QIN_H5_(n) QIN_H4_(n), qin_h_(4, n)
#define QIN_H6_(n) QIN_H5_(n), qin_h_(5, n)
#define QIN_H7_(n) QIN_H6_(n), qin_h_(6, n)
#define QIN_H8_(n) QIN_H7_(n), qin_h_(7, n)
#define QIN_H9_(n) QIN_H8_(n), qin_h_(8, n)
#define qin(n) EXPAND_(QIN_H##n##_(n))

// output

template <typename ...T> inline void rprint(const T&... a_) { (std::cout << ... << a_); } inline void rprint() {}
template <typename ...T> inline void rprintln(const T&... a_) { (std::cout << ... << a_); std::cout << '\n'; }
inline void rprintln() { std::cout << '\n'; }

template <typename... Args> void printf_legacy(const Args&... args) { printf(args...); }

#define defIsChild(name, abbv) template <typename> struct is##name##Struct_ : std::false_type {};\
                               template <typename T> struct is##name##Struct_< abbv <T>> : std::true_type {};\
                               template <typename T> concept is##name = is##name##Struct_<T>::value;
template <typename T> using vector2_ = std::vector<std::vector<T>>;
defIsChild(Vector_, std::vector) defIsChild(Queue_, std::queue) defIsChild(Stack_, std::stack)
defIsChild(PQ_, std::priority_queue) defIsChild(Vector2_, vector2_)
template <typename T> concept isStQue_ = isStack_<T> || isQueue_<T> || isPQ_<T>;
template <typename T> concept isVector1_ = isVector_<T> && !isVector2_<T>;

struct Printf {
    std::string sep = " ", end;
    signed prec = -1;
    long long width = -1; char fill = ' ';
    bool exit = false; bool local = false;
    void operator()() const { std::cout << end; if(exit) std::exit(0); }
    template <typename ...T> requires (sizeof...(T) > 0)
    void operator()(const T&... v_) {
#ifdef LOCAL
        prf_imp_(v_...);
#else
        if(!local) prf_imp_(v_...);
#endif
    }
    Printf& appendEnd(const std::string& end_) { end += end_; return *this; }
    Printf& setExit() { exit = true; return *this; }
    Printf& setLocal() { local = true; return *this; }
private:
    inline void prf_imp_preset_() const {
        std::cout << std::fixed;
        if(prec != -1) std::cout.precision(prec);
        if(width != -1) std::cout << std::setw(width) << std::setfill(fill);
    }
    template <typename T> void prf_imp_(const T& v_) const { prf_imp_preset_(); std::cout << v_ << end; if(exit) std::exit(0); }
    template <isVector1_ T> void prf_imp_(const T& v_) const {
        long long len_ = Size(v_);
        for(long long i = 0; i < len_ - 1; i++) { prf_imp_preset_(); std::cout << v_[i] << sep; }
        if(len_) prf_imp_preset_(), std::cout << v_[len_-1] << end;
        if(exit) std::exit(0);
    }
    template <isStQue_ T> void prf_imp_(const T& v_) const { T st = v_;
        while(!st.empty()) { prf_imp_preset_();
            if(st.size() == 1) { std::cout << pop(st) << end; break; }
            std::cout << pop(st) << sep; }
        if(exit) std::exit(0);
    }
    template <isVector2_ T> void prf_imp_(const T& arr) {
        bool pExit = exit; exit = false;
        for(const auto& v_ : arr) prf_imp_(v_);
        exit = pExit; if(exit) std::exit(0);
    }
    template <typename T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const {
        prf_imp_preset_(); std::cout << _ << sep; prf_imp_(b_...);
    }
    template <isVector1_ T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const {
        for(const auto& v_ : _) { prf_imp_preset_(); std::cout << v_ << sep; } prf_imp_(b_...);
    }
    template <isStQue_ T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const { T1 st = _;
        while(!st.empty()) { prf_imp_preset_(); std::cout << pop(st) << sep; } prf_imp_(b_...);
    }
    template <isVector2_ T1, typename ... T2> void prf_imp_(const T1& arr, const T2&... b_) {
        bool pExit = exit; exit = false; prf_imp_(arr); exit = pExit; prf_imp_(b_...);
    }
};
#define printf(...) Printf({__VA_ARGS__})
#define lprintf(...) Printf({__VA_ARGS__}).setLocal()
#define printfln(...) printf(__VA_ARGS__).appendEnd("\n")
#define lprintfln(...) printfln(__VA_ARGS__).setLocal()
#define printfExit(...) printfln(__VA_ARGS__).setExit()
#define printExit(...) printfln().setExit()(__VA_ARGS__)
#define print(...) printf()(__VA_ARGS__)
#define println(...) printfln()(__VA_ARGS__)

#ifdef LOCAL
#define lprint print
#define lprintln println
#define lprintvar(...) lprintvar_(#__VA_ARGS__, __VA_ARGS__)

template <typename... Args>
void lprintvar_(const std::string& names_, Args... args) {
    size_t pos = 0; std::string delimiter = ",", name, names = names_;
    auto print_each = [&](auto&& value) {
        pos = names.find(delimiter); name = (pos == std::string::npos) ? names : names.substr(0, pos);
        while(name[0] == ' ') {name = name.substr(1);} while(name.back() == ' ') {name.pop_back();}
        std::cout << name << ": "; printf()(value); std::cout << (pos == std::string::npos ? "\n" : ", ");
        if (pos != std::string::npos) names = names.substr(pos + delimiter.length());
    };
    (print_each(args), ...);
}

#else // LOCAL
#define lprint(...) print()
#define lprintln(...) print()
#define lprintvar(...) print()
#endif // LOCAL

#pragma endregion
#pragma region conversion
template <typename T> inline std::string tostr(const T &t) { return std::to_string(t); }
inline std::string tostr(const std::string &t) { return t; }
#define mac_conv_(name, type, sh) template <typename T> inline type to##name(const T &t) { return cast<type>(t); } \
                                                        inline type to##name(const std::string &t) { return sto##sh(t); }
template <typename T> inline __int128 toi128(const T &t) { return cast<__int128>(t); }
inline __int128 toi128(const std::string &t) { return static_cast<__int128>(stoull(t)); }
mac_conv_(i64, long long, ll) mac_conv_(i32, signed, i) mac_conv_(u64, unsigned long long, ull)
mac_conv_(f32, float, f) mac_conv_(f64, double, d) mac_conv_(f128, long double, ld)
#pragma endregion
#pragma region qol
template <typename T, typename T2, typename T3> inline T replace_if(const T& origin, const T2& cond, const T3& replacement)
requires std::is_convertible_v<T2, T> && std::is_convertible_v<T3, T> {
    return origin == static_cast<T>(cond) ? static_cast<T>(replacement) : origin;
}
#define rplf replace_if

template <typename T, typename T2> inline void setMin(T& tar, const T2& val) requires std::is_convertible_v<T2, T> {
    if(static_cast<T>(val) < tar) tar = static_cast<T>(val);
}
template <typename T, typename T2> inline void setMax(T& tar, const T2& val) requires std::is_convertible_v<T2, T> {
    if(static_cast<T>(val) > tar) tar = static_cast<T>(val);
}
#pragma endregion
#pragma region custom_types

template <long long mod = 1000000007>
struct ModInt {
    long long v = 0;
    ModInt() = default;
    explicit ModInt(long long val) : v((val % mod + mod) % mod) {}
    explicit operator long long() { return v; }
    ModInt operator+(const ModInt& b) const { return {(v + b.v) % mod}; }
    ModInt operator-(const ModInt& b) const { return {(v - b.v + mod) % mod}; }
    ModInt operator*(const ModInt& b) const { return {(v * b.v) % mod}; }
    ModInt& operator+=(const ModInt& b) { v = (v + b.v) % mod; return *this; }
    ModInt& operator-=(const ModInt& b) { v = (v - b.v + mod) % mod; return *this; }
    ModInt& operator*=(const ModInt& b) { v = (v * b.v) % mod; return *this; }
    ModInt operator+(long long b) const { b = (b % mod + mod) % mod; return {(v + b) % mod}; }
    ModInt operator-(long long b) const { b = (b % mod + mod) % mod; return {(v - b + mod) % mod}; }
    ModInt operator*(long long b) const { b = (b % mod + mod) % mod; return {(v * b) % mod}; }
    ModInt& operator+=(long long b) { b = (b % mod + mod) % mod; v = (v + b) % mod; return *this; }
    ModInt& operator-=(long long b) { b = (b % mod + mod) % mod; v = (v - b + mod) % mod; return *this; }
    ModInt& operator*=(long long b) { b = (b % mod + mod) % mod; v = (v * b) % mod; return *this; }
};
namespace ModIntOpInternal {
    template <long long mod> std::istream& operator>>(std::istream& in, ModInt<mod>& t) { in >> t.v; return in; }
    template <long long mod> std::ostream& operator<<(std::ostream& out, const ModInt<mod>& t) { out << t.v; return out; }
    template <long long mod> ModInt<mod> operator+(long long a, const ModInt<mod>& b) { a = (a % mod + mod) % mod; return {(b.v + a) % mod}; }
    template <long long mod> ModInt<mod> operator-(long long a, const ModInt<mod>& b) { a = (a % mod + mod) % mod; return {(b.v - a + mod) % mod}; }
    template <long long mod> ModInt<mod> operator*(long long a, const ModInt<mod>& b) { a = (a % mod + mod) % mod; return {(b.v * a) % mod}; }
} using namespace ModIntOpInternal;

/// 1/0 == infinity, -1/0 == -infinity (only comparisons are available)
class Frac {
    inline void reduction() { long long g = std::gcd(numerator, denominator); numerator /= g; denominator /= g; }
    inline void checkDivZ() const { if(denominator == 0) { std::cerr << "Cannot divide by zero!\n"; exit(1); } }
    inline void checkDivZ(const Frac& a) const { checkDivZ(); a.checkDivZ(); }
public:
    long long numerator = 0; // 분자
    long long denominator = 1; // 분모 (항상 >= 0, 0인 경우 abs(분자) == 1)
    Frac() = default;
    explicit Frac(long long i) : numerator(i), denominator(1) {}
    Frac(long long Numerator, long long Denominator) : numerator(Numerator), denominator(Denominator) {
        if(denominator < 0) numerator *= -1, denominator *= -1;
        reduction();
    }
    template <typename T> explicit operator T() { return static_cast<T>(numerator) / static_cast<T>(denominator); }
    Frac& operator+=(const Frac& b) { checkDivZ(b);
        long long l = std::lcm(denominator, b.denominator);
        numerator *= l / denominator; numerator += b.numerator * (l / b.denominator);
        denominator = l; reduction(); return *this;
    }
    Frac& operator+=(const long long& i) { checkDivZ(); numerator += i * denominator; return *this; }
    Frac operator+(const Frac& b) const { checkDivZ(b); Frac ret = *this; ret += b; return ret; }
    Frac operator+(const long long& i) const { checkDivZ(); Frac ret = *this; ret += i; return ret; }
    Frac& operator-=(const Frac& b) {checkDivZ(b);
        long long l = std::lcm(denominator, b.denominator);
        numerator *= l / denominator; numerator -= b.numerator * (l / b.denominator);
        denominator = l; reduction(); return *this;
    }
    Frac& operator-=(const long long& i) { checkDivZ(); numerator -= i * denominator; return *this; }
    Frac operator-(const Frac& b) const { checkDivZ(b);  Frac ret = *this; ret -= b; return ret; }
    Frac operator-(const long long& i) const { checkDivZ(); Frac ret = *this; ret -= i; return ret; }
    Frac& operator*=(const Frac& b) { checkDivZ(b);
        numerator *= b.numerator; denominator *= b.denominator;
        reduction(); return *this;
    }
    Frac& operator*=(const long long& i) { checkDivZ(); numerator *= i; reduction(); return *this; }
    Frac operator*(const Frac& b) const { checkDivZ(b); Frac ret = *this; ret *= b; return ret; }
    Frac operator*(const long long& i) const { checkDivZ(); Frac ret = *this; ret *= i; return ret; }
    Frac& operator/=(const Frac& b) { checkDivZ(b);
        assert(b.numerator); // cannot divide by 0
        numerator *= b.denominator; denominator *= b.numerator;
        reduction(); return *this;
    }
    Frac& operator/=(const long long& i) { checkDivZ();
        assert(i); // cannot divide by 0
        denominator *= i; reduction(); return *this;
    }
    Frac operator/(const Frac& b) const { checkDivZ(b); Frac ret = *this; ret /= b; return ret; }
    Frac operator/(const long long& i) const { checkDivZ(); Frac ret = *this; ret /= i; return ret; }
    inline bool operator==(const Frac& b) const { return numerator == b.numerator && denominator == b.denominator; }
    inline bool operator!=(const Frac& b) const { return numerator != b.numerator || denominator != b.denominator; }
    inline bool operator<(const Frac& b) const {
        if(!denominator && !b.denominator) return numerator < b.numerator;
        return numerator * b.denominator < b.numerator * denominator;
    }
    inline bool operator<=(const Frac& b) const {
        if(!denominator && !b.denominator) return numerator <= b.numerator;
        return numerator * b.denominator <= b.numerator * denominator;
    }
    inline bool operator>(const Frac& b) const {
        if(!denominator && !b.denominator) return numerator > b.numerator;
        return numerator * b.denominator > b.numerator * denominator;
    }
    inline bool operator>=(const Frac& b) const {
        if(!denominator && !b.denominator) return numerator >= b.numerator;
        return numerator * b.denominator >= b.numerator * denominator;
    }

    inline bool operator==(const long long& b) const { return numerator == b && denominator == 1; }
    inline bool operator!=(const long long& b) const { return numerator != b || denominator != 1; }
    inline bool operator<(const long long& b) const { return !denominator ? numerator < 0 : numerator < b * denominator; }
    inline bool operator<=(const long long& b) const { return denominator && numerator <= b * denominator; }
    inline bool operator>(const long long& b) const { return !denominator ? numerator > 0 : numerator > b * denominator; }
    inline bool operator>=(const long long& b) const { return denominator && numerator >= b * denominator; }
};
namespace FracOpInternal {
    Frac operator+(const long long& a, const Frac& b) { Frac ret(a); ret += b; return ret; }
    Frac operator-(const long long& a, const Frac& b) { Frac ret(a); ret -= b; return ret; }
    Frac operator*(const long long& a, const Frac& b) { Frac ret(a); ret *= b; return ret; }
    Frac operator/(const long long& a, const Frac& b) { Frac ret(a); ret /= b; return ret; }
    inline bool operator==(const long long &a, const Frac& b) { return b.numerator == a && b.denominator == 1; }
    inline bool operator!=(const long long &a, const Frac& b) { return b.numerator != a || b.denominator != 1; }
    inline bool operator<(const long long &a, const Frac& b) { return !b.denominator ? 0 < b.numerator : a * b.denominator < b.numerator; }
    inline bool operator<=(const long long &a, const Frac& b) { return b.denominator && a * b.denominator <= b.numerator; }
    inline bool operator>(const long long &a, const Frac& b) { return !b.denominator ? 0 > b.numerator : a * b.denominator > b.numerator; }
    inline bool operator>=(const long long &a, const Frac& b) { return b.denominator && a * b.denominator >= b.numerator; }
} using namespace FracOpInternal;

#define defStructIO_(name) std::istream& operator>>(std::istream& in, name& t) { in >> t.v; return in; }\
                           std::ostream& operator<<(std::ostream& out, const name& t) { out << t.v; return out; }

struct Mx64 { long long v = -4001557155715570000; Mx64 operator+(const Mx64& b) const { return { std::max(v, b.v) }; }
    Mx64& operator+=(const Mx64& b) { if(v < b.v) { v = b.v; } return *this; }
    bool operator<(const Mx64& b) const { return v < b.v; } explicit operator long long() const { return v; }};
struct Mn64 { long long v = 4001557155715570000; Mn64 operator+(const Mn64& b) const { return { std::min(v, b.v) }; }
    Mn64& operator+=(const Mn64& b) { if(v > b.v) { v = b.v; } return *this; }
    bool operator<(const Mn64& b) const { return v < b.v; } explicit operator long long() const { return v; }};
struct Mx32 { signed v = -2147481557; Mx32 operator+(const Mx32& b) const { return { std::max(v, b.v) }; }
    Mx32& operator+=(const Mx32& b) { if(v < b.v) { v = b.v; } return *this; }
    bool operator<(const Mx32& b) const { return v < b.v; } explicit operator signed() const { return v; }};
struct Mn32 { signed v = 2147481557; Mn32 operator+(const Mn32& b) const { return { std::min(v, b.v) }; }
    Mn32& operator+=(const Mn32& b) { if(v > b.v) { v = b.v; } return *this; }
    bool operator<(const Mn32& b) const { return v < b.v; } explicit operator signed() const { return v; }};
defStructIO_(Mx64) defStructIO_(Mn64) defStructIO_(Mx32) defStructIO_(Mn32)

struct GoldMine {
    long long mx = -1000000000000000000, lmx = - 1000000000000000000, rmx = -1000000000000000000, sum = 0; GoldMine() = default;
    GoldMine(long long a, long long la, long long ra, long long s) : mx(a), lmx(la), rmx(ra), sum(s) {}
    GoldMine(long long v) : mx(v), lmx(v), rmx(v), sum(v) {} // NOLINT(*-explicit-constructor)
    GoldMine operator+(const GoldMine&b) const { return {std::max({mx,b.mx,rmx+b.lmx}),std::max(lmx,sum+b.lmx),std::max(rmx+b.sum,b.rmx),sum+b.sum};}
};

#pragma endregion
#pragma clang diagnostic pop
//@formatter:on
#pragma endregion

struct SimpleEdge { signed start, end; };
struct DistEdge { signed start, end; long long dist; };
template <typename T> concept isEdge1_ = requires(const T& a) { a.s; a.e; };
template <typename T> concept isEdge2_ = requires(const T& a) { a.start; a.end; };
template <typename T> concept isEdge = isEdge1_<T> || isEdge2_<T>;

/// node >= 0
/// requirements : (EdgeType.s && EdgeType.e) || (EdgeType.start && EdgeType.end)
/// detects : start/s, end/e, distance/dist/d
template <isEdge EdgeType = SimpleEdge>
class Graph {
#define defGCFs_ static long long es_(const EdgeType& edge) { if constexpr(isEdge1_<EdgeType>) { return edge.s; } return edge.start; }\
                 static long long ee_(const EdgeType& edge) { if constexpr(isEdge1_<EdgeType>) { return edge.e; } return edge.end; }\
                 static long long ed_(const EdgeType& edge) {\
                     if constexpr(requires{edge.d;}) return edge.d;\
                     if constexpr(requires{edge.dist;}) return edge.dist;\
                     if constexpr(requires{edge.distance;}) return edge.distance;\
                     return 1;\
                 }
    defGCFs_
    static EdgeType revEdge_(EdgeType e) {
        if constexpr(isEdge1_<EdgeType>) std::swap(e.s, e.e);
        else if constexpr(isEdge2_<EdgeType>) std::swap(e.start, e.end);
        return e;
    }
public:
    long long nodeCnt = 0; // (maxNodeNumber) + 1
    std::vector<std::vector<EdgeType>> child, parent, undir;
    /// disables all error check if true
    /// increases performance
    bool unsafe = false;

    Graph() = default;
    explicit Graph(long long maxNodeNum) {
        if(!unsafe && nodeCnt > maxNodeNum) { std::cerr << "Invalid resizing"; exit(1); }
        nodeCnt = maxNodeNum + 1;
        child.resize(nodeCnt, std::vector<EdgeType>()); parent.resize(nodeCnt, std::vector<EdgeType>()); undir.resize(nodeCnt, std::vector<EdgeType>());
    }
    /// reset
    virtual void clear() { child = parent = undir = std::vector<std::vector<EdgeType>>(); nodeCnt = 0; unsafe = false; }

    virtual void resize(long long maxNodeNum) {
        if(!unsafe && nodeCnt > maxNodeNum) { std::cerr << "Invalid resizing"; exit(1); }
        nodeCnt = maxNodeNum + 1;
        child.resize(nodeCnt, std::vector<EdgeType>()); parent.resize(nodeCnt, std::vector<EdgeType>()); undir.resize(nodeCnt, std::vector<EdgeType>());
    }
    virtual void addUEdge(const EdgeType& edge) { undir[es_(edge)].emplace_back(edge); undir[ee_(edge)].emplace_back(revEdge_(edge)); }
    template <typename... Args> void makeUEdge(Args&&... args) { EdgeType edge(std::forward<Args>(args)...);
        undir[es_(edge)].emplace_back(edge); undir[ee_(edge)].emplace_back(revEdge_(edge)); }
    virtual void addDEdge(const EdgeType& edge) { child[es_(edge)].emplace_back(edge); parent[ee_(edge)].emplace_back(edge); }
    template <typename... Args> void makeDEdge(Args&&... args) { EdgeType edge(std::forward<Args>(args)...);
        child[es_(edge)].emplace_back(edge); parent[ee_(edge)].emplace_back(edge); }
    void removeDuplicateEdge() {
        std::function<void(std::vector<std::vector<EdgeType>>&)> f = [&](std::vector<std::vector<EdgeType>>& k) {
            for(auto &arr : k) {
                sort(arr, [&](const EdgeType& a, const EdgeType& b) {
                    if(es_(a) == es_(b)) {
                        if(ee_(a) == ee_(b)) return ed_(a) < ed_(b);
                        return ee_(a) < ee_(b);
                    }
                    return es_(a) < es_(b);
                });
                arr.erase(std::unique(arr.begin(), arr.end(), [&](const EdgeType& a, const EdgeType& b) {
                    return es_(a) == es_(b) && ee_(a) == ee_(b) && ed_(a) == ed_(b);
                }), arr.end());
            }
        };
        f(child); f(parent); f(undir);
    }
    /// child와 undir에 대한 forEach문을 지원
    class Connection {
        Graph<EdgeType>* g; long long n;
    public:
        explicit Connection(Graph<EdgeType>* gp, long long node) : g(gp), n(node) { }
        class Iter {
            friend class Connection;
            Graph<EdgeType>* g; std::vector<EdgeType>::iterator cur; long long n;
            Iter(Graph<EdgeType>* gp, std::vector<EdgeType>::iterator i, long long N) : g(gp), cur(i), n(N) {}
        public:
            Iter& operator++() { ++cur; if(cur == g->child[n].end()) { cur = g->undir[n].begin(); } return *this; }
            bool operator!=(const Iter& o) const { return cur != o.cur; }
            EdgeType& operator*() { return *cur; }
        };
        Iter begin() { return g->child[n].empty() ? Iter(g, g->undir[n].begin(), n) : Iter(g, g->child[n].begin(), n); }
        Iter end() { return Iter(g, g->undir[n].end(), n); }
    };
    Connection getConnection(long long node) { return Connection(this, node); }

    /// Complexity : O(ElogV)
    /// @returns {minDist, parent}
    std::pair<std::vector<long long>, std::vector<long long>> dijkstra(long long startNode) {
        std::vector<long long> dist(nodeCnt, 1000000000000000000), par(nodeCnt, -1);
        std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<>> q;
        q.emplace(0, startNode); dist[startNode] = 0;
        while(!q.empty()) {
            auto [d, cur] = q.top(); q.pop(); if(d > dist[cur]) continue;
            for(const auto& i : getConnection(cur)) {
                if(!unsafe && ed_(i) < 0) { std::cerr << "Negative distance is not allowed."; exit(1); }
                long long nxt = ee_(i), nxtCost = d + ed_(i);
                if(nxtCost < dist[nxt]) { dist[nxt] = nxtCost; q.emplace(nxtCost, nxt); par[nxt] = cur; }
            }
        }
        return {dist, par};
    }
    /// Complexity : O(N)
    std::vector<EdgeType> getConnectionArr(long long node) {
        std::vector<EdgeType> ret; for(const auto& e : child[node]) ret.emplace_back(e); for(const auto& e : undir[node]) ret.emplace_back(e); return ret;
    }
    Graph& setUnsafe(bool _ = true) { unsafe = _; return *this; }
};

template <typename EdgeType>
class Tree : public Graph<EdgeType> { defGCFs_
    bool usingHld = false;
public:
    long long root = -1; std::vector<long long> sz, dep, top, in, out, inRev;
    void clear() override {
        Graph<EdgeType>::clear(); sz = dep = top = in = out = inRev = std::vector<long long>(); usingHld = false; root = 0;
        logH = 0; usingSparse = false; sparsePar = sparseDist = std::vector<std::vector<long long>>();
    }
    Tree() = default; // creates empty tree
    Tree(long long rootNode, const Graph<EdgeType>& graph) : Graph<EdgeType>(graph), root(rootNode) {
        if(!this->unsafe) { // check cycle
            std::vector<bool> vis(this->nodeCnt, false);
            bool hasCycle = false;
            std::function<void(long long, long long)> dfs_ = [&](long long cur, long long par) {
                if(hasCycle) return;
                if(vis[cur]) { hasCycle = true; return; }
                vis[cur] = true;
                for(const auto& e : this->child[cur]) if(ee_(e) != par) dfs_(ee_(e), cur);
                for(const auto& e : this->undir[cur]) if(ee_(e) != par) dfs_(ee_(e), cur);
            };
            dfs_(rootNode, -1);
            if(hasCycle) { std::cerr << "Cycle detected while constructing Tree"; exit(1); }
        }
        std::function<void(long long, long long)> dfs2_ = [&](long long cur, long long par) { // move undir -> child & parent
            for(const auto& e : this->child[cur]) if(ee_(e) != par) dfs2_(ee_(e), cur);
            for(const auto& e : this->undir[cur]) if(ee_(e) != par) {
                    this->child[cur].emplace_back(e); this->parent[ee_(e)].emplace_back(e);
                    dfs2_(ee_(e), cur);
                }
        };
        dfs2_(rootNode, -1);
        this->undir.clear();
    }

    long long par(long long node) { if(!this->unsafe) assert(this->parent[node].size() == 1);
        return es_(this->parent[node][0]); }

    /// euler tour technique (range: [1, n])
    /// saves results at in & out. new edges does not update the results.
    /// Complexity : O(N)
    std::pair<std::vector<long long>, std::vector<long long>> getInOut() {
        in = std::vector<long long>(this->nodeCnt, -1), out = in; long long cur = 0;
        std::function<void(long long)> f = [&](long long p) { in[p] = ++cur;
            for(const auto& e : this->child[p]) f(ee_(e));
            out[p] = cur; };
        f(root); return {in, out};
    }

    /// heavy_light decomposition
    void initHld() {
        sz = dep = top = in = out = inRev = vl(this->nodeCnt, 0); usingHld = true;
        long long pv = 0; top[this->root] = this->root;
        // sz & dep & par, reconstruct
        std::function<void(long long)> dfs1 = [&](long long v) {
            sz[v] = 1;
            for(auto &i : this->child[v]) {
                long long j = ee_(i); dep[j] = dep[v] + 1; dfs1(j); sz[v] += sz[j];
                if(sz[j] > sz[ee_(this->child[v][0])]) std::swap(i, this->child[v][0]);
            }
        }; dfs1(this->root);
        // in & out & top
        std::function<void(long long)> dfs2 = [&](long long v) {
            in[v] = ++pv;
            for(const auto& i : this->child[v]) {
                long long j = ee_(i); top[j] = (j == ee_(this->child[v][0])) ? top[v] : j; dfs2(j); }
            out[v] = pv;
        }; dfs2(this->root);
        for(long long i = 0; i < this->nodeCnt; i++) inRev[in[i]] = i;
    }

    /// calls func(ettNum1, ettNum2) (ettNum1 <= ettNum2)
    /// for decomposed chains for a ~ b
    /// calls initHld() automatically if you didn't
    /// @returns lca(a, b)
    long long hld(long long a, long long b, const std::function<void(long long, long long)> &func) {
        if(!usingHld) initHld();
        while(top[a] != top[b]) {
            if(dep[top[a]] < dep[top[b]]) std::swap(a, b);
            long long st = top[a]; func(in[st], in[a]); a = par(st);
        }
        if(dep[a] > dep[b]) std::swap(a, b);
        func(in[a], in[b]);
        return a;
    }

    long long hld(long long a, long long b, const std::function<void(long long, long long)> &lFunc, const std::function<void(long long, long long)> &rFunc) {
        if(!usingHld) initHld();
        while(top[a] != top[b]) {
            if(dep[top[a]] > dep[top[b]]) {
                lFunc(in[top[a]], in[a]);
                a = par(top[a]);
            } else {
                rFunc(in[top[b]], in[b]);
                b = par(top[b]);
            }
        }
        if(dep[a] > dep[b]) lFunc(in[b], in[a]);
        else rFunc(in[a], in[b]);
        return dep[a] > dep[b] ? b : a;
    }

private:
    long long logH = 0; std::vector<std::vector<long long>> sparsePar, sparseDist; bool usingSparse = false;
    void initSparse() {
        if(usingSparse) return;
        usingSparse = true; sparsePar.resize(this->nodeCnt, std::vector<long long>()); sparseDist.resize(this->nodeCnt, std::vector<long long>());
        dep = std::vector<long long>(this->nodeCnt, 0);
        std::function<void(long long)> dfs = [&](long long v) {
            logH = std::max(logH, static_cast<long long>(log2(dep[v]+1)));
            for(auto &i : this->child[v]) { long long j = ee_(i); dep[j] = dep[v] + 1; dfs(j); }
        }; dfs(this->root);
        for(long long v = 0; v <= this->nodeCnt-1; v++) {
            if(this->parent[v].empty()) sparsePar[v].emplace_back(v), sparseDist[v].push_back(0);
            else sparsePar[v].emplace_back(par(v)), sparseDist[v].emplace_back(ed_(this->parent[v][0]));
        }
        for(long long i = 0; i < logH+1; i++) for(long long v = 0; v <= this->nodeCnt-1; v++) {
                sparsePar[v].emplace_back(sparsePar[sparsePar[v][i]][i]);
                sparseDist[v].emplace_back(sparseDist[v][i] + sparseDist[sparsePar[v][i]][i]);
            }
    }
public:
    std::pair<long long, long long> sparseLca(long long a, long long b) { initSparse();
        if(dep[a] > dep[b]) std::swap(a, b);
        long long depDiff = dep[b] - dep[a], dist = 0;
        for(long long i = logH; depDiff && i >= 0; i--)
            if(depDiff & (1<<i)) dist += sparseDist[b][i], b = sparsePar[b][i], depDiff ^= (1<<i);
        for(long long i = logH; i >= 0; i--)
            if(sparsePar[a][i] != sparsePar[b][i])
                dist += sparseDist[a][i] + sparseDist[b][i], a = sparsePar[a][i], b = sparsePar[b][i];
        if(a == b) return {a, dist};
        return {sparsePar[a][0], dist + sparseDist[a][0] + sparseDist[b][0]};
    }

    /// if hld is made => returns lca using hld
    /// else => makes sparse tree
    long long lca(long long a, long long b) {
        if(usingHld) return hld(a, b, [&](long long, long long){});
        return sparseLca(a, b).first;
    }

    /// uses sparse table
    long long dist(long long a, long long b) { return sparseLca(a, b).second; }
};

/// Persistent Li Chao Tree
class Plct {
public:
    struct Line { long long a = 0, b = 9223372036854775807; long long operator[](long long x) const { return a*x+b; } };
private:
    std::vector<Line> tr; std::vector<signed> l, r; long long ln, rn; long long mode = 1;
public:
    Plct(long long leftBound, long long rightBound, bool useMaxQuery = false) : ln(leftBound), rn(rightBound) {
        for(signed i=0; i<2; i++) tr.emplace_back(), l.emplace_back(0), r.emplace_back(0);
        if(useMaxQuery) mode = -1;
    }
    struct Root {
        signed pos = 0, prvPos = 0; Plct* ptr = nullptr;
        Root next() const {
            Root ret; ret.pos = ssize(ptr->tr); ret.prvPos = pos; ret.ptr = ptr;
            ptr->tr.emplace_back(ptr->tr[pos]); ptr->l.emplace_back(ptr->l[pos]); ptr->r.emplace_back(ptr->r[pos]);
            return ret;
        }
        /// @returns self
        Root& add(long long a, long long b) { ptr->update({a*ptr->mode, b*ptr->mode}, prvPos, pos, ptr->ln, ptr->rn); return *this; }
        /// @returns self
        Root& add(const Line& line) { add(line.a, line.b); return *this; }
        /// @returns self
        Root& addAt(long long left, long long right, long long a, long long b) { ptr->updateAt(left, right, prvPos, pos, ptr->ln, ptr->rn, {a*ptr->mode, b*ptr->mode}); return *this; }
        long long query(long long x) const { return ptr->mode * ptr->query(x, pos, ptr->ln, ptr->rn); }
    };
    friend Root; Root root() { return { 1, 0, this }; }
private:
    void updateAt(long long ul, long long ur, long long pp, long long p, long long s, long long e, const Line& line) {
        if(ur < s || e < ul) return;
        if(ul <= s && e <= ur) { update(line, pp, p, s, e); return; }
        if(!l[p] || l[p] == l[pp]) l[p] = std::ssize(tr), tr.emplace_back(tr[l[pp]]), l.emplace_back(l[r[pp]]), r.emplace_back(r[r[pp]]);
        if(!r[p] || r[p] == r[pp]) r[p] = std::ssize(tr), tr.emplace_back(tr[r[pp]]), l.emplace_back(l[l[pp]]), r.emplace_back(r[l[pp]]);
        updateAt(ul, ur, l[pp], l[p], s, (s+e)/2, line);
        updateAt(ul, ur, r[pp], r[p], (s+e)/2+1, e, line);
    }
    void update(const Line& line, long long pp, long long p, long long s, long long e) {
        long long m = (s + e) >> 1; Line low = tr[p], high = line;
        if(low[s] > high[s]) std::swap(low, high);
        if(low[e] <= high[e]) { tr[p] = low; return; }
        if(low[m] < high[m]) {
            tr[p] = low;
            if(!l[p]) l[p] = l[pp];
            if(!r[p] || r[p] == r[pp]) r[p] = std::ssize(tr), tr.emplace_back(tr[r[pp]]), l.emplace_back(l[r[pp]]), r.emplace_back(r[r[pp]]);
            update(high, r[pp], r[p], m+1, e);
        } else {
            tr[p] = high;
            if(!l[p] || l[p] == l[pp]) l[p] = std::ssize(tr), tr.emplace_back(tr[l[pp]]), l.emplace_back(l[l[pp]]), r.emplace_back(r[l[pp]]);
            if(!r[p]) r[p] = r[pp];
            update(low, l[pp], l[p], s, m);
        }
    }
    long long query(long long x, long long p, long long s, long long e) const {
        if(!p) { return 9223372036854775807; } long long m = (s + e) >> 1;
        if(x <= m) return std::min(tr[p][x], query(x, l[p], s, m));
        return std::min(tr[p][x], query(x, r[p], m+1, e));
    }
};
using PlctRoot = Plct::Root;

// ans[i] = min(ans[j] + (dst[i]-dst[j]) * v[i]) + s[i] )
//        = dst[i] * v[i] + s[i] + min(ans[j] + -dst[j] * v[i])

i32 main() {
    fastio;
    in64(n);
    Tree t(1, [&](){Graph<DistEdge> g(n); rep(n-1) g.makeUEdge(qin(3)); return g;}());
    Plct cht(-1000, 1010011557);
    vl ans(n+1, INF), dist(n+1, 0);
    vec<ll> msgr(n+1, {0,0}); forf(i, 2, n) input(msgr[i][0], msgr[i][1]);
    vec<PlctRoot> roots(1, cht.root());
    ans[0] = ans[1] = 0;
    fun<void(i64)> dfs = [&](i64 cur) {
        if(cur-1) {
            ans[cur] = dist[cur] * msgr[cur][1] + msgr[cur][0];
            i64 q = roots.back().query(msgr[cur][1]);
            i64 q2 = dist[cur] * msgr[cur][1] + msgr[cur][0];
            setMin(ans[cur], q + q2);
        }
        roots.pb(roots.back().next().add(-dist[cur], ans[cur]));
        for(auto [CUR, i, d] : t.child[cur]) {
            dist[i] = dist[cur] + d; dfs(i);
        }
        pop(roots);
    };
    dfs(1);
    forf(i, 2, n) print(ans[i], "");
}
