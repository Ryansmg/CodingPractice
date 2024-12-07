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
#if DISABLE_KOISTUDY_ERROR
using namespace std;
#else
using std::cin, std::cout, std::cerr, std::clog, std::endl, std::istream, std::ostream, std::ifstream, std::ofstream, std::setw, std::setfill;
using std::array, std::vector, std::stack, std::queue, std::deque, std::list, std::pair, std::tuple;
using std::set, std::multiset, std::map, std::initializer_list, std::bitset;
using std::max, std::min, std::gcd, std::lcm, std::pow, std::swap, std::abs, std::sin, std::cos, std::tan, std::asin, std::acos, std::atan;
using std::sinh, std::cosh, std::tanh, std::atan2;
using std::less, std::greater, std::less_equal, std::greater_equal, std::all_of, std::any_of, std::hash;
using std::stoi, std::stol, std::stoll, std::stoul, std::stoull, std::stof, std::stod, std::stold;
using std::sort, std::stable_sort, std::shuffle, std::uniform_int_distribution, std::mt19937, std::random_device;
using std::iota, std::prev, std::next, std::prev_permutation, std::next_permutation;
using std::complex, std::polar, std::is_integral_v;

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

// data structures ///////////////////////////////////////////////////////////////

constexpr i64 add_i64_(ci64 a, ci64 b) { return a + b; }

template <typename Type = i64>
class Segtree {
    vector<Type> tree; i32 n;
    Type identityElement; fun<Type(const Type&, const Type&)> merge;
public:
    class iterator {
        friend Segtree; Segtree* treePtr;
        iterator(Segtree* a, i32 b, i32 c, i32 d) : treePtr(a), node(b), start(c), end(d) {}
    public:
        i32 node, start, end;
        inline Type& operator*() const { return treePtr->tree[node]; }
        inline bool leaf() const { return start == end; }
        inline iterator left() const { lassert(!leaf()); return iterator(treePtr, node<<1, start, (start+end)>>1); }
        inline iterator right() const { lassert(!leaf()); return iterator(treePtr, (node<<1)|1, ((start+end)>>1)+1, end); }
        inline bool isNul() const { return node == 0; }
    };
    iterator begin() { return iterator(this, 1, 1, n); }
    explicit Segtree(ci32 treeSize, const Type& IdentityElement = 0,
                     const fun<Type(const Type&, const Type&)>& mergeFunc = add_i64_) {
        tree = v<Type>(4*treeSize, identityElement); n = treeSize;
        identityElement = IdentityElement; merge = mergeFunc;
    }
    explicit Segtree(const v<Type> &a, const Type& IdentityElement = 0,
                     const fun<Type(const Type&, const Type&)>& mergeFunc = add_i64_)
        : Segtree(Size(a), IdentityElement, mergeFunc) { init(a, begin()); }
    void update(ci32 tar, const Type& diff) { lassert(1 <= tar && tar <= n); update(begin(), tar, diff); }
    void set(ci32 tar, const Type& val) { lassert(1 <= tar && tar <= n); set(begin(), tar, val); }
    Type query(ci32 left, ci32 right) { lassert(1 <= left && left <= n && 1 <= right && right <= n);
        if(left > right) { return identityElement; } return query(begin(), left, right); }
    iterator operator[](ci32 tar) { return queryIter(begin(), tar); }
    const iterator nul = iterator(this, 0, 0, 0);
    void foreach(const fun<void(const iterator&)> f) { foreach(begin(), f); }
private:
    Type init(const v<Type> &a, const iterator& iter) {
        if(iter.leaf()) return *iter = a[iter.start-1];
        else return *iter = merge(init(a, iter.left()), init(a, iter.right()));
    }
    const Type& update(const iterator& iter, ci32 tar, const Type& diff) {
        if(iter.end < tar || tar < iter.start) return *iter;
        if(iter.leaf()) return *iter = merge(*iter, diff);
        return *iter = merge(update(iter.left(), tar, diff), update(iter.right(), tar, diff));
    }
    Type set(const iterator& iter, ci32 tar, Type val) {
        if(iter.end < tar || tar < iter.start) return *iter;
        if(iter.leaf()) return *iter = val;
        return *iter = merge(set(iter.left(), tar, val), set(iter.right(), tar, val));
    }
    iterator queryIter(const iterator& iter, ci32 tar) {
        if(iter.end < tar || tar < iter.start) return nul;
        if(iter.leaf()) return iter;
        iterator ret = queryIter(iter.left(), tar);
        if(ret.isNul()) return queryIter(iter.right(), tar);
        return ret;
    }
    Type query(const iterator& iter, ci32 left, ci32 right) const {
        if(right < iter.start || iter.end < left) return identityElement;
        if(left <= iter.start && iter.end <= right) return *iter;
        return merge(query(iter.left(), left, right), query(iter.right(), left, right));
    }
    void foreach(const iterator& iter, const fun<void(const iterator&)> f) {
        if(iter.leaf()) f(iter);
        else foreach(iter.left(), f), foreach(iter.right(), f);
    }
};

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

// useful structs
struct edge { i64 s, e, v; };

#pragma clang diagnostic pop
//@formatter:on
#pragma endregion

i32 main() {
    fastio;

}
