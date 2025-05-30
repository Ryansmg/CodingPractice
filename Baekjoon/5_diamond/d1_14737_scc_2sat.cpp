#pragma region macros
//@formatter:off
#define ENABLE_MACRO true
#define ENABLE_O3 false
#define CPP11_MODE false
#define CPP17_MODE false

#pragma region start

#if !ENABLE_MACRO // basic macros
#include <bits/stdc++.h>
#include <cassert>
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define i32 signed
using namespace std;
#endif

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma ide diagnostic ignored "OCUnusedTypeAliasInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "UnreachableCallsOfFunction"
#pragma ide diagnostic ignored "UnusedLocalVariable"
#pragma ide diagnostic ignored "UnusedValue"

#if ENABLE_MACRO

#if ENABLE_O3
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
#include <cassert> // biko 기준 stdc++에 없음;;

#pragma endregion // start

#pragma region keyword_reassign

#define Tpl template <typename T>
#define Tpl64 template <typename T = i64>
#define elif else if
// used to avoid koistudy's CHEATING ERROR!! thing
#define strcc_(a, b) a##b

#if CPP11_MODE
using namespace std;
#else
using std::cin, std::cout, std::cerr, std::clog, std::endl, std::istream, std::ostream, std::ifstream, std::ofstream, std::setw, std::setfill;
using std::array, std::vector, std::list, std::pair, std::tuple, std::tie;
using std::stack, std::queue, std::deque, std::set, std::multiset, std::unordered_map, std::unordered_set, std::numeric_limits, std::function;
using std::map, std::initializer_list, std::bitset, std::string;
using std::max, std::min, std::gcd, std::lcm, std::pow, std::swap, std::abs, std::sin, std::cos, std::tan, std::asin, std::acos, std::atan;
using std::floor, std::ceil, std::round, std::sinh, std::cosh, std::tanh, std::atan2;
using std::less, std::greater, std::less_equal, std::greater_equal, std::all_of, std::any_of, std::hash;
using std::stoi, std::stol, std::stoll, std::stoul, std::stoull, std::stof, std::stod, std::stold;
using std::sort, std::stable_sort, std::shuffle, std::uniform_int_distribution, std::mt19937, std::random_device, std::reverse;
using std::iota, std::prev, std::next, std::prev_permutation, std::next_permutation;
using std::complex, std::polar, std::is_integral_v, std::is_convertible_v, std::is_arithmetic_v, std::is_floating_point_v, std::to_string;
#if !CPP17_MODE
using std::popcount;
#endif // !CPP17_MODE
#endif // CPP11_MODE else

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
Tpl using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
Tpl using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
Tpl bool contains(ordered_set<T> &oset_, T val_) { if(oset_.empty()) { return false; } return *oset_.find_by_order(oset_.order_of_key(val_)) == val_; }
Tpl bool contains(ordered_multiset<T> &omset_, T val_) { if(omset_.empty()) { return false; } return *omset_.find_by_order(omset_.order_of_key(val_)) == val_; }
Tpl void erase_one(ordered_multiset<T> &omset_, T val_) { int index = omset_.order_of_key(val_); auto it = omset_.find_by_order(index); if(*it == val_) omset_.erase(it); }
Tpl void erase_all(ordered_multiset<T> &omset_, T val_) { while(contains(omset_, val_)) erase_one(omset_, val_); }

using i16 = short; using i32 = signed; using i64 = long long; using i128 = __int128;
using ll = long long;
using u16 = unsigned short; using u32 = unsigned; using u64 = unsigned long long; using u128 = unsigned __int128;
using f32 = float; using f64 = double; using f128 = long double;
using str = std::string;
template <typename T, typename T2> using umap = std::unordered_map<T, T2>;
Tpl using uset = std::unordered_set<T>;
Tpl using v = std::vector<T>; Tpl using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>; using vi = v<i32>; using v2i = v2<i32>; using vb = v<bool>; using vb2 = v2<bool>;
using ii = array<i64, 2>; using iii = array<i64, 3>; using iiii = array<i64, 4>; using iiiii = array<i64, 5>;
Tpl using lim = std::numeric_limits<T>;
template <typename Signature> using fun = std::function<Signature>;
#define int i64
#define uint u64
#define ci64 const i64 &
#define cint ci64
#define ci32 const i32 &
#define cast static_cast

#pragma endregion // keyword_reassign

#pragma region consts
constexpr i64
        i64max = 9223372036854775807,
        llmax  = 9223372036854775807,
        lmax   = 9221557155715571557,
        INFIN  = 4001557155715570000,
        INF    = 1000000000000000000,
        inf    = 3000000000,
        i32max = 2147483647,
        imax   = 2147481557,
        iinf   = 2000000000,
        mod1   = 1000000007,
        mod9   = 998244353;
constexpr f128
        PI = 3.141592653589793238462643383279502884L;
const fun<void(i64, i64)> ll_nullFunc_ = [](ci64, ci64){};
const set<i64> l_nullSet_;
#pragma endregion consts

#pragma region basic
#define forn(name, val) for(i64 name = 0; (name) < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define forr(name, start, end) for(i64 name = start; name >= end; name--)
// foreach reverse
#define forer(something) for(something | std::views::reverse)
#define rep(n) forn(rep_mac_name_1_, n)
#define rep2(n) forn(rep_mac_name_2_, n)

i64 iR_v_, iR_v2_, iR_v5_;
#define inRep() input(iR_v_); forn(iR_v3_, iR_v_)
#define inRep2() input(iR_v2_); forn(iR_v4_, iR_v2_)
#define tcRep() input(iR_v5_); forf(TCN, 1, iR_v5_)
#pragma endregion // basic

#pragma region STL
#if !CPP11_MODE
template <typename T=i64, typename T3=less<>> using pq = std::priority_queue<T, v<T>, T3>;
template <typename T, typename T3> inline T pop(pq<T, T3> &pq_) { T t_ = pq_.top(); pq_.pop(); return t_; }
#else
#define pq priority_queue
#endif

#define all(vec) (vec).begin(), (vec).end()
#define pb push_back
#define eb emplace_back
#if !CPP11_MODE
Tpl inline auto lb(const v<T> &arr, T v) { return lower_bound(all(arr), v); }
Tpl inline auto ub(const v<T> &arr, T v) { return upper_bound(all(arr), v); }
template <typename T, typename Cmp> inline auto lb(const v<T> &arr, T v, const Cmp& cmp) { return lower_bound(all(arr), v, cmp); }
template <typename T, typename Cmp> inline auto ub(const v<T> &arr, T v, const Cmp& cmp) { return upper_bound(all(arr), v, cmp); }

#else
#define lb(arr, v) lower_bound(all((arr)), (v))
#define ub(arr, v) upper_bound(all((arr)), (v))
#endif //!CPP11_MODE
Tpl inline i64 Size(const T &_) { return static_cast<i64>(_.size()); }

Tpl inline T pop(stack<T> &st) { T t_ = st.top(); st.pop(); return t_; }
Tpl inline T pop(queue<T> &q) { T t_ = q.front(); q.pop(); return t_; }
Tpl inline T pop(v<T> &arr) { T t_ = arr.back(); arr.pop_back(); return t_; }
Tpl inline void reverse(T &_) { reverse(all(_)); } Tpl inline T reversed(T _) { reverse(all(_)); return _; }
Tpl inline void sort(T &_) { sort(all(_)); } Tpl inline T sorted(T _) { sort(all(_)); return _; }
template <typename T, typename Cmp> inline void sort(T& arr, const Cmp& cmp) { sort(all(arr), cmp); }
template <typename T, typename Cmp> inline T sorted(T arr, const Cmp& cmp) { sort(all(arr), cmp); return arr; }
Tpl inline void compress(v<T> &arr, const bool &autosort=true) { if(autosort) sort(all(arr)); arr.erase(unique(all(arr)), arr.end()); }
Tpl inline T compressed(T arr, const bool &autosort=true) { compress(arr, autosort); return arr; }
Tpl inline i64 idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
Tpl inline T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
Tpl inline T pow(const T& a, const T& b, const T& mod) { return pow_(a, b, mod); }
inline i64 pow(ci64 a, ci64 b, ci64 mod) { return pow_(a, b, mod); }

Tpl inline T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
Tpl inline T max(const v<T>& v_) { T ret = lim<T>::min(); for(const T &t_ : v_) { ret = max(ret, t_); } return ret; }
Tpl inline T min(const v<T>& v_) { T ret = lim<T>::max(); for(const T &t_ : v_) { ret = min(ret, t_); } return ret; }
inline i64 max(ci64 a, ci64 b) { return a > b ? a : b; } inline i64 min(ci64 a, ci64 b) { return a < b ? a : b; }
Tpl inline T lcm_(const T& a, const T& b) { return a / gcd_(a, b) * b; }
Tpl inline T sq_(const T &i) { return i * i; }
Tpl inline T sum(const v<T>& _) { T s_ = T(); {for(const T& i_ : _) s_ += i_;} return s_; }

#if !CPP11_MODE
Tpl inline T gcd(const initializer_list<T>& l_) { auto iter = l_.begin(); T ret = *iter; i64 sz_ = l_.size();
    forf(i_, 1, sz_-1) { ret = std::gcd(ret, *(++iter)); } return ret; }
Tpl inline T lcm(const initializer_list<T>& l_) { auto iter = l_.begin(); T ret = *iter / gcd(l_); i64 sz_ = l_.size();
    forf(i_, 1, sz_-1) { ret *= *(++iter); } return ret; }
#endif // !CPP11_MODE

random_device mrdvce_; mt19937 m1gn_(mrdvce_()); uniform_int_distribution<i32> uni3i32_(0, lim<i32>::max()); uniform_int_distribution<i64> uni3i64_(0, lim<i64>::max());
#define rand() randi()
inline i32 randi() { return uni3i32_(m1gn_); } inline i64 randl() { return uni3i64_(m1gn_); }
inline i64 randInt(ci64 l_, ci64 r_) { return randl() % (r_ - l_ + 1) + l_; } // inclusive

template <typename T2, typename T1> v<T2> castVec(const T1& arr) { v<T2> ret; for(const auto& t : arr) { ret.emplace_back(t); } return ret; }

#ifdef LOCAL
#define lassert assert
#else
#define lassert(...)
#endif
#pragma endregion // STL

