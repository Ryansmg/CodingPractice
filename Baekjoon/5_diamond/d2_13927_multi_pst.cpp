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
using std::floor, std::ceil, std::round, std::sinh, std::cosh, std::tanh, std::atan2, std::sqrt;
using std::less, std::greater, std::less_equal, std::greater_equal, std::all_of, std::any_of, std::hash;
using std::stoi, std::stol, std::stoll, std::stoul, std::stoull, std::stof, std::stod, std::stold;
using std::sort, std::stable_sort, std::shuffle, std::uniform_int_distribution, std::mt19937, std::random_device, std::reverse;
using std::iota, std::prev, std::next, std::prev_permutation, std::next_permutation;
using std::complex, std::polar, std::is_integral_v, std::is_convertible_v, std::is_arithmetic_v, std::is_floating_point_v, std::is_same_v, std::to_string;
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
#ifdef LOCAL
using F128 = long double;
#else
using F128 = __float128;
#endif
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
Tpl inline T max(const v<T>& v_) { T ret = v_.empty() ? lim<T>::min() : v_[0]; for(const T &t_ : v_) { ret = max(ret, t_); } return ret; }
Tpl inline T min(const v<T>& v_) { T ret = v_.empty() ? lim<T>::max() : v_[0]; for(const T &t_ : v_) { ret = min(ret, t_); } return ret; }
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
#pragma clang diagnostic pop // remove at ext
//@formatter:on              // remove at ext
#pragma endregion // macros

/// Persistent Segment Tree
template <typename T = i64>
class Pst {
    v<T> tree; vi l, r; i64 ln, rn;
public:
    Pst(i64 leftBound, i64 rightBound) : ln(leftBound), rn(rightBound) { rep(2) tree.eb(), l.eb(0), r.eb(0); }
    // index = [1..n]
    explicit Pst(const v<T>& arr) : ln(1), rn(Size(arr)) { tree.reserve(4*rn); rep(2) tree.eb(), l.eb(0), r.eb(0);
        init(1, ln, rn, arr); }
    struct Iter {
        Pst* ptr = nullptr; i32 pos = 0; i64 s = INF, e = -INF;
        T operator*() { return ptr->tree[pos]; } bool null() { return !pos; }
        Iter left() { return {ptr, ptr->l[pos], s, (s+e)/2}; } Iter right() { return {ptr, ptr->r[pos], (s+e)/2+1, e}; }
    };
    struct Root {
        i32 pos = 0, prvPos = 0; Pst* ptr = nullptr;
        Root next() {
            Root ret; ret.pos = Size(ptr->tree); ret.prvPos = pos; ret.ptr = ptr;
            ptr->tree.eb(ptr->tree[pos]); ptr->l.eb(ptr->l[pos]); ptr->r.eb(ptr->r[pos]);
            return ret;
        }
        Iter iter() { return {ptr, pos, ptr->ln, ptr->rn}; }
        /// @returns self
        Root& add(i64 tar, const T& diff) { ptr->update(prvPos, pos, ptr->ln, ptr->rn, tar, diff, true); return *this; }
        /// @returns self
        Root& set(i64 tar, const T& val) { ptr->update(prvPos, pos, ptr->ln, ptr->rn, tar, val, false); return *this; }
        T query(i64 left, i64 right) { return ptr->query(pos, ptr->ln, ptr->rn, left, right); }
    };
    friend Root; friend Iter; Root root() { return { 1, 0, this }; }
private:
    T& init(i32 cur, i64 s, i64 e, const v<T>& arr) {
        if(s == e) return tree[cur] = arr[s-1];
        l[cur] = Size(tree); r[cur] = Size(tree)+1; rep(2) tree.eb(), l.eb(0), r.eb(0);
        return tree[cur] = init(l[cur], s, (s+e)>>1, arr) + init(r[cur], ((s+e)>>1)+1, e, arr);
    }
    void update(i32 prv, i32 cur, i64 s, i64 e, i64 t, const T& d, bool isAdd) {
        if(s == e) { if(isAdd) { tree[cur] = tree[cur] + d; } else { tree[cur] = d; } return; } i64 m = (s + e) >> 1;
        if(t <= m) {
            if(!l[cur] || l[cur] == l[prv]) l[cur] = Size(tree), tree.eb(tree[l[prv]]), l.eb(l[l[prv]]), r.eb(r[l[prv]]);
            if(!r[cur]) r[cur] = r[prv];
            update(l[prv], l[cur], s, m, t, d, isAdd);
        } else {
            if(!l[cur]) l[cur] = l[prv];
            if(!r[cur] || r[cur] == r[prv]) r[cur] = Size(tree), tree.eb(tree[r[prv]]), l.eb(l[r[prv]]), r.eb(r[r[prv]]);
            update(r[prv], r[cur], m + 1, e, t, d, isAdd);
        }
        tree[cur] = tree[l[cur]] + tree[r[cur]];
    }
    T query(i32 cur, i64 s, i64 e, i64 ql, i64 qr) {
        if(!cur || qr < s || e < ql) { return T(); } if(ql <= s && e <= qr) return tree[cur];
        return query(l[cur], s, (s+e)>>1, ql, qr) + query(r[cur], ((s+e)>>1)+1, e, ql, qr);
    }
};
using PstIter = Pst<i64>::Iter; using PstRoot = Pst<i64>::Root;

