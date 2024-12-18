#pragma region macros
//@formatter:off
#define GCC_OFAST_ENABLE false
#define DISABLE_KOISTUDY_ERROR false
#define IGNORE_UNUSED_MACRO_WARNING true

#pragma clang diagnostic push
#if IGNORE_UNUSED_MACRO_WARNING
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma ide diagnostic ignored "OCUnusedTypeAliasInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "UnreachableCallsOfFunction"
#endif

#if GCC_OFAST_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#include <bits/stdc++.h>

// keyword reassign ///////////////////////////////////////////////////////////////
#define Tpl template <typename T>
#define elif else if
#if DISABLE_KOISTUDY_ERROR
using namespace std;
#else
using std::cin, std::cout, std::cerr, std::clog, std::endl, std::istream, std::ostream, std::ifstream, std::ofstream, std::setw, std::setfill;
using std::array, std::vector, std::stack, std::queue, std::deque, std::list, std::pair, std::tuple;
using std::set, std::multiset, std::map, std::initializer_list, std::bitset;
using std::max, std::min, std::gcd, std::lcm, std::pow, std::swap, std::abs, std::sin, std::cos, std::tan, std::asin, std::acos, std::atan;
using std::floor, std::ceil, std::round;
using std::sinh, std::cosh, std::tanh, std::atan2;
using std::less, std::greater, std::less_equal, std::greater_equal, std::all_of, std::any_of, std::hash;
using std::stoi, std::stol, std::stoll, std::stoul, std::stoull, std::stof, std::stod, std::stold;
using std::sort, std::stable_sort, std::shuffle, std::uniform_int_distribution, std::mt19937, std::random_device;
using std::iota, std::prev, std::next, std::prev_permutation, std::next_permutation;
using std::complex, std::polar, std::is_integral_v;

#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename Type>
using ordered_set = __gnu_pbds::tree<Type, __gnu_pbds::null_type, less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename Type>
using ordered_multiset = __gnu_pbds::tree<Type, __gnu_pbds::null_type, less_equal<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
Tpl bool contains(ordered_set<T> &oset, T val) {
    if(oset.empty()) return false;
    return *oset.find_by_order(oset.order_of_key(val)) == val;
}
Tpl bool contains(ordered_multiset<T> &omset, T val) {
    if(omset.empty()) return false;
    return *omset.find_by_order(omset.order_of_key(val)) == val;
}
Tpl void erase_one(ordered_multiset<T> &omset, T val) {
    int index = omset.order_of_key(val);
    auto it = omset.find_by_order(index);
    if(*it == val) omset.erase(it);
}
Tpl void erase_all(ordered_multiset<T> &omset, T val) { while(contains(omset, val)) erase_one(omset, val); }
#endif

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

// consts ///////////////////////////////////////////////////////////////
constexpr i64
    i64max = 9223372036854775807,
    llmax  = 9223372036854775807,
    INF    = 1000000000000000000,
    inf    = 3000000000;
constexpr f128
    pi = 3.14159265358979323846;

// basic cpp macros ///////////////////////////////////////////////////////////////
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define forr(name, start, end) for(i64 name = start; name >= end; name--)
#define rep(n) forn(rep_mac_name_1_, n)
#define rep2(n) forn(rep_mac_name_2_, n)

i64 iR_v_, iR_v2_, iR_v5_;
#define inRep() input(iR_v_); forn(iR_v3_, iR_v_)
#define inRep2() input(iR_v2_); forn(iR_v4_, iR_v2_)
#define tcRep() input(iR_v5_); forf(TCN, 1, iR_v5_)

// STL macros ///////////////////////////////////////////////////////////////
#if !DISABLE_KOISTUDY_ERROR
template <typename T=i64, typename T3=less<>> using pq = std::priority_queue<T, v<T>, T3>;
template <typename T, typename T3> inline T pop(pq<T, T3> &pq) { T t = pq.top(); pq.pop(); return t; }
#endif

#define all(vec) (vec).begin(), (vec).end()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
Tpl inline auto lb(const v<T> &r_, T i_) { return lower_bound(all(r_), i_); }
Tpl inline auto ub(const v<T> &r_, T i_) { return upper_bound(all(r_), i_); }
Tpl inline i64 Size(const T &_) { return static_cast<i64>(_.size()); }

Tpl inline T pop(stack<T> &st) { T t = st.top(); st.pop(); return t; }
Tpl inline T pop(queue<T> &q) { T t = q.front(); q.pop(); return t; }
Tpl inline void reverse(T &v) { reverse(all(v)); }
Tpl inline void sort(T &v) { sort(all(v)); }
Tpl inline void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
Tpl inline T reversed(T arr) { reverse(all(arr)); return arr; }
Tpl inline T sorted(T arr) { sort(all(arr)); return arr; }
Tpl inline T compressed(T arr, const bool &autosort=true) { compress(arr, autosort); return arr; }
Tpl inline T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
Tpl inline T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
Tpl inline T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }

