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
#include <span>
#include <string>
#include <vector>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#pragma endregion
#define CPPP 250215
#pragma region MMAP
#ifndef LOCAL
#if ENABLE_MMAP
#include <sys/stat.h>
#include <sys/mman.h>
#define cin mmi_
namespace std {
    class MmapInput_ {
        struct stat st{}; char* data = nullptr; bool initCalled = false;
        inline void skipBlank() {
            assert(initCalled);
            while(data && (*data == ' ' || *data == '\n')) data++;
        }
    public:
        MmapInput_() {
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
        inline void tie(void*) {}
    } mmi_;
}
#endif // ENABLE_MMAP
#endif // ifndef LOCAL
#pragma endregion
#pragma region keywords
#define elif else if
#define strcc_(a, b) a##b
// C++ keywords without modification
/// io
using std::cin, std::cout, std::cerr, std::clog, std::endl, std::istream, std::ostream, std::ifstream, std::ofstream;
using std::stringstream, std::istringstream, std::ostringstream;
/// data structures
using std::array, std::list, std::tuple, std::get, std::tie, std::initializer_list, std::bitset;
using std::ssize, std::span;
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
template <typename T = long long> using rope = __gnu_cxx::rope<T>;

template <typename T = long long, typename Compare = std::less<>> using pq = std::priority_queue<T, std::vector<T>, Compare>;
template <typename T = long long, typename T2 = long long> using umap = std::unordered_map<T, T2>;
template <typename T = long long, typename T2 = long long> using ummap = std::unordered_multimap<T, T2>;
template <typename T = long long> using uset = std::unordered_set<T>;
template <typename T = long long> using umset = std::unordered_multiset<T>;
template <typename T = long long> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename T = long long> using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename T = long long> using vector = std::vector<T>;
//template <typename T = long long> using vec = std::vector<T>;
//template <typename T = long long> using vec2 = std::vector<std::vector<T>>;
//using vl = std::vector<long long>; using vi = std::vector<signed>; using vb = std::vector<bool>;
//using v2l = std::vector<std::vector<long long>>; using v2i = std::vector<std::vector<signed>>; using v2b = std::vector<std::vector<bool>>;
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
#pragma region control_statements
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
/// @returns >= 0
template <typename T> inline long long cidx(const T &val, const std::vector<T> &compressed) { return std::lower_bound(compressed.begin(), compressed.end(), val) - compressed.begin(); }
/// min(arr) == 1, max(arr) <= Size(arr)
template <typename T> inline void autoCompress(T &v_) { auto comp_ = compressed(v_); for(auto& t : v_) t = cidx(t, comp_) + 1; }
/// min(arr) == 0, max(arr) <= Size(arr)
template <typename T> inline void autoCompress0(T &v_) { auto comp_ = compressed(v_); for(auto& t : v_) t = cidx(t, comp_); }
template <typename T> inline T autoCompressed(T v_) { autoCompress(v_); return v_; }
template <typename T> inline T autoCompressed0(T v_) { autoCompress0(v_); return v_; }

/// 처음 cnt 개만 정렬, O(arr.size() * log2(cnt))
template <typename T> inline void partial_sort(T& arr, long long cnt) { std::partial_sort(arr.begin(), arr.begin() + cnt, arr.end()); }
template <typename T, typename Cmp> inline void partial_sort(T& arr, long long cnt, const Cmp& cmp) {
    std::partial_sort(arr.begin(), arr.begin() + cnt, arr.end(), cmp);
}

/// sorted(arr)[i]를 반환. arr의 값들의 순서는 변경된다.
template <typename T> inline T& nth_element(std::vector<T>& arr, long long i) {
    std::nth_element(arr.begin(), arr.begin() + i, arr.end()); return arr[i];
}
template <typename T, typename Cmp> inline T& nth_element(std::vector<T>& arr, long long i, const Cmp& cmp) {
    std::nth_element(arr.begin(), arr.begin() + i, arr.end(), cmp); return arr[i];
}

template <typename T2, typename T1> inline std::vector<T2> castVec(const T1& arr) { std::vector<T2> ret; for(const auto& t : arr) { ret.emplace_back(t); } return ret; }

template <typename T> inline std::vector<T> merge(const std::vector<T>&a, const std::vector<T>&b) {
    std::vector<T> ret(a.size()+b.size());
    std::merge(a.begin(), a.end(), b.begin(), b.end(), ret.begin());
    return ret;
}
#pragma endregion
#pragma region math
template <typename T> inline T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T modInv(T a, const T& m, bool chkGcd = true) { // by @kuhyaku
    T b = m, u = 1, v = 0; if(chkGcd) assert(std::gcd(a, m) == 1);
    while (b) { T t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
    u %= m; if (u < 0) {u += m;} return u;
}
inline long long pow(const long long& a, const long long& b, const long long& mod) {
    return pow_(b < 0 ? modInv(a, mod) : a, std::abs(b), mod);
}

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
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr)
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
template <typename T = long long> inline T input() { T t; std::cin >> t; return t; }

template <typename ...T> inline void input(T&... a_) { (std::cin >> ... >> a_); }
#define in64(...) long long __VA_ARGS__; input(__VA_ARGS__)
#define in32(...) signed __VA_ARGS__; input<signed>(__VA_ARGS__)

inline std::string inStr() { std::string t; std::cin >> t; return t; }
template <typename T = long long> inline std::vector<T> inArr(long long sz) {
    std::vector<T> a;
    for(long long i = 0; i<sz; i++) { T t; std::cin >> t; a.push_back(t); }
    return a;
}

template <typename T = long long> inline void inArr(std::vector<T> &arr, long long sz, bool clear = false) {
    if(clear) arr.clear();
    for(long long i = 0; i < sz; i++) { T t; std::cin >> t; arr.push_back(t); }
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
        for(long long i = 0; i < n; i++) std::cin >> qin_data_[i]; }
    if(++qin_c_ == qin_t_) qin_t_ = qin_c_ = 0;
    return qin_data_[idx];
}
long long QIN_H_() { long long t; std::cin >> t; return t; } // qin() support
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
defIsChild(PQ_, std::priority_queue) defIsChild(Vector2_, vector2_) defIsChild(Span_, std::span)
template <typename T> concept isStQue_ = isStack_<T> || isQueue_<T> || isPQ_<T>;
template <typename T> concept isVector1_ = (isVector_<T> && !isVector2_<T>) || isSpan_<T>;

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