#pragma region I/O

#ifdef LOCAL
#define lfastio print()
#else
#define lfastio fastio
#endif
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
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
Tpl64 inline T input() {T t; cin >> t; return t;}
inline str inStr() { str t; cin >> t; return t; }
Tpl64 inline v<T> inArr(i64 sz) { v<T> a; forn(i,sz) a.eb(input<T>()); return a; }
Tpl64 inline void inArr(v<T> &arr, i64 sz, bool clear = false) { if(clear) arr.clear(); forn(i,sz) arr.eb(input<T>()); }
Tpl64 inline v<T> inArr() { return inArr<T>(input()); }
inline str readline() { char c = '\n'; while(c == '\n') cin.get(c); str s; getline(cin, s); s = c + s; return s; }

#if CPP11_MODE
template <typename... T> inline void print(const T&... a_) { using expander = i32[]; (void)expander{0, (cout << a_, 0)...}; }
template <typename ...T> inline void println(const T&... a_) { print(a_...); cout << '\n'; }
template <typename... T> inline void input(T&... a_) { using expander = i32[]; (void)expander{0, (std::cin >> a_, 0)...}; }
#else
template <typename ...T> inline void rprint(const T&... a_) { (cout << ... << a_); } inline void rprint() {}
template <typename ...T> inline void rprintln(const T&... a_) { (cout << ... << a_); cout << '\n'; } inline void rprintln() { cout << '\n'; }
template <typename ...T> inline void input(T&... a_) { (cin >> ... >> a_); }
#define in64(...) i64 __VA_ARGS__; input(__VA_ARGS__)

#if !CPP17_MODE
template <typename... Args> void printf_legacy(const Args&... args) { printf(args...); }

#define defIsChild(name, abbv) template <typename> struct is##name##Struct_ : std::false_type {};\
                               Tpl struct is##name##Struct_< abbv <T>> : std::true_type {};\
                               Tpl concept is##name = is##name##Struct_<T>::value;
defIsChild(Vector_, v) defIsChild(Queue_, queue) defIsChild(Stack_, stack) defIsChild(PQ_, pq) defIsChild(Vector2_, v2)
Tpl concept isStQue_ = isStack_<T> || isQueue_<T> || isPQ_<T>;
Tpl concept isVector1_ = isVector_<T> && !isVector2_<T>;