Tpl inline T gcd(const initializer_list<T>& l_) {
    auto iter = l_.begin(); T ret = *iter; i64 sz_ = l_.size();
    forf(i_, 1, sz_-1) ret = std::gcd(ret, *(++iter));
    return ret;
}
Tpl inline T lcm(const initializer_list<T>& l_) {
    auto iter = l_.begin(); T ret = *iter / gcd(l_); i64 sz_ = l_.size();
    forf(i_, 1, sz_-1) ret *= *(++iter);
    return ret;
}
Tpl inline T max(const v<T>& v_) {
    T ret = lim<T>::min(); for(const T &t_ : v_) ret = max(ret, t_);
    return ret;
}
Tpl inline T min(const v<T>& v_) {
    T ret = lim<T>::max(); for(const T &t_ : v_) ret = min(ret, t_);
    return ret;
}

Tpl inline T lcm_(const T& a, const T& b) { return a / gcd_(a, b) * b; }
Tpl inline T sq_(const T &i) { return i * i; }
Tpl inline T sum(const v<T>& r_) { T s_ = 0; {for(const T& i_ : r_) s_ += i_;} return s_; }

random_device macro_random_device_;
mt19937 mt19937_gen_(macro_random_device_());
uniform_int_distribution<i32> uni_i_dis_i32_(0, lim<i32>::max());
uniform_int_distribution<i64> uni_i_dis_i64_(0, lim<i64>::max());
#define rand() randi()
inline i32 randi() { return uni_i_dis_i32_(mt19937_gen_); }
inline i64 randl() { return uni_i_dis_i64_(mt19937_gen_); }
inline i64 randInt(ci64 l_, ci64 r_) { return randl() % (r_ - l_ + 1) + l_; } // inclusive

#ifdef LOCAL
#define lassert assert
#else
#define lassert(...)
#endif

// I/O macros ///////////////////////////////////////////////////////////////
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
#define ansout print()
#define inputout print()
#define outputin print()
#endif // LOCAL
template <typename T = i64> inline T input() {T t; cin >> t; return t;}
inline str inStr() { str t; cin >> t; return t; }
template <typename T = i64> inline v<T> inputArr(i64 sz) { v<T> a; forn(i,sz) a.eb(input<T>()); return a; }
template <typename T = i64> inline void inputArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.eb(input<T>()); }
template <typename T = i64> inline void inArr(v<T> &arr, i64 sz, bool clear = true) { inputArr(arr, sz, clear); }
template <typename T = i64> inline v<T> inArr(i64 sz) { v<T> a; forn(i,sz) a.eb(input<T>()); return a; }
template <typename T = i64> inline v<T> inArr() { return inArr(input()); }
inline str readline() { char c = '\n'; while(c == '\n') cin.get(c); str s; getline(cin, s); s = c + s; return s; }
Tpl inline void printArr(const v<T> &v, const str &sep = " ", const str &end = "\n") {
    if(v.empty()) return;
    i64 paSz_ = v.size(); forn(i, paSz_-1) cout << v[i] << sep; cout << v[paSz_-1] << end;
}
inline void fixPrecision(i32 a_) { cout << std::fixed; cout.precision(a_); }

#if !DISABLE_KOISTUDY_ERROR
template <typename ...T> inline void print(const T&... a_) { (cout << ... << a_); }
inline void print() {}
template <typename ...T> inline void println(const T&... a_) { (cout << ... << a_); cout << '\n'; }
inline void println() { cout << '\n'; }
Tpl inline void printSep(const T& a_) { cout << a_; }
template <typename T1, typename ...T2> inline void printSep(const T1& a_, const T2&... b_) { cout << a_ << ' '; printSep(b_...); }
template <typename ...T> inline void printSepLn(const T&... a_) { printSep(a_...); println(); }
template <typename ...T> inline void printExit(const T&... a_) { (cout << ... << a_); cout << '\n'; exit(0); }
template <typename ...T> inline void input(T&... a_) { (cin >> ... >> a_); }

