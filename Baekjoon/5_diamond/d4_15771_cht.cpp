#pragma region macros
//@formatter:off
#define ENABLE_MACRO true
#define ENABLE_O3 false
#define CPP11_MODE false
#define CPP17_MODE false
#define IGNORE_UNUSED_MACRO_WARNING true

#pragma region start

#if !ENABLE_MACRO // basic macros
#include <bits/stdc++.h>
#include <cassert>
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define i32 signed
using namespace std;
#endif

#if IGNORE_UNUSED_MACRO_WARNING
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma ide diagnostic ignored "OCUnusedTypeAliasInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "UnreachableCallsOfFunction"
#pragma ide diagnostic ignored "UnusedLocalVariable"
#pragma ide diagnostic ignored "UnusedValue"
#endif

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
using std::array, std::vector, std::list, std::pair, std::tuple;
using std::stack, std::queue, std::deque, std::set, std::multiset, std::unordered_map, std::unordered_set, std::numeric_limits, std::function;
using std::map, std::initializer_list, std::bitset, std::string;
using std::max, std::min, std::gcd, std::lcm, std::pow, std::swap, std::abs, std::sin, std::cos, std::tan, std::asin, std::acos, std::atan;
using std::floor, std::ceil, std::round, std::sinh, std::cosh, std::tanh, std::atan2;
using std::less, std::greater, std::less_equal, std::greater_equal, std::all_of, std::any_of, std::hash;
using std::stoi, std::stol, std::stoll, std::stoul, std::stoull, std::stof, std::stod, std::stold;
using std::sort, std::stable_sort, std::shuffle, std::uniform_int_distribution, std::mt19937, std::random_device, std::reverse;
using std::iota, std::prev, std::next, std::prev_permutation, std::next_permutation;
using std::complex, std::polar, std::is_integral_v, std::is_convertible_v, std::is_arithmetic_v, std::is_floating_point_v, std::to_string;
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
Tpl using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
Tpl using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
Tpl bool contains(ordered_set<T> &oset_, T val_) { if(oset_.empty()) { return false; } return *oset_.find_by_order(oset_.order_of_key(val_)) == val_; }
Tpl bool contains(ordered_multiset<T> &omset_, T val_) { if(omset_.empty()) { return false; } return *omset_.find_by_order(omset_.order_of_key(val_)) == val_; }
Tpl void erase_one(ordered_multiset<T> &omset_, T val_) { int index = omset_.order_of_key(val_); auto it = omset_.find_by_order(index); if(*it == val_) omset_.erase(it); }
Tpl void erase_all(ordered_multiset<T> &omset_, T val_) { while(contains(omset_, val_)) erase_one(omset_, val_); }

using i16 = short; using i32 = signed; using i64 = long long; using i128 = __int128;
using u16 = unsigned short; using u32 = unsigned; using u64 = unsigned long long; using u128 = unsigned __int128;
using f32 = float; using f64 = double; using f128 = long double;
using str = std::string;
template <typename T, typename T2> using umap = std::unordered_map<T, T2>;
Tpl using uset = std::unordered_set<T>;
Tpl using v = std::vector<T>; Tpl using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>; using vi = v<i32>; using vb = v<bool>;
using ii = array<i64, 2>; using iii = array<i64, 3>;
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
    INF    = 1000000000000000000,
    inf    = 3000000000,
    mod1   = 1000000007,
    mod9   = 998244353;
constexpr f128
    PI = 3.14159265358979323846;
const fun<void(i64, i64)> ll_nullFunc_ = [](ci64, ci64){};
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
template <typename ...T> inline void print(const T&... a_) { (cout << ... << a_); } inline void print() {}
template <typename ...T> inline void println(const T&... a_) { (cout << ... << a_); cout << '\n'; } inline void println() { cout << '\n'; }
template <typename ...T> inline void input(T&... a_) { (cin >> ... >> a_); }
#define in64(...) i64 __VA_ARGS__; input(__VA_ARGS__)

#if !CPP17_MODE
template <typename... Args> void printf_legacy(const Args&... args) { printf(args...); }

#define defIsChild(name, abbv) template <typename> struct is##name##Struct_ : std::false_type {};\
                               Tpl struct is##name##Struct_< abbv <T>> : std::true_type {};\
                               Tpl concept is##name = is##name##Struct_<T>::value;
defIsChild(Vector_, v) defIsChild(Queue_, queue) defIsChild(Stack_, stack) defIsChild(PQ_, pq)
Tpl concept isStQue_ = isStack_<T> || isQueue_<T> || isPQ_<T>;