struct Printf {
    str sep = " ", end;
    i32 prec = -1;
    i64 width = -1; char fill = ' ';
    bool exit = false; bool local = false;
    void operator()() const { cout << end; if(exit) std::exit(0); }
    template <typename ...T> requires (sizeof...(T) > 0)
    void operator()(const T&... _) {
#ifdef LOCAL
        prf_imp_(_...);
#else
        if(!local) prf_imp_(_...);
#endif
    }
    Printf& appendEnd(const str& end_) { end += end_; return *this; }
    Printf& setExit() { exit = true; return *this; }
    Printf& setLocal() { local = true; return *this; }
private:
    inline void prf_imp_preset_() const {
        cout << std::fixed;
        if(prec != -1) cout.precision(prec);
        if(width != -1) cout << std::setw(width) << std::setfill(fill);
    }
    Tpl void prf_imp_(const T& _) const { prf_imp_preset_(); cout << _ << end; if(exit) std::exit(0); }
    template <isVector1_ T> void prf_imp_(const T& _) const {
        i64 len_ = Size(_);
        forn(i, len_-1) { prf_imp_preset_(); cout << _[i] << sep; }
        if(len_) prf_imp_preset_(), cout << _[len_-1] << end;
        if(exit) std::exit(0);
    }
    template <isStQue_ T> void prf_imp_(const T& _) const { T st = _;
        while(!st.empty()) { prf_imp_preset_();
            if(st.size() == 1) {cout << pop(st) << end; break; }
            cout << pop(st) << sep; }
        if(exit) std::exit(0);
    }
    template <isVector2_ T> void prf_imp_(const T& arr) {
        bool pExit = exit; exit = false;
        for(const auto& v_ : arr) prf_imp_(v_);
        exit = pExit; if(exit) std::exit(0);
    }
    template <typename T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const {
        prf_imp_preset_(); cout << _ << sep; prf_imp_(b_...);
    }
    template <isVector1_ T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const {
        for(const auto& v_ : _) { prf_imp_preset_(); cout << v_ << sep; } prf_imp_(b_...);
    }
    template <isStQue_ T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const { T1 st = _;
        while(!st.empty()) { prf_imp_preset_(); cout << pop(st) << sep; } prf_imp_(b_...);
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
void lprintvar_(const string& names_, Args... args) {
    size_t pos = 0; string delimiter = ",", name, names = names_;
    auto print_each = [&](auto&& value) {
        pos = names.find(delimiter); name = (pos == string::npos) ? names : names.substr(0, pos);
        while(name[0] == ' ') {name = name.substr(1);} while(name.back() == ' ') {name.pop_back();}
        cout << name << ": "; printf()(value); cout << (pos == string::npos ? "\n" : ", ");
        if (pos != string::npos) names = names.substr(pos + delimiter.length());
    };
    (print_each(args), ...);
}

#else // LOCAL
#define lprint(...) print()
#define lprintln(...) print()
#define lprintvar(...) print()
#endif // LOCAL

vl qin_data_;
i16 qin_t_ = 0, qin_c_ = 0;
i64 qin_h_(ci64 idx, ci64 n) {
    if(!qin_c_) { qin_t_ = n; qin_data_.resize(n);
        forn(i, n) cin >> qin_data_[i]; }
    if(++qin_c_ == qin_t_) qin_t_ = qin_c_ = 0;
    return qin_data_[idx];
}
i64 QIN_H_() { i64 t; cin >> t; return t; } // qin() support
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

#endif // !CPP17_MODE

#endif // !CPP11_MODE
#pragma endregion // I/O

#pragma region conversions
Tpl inline str tostr(const T &t) { return std::to_string(t); }
inline str tostr(const str &t) { return t; }
#define mac_conv_(type, sh) Tpl inline type to##type(const T &t) { return cast<type>(t); } \
                                inline type to##type(const str &t) { return sto##sh(t); }
Tpl inline i128 toi128(const T &t) { return cast<i128>(t); }
inline i128 toi128(const str &t) { return cast<i128>(stoull(t)); }
mac_conv_(i64, ll) mac_conv_(i32, i) mac_conv_(u64, ull) mac_conv_(f64, d) mac_conv_(f128, ld)
#pragma endregion // conversions

#pragma region miscellaneous
template <typename T, typename T2, typename T3> inline T replace_if(const T& origin, const T2& cond, const T3& replacement)
requires is_convertible_v<T2, T> && is_convertible_v<T3, T> {
    return origin == cast<T>(cond) ? cast<T>(replacement) : origin;
}
#define rplf replace_if

template <typename T, typename Func> inline v<T> funVec(ci64 len, const Func& f) { v<T> ret; forn(i, len) { ret.pb(f(i)); } return ret; }
template <typename T, typename T2> inline void setMin(T& tar, const T2& val) requires is_convertible_v<T2, T> {
    if(cast<T>(val) < tar) tar = cast<T>(val);
}
template <typename T, typename T2> inline void setMax(T& tar, const T2& val) requires is_convertible_v<T2, T> {
    if(cast<T>(val) > tar) tar = cast<T>(val);
}

#pragma endregion // miscellaneous


#endif // ENABLE_MACRO
#pragma endregion // macros


#pragma region dataStructures

/// requirements: (T + T), add -> (T += i64)
template <typename T = i64>
struct iterSeg {
    v<T> tree; i32 n=-1;
    explicit iterSeg(const v<T> &arr) { n = Size(arr); tree = v<T>(2*n+10, T());
        for(i32 i=n, j=0; i<2*n; i++, j++) tree[i] = arr[j];
        for(i32 i=n-1; i>0; i--) tree[i] = tree[i<<1] + tree[i<<1|1];  }
    explicit iterSeg(ci32 i) { tree = v<T>(i*2+10, T()); n = i; }
    void add(i32 tar, i64 val) { tar--; tree[n+tar]+=val; for(i32 i=n+tar; i>1; i>>=1) tree[i>>1]=tree[i]+tree[i^1]; }
    void set(i32 tar, i64 val) { tar--; tree[n+tar]=val; for(i32 i=n+tar; i>1; i>>=1) tree[i>>1]=tree[i]+tree[i^1]; }
    T query(i32 left, i32 right) { left--; i64 l = n+left, r = n+right; T ans = T();
        for(; l<r; l>>=1, r>>=1) { if(l&1) { ans = ans + tree[l++]; } if(r&1) { ans = ans + tree[--r]; } } return ans; }
};

Tpl concept hasOperatorMinus = requires(const T& a, const T& b) { { a - b }; };

/// requirements: operator+(T, T)
template <typename T = i64>
class Segtree {
    vector<T> tree; i32 n;
public:
    Segtree() : n(0) {}
    explicit Segtree(ci32 treeSize) { tree = v<T>(4*treeSize, T()); n = treeSize; }
    explicit Segtree(const v<T> &a) { n = Size(a); tree = v<T>(4*n, T()); init(a, 1, 1, n); }
    void set(ci32 tar, const T& val) { set(1, tar, 1, n, val); }
    void add(ci32 tar, const T& diff) { update(1, tar, 1, n, diff); }
    void update(ci32 tar, const T& diff) { update(1, tar, 1, n, diff); }
    T query(ci32 left, ci32 right) { if(left > right) { return T(); } return query(1, left, right, 1, n); }
    T query(ci32 tar) { return query(tar, tar); }
    struct iter {
        i32 node, start, end; T value; Segtree<T>* segPtr;
        bool leaf() const { return start == end; }
        iter left() const { return iter(node<<1, start, (start+end)>>1, segPtr->tree[node<<1], segPtr); }
        iter right() const { return iter(node<<1|1, ((start+end)>>1)+1, end, segPtr->tree[node<<1|1], segPtr); }
    };
    iter root() { return iter(1, 1, n, tree[1], this); }
    // ret[i] == query(i+1)
    v<T> getLeafs() { v<T> ret(n);
        fun<void(i64, i64, i64)> f = [&](i64 p, i64 s, i64 e) {
            if(s == e) ret[s-1] = tree[p];
            else f(p<<1, s, (s+e)>>1), f(p<<1|1, ((s+e)>>1)+1, e); };
        f(1, 1, n); return ret; }

    /// [1..i] 범위 합이 val 이하인 최대의 i를 리턴
    iter strcc_(bi,nSearch)(T val) requires hasOperatorMinus<T> {
        iter cur = root();
        while(!cur.leaf()) { iter l = cur.left();
            if(val <= l.value) cur = l;
            else val = val - l.value, cur = cur.right(); }
        return cur;
    }
protected:
    T& init(const v<T> &a, ci32 node, ci32 start, ci32 end) {
        if(start==end) return tree[node] = a[start-1];
        else return tree[node] = init(a, node<<1, start, (start+end)>>1) + init(a, node<<1|1, ((start+end)>>1)+1, end);
    }
    T& update(ci32 node, ci32 tar, ci32 start, ci32 end, const T& diff) { if(end < tar || tar < start) return tree[node];
        if(start == end) return tree[node] = tree[node] + diff;
        return tree[node] = update(node<<1, tar, start, (start+end)>>1, diff) + update(node<<1|1, tar, ((start+end)>>1)+1, end, diff);
    }
    T& set(ci32 node, ci32 tar, ci32 start, ci32 end, const T& val) { if(end < tar || tar < start) return tree[node];
        if(start == end) return tree[node] = val;
        return tree[node] = set(node<<1, tar, start, (start+end)>>1, val) + set(node<<1|1, tar, ((start+end)>>1)+1, end, val);
    }
    T query(ci32 node, ci32 left, ci32 right, ci32 start, ci32 end) { if(right < start || end < left) return T();
        if(left <= start && end <= right) return tree[node];
        return query(node<<1, left, right, start, (start+end)>>1) + query(node<<1|1, left, right, ((start+end)>>1)+1, end);
    }
};


struct SumLazy;

/// requirements: (TreeType + TreeType), (LazyType + UpdateType), (TreeType + LazyIter&&), (LazyType + LazyIter&&)
/// <br> usage: node merge, node update, lazy update, lazy update
template <typename TreeType = i64, typename LazyType = SumLazy, typename UpdateType = i64>
class Lazyprop {
public:
    /// tree & lazy are copied values, should not be modified
    struct iter {
        i32 node, start, end; TreeType tree; LazyType lazy; Lazyprop* segPtr;
        iter left() { segPtr->push(node<<1, start, (start+end)>>1);
            return iter(node<<1, start, (start+end)>>1, segPtr->tree[node<<1], segPtr->lazy[node<<1], segPtr); }
        iter right() { segPtr->push(node<<1|1, ((start+end)>>1)+1, end);
            return iter(node<<1|1, ((start+end)>>1)+1, end, segPtr->tree[node<<1|1], segPtr->lazy[node<<1|1], segPtr); }
        bool leaf() { return start == end; }
    };
protected:
    v<TreeType> tree; v<LazyType> lazy; i32 n=-1;
    void push(i32 node, i32 start, i32 end) {
        tree[node] = tree[node] + iter(node, start, end, tree[node], lazy[node], this);
        if(start!=end) { lazy[node<<1] = lazy[node<<1] + iter(node, start, end, tree[node], lazy[node], this);
            lazy[node<<1|1] = lazy[node<<1|1] + iter(node, start, end, tree[node], lazy[node], this); }
        lazy[node] = LazyType();
    }
public:
    explicit Lazyprop(i32 treeSize) { tree = v<TreeType>(4*treeSize, TreeType()); lazy = v<LazyType>(4*treeSize, LazyType()); n = treeSize; }
    explicit Lazyprop(const v<TreeType> &a) : Lazyprop((i32) a.size()) { init(a, 1, 1, n); }
    void update(i32 left, i32 right, UpdateType diff) { if(left > right) { return; } update(1, left, right, 1, n, diff); }
    TreeType query(i32 left, i32 right) { if(left > right) { return TreeType(); } return query(1, left, right, 1, n); }
    TreeType query(i32 tar) { return query(tar, tar); }
    iter root() { push(1, 1, n); return iter(1, 1, n, tree[1], lazy[1], this); }
    // ret[i] == query(i+1)
    v<TreeType> getLeafs() { v<TreeType> ret(n);
        fun<void(i64, i64, i64)> f = [&](i64 p, i64 s, i64 e) { push(p, s, e);
            if(s == e) ret[s-1] = tree[p];
            else f(p<<1, s, (s+e)>>1), f(p<<1|1, ((s+e)>>1)+1, e); };
        f(1, 1, n); return ret; }
protected:
    TreeType& init(const v<TreeType> &a, i32 node, i32 start, i32 end) {
        if(start==end) return tree[node] = a[start-1];
        else return tree[node] = init(a, node<<1, start, (start+end)>>1) + init(a, node<<1|1, ((start+end)>>1)+1, end);
    }
    TreeType& update(i32 node, i32 left, i32 right, i32 start, i32 end, UpdateType diff) {
        push(node, start, end); if(end < left || right < start) return tree[node];
        if(left <= start && end <= right) { lazy[node] = lazy[node] + diff; push(node, start, end); return tree[node]; }
        return tree[node] = update(node<<1, left, right, start, (start+end)>>1, diff) + update(node<<1|1, left, right, ((start+end)>>1)+1, end, diff);
    }
    TreeType query(i32 node, i32 left, i32 right, i32 start, i32 end) {
        push(node, start, end); if(right < start || end < left) return TreeType();
        if(left <= start && end <= right) return tree[node];
        return query(node<<1, left, right, start, (start+end)>>1) + query(node<<1|1, left, right, ((start+end)>>1)+1, end);
    }
};

struct SumLazy { i64 v = 0; SumLazy operator+(ci64 i) const { return SumLazy(v+i); }
    SumLazy operator+(const Lazyprop<i64, SumLazy, i64>::iter& i) const { return SumLazy(v+i.lazy.v); } };
i64 operator+(ci64 a, const Lazyprop<i64, SumLazy, i64>::iter& b) { return a + (b.end - b.start + 1) * b.lazy.v; }

#define Dlp Lazyprop<tr, lz, i64>


struct GoldMine {
    i64 mx = -INF, lmx = - INF, rmx = -INF, sum = 0; GoldMine() = default;
    GoldMine(i64 a, i64 la, i64 ra, i64 s) : mx(a), lmx(la), rmx(ra), sum(s) {}
    GoldMine(i64 v) : mx(v), lmx(v), rmx(v), sum(v) {} // NOLINT(*-explicit-constructor)
    GoldMine operator+(const GoldMine&b) const { return {max({mx,b.mx,rmx+b.lmx}),max(lmx,sum+b.lmx),max(rmx+b.sum,b.rmx),sum+b.sum};}
};

class LiChaoTree {
public:
    struct Line { i64 a = 0, b = llmax; i64 operator[](ci64 x) const { return a*x+b; } };
    LiChaoTree() : left(0), right(0) {}
    LiChaoTree(i64 l, i64 r, bool useMaxQuery = false) : left(l), right(r) { tr.eb(); if(useMaxQuery) mode = -1; }
    void update(const Line& line) { update({mode*line.a, mode*line.b}, 0, left, right); }
    void update(ci64 a, ci64 b) { update({mode*a, mode*b}, 0, left, right); }
    void updateAt(ci64 l, ci64 r, const Line& line) { updateAt(l, r, 0, left, right, {mode*line.a, mode*line.b}); }
    i64 query(i64 x) const { return mode*query(x, 0, left, right); }
    i64 operator[](i64 x) const { return mode*query(x, 0, left, right); }
private:
    struct Node { i32 l = -1, r = -1; Line line = Line(); };
    v<Node> tr; i64 left, right; i64 mode = 1;
    void updateAt(i64 l, i64 r, i64 p, i64 s, i64 e, const Line& line) {
        if(r < s || e < l) return;
        if(l <= s && e <= r) { update(line, p, s, e); return; }
        if(tr[p].l == -1) tr[p].l = Size(tr), tr.eb();
        if(tr[p].r == -1) tr[p].r = Size(tr), tr.eb();
        updateAt(l, r, tr[p].l, s, (s+e)/2, line);
        updateAt(l, r, tr[p].r, (s+e)/2+1, e, line);
    }
    void update(const Line& line, i64 p, i64 s, i64 e) {
        i64 m = (s + e) >> 1; Line low = tr[p].line, high = line;
        if(low[s] > high[s]) swap(low, high);
        if(low[e] <= high[e]) { tr[p].line = low; return; }
        if(low[m] < high[m]) {
            tr[p].line = low;
            if(tr[p].r == -1) tr[p].r = Size(tr), tr.eb();
            update(high, tr[p].r, m+1, e);
        } else {
            tr[p].line = high;
            if(tr[p].l == -1) tr[p].l = Size(tr), tr.eb();
            update(low, tr[p].l, s, m);
        }
    }
    i64 query(i64 x, i64 p, i64 s, i64 e) const {
        if(p == -1) { return llmax; } i64 m = (s + e) >> 1;
        if(x <= m) return min(tr[p].line[x], query(x, tr[p].l, s, m));
        return min(tr[p].line[x], query(x, tr[p].r, m+1, e));
    }
};

/// 1-based index
Tpl64 struct Fenwick {
    v<T> tree; i32 n;
    explicit Fenwick(i32 treeSize) { n = treeSize; tree = v<T>(treeSize+10, T()); }
    void add(i32 tar, const T& val) { if(tar <= 0) { return; } for(; tar<=n; tar+=tar&-tar) tree[tar] += val; }
    /// [l, r]
    T query(i32 left, i32 right) { if(left > right) { return T(); } left = max(left, 1LL); return query(right) - query(left-1); }
    /// [1, tar]
    T query(i32 tar) { T ans = T(); for(; tar; tar-=(tar&-tar)) ans += tree[tar]; return ans; }
};

struct Fenwick2d {
    v2l tree; i32 xn, yn;
    explicit Fenwick2d(i32 xlen, i32 ylen) : xn(xlen), yn(ylen) { tree.resize(xlen+10, vl(ylen+10, 0)); }
    void update(i32 x, i32 y, i64 v){ for(; x<=xn; x+=x&-x) for(i32 yy=y; yy<=yn; yy+=yy&-yy) tree[x][yy] += v; }
    i64 query(i32 x, i32 y){ i64 ret = 0; for(; x; x-=x&-x) for(i32 yy=y; yy; yy-=yy&-yy) ret += tree[x][yy];
        return ret; }
    i64 query(i32 x1, i32 y1, i32 x2, i32 y2) { return query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1); }
};

template <typename T = i64>
class DynamicSeg {
    v<T> tree; i64 ln, rn; vi l, r;
    i32 next() { tree.eb(); l.eb(-1); r.eb(-1); return Size(tree)-1; }
public:
    explicit DynamicSeg(i64 li, i64 ri) : ln(li), rn(ri) { next(); }
    void add(i64 tar, const T& val) { add(0, ln, rn, tar, val); }
    void set(i64 tar, const T& val) { set(0, ln, rn, tar, val); }
    T query(i64 left, i64 right) { return query(0, ln, rn, left, right); }
private:
    T& add(i32 p, i64 s, i64 e, i64 t, const T& v) {
        if(s == e) return tree[p] = tree[p] + v;
        if(t <= (s + e) / 2) {
            if(l[p] == -1) l[p] = next();
            return tree[p] = add(l[p], s, (s+e)/2, t, v) + (r[p] == -1 ? T() : tree[r[p]]);
        }
        if(r[p] == -1) r[p] = next();
        return tree[p] = (l[p] == -1 ? T() : tree[l[p]]) + add(r[p], (s+e)/2+1, e, t, v);
    }
    T& set(i32 p, i64 s, i64 e, i64 t, const T& v) {
        if(s == e) return tree[p] = v;
        if(t <= (s + e) / 2) {
            if(l[p] == -1) l[p] = next();
            return tree[p] = set(l[p], s, (s+e)/2, t, v) + (r[p] == -1 ? T() : tree[r[p]]);
        }
        if(r[p] == -1) r[p] = next();
        return tree[p] = (l[p] == -1 ? T() : tree[l[p]]) + set(r[p], (s+e)/2+1, e, t, v);
    }
    T query(i32 p, i64 s, i64 e, i64 ql, i64 qr) {
        if(p == -1 || qr < s || e < ql) return T();
        if(ql <= s && e <= qr) return tree[p];
        return query(l[p], s, (s+e)/2, ql, qr) + query(r[p], (s+e)/2+1, e, ql, qr);
    }
};

template <typename T = i64>
class Dynamic2dSeg {
    i64 lx, rx, ly, ry; v<DynamicSeg<T>> tree; vi l, r;
public:
    Dynamic2dSeg(i64 lxi, i64 rxi, i64 lyi, i64 ryi) : lx(lxi), rx(rxi), ly(lyi), ry(ryi) { tree.eb(ly, ry); l.eb(-1); r.eb(-1); }
    void add(i64 tx, i64 ty, const T& val) { add(0, lx, rx, tx, ty, val); }
    void set(i64 tx, i64 ty, const T& val) { set(0, lx, rx, tx, ty, val); }
    T query(i64 left_x, i64 right_x, i64 left_y, i64 right_y) { return query(0, lx, rx, left_x, right_x, left_y, right_y); }
private:
    void add(i32 p, i64 sx, i64 ex, i64 tx, i64 ty, const T& val) {
        tree[p].add(ty, val); if(sx == ex) { return; }
        i64 mx = (sx + ex) / 2;
        if(tx <= mx) {
            if(l[p] == -1) l[p] = Size(tree), tree.eb(ly, ry), l.eb(-1), r.eb(-1);
            add(l[p], sx, mx, tx, ty, val);
        } else {
            if(r[p] == -1) r[p] = Size(tree), tree.eb(ly, ry), l.eb(-1), r.eb(-1);
            add(r[p], mx+1, ex, tx, ty, val);
        }
    }
    void set(i32 p, i64 sx, i64 ex, i64 tx, i64 ty, const T& val) {
        tree[p].set(ty, val); if(sx == ex) { return; } i64 mx = (sx + ex) / 2;
        if(tx <= mx) { if(l[p] == -1) l[p] = Size(tree), tree.eb(ly, ry), l.eb(-1), r.eb(-1);
            set(l[p], sx, mx, tx, ty, val); } else { if(r[p] == -1) r[p] = Size(tree), tree.eb(ly, ry), l.eb(-1), r.eb(-1);
            set(r[p], mx+1, ex, tx, ty, val); }
    }
    T query(i32 p, i64 sx, i64 ex, i64 qlx, i64 qrx, i64 qly, i64 qry) {
        if(p == -1 || ex < qlx || qrx < sx) return T();
        if(qlx <= sx && ex <= qrx) return tree[p].query(qly, qry);
        return query(l[p], sx, (sx+ex)/2, qlx, qrx, qly, qry) + query(r[p], (sx+ex)/2+1, ex, qlx, qrx, qly, qry);
    }
};


struct SpSumLazy;

/// requirements: (TreeType + TreeType), (LazyType + UpdateType), (TreeType + LazyIter&&), (LazyType + LazyIter&&)
/// <br> usage: node merge, node update, lazy update, lazy update
template <typename TreeType = i64, typename LazyType = SpSumLazy, typename UpdateType = i64>
class SparseSeg {
    v<TreeType> tree; v<LazyType> lazy; vi l, r; i64 ln, rn;
    i32 next() { tree.eb(); lazy.eb(); l.eb(-1); r.eb(-1); return Size(tree)-1; }
public:
    SparseSeg(i64 li, i64 ri) : ln(li), rn(ri) { next(); }
    /// tree & lazy are copied values, should not be modified
    struct iter {
        i32 node, start, end; TreeType tree; LazyType lazy; SparseSeg* segPtr;
        iter left() {
            assert(segPtr->l[node] != -1);
            segPtr->push(segPtr->l[node], start, (start+end)>>1);
            return iter(segPtr->l[node], start, (start+end)>>1, segPtr->tree[segPtr->l[node]], segPtr->lazy[segPtr->l[node]], segPtr);
        }
        iter right() {
            assert(segPtr->r[node] != -1);
            segPtr->push(segPtr->r[node], ((start+end)>>1)+1, end);
            return iter(segPtr->r[node], ((start+end)>>1)+1, end, segPtr->tree[segPtr->r[node]], segPtr->lazy[segPtr->r[node]], segPtr);
        }
        bool leaf() { return start == end; }
    };
    void update(i64 left, i64 right, const UpdateType& val) { update(0, ln, rn, left, right, val); }
    TreeType query(i64 tar) { return query(tar, tar); }
    TreeType query(i64 left, i64 right) { return query(0, ln, rn, left, right); }
    iter root() { push(0, ln, rn); return iter(0, ln, rn, tree[0], lazy[0], this); }
private:
    void push(i64 p, i64 s, i64 e) {
        tree[p] = tree[p] + iter(p, s, e, tree[p], lazy[p], this);
        if(s != e) {
            if(l[p] == -1) l[p] = next();
            lazy[l[p]] = lazy[l[p]] + iter(p, s, e, tree[p], lazy[p], this);
            if(r[p] == -1) r[p] = next();
            lazy[r[p]] = lazy[r[p]] + iter(p, s, e, tree[p], lazy[p], this);
        }
        lazy[p] = LazyType();
    }
    TreeType& update(i64 p, i64 s, i64 e, i64 ql, i64 qr, const UpdateType& v) {
        push(p, s, e);
        if(qr < s || e < ql) return tree[p];
        if(ql <= s && e <= qr) { lazy[p] = lazy[p] + v; push(p, s, e); return tree[p]; }
        i64 m = (s + e) >> 1;
        return tree[p] = update(l[p], s, m, ql, qr, v) + update(r[p], m+1, e, ql, qr, v);
    }
    TreeType query(i64 p, i64 s, i64 e, i64 ql, i64 qr) {
        push(p, s, e);
        if(qr < s || e < ql) return TreeType();
        if(ql <= s && e <= qr) return tree[p];
        i64 m = (s + e) >> 1;
        return query(l[p], s, m, ql, qr) + query(r[p], m+1, e, ql, qr);
    }
};

struct SpSumLazy { i64 v = 0; SpSumLazy operator+(ci64 i) const { return SpSumLazy(v+i); }
    SpSumLazy operator+(const SparseSeg<i64, SpSumLazy, i64>::iter& i) const { return SpSumLazy(v+i.lazy.v); } };
i64 operator+(ci64 a, const SparseSeg<i64, SpSumLazy, i64>::iter& b) { return a + (b.end - b.start + 1) * b.lazy.v; }


template <typename T = i64>
class pst {
    v<T> tree; vi l, r; i64 ln, rn;
public:
    pst(i64 leftBound, i64 rightBound) : ln(leftBound), rn(rightBound) { rep(2) tree.eb(), l.eb(0), r.eb(0); }
    // index = [1..n]
    explicit pst(const v<T>& arr) : ln(1), rn(Size(arr)) { tree.reserve(4*rn); rep(2) tree.eb(), l.eb(0), r.eb(0);
        init(1, ln, rn, arr); }
    struct iter {
        pst* ptr = nullptr; i32 pos = 0; i64 s = INF, e = -INF;
        T operator*() { return ptr->tree[pos]; } bool null() { return !pos; }
        iter left() { return {ptr, ptr->l[pos], s, (s+e)/2}; } iter right() { return {ptr, ptr->r[pos], (s+e)/2+1, e}; }
    };
    struct root {
        i32 pos = 0, prvPos = 0; pst* ptr = nullptr;
        root next() {
            root ret; ret.pos = Size(ptr->tree); ret.prvPos = pos; ret.ptr = ptr;
            ptr->tree.eb(ptr->tree[pos]); ptr->l.eb(ptr->l[pos]); ptr->r.eb(ptr->r[pos]);
            return ret;
        }
        iter getIter() { return {ptr, pos, ptr->ln, ptr->rn}; }
        /// @returns self
        root& add(i64 tar, const T& diff) { ptr->update(prvPos, pos, ptr->ln, ptr->rn, tar, diff, true); return *this; }
        /// @returns self
        root& set(i64 tar, const T& val) { ptr->update(prvPos, pos, ptr->ln, ptr->rn, tar, val, false); return *this; }
        T query(i64 left, i64 right) { return ptr->query(pos, ptr->ln, ptr->rn, left, right); }
    };
    friend root; friend iter; root begin() { return { 1, 0, this }; }
private:
    T& init(i32 cur, i64 s, i64 e, const v<T>& arr) {
        if(s == e) return tree[cur] = arr[s-1];
        l[cur] = Size(tree); r[cur] = Size(tree)+1; rep(2) tree.eb(), l.eb(0), r.eb(0);
        return tree[cur] = init(l[cur], s, (s+e)>>1, arr) + init(r[cur], ((s+e)>>1)+1, e, arr);
    }
    void update(i32 prv, i32 cur, i64 s, i64 e, i64 t, const T& d, bool isAdd) {
        if(s == e) { if(isAdd) { tree[cur] = tree[cur] + d; } else { tree[cur] = d; } return; } i64 m = (s + e) >> 1;
        if(t <= m) {
            if(!l[cur] || l[cur] == l[prv]) l[cur] = Size(tree), tree.eb(tree[l[prv]]), l.eb(0), r.eb(0);
            if(!r[cur]) r[cur] = r[prv];
            update(l[prv], l[cur], s, m, t, d, isAdd);
        } else {
            if(!l[cur]) l[cur] = l[prv];
            if(!r[cur] || r[cur] == r[prv]) r[cur] = Size(tree), tree.eb(tree[r[prv]]), l.eb(0), r.eb(0);
            update(r[prv], r[cur], m + 1, e, t, d, isAdd);
        }
        tree[cur] = tree[l[cur]] + tree[r[cur]];
    }
    T query(i32 cur, i64 s, i64 e, i64 ql, i64 qr) {
        if(!cur || qr < s || e < ql) { return T(); } if(ql <= s && e <= qr) return tree[cur];
        return query(l[cur], s, (s+e)>>1, ql, qr) + query(r[cur], ((s+e)>>1)+1, e, ql, qr);
    }
};
using pstIter = pst<i64>::iter; using pstRoot = pst<i64>::root;

struct PrefixSum2d {
    v2l data;
    PrefixSum2d()=default;
    explicit PrefixSum2d(const v2l& arr) {
        i64 yn = Size(arr), xn = Size(arr[0]);
        data.resize(yn, vl());
        forn(i, yn) forn(j, xn) {
            if(!j) data[i].eb(arr[i][j]);
            else data[i].eb(data[i][j-1] + arr[i][j]);
        }
        forn(j, xn) forf(i, 1, yn-1) data[i][j] += data[i-1][j];
    }
    i64 operator()(i64 ly, i64 ry, i64 lx, i64 rx) {
        i64 ret = data[ry][rx];
        if(lx) ret -= data[ry][lx-1];
        if(ly) ret -= data[ly-1][rx];
        if(lx&&ly) ret += data[ly-1][lx-1];
        return ret;
    }
};

#pragma endregion // dataStructures

#pragma region graph

struct SimpleEdge { i64 start, end; }; struct DistEdge { i64 start, end, dist; }; struct SimpleI32Edge { i32 start, end; };
Tpl concept isEdge1_ = requires(const T& a) { a.s; a.e; }; Tpl concept isEdge2_ = requires(const T& a) { a.start; a.end; }; Tpl concept isEdge = isEdge1_<T> || isEdge2_<T>;

/// node >= 0
/// requirements : (EdgeType.s && EdgeType.e) || (EdgeType.start && EdgeType.end)
/// detects : start/s, end/e, distance/dist/d
template <isEdge EdgeType = SimpleI32Edge>
class Graph {
#define defGCFs_ static i64 es_(const EdgeType& edge) { if constexpr(isEdge1_<EdgeType>) { return edge.s; } return edge.start; }\
                 static i64 ee_(const EdgeType& edge) { if constexpr(isEdge1_<EdgeType>) { return edge.e; } return edge.end; }\
                 static i64 ed_(const EdgeType& edge) {\
                     if constexpr(requires{edge.d;}) return edge.d;\
                     if constexpr(requires{edge.dist;}) return edge.dist;\
                     if constexpr(requires{edge.distance;}) return edge.distance;\
                     return 1;\
                 }
    defGCFs_
    static EdgeType revEdge_(EdgeType e) {
        if constexpr(isEdge1_<EdgeType>) swap(e.s, e.e);
        else if constexpr(isEdge2_<EdgeType>) swap(e.start, e.end);
        return e;
    }
public:
    i64 nodeCnt = 0; // (maxNodeNumber) + 1
    v2<EdgeType> child, parent, undir;
    /// disables all error check if true
    /// increases performance
    bool unsafe = false;