struct Printf {
    str sep = " ", end;
    i32 prec = -1;
    i32 width = -1; char fill = ' ';
    void operator()() {}
    template <typename ...T> void operator()(const T&... _) { prf_imp_(_...); }
    Printf& appendEnd(const str& end_) { end += end_; return *this; }
private:
    inline void prf_imp_preset_() const {
        if(prec != -1) cout << std::fixed, cout.precision(prec);
        if(width != -1) cout << std::setw(width) << std::setfill(fill);
    }
    Tpl void prf_imp_(const T& _) const { prf_imp_preset_(); cout << _ << end; }
    template <typename T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const {
        prf_imp_preset_(); cout << _ << sep; prf_imp_(b_...);
    }
};
#define printf(...) Printf({__VA_ARGS__})
#define printfln(...) printf(__VA_ARGS__).appendEnd("\n")

#endif // !DISABLE_KOISTUDY_ERROR
#define invar(...) i64 __VA_ARGS__; input(__VA_ARGS__)

// conversions ///////////////////////////////////////////////////////////////
Tpl inline str tostr(const T &t) { return std::to_string(t); }
inline str tostr(const str &t) { return t; }
#define mac_conv_(type, sh) Tpl inline type to##type(const T &t) { return cast<type>(t); } \
                                inline type to##type(const str &t) { return sto##sh(t); }
Tpl inline i128 toi128(const T &t) { return cast<i128>(t); }
inline i128 toi128(const str &t) { return cast<i128>(stoull(t)); }
mac_conv_(i64, ll) mac_conv_(i32, i) mac_conv_(u64, ull) mac_conv_(f64, d) mac_conv_(f128, ld)

// extra math ///////////////////////////////////////////////////////////////
namespace PollardRho {
    namespace itnl {
        v<i128>base={2,3,5,7,11,13,17,19,23,29,31,37,41};mt19937 gen=mt19937(random_device()());uniform_int_distribution<i128>dis;
        bool _isPrime(i128 n,i128 a){if(a%n==0){return true;}i128 d=n-1;while(true){i128 t=pow_(a,d,n);if(t==n-1){return true;}
        if(d%2==1){return(t==1||t==n-1);}d/= 2;}}
    }
    bool isPrime(i128 n){if(n<=1)return false;for(const i128&a:itnl::base){if(!itnl::_isPrime(n, a))return false;}return true;}
    i128 factorize(i128 n){lassert(n>=2);if(n%2==0){return 2;}if(isPrime(n)){return n;}i128 x=itnl::dis(itnl::gen)%(n-2)+2,y=x,
        c=itnl::dis(itnl::gen)%10+1,g=1;while(g==1){x=(x*x%n+c)%n;y=(y*y%n+c)%n;y=(y*y%n+c)%n;g=gcd_(x-y>0?x-y:y-x,n);
        if(g==n)return factorize(n);}if(isPrime(g)){return g;}else return factorize(g);}
    vl getPrimes(i128 n) { vl r; while(n != 1) { i128 p = factorize(n); r.eb(p); n /= p; } return r; }
}
constexpr i32 dx4[] = {1, 0, -1, 0};
constexpr i32 dy4[] = {0, 1, 0, -1};

#pragma endregion

#pragma region structs
struct edge { i64 s, e, v; };

/// requirements: operator+(T, T)
template <typename T = i64>
class Segtree {
protected:
    vector<T> tree; i32 n;
public:
    explicit Segtree(ci32 treeSize) {
        tree = v<T>(4*treeSize, T()); n = treeSize;
    }
    explicit Segtree(const v<T> &a) {
        n = Size(a); tree = v<T>(4*n, T());
        init(a, 1, 1, n);
    }
    void set(ci32 tar, const T& val) { set(1, tar, 1, n, val); }
    void update(ci32 tar, const T& diff) { update(1, tar, 1, n, diff); }
    T query(ci32 left, ci32 right) { return query(1, left, right, 1, n); }
protected:
    T init(const v<T> &a, ci32 node, ci32 start, ci32 end) {
        if(start==end) return tree[node] = a[start-1];
        else return tree[node] = init(a, node*2, start, (start+end)/2)
                                 + init(a, node*2+1, (start+end)/2+1, end);
    }
    T update(ci32 node, ci32 tar, ci32 start, ci32 end, const T& diff) {
        if(end < tar || tar < start) return tree[node];
        if(start == end) return tree[node] = tree[node] + diff;
        return tree[node] = update(node*2, tar, start, (start+end)/2, diff)
                            + update(node*2+1, tar, (start+end)/2+1, end, diff);
    }
    T set(ci32 node, ci32 tar, ci32 start, ci32 end, const T& val) {
        if(end < tar || tar < start) return tree[node];
        if(start == end) return tree[node] = val;
        return tree[node] = set(node*2, tar, start, (start+end)/2, val)
                            + set(node*2+1, tar, (start+end)/2+1, end, val);
    }
    T query(ci32 node, ci32 left, ci32 right, ci32 start, ci32 end) {
        if(right < start || end < left) return T();
        if(left <= start && end <= right) return tree[node];
        return query(node*2, left, right, start, (start+end)/2) +
               query(node*2+1, left, right, (start+end)/2+1, end);
    }
};