template <typename T = long long>
class vec : public std::vector<T> {
public:
    vec() = default;
    explicit vec(unsigned size) : std::vector<T>(size) {}
    static vec fromArr(const std::vector<T>& arr) {
        vec ret(arr.size()); for(long long i = 0; i < arr.size(); i++) ret[i] = arr[i];
        return ret;
    }
    vec(unsigned size, const T& value) : std::vector<T>(size, value) {}
    inline T& operator[](long long idx) {
        if(idx < 0 || idx >= sz()) [[unlikely]] { std::cerr << "vec::OutOfBounds\n"; exit(43301); }
        return *(this->begin() + idx);
    }
    inline const T& operator[](long long idx) const {
        if(idx < 0 || idx >= sz()) [[unlikely]] { std::cerr << "vec::OutOfBounds\n"; exit(43301); }
        return *(this->begin() + idx);
    }
    template <typename Cmp> inline void sort(const Cmp& cmp) { std::sort(this->begin(), this->end(), cmp); }
    inline void sort() { sort(std::less<T>()); }
    template <typename Cmp> inline vec sorted(const Cmp& cmp) const { vec r = *this; r.sort(cmp); return r; }
    inline vec sorted() const { return sorted(std::less<T>()); }
    inline void reverse() { std::reverse(this->begin(), this->end()); }
    inline vec reversed() const { vec r = *this; r.reverse(); return r; }
    inline T pop() {
        if(mt()) [[unlikely]] { std::cerr << "vec::EmptyPop\n"; exit(43302); }
        T r = this->back(); this->pop_back(); return r;
    }
    inline void unique() { this->erase(std::unique(this->begin(), this->end()), this->end()); }
    template <typename Cmp> inline void compress(const Cmp& cmp) { sort(cmp); unique(); }
    inline void compress() { compress(std::less<T>()); }
    template <typename Cmp> inline vec compressed(const Cmp& cmp) const { vec r = *this; r.compress(cmp); return r; }
    inline vec compressed() const { return compressed(std::less<T>()); }
    template <typename Cmp> inline auto lb(const T& v, const Cmp& cmp) const {
        return std::lower_bound(this->begin(), this->end(), v, cmp);
    }
    inline auto lb(const T& v) const { return lb(v, std::less<T>()); }
    template <typename Cmp> inline auto lower_bound(const T& v, const Cmp& cmp) { return lb(v, cmp); }
    inline auto lower_bound(const T& v) const { return lb(v); }
    template <typename Cmp> inline auto ub(const T& v, const Cmp& cmp) const {
        return std::upper_bound(this->begin(), this->end(), v, cmp);
    }
    inline auto ub(const T& v) const { return ub(v, std::less<T>()); }
    template <typename Cmp> inline auto upper_bound(const T& v, const Cmp& cmp) const { return ub(v, cmp); }
    inline auto upper_bound(const T& v) const { return ub(v); }
    inline signed idx(const T& v) const { return lb(v) - this->begin(); }
    template <typename Cmp> inline signed idx(const T& v, const Cmp& cmp) const { return lb(v, cmp) - this->begin(); }
    inline long long sz() const { return this->size(); }
    inline bool mt() const { return this->empty(); }
    template <typename T2> vec<T2> to() {
        vec<T2> ret; for(const auto& t : *this) ret.emplace_back(t);
        return ret;
    }
    static vec<T> iota(long long size, long long offset = 0) {
        vec<T> ret(size); for(long long i = 0; i < size; i++) ret[i] = offset + i;
        return ret;
    }
    void concat(const std::vector<T>& v) { for(const T& t : v) this->push_back(t); }
    void accumulate() { for(long long i = 1; i < sz(); i++) this->operator[](i) += this->operator[](i-1); }
    void revAccumulate() { for(long long i = sz()-2; i >= 0; i--) this->operator[](i) += this->operator[](i+1); }
};
template<> class vec<bool> : public std::vector<bool> {
public:
    vec() = default;
    explicit vec(unsigned size) : std::vector<bool>(size) {}
    vec(unsigned size, bool value) : std::vector<bool>(size, value) {}
    inline long long sz() const { return this->size(); }
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
    inline auto operator[](long long idx) {
        if(idx < 0 || idx >= sz()) [[unlikely]] { std::cerr << "vec::OutOfBounds\n"; exit(43301); }
        return this->begin()[idx];
    }
    inline auto operator[](long long idx) const {
        if(idx < 0 || idx >= sz()) [[unlikely]] { std::cerr << "vec::OutOfBounds\n"; exit(43301); }
        return this->begin()[idx];
    }
};