    Graph() = default;
    explicit Graph(ci64 maxNodeNum) { resize(maxNodeNum); }
    /// reset
    virtual void clear() { child = parent = undir = v2<EdgeType>(); nodeCnt = 0; unsafe = false; }
    void resize(ci64 maxNodeNum) {
        if(!unsafe && nodeCnt > maxNodeNum) { cerr << "Invalid resizing"; exit(1); }
        nodeCnt = maxNodeNum + 1;
        child.resize(nodeCnt, v<EdgeType>()); parent.resize(nodeCnt, v<EdgeType>()); undir.resize(nodeCnt, v<EdgeType>());
    }
    virtual void addUEdge(const EdgeType& edge) { undir[es_(edge)].eb(edge); undir[ee_(edge)].eb(revEdge_(edge)); }
    template <typename... Args> void makeUEdge(Args&&... args) { EdgeType edge(std::forward<Args>(args)...);
        undir[es_(edge)].eb(edge); undir[ee_(edge)].eb(revEdge_(edge)); }
    virtual void addDEdge(const EdgeType& edge) { child[es_(edge)].eb(edge); parent[ee_(edge)].eb(edge); }
    template <typename... Args> void makeDEdge(Args&&... args) { EdgeType edge(std::forward<Args>(args)...);
        child[es_(edge)].eb(edge); parent[ee_(edge)].eb(edge); }
    void removeDuplicateEdge() {
        fun<void(v2<EdgeType>&)> f = [&](v2<EdgeType>& k) {
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
        Graph<EdgeType>* g; i64 n;
    public:
        explicit Connection(Graph<EdgeType>* gp, i64 node) : g(gp), n(node) { }
        class Iter {
            friend class Connection;
            Graph<EdgeType>* g; v<EdgeType>::iterator cur; i64 n;
            Iter(Graph<EdgeType>* gp, v<EdgeType>::iterator i, i64 N) : g(gp), cur(i), n(N) {}
        public:
            Iter& operator++() { ++cur; if(cur == g->child[n].end()) { cur = g->undir[n].begin(); } return *this; }
            bool operator!=(const Iter& o) const { return cur != o.cur; }
            EdgeType& operator*() { return *cur; }
        };
        Iter begin() { return Iter(g, g->child[n].begin(), n); }
        Iter end() { return Iter(g, g->undir[n].end(), n); }
    };
    Connection getConnection(i64 node) { return Connection(this, node); }

    /// Complexity : O(ElogV)
    /// @returns {minDist, parent}
    pair<vl, vl> dijkstra(i64 startNode) {
        vl dist(nodeCnt, INF), par(nodeCnt, -1); pq<pair<i64, i64>, greater<>> q; q.emplace(0, startNode); dist[startNode] = 0;
        while(!q.empty()) {
            auto [d, cur] = pop(q); if(d > dist[cur]) continue;
            for(const auto& i : getConnection(cur)) {
                if(!unsafe && ed_(i) < 0) { cerr << "Negative distance is not allowed."; exit(1); }
                i64 nxt = ee_(i), nxtCost = d + ed_(i);
                if(nxtCost < dist[nxt]) { dist[nxt] = nxtCost; q.emplace(nxtCost, nxt); par[nxt] = cur; }
            }
        }
        return {dist, par};
    }
    /// Complexity : O(N)
    v<EdgeType> getConnectionArr(i64 node) { v<EdgeType> ret; for(const auto& e : child[node]) ret.eb(e); for(const auto& e : undir[node]) ret.eb(e); return ret; }
    Graph& setUnsafe(bool _ = true) { unsafe = _; return *this; }
};

template <isEdge EdgeType = SimpleEdge>
class DGraph : public Graph<EdgeType> { defGCFs_
public:
    explicit DGraph() = default;
    explicit DGraph(i64 maxNodeNum) : Graph<EdgeType>(maxNodeNum) {}
    explicit DGraph(const Graph<EdgeType>& g) : Graph<EdgeType>(g) {
        if(!this->unsafe) for(const auto& arr : this->undir) if(!arr.empty()) { cerr << "Not a valid DGraph.\n"; exit(1); }
    }
    /// SCC들은 위상 정렬되어 반환됨
    /// SCC 안 노드들은 번호 순서대로 정렬됨
    v2l getScc(const set<i64>& ignore = l_nullSet_) {
        vb finished(this->nodeCnt, false);
        vl id(this->nodeCnt, -1); i64 curId = 0;
        vl st; v2l ret;
        fun<i64(i64)> f = [&](i64 node) {
            id[node] = ++curId; st.pb(node);
            i64 parent = id[node];
            for(const auto& e : this->child[node]) {
                i64 i = ee_(e);
                if(id[i] == -1) parent = min(parent, f(i));
                else if(!finished[i]) parent = min(parent, id[i]);
            }
            if(parent == id[node]) {
                vl scc;
                while(true) {
                    i64 top = st.back(); st.pop_back();
                    scc.eb(top); finished[top] = true;
                    if(top == node) break;
                }
                sort(scc); ret.eb(scc);
            }
            return parent;
        };
        forn(i, this->nodeCnt) {
            if(ignore.contains(i)) continue;
            if(finished[i]) continue;
            f(i);
        }
        reverse(ret); return ret;
    }
};

template <isEdge EdgeType = SimpleEdge>
class Dag : public DGraph<EdgeType> {
public:
    /// does not check cycles.
    explicit Dag(const DGraph<EdgeType>& g) : DGraph<EdgeType>(g) { }
    vl topologySort(const set<i64>& ignore = l_nullSet_) {
        vl ret, inDegree(this->nodeCnt); i64 n = 0;
        forn(i, this->nodeCnt) inDegree[i] = Size(this->parent[i]);
        queue<i64> q;
        forn(i, this->nodeCnt) { if(ignore.contains(i)) { continue; } ++n; if(!inDegree[i]) q.emplace(i); }
        rep(n) {
            if(q.empty()) { cerr << "Dag has cycles!\n"; exit(1); }
            i64 x = pop(q); ret.eb(x);
            for(const auto& [X, i] : this->child[x]) if(--inDegree[i] == 0) q.emplace(i);
        }
        return ret;
    }
};

template <typename EdgeType = SimpleEdge>
class UGraph : public Graph<EdgeType> { defGCFs_
    bool useUnionFind = false; vl groupNum, groupSize;
    i64 uf_find(i64 tar) { if(groupNum[tar] == tar) return tar;
        return groupNum[tar] = uf_find(groupNum[tar]); }
    void uf_union(i64 a, i64 b) {
        if(uf_find(a) == uf_find(b)) return;
        if(groupSize[uf_find(a)] < groupSize[uf_find(b)]) swap(a, b);
        groupSize[uf_find(a)] += groupSize[uf_find(b)]; groupSize[uf_find(b)] = 0; groupNum[uf_find(b)] = uf_find(a);
    }
    void uf_init() {
        if(useUnionFind) { return; } useUnionFind = true;
        vb vis(this->nodeCnt, false); groupNum.resize(this->nodeCnt, -1); groupSize.resize(this->nodeCnt, 0);
        forn(i, this->nodeCnt) groupNum[i] = i;
        forn(i, this->nodeCnt) {
            if(vis[i]) { continue; } queue<i64> bfs; bfs.emplace(i); vis[i] = true; groupSize[i]++;
            while(!bfs.empty()) {
                i64 cur = pop(bfs);
                for(const auto& e : this->undir[cur]) {
                    i64 dest = ee_(e); if(vis[dest]) continue;
                    vis[dest] = true; groupNum[dest] = i; groupSize[i]++; bfs.emplace(dest);
                } } } }
public:
    void clear() { Graph<EdgeType>::clear(); useUnionFind = false; groupNum = groupSize = vl(); }
    void addEdge(const EdgeType& edge) { Graph<EdgeType>::addUEdge(edge); if(useUnionFind) uf_union(es_(edge), ee_(edge)); }
    template <typename... Args> void makeEdge(Args&&... args) { EdgeType edge(std::forward<Args>(args)...);
        Graph<EdgeType>::addUEdge(edge); if(useUnionFind) uf_union(es_(edge), ee_(edge)); }
    UGraph() = default;
    explicit UGraph(i64 maxNodeNum) : Graph<EdgeType>(maxNodeNum) { this->child = this->parent = v2<EdgeType>(); }
    explicit UGraph(const Graph<EdgeType>& g) : Graph<EdgeType>(g) { if(this->unsafe) return;
        for(const auto& arr : this->child) if(Size(arr)) { cerr << "Not a valid UGraph."; exit(1); }
        this->child = this->parent = v2<EdgeType>(); }
    void resize(i64 maxNodeNum) { if(!this->unsafe && this->nodeCnt >= maxNodeNum) { cerr << "Invalid resizing"; exit(1); }
        i64 preNodeCnt = this->nodeCnt; this->nodeCnt = maxNodeNum + 1; this->undir.resize(this->nodeCnt, v<EdgeType>());
        if(useUnionFind) forf(i, preNodeCnt, maxNodeNum) { groupNum.eb(i); groupSize.eb(1); } }
    /// union-find ( 0 <= group < nodeCnt ), O(N) (calls uf_find for all nodes)
    /// @return {[node] = group}
    [[nodiscard]] vl getAllGroup() { uf_init(); forn(i, this->nodeCnt) groupNum[i] = uf_find(i);
        return groupNum; }
    vl getAllGroupSize() { uf_init(); return groupSize; }
    /// union-find ( 0 <= group < nodeCnt ), O(1) (O(N) at first uf call)
    i64 getGroup(i64 node) { uf_init(); return uf_find(node); }
    /// union-find ( 0 <= group < nodeCnt ), O(1) (O(N) at first uf call)
    i64 getGroupSize(i64 group) { uf_init(); return groupSize[group]; }
};

class UF {
    bool useUnionFind = false; i64 n{};
    vi groupNum, groupSize;
    i64 uf_find(i64 tar) { if(groupNum[tar] == tar) return tar;
        return groupNum[tar] = uf_find(groupNum[tar]); }
    void uf_union(i64 a, i64 b) {
        if(uf_find(a) == uf_find(b)) return;
        if(groupSize[uf_find(a)] < groupSize[uf_find(b)]) swap(a, b);
        groupSize[uf_find(a)] += groupSize[uf_find(b)]; groupSize[uf_find(b)] = 0; groupNum[uf_find(b)] = uf_find(a);
    }
    void uf_init() {
        if(useUnionFind) { return; } useUnionFind = true;
        groupNum.resize(n, -1); groupSize.resize(n, 0);
        forn(i, n) groupNum[i] = i, groupSize[i] = 1;
    }
public:
    void merge(ci64 a, ci64 b) { uf_init(); uf_union(a, b); }
    void clear() { useUnionFind = false; n = 0; groupNum = groupSize = vi(); }
    explicit UF(i64 maxNodeNum) : n(maxNodeNum+1) { }
    /// union-find ( 0 <= group <= maxNodeNum ), O(N) (calls uf_find for all nodes)
    /// @return {[node] = group}
    [[nodiscard]] vi getAllGroup() { uf_init(); forn(i, n) groupNum[i] = uf_find(i);
        return groupNum; }
    vi getAllGroupSize() { uf_init(); return groupSize; }
    /// union-find ( 0 <= group <= maxNodeNum ), O(1) (O(N) at first uf call)
    i64 group(i64 node) { uf_init(); return uf_find(node); }
    /// union-find ( 0 <= group <= maxNodeNum ), O(1) (O(N) at first uf call)
    i64 size(i64 group) { uf_init(); return groupSize[group]; }
};

template <typename EdgeType>
class Tree : public Graph<EdgeType> { defGCFs_
    bool usingHld = false;
public:
    i64 root = -1; vl sz, dep, top, in, out, inRev;
    void clear() override {
        Graph<EdgeType>::clear(); sz = dep = top = in = out = inRev = vl(); usingHld = false; root = 0;
        logH = 0; usingSparse = false; sparsePar = sparseDist = v2l();
    }
    Tree() = default; // creates empty tree
    Tree(ci64 rootNode, const Graph<EdgeType>& graph) : Graph<EdgeType>(graph), root(rootNode) {
        if(!this->unsafe) { // check cycle
            vb vis(this->nodeCnt, false);
            bool hasCycle = false;
            fun<void(i64, i64)> dfs_ = [&](i64 cur, i64 par) {
                if(hasCycle) return;
                if(vis[cur]) { hasCycle = true; return; }
                vis[cur] = true;
                for(const auto& e : this->child[cur]) if(ee_(e) != par) dfs_(ee_(e), cur);
                for(const auto& e : this->undir[cur]) if(ee_(e) != par) dfs_(ee_(e), cur);
            };
            dfs_(rootNode, -1);
            if(hasCycle) { cerr << "Cycle detected while constructing Tree"; exit(1); }
        }
        fun<void(i64, i64)> dfs2_ = [&](i64 cur, i64 par) { // move undir -> child & parent
            for(const auto& e : this->child[cur]) if(ee_(e) != par) dfs2_(ee_(e), cur);
            for(const auto& e : this->undir[cur]) if(ee_(e) != par) {
                    this->child[cur].eb(e); this->parent[ee_(e)].eb(e);
                    dfs2_(ee_(e), cur);
                }
        };
        dfs2_(rootNode, -1);
        this->undir.clear();
    }