struct Printf {
    str sep = " ", end;
    i32 prec = -1;
    i64 width = -1; char fill = ' ';
    bool exit = false; bool local = false;
    void operator()() {}
    template <typename ...T> void operator()(const T&... _) {
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
        if(prec != -1) cout << std::fixed, cout.precision(prec);
        if(width != -1) cout << std::setw(width) << std::setfill(fill);
    }
    Tpl void prf_imp_(const T& _) const { prf_imp_preset_(); cout << _ << end; if(exit) std::exit(0); }
    template <isVector_ T> void prf_imp_(const T& _) const {
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
    template <typename T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const {
        prf_imp_preset_(); cout << _ << sep; prf_imp_(b_...);
    }
    template <isVector_ T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const {
        for(const auto& v_ : _) { prf_imp_preset_(); cout << v_ << sep; } prf_imp_(b_...);
    }
    template <isStQue_ T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const { T1 st = _;
        while(!st.empty()) { prf_imp_preset_(); cout << pop(st) << sep; } prf_imp_(b_...);
    }
};
#define printf(...) Printf({__VA_ARGS__})
#define lprintf(...) Printf({__VA_ARGS__}).setLocal()
#define printfln(...) printf(__VA_ARGS__).appendEnd("\n")
#define lprintfln(...) printfln(__VA_ARGS__).setLocal()
#define printfExit(...) printfln(__VA_ARGS__).setExit()
#define printExit(...) printfln().setExit()(__VA_ARGS__)

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
template <typename T, typename T2, typename T3> T replace_if(const T& origin, const T2& cond, const T3& replacement)
    requires is_convertible_v<T2, T> && is_convertible_v<T3, T> {
    return origin == cast<T>(cond) ? cast<T>(replacement) : origin;
}
#define rplif replace_if

#pragma endregion // miscellaneous

#pragma endregion

#pragma region structs

/// requirements: (T + T), add -> (T += i64), set -> (T = i64)
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
    explicit Segtree(ci32 treeSize) { tree = v<T>(4*treeSize, T()); n = treeSize; }
    explicit Segtree(const v<T> &a) { n = Size(a); tree = v<T>(4*n, T()); init(a, 1, 1, n); }
    void set(ci32 tar, const T& val) { set(1, tar, 1, n, val); }
    void update(ci32 tar, const T& diff) { update(1, tar, 1, n, diff); }
    T query(ci32 left, ci32 right) { return query(1, left, right, 1, n); }
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
            else f(p<<1, s, (s+e)>>1), f(p<<1|1, ((s+e)>>1)|1, e); };
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
    void update(i32 left, i32 right, UpdateType diff) { update(1, left, right, 1, n, diff); }
    TreeType query(i32 left, i32 right) { return query(1, left, right, 1, n); }
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

struct SimpleEdge { i64 start, end; }; struct DistEdge { i64 start, end, dist; };
Tpl concept isEdge1_ = requires(const T& a) { a.s; a.e; }; Tpl concept isEdge2_ = requires(const T& a) { a.start; a.end; }; Tpl concept isEdge = isEdge1_<T> || isEdge2_<T>;

/// node >= 0
/// requirements : (EdgeType.s && EdgeType.e) || (EdgeType.start && EdgeType.end)
/// detects : start/s, end/e, distance/dist/d
template <isEdge EdgeType = SimpleEdge>
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
    virtual void clear() { child.clear(); parent.clear(); undir.clear(); nodeCnt = 0; unsafe = false; }
    void resize(ci64 maxNodeNum) {
        if(!unsafe && nodeCnt >= maxNodeNum) { cerr << "Invalid resizing"; exit(1); }
        nodeCnt = maxNodeNum + 1;
        child.resize(nodeCnt, v<EdgeType>()); parent.resize(nodeCnt, v<EdgeType>()); undir.resize(nodeCnt, v<EdgeType>());
    }
    virtual void addUEdge(const EdgeType& edge) { undir[es_(edge)].eb(edge); undir[ee_(edge)].eb(revEdge_(edge)); }
    template <typename... Args> void makeUEdge(Args&&... args) { EdgeType edge(std::forward<Args>(args)...);
        undir[es_(edge)].eb(edge); undir[ee_(edge)].eb(revEdge_(edge)); }
    virtual void addDEdge(const EdgeType& edge) { child[es_(edge)].eb(edge); parent[ee_(edge)].eb(edge); }
    template <typename... Args> void makeDEdge(Args&&... args) { EdgeType edge(std::forward<Args>(args)...);
        child[es_(edge)].eb(edge); parent[ee_(edge)].eb(edge); }

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

class UF {
    bool useUnionFind = false; i64 n{};
    vl groupNum, groupSize;
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
    explicit UF(i64 maxNodeNum) : n(maxNodeNum+1) { }
    /// union-find ( 0 <= group < nodeCnt ), O(N) (calls uf_find for all nodes)
    /// @return {[node] = group}
    [[nodiscard]] vl getAllGroup() { uf_init(); forn(i, n) groupNum[i] = uf_find(i);
        return groupNum; }
    vl getAllGroupSize() { uf_init(); return groupSize; }
    /// union-find ( 0 <= group < nodeCnt ), O(1) (O(N) at first uf call)
    i64 group(i64 node) { uf_init(); return uf_find(node); }
    /// union-find ( 0 <= group < nodeCnt ), O(1) (O(N) at first uf call)
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


#endif // ENABLE_MACRO
#if IGNORE_UNUSED_MACRO_WARNING
#pragma clang diagnostic pop
#endif
//@formatter:on
#pragma endregion // macros

class LiChaoTree {
public:
    struct Line { i64 a = 0, b = llmax; i64 operator[](ci64 x) const { return a*x+b; } };
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

// 대충 i일째에 산 식재료의 신선도 = n + Fi
// i일째에 필요한 신선도 = Li + i
// i일째에 (Fj+j=F)로 만든 요리의 맛 = (F-i) * Ci
// k일에 요리를 한다 == max(dp[j] + Fj * Ci - iCi)

// i일에 산 음식으로 j일에 요리를 한다 == max((Fi + i)Cj - jCj + dp[j+1]) (i<=j, Lj+j <= Fi+i)

i32 main() {
    fastio;
    in64(n);
    vl dp(n+2, -INF), f(n+1), c(n+1), l(n+1);
    dp[n+1] = 0;
    forf(i, 1, n) input(f[i]);
    forf(i, 1, n) input(c[i]);
    forf(i, 1, n) input(l[i]);
    LiChaoTree lct(0, 300010, true);
    forr(i, n, 1) {
        if(dp[i+1] != -INF) lct.updateAt(l[i]+i, 300010, {c[i], -i*c[i] + dp[i+1]});
        dp[i] = max(lct.query(f[i]+i), -INF);
    }
    if(dp[1] == -INF) println("Impossible");
    else println(dp[1]);
}