#pragma region VEC_IF_CPPP
#ifdef CPPP
template <typename T> struct isVector_Struct_<vec<T>> : std::true_type {};
template <typename T> struct isVector2_Struct_<vec<vec<T>>> : std::true_type {};
template <typename T = long long> using vec2 = vec<vec<T>>;
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

template <typename T2, typename T1> inline vec<T2> castVec(const vec<T1>& arr) { vec<T2> ret; for(const auto& t : arr) { ret.emplace_back(t); } return ret; }
#endif
#pragma endregion

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
    friend std::istream& operator>>(std::istream& in, ModInt& t) { in >> t.v; return in; }
    friend std::ostream& operator<<(std::ostream& out, const ModInt& t) { out << t.v; return out; }
    friend ModInt operator+(long long a, const ModInt& b) { a = (a % mod + mod) % mod; return {(b.v + a) % mod}; }
    friend ModInt operator-(long long a, const ModInt& b) { a = (a % mod + mod) % mod; return {(b.v - a + mod) % mod}; }
    friend ModInt operator*(long long a, const ModInt& b) { a = (a % mod + mod) % mod; return {(b.v * a) % mod}; }
};

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
    inline Frac& operator+=(const Frac& b) { checkDivZ(b);
        long long l = std::lcm(denominator, b.denominator);
        numerator *= l / denominator; numerator += b.numerator * (l / b.denominator);
        denominator = l; reduction(); return *this;
    }
    inline Frac& operator+=(const long long& i) { checkDivZ(); numerator += i * denominator; return *this; }
    inline Frac operator+(const Frac& b) const { checkDivZ(b); Frac ret = *this; ret += b; return ret; }
    inline Frac operator+(const long long& i) const { checkDivZ(); Frac ret = *this; ret += i; return ret; }
    inline Frac& operator-=(const Frac& b) {checkDivZ(b);
        long long l = std::lcm(denominator, b.denominator);
        numerator *= l / denominator; numerator -= b.numerator * (l / b.denominator);
        denominator = l; reduction(); return *this;
    }
    inline Frac& operator-=(const long long& i) { checkDivZ(); numerator -= i * denominator; return *this; }
    inline Frac operator-(const Frac& b) const { checkDivZ(b);  Frac ret = *this; ret -= b; return ret; }
    inline Frac operator-(const long long& i) const { checkDivZ(); Frac ret = *this; ret -= i; return ret; }
    inline Frac& operator*=(const Frac& b) { checkDivZ(b);
        numerator *= b.numerator; denominator *= b.denominator;
        reduction(); return *this;
    }
    inline Frac& operator*=(const long long& i) { checkDivZ(); numerator *= i; reduction(); return *this; }
    inline Frac operator*(const Frac& b) const { checkDivZ(b); Frac ret = *this; ret *= b; return ret; }
    inline Frac operator*(const long long& i) const { checkDivZ(); Frac ret = *this; ret *= i; return ret; }
    inline Frac& operator/=(const Frac& b) { checkDivZ(b);
        assert(b.numerator); // cannot divide by 0
        numerator *= b.denominator; denominator *= b.numerator;
        reduction(); return *this;
    }
    inline Frac& operator/=(const long long& i) { checkDivZ();
        assert(i); // cannot divide by 0
        denominator *= i; reduction(); return *this;
    }
    inline Frac operator/(const Frac& b) const { checkDivZ(b); Frac ret = *this; ret /= b; return ret; }
    inline Frac operator/(const long long& i) const { checkDivZ(); Frac ret = *this; ret /= i; return ret; }
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
    friend inline Frac operator+(const long long& a, const Frac& b) { Frac ret(a); ret += b; return ret; }
    friend inline Frac operator-(const long long& a, const Frac& b) { Frac ret(a); ret -= b; return ret; }
    friend inline Frac operator*(const long long& a, const Frac& b) { Frac ret(a); ret *= b; return ret; }
    friend inline Frac operator/(const long long& a, const Frac& b) { Frac ret(a); ret /= b; return ret; }
    friend inline bool operator==(const long long &a, const Frac& b) { return b.numerator == a && b.denominator == 1; }
    friend inline bool operator!=(const long long &a, const Frac& b) { return b.numerator != a || b.denominator != 1; }
    friend inline bool operator<(const long long &a, const Frac& b) { return !b.denominator ? 0 < b.numerator : a * b.denominator < b.numerator; }
    friend inline bool operator<=(const long long &a, const Frac& b) { return b.denominator && a * b.denominator <= b.numerator; }
    friend inline bool operator>(const long long &a, const Frac& b) { return !b.denominator ? 0 > b.numerator : a * b.denominator > b.numerator; }
    friend inline bool operator>=(const long long &a, const Frac& b) { return b.denominator && a * b.denominator >= b.numerator; }
};