    i64 par(i64 node) { if(!this->unsafe) assert(this->parent[node].size() == 1);
        return es_(this->parent[node][0]); }

    /// euler tour technique (range: [1, n])
    /// saves results at in & out. new edges does not update the results.
    /// Complexity : O(N)
    pair<vl, vl> getInOut() {
        in = vl(this->nodeCnt, -1), out = in; i64 cur = 0;
        fun<void(i64)> f = [&](i64 p) { in[p] = ++cur;
            for(const auto& e : this->child[p]) f(ee_(e));
            out[p] = cur; };
        f(root); return {in, out};
    }

    /// heavy_light decomposition
    void initHld() {
        sz = dep = top = in = out = inRev = vl(this->nodeCnt, 0); usingHld = true;
        i64 pv = 0; top[this->root] = this->root;
        // sz & dep & par, reconstruct
        fun<void(i64)> dfs1 = [&](i64 v) {
            sz[v] = 1;
            for(auto &i : this->child[v]) {
                i64 j = ee_(i); dep[j] = dep[v] + 1; dfs1(j); sz[v] += sz[j];
                if(sz[j] > sz[ee_(this->child[v][0])]) swap(i, this->child[v][0]);
            }
        }; dfs1(this->root);
        // in & out & top
        fun<void(i64)> dfs2 = [&](i64 v) {
            in[v] = ++pv;
            for(const auto& i : this->child[v]) {
                i64 j = ee_(i); top[j] = (j == ee_(this->child[v][0])) ? top[v] : j; dfs2(j); }
            out[v] = pv;
        }; dfs2(this->root);
        forn(i, this->nodeCnt) inRev[in[i]] = i;
    }