template <typename LazyType>
struct LazyIter { i32 node, start, end; LazyType val; };

struct LazypropSumLazy {
    i64 v = 0;
    LazypropSumLazy operator+(ci64 i) const { return LazypropSumLazy(v+i); }
    LazypropSumLazy operator+(const LazyIter<LazypropSumLazy>& i) const { return LazypropSumLazy(v+i.val.v); }
};
i64 operator+(ci64 a, const LazyIter<LazypropSumLazy>& b) { return a + (b.end - b.start + 1) * b.val.v; }

/// requirements: operator+(TreeType, TreeType), operator+(LazyType, TreeType), operator+(TreeType, LazyIter), operator+(LazyType, LazyIter)
/// <br> usage: node merge, node update, lazy update, lazy update
template <typename TreeType = i64, typename LazyType = LazypropSumLazy>
class Lazyprop {
typedef LazyIter<LazyType> iter;
protected:
    v<TreeType> tree; v<LazyType> lazy; i32 n=-1;
    void push(i32 node, i32 start, i32 end) {
        tree[node] = tree[node] + iter(node, start, end, lazy[node]);
        if(start!=end) {
            lazy[node*2] = lazy[node*2] + iter(node, start, end, lazy[node]);
            lazy[node*2+1] = lazy[node*2+1] + iter(node, start, end, lazy[node]);
        }
        lazy[node] = LazyType();
    }
public:
    explicit Lazyprop(i32 treeSize) {
        tree = v<TreeType>(4*treeSize, TreeType());
        lazy = v<LazyType>(4*treeSize, LazyType());
        n = treeSize;
    }
    explicit Lazyprop(const v<TreeType> &a) : Lazyprop((i32) a.size()) { init(a, 1, 1, n); }
    void update(i32 left, i32 right, TreeType diff) { update(1, left, right, 1, n, diff); }
    TreeType query(i32 left, i32 right) { return query(1, left, right, 1, n); }
protected:
    TreeType init(const v<TreeType> &a, i32 node, i32 start, i32 end) {
        if(start==end) return tree[node] = a[start-1];
        else return tree[node] = init(a, node*2, start, (start+end)/2) + init(a, node*2+1, (start+end)/2+1, end);
    }
    TreeType update(i32 node, i32 left, i32 right, i32 start, i32 end, TreeType diff) {
        push(node, start, end);
        if(end < left || right < start) return tree[node];
        if(left <= start && end <= right) {
            lazy[node] = lazy[node] + diff;
            push(node, start, end);
            return tree[node];
        }
        return tree[node] = update(node*2, left, right, start, (start+end)/2, diff) +
                            update(node*2+1, left, right, (start+end)/2+1, end, diff);
    }
    TreeType query(i32 node, i32 left, i32 right, i32 start, i32 end) {
        push(node, start, end);
        if(right < start || end < left) return TreeType();
        if(left <= start && end <= right) return tree[node];
        return query(node*2, left, right, start, (start+end)/2) + query(node*2+1, left, right, (start+end)/2+1, end);
    }
};

#pragma clang diagnostic pop
//@formatter:on
#pragma endregion

struct tr {
    i64 val = inf;
    tr operator+(const tr& b) const { return tr(min(val, b.val)); }
};

struct lz {
    i64 val = 0;
    lz operator+(const tr& b) const { return lz(val+b.val); }
    lz operator+(const LazyIter<lz>& b) const { return lz(val+b.val.val); }
};

tr operator+(const tr& a, const LazyIter<lz>& b) { return tr(a.val+b.val.val); }

i32 main() {
    fastio;
    str s = inStr();
    i64 n = Size(s);
    v<tr> r; for(char c : s) r.eb(c=='('?1:-1);
    v<tr> r2 = r;
    forf(i, 1, n-1) r2[i].val += r2[i-1].val;
    Lazyprop<tr, lz> lp(r2);
    i64 ans = 0, bracketSum = 0;
    for(const tr& t : r) bracketSum += t.val;
    inRep() {
        invar(t);
        bool wasOpenBracket = r[t-1].val == 1;
        if(wasOpenBracket) lp.update(t, n, tr(-2)), r[t-1].val = -1, bracketSum -= 2;
        else lp.update(t, n, tr(2)), r[t-1].val = 1, bracketSum += 2;
        ans += lp.query(1, n).val == 0 && bracketSum == 0;
    }
    println(ans);
}