/// 2D Persistent Segment Tree
class Pst2d {
    vector<PstRoot> tree; vi l, r; i64 ln, rn;
    Pst<i64> pst;
public:
    Pst2d(i64 yLeftBound, i64 yRightBound, i64 xLeftBound, i64 xRightBound)
        : ln(yLeftBound), rn(yRightBound), pst(xLeftBound, xRightBound){
        tree.eb(pst.root()), l.eb(0), r.eb(0);
        tree.eb(pst.root().next()), l.eb(0), r.eb(0);
    }
    // index = [1..n]
    struct Iter {
        Pst2d* ptr = nullptr; i32 pos = 0; i64 s = INF, e = -INF;
        PstRoot& operator*() const { return ptr->tree[pos]; } bool null() const { return !pos; }
        Iter left() { return {ptr, ptr->l[pos], s, (s+e)/2}; } Iter right() { return {ptr, ptr->r[pos], (s+e)/2+1, e}; }
    };
    struct Root {
        i32 pos = 0, prvPos = 0; Pst2d* ptr = nullptr;
        Root next() const {
            Root ret; ret.pos = Size(ptr->tree); ret.prvPos = pos; ret.ptr = ptr;
            ptr->tree.eb(ptr->tree[pos].next()); ptr->l.eb(ptr->l[pos]); ptr->r.eb(ptr->r[pos]);
            return ret;
        }
        Iter iter() { return {ptr, pos, ptr->ln, ptr->rn}; }
        /// @returns self
        Root& add(i64 y, i64 x, const i64& diff) { ptr->update(prvPos, pos, ptr->ln, ptr->rn, y, x, diff, true); return *this; }
        /// @returns self
        Root& set(i64 y, i64 x, const i64& val) { ptr->update(prvPos, pos, ptr->ln, ptr->rn, y, x, val, false); return *this; }
        v<PstRoot> query(i64 yl, i64 yr) const { ptr->queryRet.clear(); ptr->query(pos, ptr->ln, ptr->rn, yl, yr); return ptr->queryRet; }
    };
    friend Root; friend Iter; Root root() { return { 1, 0, this }; }
private:
    v<PstRoot> queryRet;
    void update(i32 prv, i32 cur, i64 s, i64 e, i64 yt, i64 xt, ci64 d, bool isAdd) {
        if(isAdd) { tree[cur].add(xt, d); } else { tree[cur].set(xt, d); }
        if(s == e) return;
        i64 m = (s + e) >> 1;
        if(yt <= m) {
            if(!l[cur] || l[cur] == l[prv]) l[cur] = Size(tree), tree.eb(tree[l[prv]].next()), l.eb(l[l[prv]]), r.eb(r[l[prv]]);
            if(!r[cur]) r[cur] = r[prv];
            update(l[prv], l[cur], s, m, yt, xt, d, isAdd);
        } else {
            if(!l[cur]) l[cur] = l[prv];
            if(!r[cur] || r[cur] == r[prv]) r[cur] = Size(tree), tree.eb(tree[r[prv]].next()), l.eb(l[r[prv]]), r.eb(r[r[prv]]);
            update(r[prv], r[cur], m + 1, e, yt, xt, d, isAdd);
        }
    }
    void query(i32 cur, i64 s, i64 e, i64 ql, i64 qr) {
        if(!cur) return;
        if(qr < s || e < ql) { return; } if(ql <= s && e <= qr) { queryRet.pb(tree[cur]); return; }
        query(l[cur], s, (s+e)>>1, ql, qr); query(r[cur], ((s+e)>>1)+1, e, ql, qr);
    }
};
using Pst2dIter = Pst2d::Iter; using Pst2dRoot = Pst2d::Root;


i32 main() {
    fastio;
    in64(n);
    vl a = inArr(n);
    vl comp = compressed(a);
    for(i64& i : a) i = idx(i, comp)+1;
    Pst2d seg(1, n, 1, n);
    v<Pst2dRoot> psts; psts.pb(seg.root());
    map<i64, i64> prv;
    forn(i, n) {
        Pst2dRoot cur = psts.back().next();
        auto iter = prv.find(a[i]);
        if(iter != prv.end()) cur.set(iter->second, a[i], 0), iter->second = i+1;
        else prv.insert({a[i], i+1});
        cur.set(i+1, a[i], 1);
        psts.pb(cur);
    }
    i64 ans = 0;
    inRep() {
        in64(ai, b, c, d, k);
        i64 l = ((ai * max(ans, 0) + b) % n) + 1, r = ((c * max(ans, 0) + d) % n) + 1;
        if(l > r) swap(l, r);
        auto segArr = psts[r].query(l, r);
        v<PstIter> iters;
        for(auto& s : segArr) iters.pb(s.iter());
        i64 arrSum = 0; for(auto& s : iters) arrSum += *s;
        if(arrSum < k) { println(ans = -1); continue; }
        while(iters[0].s != iters[0].e) {
            i64 lSum = 0;
            for(auto& s : iters) lSum += *s.left();
            if(lSum >= k) {
                for(auto &s : iters) s = s.left();
            } else {
                k -= lSum;
                for(auto &s : iters) s = s.right();
            }
        }
        println(ans = comp[iters[0].s-1]);
    }
}