    /// calls func(ettNum1, ettNum2) (ettNum1 <= ettNum2)
    /// for decomposed chains for a ~ b
    /// calls initHld() automatically if you didn't
    /// @returns lca(a, b)
    i64 hld(i64 a, i64 b, const fun<void(i64, i64)> &func) {
        if(!usingHld) initHld();
        while(top[a] != top[b]) {
            if(dep[top[a]] < dep[top[b]]) swap(a, b);
            i64 st = top[a]; func(in[st], in[a]); a = par(st);
        }
        if(dep[a] > dep[b]) swap(a, b);
        func(in[a], in[b]);
        return a;
    }

private:
    i64 logH = 0; v2l sparsePar, sparseDist; bool usingSparse = false;
    void initSparse() {
        if(usingSparse) return;
        usingSparse = true; sparsePar.resize(this->nodeCnt, vl()); sparseDist.resize(this->nodeCnt, vl());
        dep = vl(this->nodeCnt, 0);
        fun<void(i64)> dfs = [&](i64 v) {
            logH = max(logH, cast<i64>(log2(dep[v]+1)));
            for(auto &i : this->child[v]) { i64 j = ee_(i); dep[j] = dep[v] + 1; dfs(j); }
        }; dfs(this->root);
        forf(v, 0, this->nodeCnt-1) {
            if(this->parent[v].empty()) sparsePar[v].eb(v), sparseDist[v].pb(0);
            else sparsePar[v].eb(par(v)), sparseDist[v].eb(ed_(this->parent[v][0]));
        }
        forn(i, logH+1) forf(v, 0, this->nodeCnt-1) {
                sparsePar[v].eb(sparsePar[sparsePar[v][i]][i]);
                sparseDist[v].eb(sparseDist[v][i] + sparseDist[sparsePar[v][i]][i]);
            }
    }
public:
    pair<i64, i64> sparseLca(i64 a, i64 b) { initSparse();
        if(dep[a] > dep[b]) swap(a, b);
        i64 depDiff = dep[b] - dep[a], dist = 0;
        for(i64 i = logH; depDiff && i >= 0; i--)
            if(depDiff & (1<<i)) dist += sparseDist[b][i], b = sparsePar[b][i], depDiff ^= (1<<i);
        for(i64 i = logH; i >= 0; i--)
            if(sparsePar[a][i] != sparsePar[b][i])
                dist += sparseDist[a][i] + sparseDist[b][i], a = sparsePar[a][i], b = sparsePar[b][i];
        if(a == b) return {a, dist};
        return {sparsePar[a][0], dist + sparseDist[a][0] + sparseDist[b][0]};
    }