#define defStructIO_(name) std::istream& operator>>(std::istream& in, name& t) { in >> t.v; return in; }\
                           std::ostream& operator<<(std::ostream& out, const name& t) { out << t.v; return out; }

struct Mx64 { long long v = -4001557155715570000; Mx64 operator+(const Mx64& b) const { return { std::max(v, b.v) }; }
    Mx64& operator+=(const Mx64& b) { if(v < b.v) { v = b.v; } return *this; }
    bool operator<(const Mx64& b) const { return v < b.v; } explicit operator long long() const { return v; }}; defStructIO_(Mx64)
struct Mn64 { long long v = 4001557155715570000; Mn64 operator+(const Mn64& b) const { return { std::min(v, b.v) }; }
    Mn64& operator+=(const Mn64& b) { if(v > b.v) { v = b.v; } return *this; }
    bool operator<(const Mn64& b) const { return v < b.v; } explicit operator long long() const { return v; }}; defStructIO_(Mn64)
struct Mx32 { signed v = -2147481557; Mx32 operator+(const Mx32& b) const { return { std::max(v, b.v) }; }
    Mx32& operator+=(const Mx32& b) { if(v < b.v) { v = b.v; } return *this; }
    bool operator<(const Mx32& b) const { return v < b.v; } explicit operator signed() const { return v; }}; defStructIO_(Mx32)
struct Mn32 { signed v = 2147481557; Mn32 operator+(const Mn32& b) const { return { std::min(v, b.v) }; }
    Mn32& operator+=(const Mn32& b) { if(v > b.v) { v = b.v; } return *this; }
    bool operator<(const Mn32& b) const { return v < b.v; } explicit operator signed() const { return v; }}; defStructIO_(Mn32)

struct GoldMine {
    long long mx = -1000000000000000000, lmx = - 1000000000000000000, rmx = -1000000000000000000, sum = 0; GoldMine() = default;
    GoldMine(long long a, long long la, long long ra, long long s) : mx(a), lmx(la), rmx(ra), sum(s) {}
    GoldMine(long long v) : mx(v), lmx(v), rmx(v), sum(v) {} // NOLINT(*-explicit-constructor)
    GoldMine operator+(const GoldMine&b) const { return {std::max({mx,b.mx,rmx+b.lmx}),std::max(lmx,sum+b.lmx),std::max(rmx+b.sum,b.rmx),sum+b.sum};}
    friend std::istream& operator>>(std::istream& in, GoldMine& t) { long long v; in >> v; t.mx = t.lmx = t.rmx = t.sum = v; return in; }
    friend std::ostream& operator<<(std::ostream& out, const GoldMine& t) { out << t.mx; return out; }
};

#pragma endregion
#pragma clang diagnostic pop
//@formatter:on
#pragma endregion


i32 main() {
    fastio;
    tcRep() {
        in64(n);
        vl left, right;
        rep(n) {
            in64(v);
            if(v < 0) left.pb(0), right.pb(-v);
            else left.pb(v), right.pb(0);
        }
        left.accumulate(); right.revAccumulate();
        i64 ans = max({left[0], right[0], left[n-1], right[n-1]});
        forn(i, n-1) setMax(ans, left[i] + right[i+1]);
        println(ans);
    }
}