    /// if hld is made => returns lca using hld
    /// else => makes sparse tree
    i64 lca(ci64 a, ci64 b) {
        if(usingHld) return hld(a, b, ll_nullFunc_);
        return sparseLca(a, b).first;
    }

    /// uses sparse table
    i64 dist(ci64 a, ci64 b) { return sparseLca(a, b).second; }
};


class Flow {
public:
    i64 maxFlow = 0, source = -1, sink = -1;
protected:
    i64 maxNodeN = -1, edgeCount = -1;
    vl capacity, edgeFlow, revEdge;
    v<iii> edges; v2l con; vl visited;
public:
    Flow() = default;
    Flow(i64 MaxNodeNum, i64 Source, i64 Sink) {
        maxNodeN = MaxNodeNum; source = Source; sink = Sink;
        con = v2l(maxNodeN+10, vl());
        visited = vl(maxNodeN+10, -1);
        assert(Source <= MaxNodeNum && Sink <= MaxNodeNum);
    }
    void addEdge(i64 start, i64 end, i64 Capacity, i64 Dist = 0) {
        assert(start <= maxNodeN && end <= maxNodeN);
        assert(Capacity >= 0);
        edgeCount++; edges.push_back({start, end, Dist});
        capacity.push_back(Capacity); edgeFlow.push_back(0);
        revEdge.push_back(edgeCount+1); con[start].push_back(edgeCount);
        edgeCount++; edges.push_back({end, start, -Dist});
        capacity.push_back(0); edgeFlow.push_back(0);
        revEdge.push_back(edgeCount-1); con[end].push_back(edgeCount);
    }

    /// returns true if successes
    virtual bool run() {
        while(true) {
            for(i64 &i : visited) i = -1;
            queue<i64> bfs; bfs.push(source);
            while (!bfs.empty()) {
                i64 cur = bfs.front(); bfs.pop();
                for (i64 edge: con[cur]) {
                    if (capacity[edge] - edgeFlow[edge] > 0 && visited[edges[edge][1]] == -1) {
                        bfs.push(edges[edge][1]);
                        visited[edges[edge][1]] = edge;
                        if (edges[edge][1] == sink) break;
                    }
                }
                if (visited[sink] != -1) break;
            }
            if (visited[sink] == -1) break;

            i64 tempFlow = llmax;
            for (i64 i = sink; i != source; i = edges[visited[i]][0])
                tempFlow = min(tempFlow, capacity[visited[i]] - edgeFlow[visited[i]]);

            for (i64 i = sink; i != source; i = edges[visited[i]][0]) {
                edgeFlow[visited[i]] += tempFlow;
                edgeFlow[revEdge[visited[i]]] -= tempFlow;
            }
            maxFlow += tempFlow;
        }
        return true;
    }
};

class Mcmf : public Flow {
protected:
    vl dist;
public:
    i64 distSum = 0;
    Mcmf(i64 MaxNodeNum, i64 Source, i64 Sink) : Flow(MaxNodeNum, Source, Sink) { dist = vl(MaxNodeNum+10); }
    /// returns true if succeeds
    bool run() override {
        while(true) {
            for(i64 &i : visited) i = -1;
            for(i64 &i : dist) i = INF;
            v<bool> inQueue(maxNodeN+10, false);
            vl cycle(maxNodeN+10, 0);
            queue<int> spfa; spfa.push(source);
            dist[source] = 0;
            while (!spfa.empty()) {
                i64 cur = spfa.front(); spfa.pop();
                inQueue[cur] = false;
                cycle[cur]++;
                if(cycle[cur] >= maxNodeN) return false;
                for (ci64 edge: con[cur]) {
                    if (capacity[edge] - edgeFlow[edge] > 0 &&
                        dist[edges[edge][1]] > dist[cur] + edges[edge][2]) {
                        dist[edges[edge][1]] = dist[cur] + edges[edge][2];
                        visited[edges[edge][1]] = edge;
                        if(!inQueue[edges[edge][1]]) {
                            spfa.push(edges[edge][1]);
                            inQueue[edges[edge][1]] = true;
                        }
                    }
                }
            }
            if (visited[sink] == -1) break;

            i64 tempFlow = llmax;
            for (i64 i = sink; i != source; i = edges[visited[i]][0])
                tempFlow = min(tempFlow, capacity[visited[i]] - edgeFlow[visited[i]]);

            for (i64 i = sink; i != source; i = edges[visited[i]][0]) {
                edgeFlow[visited[i]] += tempFlow;
                edgeFlow[revEdge[visited[i]]] -= tempFlow;
            }
            maxFlow += tempFlow;
            distSum += dist[sink] * tempFlow;
        }
        return true;
    }
};


/// 1 ~ n
class TwoSat {
    i64 n = 0; DGraph<SimpleI32Edge> g;
public:
    TwoSat() = default;
    explicit TwoSat(i64 boolCount) : n(boolCount), g(boolCount*2+1) {}
    /// a or b, a : true, -a : false
    /// 1 <= a, b <= n
    void add(i64 a, i64 b) { a = a < 0 ? (-a) * 2 + 1 : a * 2; b = b < 0 ? (-b) * 2 + 1 : b * 2;
        g.makeDEdge(a^1, b); g.makeDEdge(b^1, a); }
    void add(i64 a) { add(a, a); } void addTrue(i64 a) { add(a, a); } void addFalse(i64 a) { add(-a, -a); } void addOr(i64 a, i64 b) { add(a, b); }
    void addXor(i64 a, i64 b) { add(a, b); add(-a, -b); } /// a != b이도록 조건을 설정
    void addXnor(i64 a, i64 b) { add(a, -b); add(-a, b); } /// a == b이도록 조건을 설정
    /// a : true, -a : false
    /// 1 <= a,b <= n
    bool possible() {
        v2l sccs = g.getScc({0}); vl sccId(n*2+2, -1);
        forn(i, Size(sccs)) for(ci64 j : sccs[i]) sccId[j] = i;
        forf(i, 1, n) if(sccId[2*i] == sccId[2*i+1]) return false;
        return true;
    }
    /// @returns an empty vector if not possible
    /// <br> returns arr[i] = (answer for i) if possible
    vb getAns() {
        v2l sccs = g.getScc({0}); vl sccId(n*2+2, -1);
        forn(i, Size(sccs)) for(ci64 j : sccs[i]) sccId[j] = i;
        forf(i, 1, n) if(sccId[2*i] == sccId[2*i+1]) return {};
        vi ansi(n, -1);
        for(const vl& scc : sccs) for(ci64 i : scc) if(ansi[i/2-1] == -1) ansi[i/2-1] = (i&1) ? 1 : 0;
        vb ans(1, false); for(ci32 i : ansi) ans.eb(i);
        return ans;
    }
};

#pragma endregion // Graph

#pragma region string

class AhoCorasick {
    i32 charCnt; char offset;
    v<vi> con; vi finish; vi fail; i64 av = 0; bool findAvailable = false;
    i32 next() { con.eb(charCnt, -1); finish.eb(0); fail.eb(-1); return av++; }
public:
    explicit AhoCorasick(i32 size = 26, char startChar = 'a') : charCnt(size), offset(startChar) { next(); }
    void insert(const str& s, i64 idx = 0, i64 p = 0) { // s[idx] == 만들어야 할 노드
        assert(!findAvailable);
        if(idx == Size(s)) { finish[p] = 1; return; }
        i32 nxt = s[idx] - offset;
        if(con[p][nxt] == -1)  con[p][nxt] = next();
        insert(s, idx+1, con[p][nxt]);
    }
    void init() {
        queue<i32> q; q.emplace(0);
        fail[0] = 0;
        while(!q.empty()) {
            i32 cur = pop(q);
            forn(i, charCnt) {
                if(con[cur][i] == -1) continue;
                i32 nxt = con[cur][i], x = fail[cur];
                if(!cur) { fail[nxt] = 0; q.emplace(nxt); continue; }
                while(x && con[x][i] == -1) x = fail[x];
                if(con[x][i] != -1) x = con[x][i];
                fail[nxt] = x;
                finish[nxt] += finish[fail[nxt]];
                q.emplace(nxt);
            }
        }
        findAvailable = true;
    }
    i64 findAt(const str& s) {
        if(!findAvailable) init();
        i32 cur = 0; i64 ans = 0;
        forn(i, Size(s)) {
            i32 idx = s[i] - offset;
            while(cur && con[cur][idx] == -1) cur = fail[cur];
            if(con[cur][idx] != -1) cur = con[cur][idx];
            ans += finish[cur];
        }
        return ans;
    }
};

struct KMP {
    i64 size; vl pi; str s;
    explicit KMP(const str& s) : size(Size(s)), pi(Size(s), 0), s(s) {
        for(i64 j=0, i=1; i<size; i++) {
            while(j && s[i] != s[j]) j = pi[j-1];
            if(s[i] == s[j]) pi[i] = ++j;
        }
    }
    vl findAt(const str& t) {
        vl ans; i64 n = Size(t);
        for(i64 i=0, j=0; i<n; i++) {
            while(j && t[i] != s[j]) j = pi[j-1];
            if(t[i] == s[j]) {
                if(j == size-1) ans.eb(i-size+1), j=pi[j];
                else j++;
            }
        }
        return ans;
    }
};

struct StringHash {
    vl hash, pc; i64 p, q;
    explicit StringHash(const str& s, i64 p = mod9, i64 mod = mod1, i64 offset = 0) : p(p), q(mod) {
        pc.reserve(Size(s)+2); pc.resize(1, 1);
        hash.reserve(Size(s)+2); hash.resize(1, 0);
        for(const char &c : s) {
            hash.eb((hash.back() * p + c - offset) % q);
            pc.eb(pc.back() * p % q);
        }
    }
    /// 0-based index
    inline i64 operator()(ci64 l, ci64 r) const {
        return (hash[r+1] - hash[l] * pc[r-l+1] % q + q) % q;
    }
};

#pragma endregion

#pragma region miscellaenous

template <i64 mod = mod1>
struct ModInt {
    i64 v = 0;
    ModInt()=default;
    ModInt(i64 val) : v((val%mod+mod) % mod) {} // NOLINT(*-explicit-constructor)
    explicit operator i64() { return v; }
    ModInt operator+(const ModInt& b) const { return {(v + b.v) % mod}; }
    ModInt operator-(const ModInt& b) const { return {(v - b.v + mod) % mod}; }
    ModInt operator*(const ModInt& b) const { return {(v * b.v) % mod}; }
    ModInt& operator+=(const ModInt& b) { v = (v + b.v) % mod; return *this; }
    ModInt& operator-=(const ModInt& b) { v = (v - b.v + mod) % mod; return *this; }
    ModInt& operator*=(const ModInt& b) { v = (v * b.v) % mod; return *this; }
};
template <i64 mod> istream& operator>>(istream& in, ModInt<mod>& t) { in >> t.v; return in; }
template <i64 mod> ostream& operator<<(ostream& out, const ModInt<mod>& t) { out << t.v; return out; }

#define defStructIO_(name) istream& operator>>(istream& in, name& t) { in >> t.v; return in; }\
                           ostream& operator<<(ostream& out, const name& t) { out << t.v; return out; }

struct MxSs { i64 v = -INFIN; MxSs operator+(const MxSs& b) const { return { max(v, b.v) }; }
bool operator<(const MxSs& b) const { return v < b.v; } explicit operator i64() const { return v; }};
struct MnSs { i64 v = INFIN; MnSs operator+(const MnSs& b) const { return { min(v, b.v) }; }
bool operator<(const MnSs& b) const { return v < b.v; } explicit operator i64() const { return v; }};
defStructIO_(MxSs) defStructIO_(MnSs)

i64 moQuerySortVal = -1;
struct moQuery { i64 i, j, order; bool operator<(const moQuery& b) const { lassert(moQuerySortVal != -1);
        if(i/moQuerySortVal == b.i/moQuerySortVal) { return j < b.j; } return i/moQuerySortVal < b.i/moQuerySortVal; } };

namespace PollardRho {
    namespace itnl {
        v<i128>base={2,3,5,7,11,13,17,19,23,29,31,37,41};mt19937 gen=mt19937(random_device()());uniform_int_distribution<i64>dis;
        bool _isPrime(i128 n,i128 a){if(a%n==0){return true;}i128 d=n-1;while(true){i128 t=pow_(a,d,n);if(t==n-1){return true;}
                if(d%2==1){return(t==1||t==n-1);}d/= 2;}}
    }
    bool isPrime(i128 n){if(n<=1)return false;for(const i128&a:itnl::base){if(!itnl::_isPrime(n, a))return false;}return true;}
    i128 factorize(i128 n){lassert(n>=2);if(n%2==0){return 2;}if(isPrime(n)){return n;}i128 x=itnl::dis(itnl::gen)%(n-2)+2,y=x,
                c=itnl::dis(itnl::gen)%10+1,g=1;while(g==1){x=(x*x%n+c)%n;y=(y*y%n+c)%n;y=(y*y%n+c)%n;g=gcd_(x-y>0?x-y:y-x,n);
            if(g==n)return factorize(n);}if(isPrime(g)){return g;}else return factorize(g);}
    vl getPrimes(i128 n) { vl r; while(n != 1) { i128 p = factorize(n); r.eb(p); n /= p; } return r; }
}
using namespace PollardRho;

#pragma endregion // miscellaneous

#pragma clang diagnostic pop
//@formatter:on


i32 main() {
    fastio;
    in64(h, w);
    v<str> lvl(1, str(w+2, '#'));
    rep(h) lvl.eb('#' + inStr() + '#');
    lvl.eb(w+2, '#');
    v2<i16> r(h+1, v<i16>(w+1, 0));
    v2<i16> l = r, u = r, d = r, group = r, starId = r; i64 prvStarId = 0;
    i32 bx = -1, by = -1;
    forf(x, 1, w) forf(y, 1, h) {
        if(lvl[y][x] == 'O') bx = x, by = y, lvl[y][x] = '.';
        if(lvl[y][x] == '*') starId[y][x] = ++prvStarId;
    }
    v2<ii> paths(prvStarId+1, v<ii>()); // { y, x }
    forf(x, 1, w) forf(y, 1, h) {
        if(lvl[y][x] != '#' && lvl[y][x-1] == '#') {
            i64 tx = x;
            while(lvl[y][tx] != '#') {
                if(lvl[y][tx] == '*') paths[starId[y][tx]].pb({y, x});
                l[y][tx++] = x;
            }
        }
        if(lvl[y][x] != '#' && lvl[y][x+1] == '#') { i64 tx = x; while(lvl[y][tx] != '#') r[y][tx--] = x; }
        if(lvl[y][x] != '#' && lvl[y-1][x] == '#') {
            i64 ty = y;
            while(lvl[ty][x] != '#') {
                if(lvl[ty][x] == '*') paths[starId[ty][x]].pb({y, x});
                u[ty++][x] = y;
            }
        }
        if(lvl[y][x] != '#' && lvl[y+1][x] == '#') { i64 ty = y; while(lvl[ty][x] != '#') d[ty--][x] = y; }
    }
    i64 maxGroup = -1;
    {
        UF uf(h * w);
        i64 prvG = 0;
        auto setGroup = [&](i64 ny, i64 nx, i64 g) {
            if(group[ny][nx]) uf.merge(group[ny][nx], g);
            else group[ny][nx] = g;
        };
        forf(x, 1, w) forf(y, 1, h) {
            if(lvl[y][x] == '#') continue;
            if(!group[y][x]) group[y][x] = ++prvG;
            i64 g = group[y][x];
            if(lvl[y - 1][x] == '#') setGroup(d[y][x], x, g);
            if(lvl[y + 1][x] == '#') setGroup(u[y][x], x, g);
            if(lvl[y][x - 1] == '#') setGroup(y, r[y][x], g);
            if(lvl[y][x + 1] == '#') setGroup(y, l[y][x], g);
        }
        vi ufGroups = uf.getAllGroup();
        {
            vi comp = compressed(ufGroups);
            for(i32 &i: ufGroups) i = idx(i, comp);
        }
        forf(x, 1, w) forf(y, 1, h) if(group[y][x]) setMax(maxGroup, group[y][x] = ufGroups[group[y][x]]);
    }

    DGraph g(maxGroup);
    forf(x, 1, w) forf(y, 1, h) {
        if(lvl[y][x] == '#') continue;
        if(group[y][x] != group[y][l[y][x]]) g.makeDEdge(group[y][x], group[y][l[y][x]]);
        if(group[y][x] != group[y][r[y][x]]) g.makeDEdge(group[y][x], group[y][r[y][x]]);
        if(group[y][x] != group[u[y][x]][x]) g.makeDEdge(group[y][x], group[u[y][x]][x]);
        if(group[y][x] != group[d[y][x]][x]) g.makeDEdge(group[y][x], group[d[y][x]][x]);
        g.removeDuplicateEdge();
    }
    l = v2<i16>(); r  = v2<i16>(); u  = v2<i16>(); d = v2<i16>();

    {
        v2l sccs = g.getScc({0});
        UF uf2(maxGroup);
        vl newGroup(maxGroup + 1);
        forn(i, maxGroup + 1) newGroup[i] = i;
        for(const auto &scc: sccs) {
            forf(i, 1, Size(scc) - 1) {
                newGroup[scc[i]] = scc[0];
                for(auto &[Cur, j]: g.child[scc[i]]) g.makeDEdge(scc[0], j);
                for(auto &[j, Cur]: g.parent[scc[i]]) g.makeDEdge(j, scc[0]);
                g.removeDuplicateEdge();
            }
        }
        forf(y, 1, h) forf(x, 1, w) group[y][x] = newGroup[group[y][x]];
    }

    fun<vb(i64)> bfs = [&](i64 node) -> vb {
        vb vis(maxGroup+1, false);
        queue<i64> q; q.emplace(node); vis[node] = true;
        while(!q.empty()) {
            i64 cur = pop(q);
            for(auto [Cur, i] : g.child[cur]) if(!vis[i]) vis[i] = true, q.emplace(i);
        }
        return vis;
    };
    fun<void(i64, vb&)> revBfs = [&](i64 node, vb& vis) {
        queue<i64> q; q.emplace(node); vis[node] = true;
        while(!q.empty()) {
            i64 cur = pop(q);
            for(auto [i, Cur] : g.parent[cur]) if(!vis[i]) vis[i] = true, q.emplace(i);
        }
    };

    TwoSat ts(maxGroup); ts.addTrue(group[by][bx]);
    forf(i, 1, prvStarId) {
        vl ps; for(const auto& [y, x] : paths[i]) ps.eb(group[y][x]);
        compress(ps); assert(Size(ps) <= 2);
        if(ps.empty()) printExit("NO");
        if(Size(ps) == 1) ts.addTrue(ps[0]);
        else ts.add(ps[0], ps[1]);
    }
    forf(i, 1, maxGroup) {
        vb vis = bfs(i);
        if(i == group[by][bx]) forf(j, 1, maxGroup) if(!vis[j]) ts.addFalse(j);
        revBfs(i, vis);
        forf(j, i+1, maxGroup) {
            if(vis[j]) continue;
            ts.add(-i, -j);
        }
    }
    println(ts.possible() ? "YES" : "NO");
}
