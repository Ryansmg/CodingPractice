#pragma region macros
//@formatter:off
#define ENABLE_MACRO true
#define ENABLE_OFAST false
#define CPP11_MODE false
#define CPP17_MODE false
#define IGNORE_UNUSED_MACRO_WARNING true

#include <bits/stdc++.h>

#if !ENABLE_MACRO // basic macros
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define i32 signed
using namespace std;
#endif

#pragma clang diagnostic push
#if IGNORE_UNUSED_MACRO_WARNING
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma ide diagnostic ignored "OCUnusedTypeAliasInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "UnreachableCallsOfFunction"
#endif

#if ENABLE_MACRO

#if ENABLE_OFAST
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

// keyword reassign ///////////////////////////////////////////////////////////////
#define Tpl template <typename T>
#define elif else if
#if CPP11_MODE
using namespace std;
#else
using std::cin, std::cout, std::cerr, std::clog, std::endl, std::istream, std::ostream, std::ifstream, std::ofstream, std::setw, std::setfill;
using std::array, std::vector, std::stack, std::queue, std::deque, std::list, std::pair, std::tuple;
using std::set, std::multiset, std::map, std::initializer_list, std::bitset;
using std::max, std::min, std::gcd, std::lcm, std::pow, std::swap, std::abs, std::sin, std::cos, std::tan, std::asin, std::acos, std::atan;
using std::floor, std::ceil, std::round, std::sinh, std::cosh, std::tanh, std::atan2;
using std::less, std::greater, std::less_equal, std::greater_equal, std::all_of, std::any_of, std::hash;
using std::stoi, std::stol, std::stoll, std::stoul, std::stoull, std::stof, std::stod, std::stold;
using std::sort, std::stable_sort, std::shuffle, std::uniform_int_distribution, std::mt19937, std::random_device;
using std::iota, std::prev, std::next, std::prev_permutation, std::next_permutation;
using std::complex, std::polar, std::is_integral_v;
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
#define forn(name, val) for(i64 name = 0; (name) < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define forr(name, start, end) for(i64 name = start; name >= end; name--)
#define rep(n) forn(rep_mac_name_1_, n)
#define rep2(n) forn(rep_mac_name_2_, n)

i64 iR_v_, iR_v2_, iR_v5_;
#define inRep() input(iR_v_); forn(iR_v3_, iR_v_)
#define inRep2() input(iR_v2_); forn(iR_v4_, iR_v2_)
#define tcRep() input(iR_v5_); forf(TCN, 1, iR_v5_)

// STL macros ///////////////////////////////////////////////////////////////
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
#else
#define lb(arr, v) lower_bound(all((arr)), (v))
#define ub(arr, v) upper_bound(all((arr)), (v))
#endif //!CPP11_MODE
Tpl inline i64 Size(const T &_) { return static_cast<i64>(_.size()); }

Tpl inline T pop(stack<T> &st) { T t_ = st.top(); st.pop(); return t_; }
Tpl inline T pop(queue<T> &q) { T t_ = q.front(); q.pop(); return t_; }
Tpl inline void reverse(T &_) { reverse(all(_)); }
Tpl inline void sort(T &_) { sort(all(_)); }
template <typename T, typename Cmp> inline void sort(T& arr, const Cmp& cmp) { sort(all(arr), cmp); }
Tpl inline void compress(v<T> &arr, const bool &autosort=true) { if(autosort) sort(all(arr)); arr.erase(unique(all(arr)), arr.end()); }
Tpl inline T reversed(T _) { reverse(all(_)); return _; }
Tpl inline T sorted(T _) { sort(all(_)); return _; }
template <typename T, typename Cmp> inline T sorted(T arr, const Cmp& cmp) { sort(all(arr), cmp); return arr; }
Tpl inline T compressed(T arr, const bool &autosort=true) { compress(arr, autosort); return arr; }
Tpl inline T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
Tpl inline T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
Tpl inline T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }

#if !CPP11_MODE
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
#endif // !CPP11_MODE

Tpl inline T max(const v<T>& v_) { T ret = lim<T>::min(); for(const T &t_ : v_) { ret = max(ret, t_); } return ret; }
Tpl inline T min(const v<T>& v_) { T ret = lim<T>::max(); for(const T &t_ : v_) { ret = min(ret, t_); } return ret; }

Tpl inline T lcm_(const T& a, const T& b) { return a / gcd_(a, b) * b; }
Tpl inline T sq_(const T &i) { return i * i; }
Tpl inline T sum(const v<T>& _) { T s_ = T(); {for(const T& i_ : _) s_ += i_;} return s_; }

random_device macro_random_device_;
mt19937 mt19937_gen_(macro_random_device_());
uniform_int_distribution<i32> uni_i_dis_i32_(0, lim<i32>::max());
uniform_int_distribution<i64> uni_i_dis_i64_(0, lim<i64>::max());
#define rand() randi()
inline i32 randi() { return uni_i_dis_i32_(mt19937_gen_); }
inline i64 randl() { return uni_i_dis_i64_(mt19937_gen_); }
inline i64 randInt(ci64 l_, ci64 r_) { return randl() % (r_ - l_ + 1) + l_; } // inclusive

template <typename T2, typename T1> v<T2> castVec(const T1& arr) { v<T2> ret; for(const auto& t : arr) { ret.emplace_back(t); } return ret; }

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
#define inputout print()
#define outputin print()
#define ansout print()
#endif // LOCAL
template <typename T = i64> inline T input() {T t; cin >> t; return t;}
inline str inStr() { str t; cin >> t; return t; }
template <typename T = i64> inline v<T> inArr(i64 sz) { v<T> a; forn(i,sz) a.eb(input<T>()); return a; }
template <typename T = i64> inline void inArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.eb(input<T>()); }
template <typename T = i64> inline v<T> inArr() { return inArr<T>(input()); }
inline str readline() { char c = '\n'; while(c == '\n') cin.get(c); str s; getline(cin, s); s = c + s; return s; }

#if CPP11_MODE
template <typename... T> inline void print(const T&... a_) { using expander = i32[]; (void)expander{0, (cout << a_, 0)...}; }
template <typename ...T> inline void println(const T&... a_) { print(a_...); cout << '\n'; }
template <typename... T> inline void input(T&... a_) { using expander = i32[]; (void)expander{0, (std::cin >> a_, 0)...}; }
#else
template <typename ...T> inline void print(const T&... a_) { (cout << ... << a_); }
inline void print() {}
template <typename ...T> inline void println(const T&... a_) { (cout << ... << a_); cout << '\n'; }
inline void println() { cout << '\n'; }

template <typename ...T> inline void input(T&... a_) { (cin >> ... >> a_); }
#define in64(...) i64 __VA_ARGS__; input(__VA_ARGS__)
#define invar in64

#if !CPP17_MODE
template <typename> struct isVecStruct_ : std::false_type {};
Tpl struct isVecStruct_<v<T>> : std::true_type {};
Tpl concept isVector = isVecStruct_<T>::value;

struct Printf {
    str sep = " ", end;
    i32 prec = -1;
    i32 width = -1; char fill = ' ';
    bool exit = false;
    void operator()() {}
    template <typename ...T> void operator()(const T&... _) { prf_imp_(_...); }
    Printf& appendEnd(const str& end_) { end += end_; return *this; }
    Printf& setExit() { exit = true; return *this; }
private:
    inline void prf_imp_preset_() const {
        if(prec != -1) cout << std::fixed, cout.precision(prec);
        if(width != -1) cout << std::setw(width) << std::setfill(fill);
    }
    Tpl void prf_imp_(const T& _) const { prf_imp_preset_(); cout << _ << end; if(exit) std::exit(0); }
    template <isVector T> void prf_imp_(const T& _) const {
        i64 len_ = Size(_);
        forn(i, len_-1) { prf_imp_preset_(); cout << _[i] << sep; }
        if(len_) prf_imp_preset_(), cout << _[len_-1] << end;
        if(exit) std::exit(0);
    }
    template <typename T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const {
        prf_imp_preset_(); cout << _ << sep; prf_imp_(b_...);
    }
    template <isVector T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const {
        for(const auto& v_ : _) { prf_imp_preset_(); cout << v_ << sep; } prf_imp_(b_...);
    }
};
#define printf(...) Printf({__VA_ARGS__})
#define printfln(...) printf(__VA_ARGS__).appendEnd("\n")
#define printExit(...) printf(__VA_ARGS__).setExit()
#endif // !CPP17_MODE

#endif // !CPP11_MODE

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
constexpr i32 dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};

#pragma endregion

#pragma region structs
#if !CPP17_MODE && !CPP11_MODE
i64 moQuerySortVal = -1;
struct moQuery {
    i64 i, j, order;
    bool operator<(const moQuery& b) const {
        lassert(moQuerySortVal != -1);
        if(i/moQuerySortVal == b.i/moQuerySortVal) return j < b.j;
        return i/moQuerySortVal < b.i/moQuerySortVal;
    }
};

#pragma region dataStructures

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
    T query(ci32 tar) { return query(tar, tar); }
    struct iter {
        i32 node, start, end; T value; Segtree<T>* segPtr;
        bool leaf() const { return start == end; }
        iter left() const { return iter(node*2, start, (start+end)/2, segPtr->tree[node*2], segPtr); }
        iter right() const { return iter(node*2+1, (start+end)/2+1, end, segPtr->tree[node*2+1], segPtr); }
    };
    iter root() { return iter(1, 1, n, tree[1], this); }
    /// [1..i] 범위 합이 val 이하인 최대의 i를 리턴
    iter binSearch(T val) requires hasOperatorMinus<T> {
        iter cur = root();
        while(!cur.leaf()) {
            iter l = cur.left();
            if(val <= l.value) cur = l;
            else val = val - l.value, cur = cur.right();
        }
        return cur;
    }
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

struct SumLazy;

/// requirements: (TreeType + TreeType), (LazyType + UpdateType), (TreeType + LazyIter&&), (LazyType + LazyIter&&)
/// <br> usage: node merge, node update, lazy update, lazy update
template <typename TreeType = i64, typename LazyType = SumLazy, typename UpdateType = i64>
class Lazyprop {
public:
    /// tree & lazy are copied values, should not be modified
    struct iter {
        i32 node, start, end; TreeType tree; LazyType lazy; Lazyprop* segPtr;
        iter left() {
            segPtr->push(node*2, start, (start+end)/2);
            return iter(node*2, start, (start+end)/2, segPtr->tree[node*2], segPtr->lazy[node*2], segPtr);
        }
        iter right() {
            segPtr->push(node*2+1, (start+end)/2+1, end);
            return iter(node*2+1, (start+end)/2+1, end, segPtr->tree[node*2+1], segPtr->lazy[node*2+1], segPtr);
        }
        bool leaf() { return start == end; }
    };
protected:
    v<TreeType> tree; v<LazyType> lazy; i32 n=-1;
    void push(i32 node, i32 start, i32 end) {
        tree[node] = tree[node] + iter(node, start, end, tree[node], lazy[node], this);
        if(start!=end) {
            lazy[node*2] = lazy[node*2] + iter(node, start, end, tree[node], lazy[node], this);
            lazy[node*2+1] = lazy[node*2+1] + iter(node, start, end, tree[node], lazy[node], this);
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
    void update(i32 left, i32 right, UpdateType diff) { update(1, left, right, 1, n, diff); }
    TreeType query(i32 left, i32 right) { return query(1, left, right, 1, n); }
    TreeType query(i32 tar) { return query(tar, tar); }
    iter root() { push(1, 1, n); return iter(1, 1, n, tree[1], lazy[1], this); }
protected:
    TreeType init(const v<TreeType> &a, i32 node, i32 start, i32 end) {
        if(start==end) return tree[node] = a[start-1];
        else return tree[node] = init(a, node*2, start, (start+end)/2) + init(a, node*2+1, (start+end)/2+1, end);
    }
    TreeType update(i32 node, i32 left, i32 right, i32 start, i32 end, UpdateType diff) {
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

struct SumLazy {
    i64 v = 0;
    SumLazy operator+(ci64 i) const { return SumLazy(v+i); }
    SumLazy operator+(const Lazyprop<i64, SumLazy, i64>::iter& i) const { return SumLazy(v+i.lazy.v); }
};
i64 operator+(ci64 a, const Lazyprop<i64, SumLazy, i64>::iter& b) { return a + (b.end - b.start + 1) * b.lazy.v; }

#pragma endregion

#pragma region Graph

struct SimpleEdge { i64 start, end; };

Tpl concept isEdge1_ = requires(const T& a) { { a.s }; { a.e }; };
Tpl concept isEdge2_ = requires(const T& a) { { a.start }; { a.end }; };
Tpl concept isEdge = isEdge1_<T> || isEdge2_<T>;

/// node >= 0
/// requirements : (EdgeType.s && EdgeType.e) || (EdgeType.start && EdgeType.end)
template <isEdge EdgeType = SimpleEdge>
class Graph {
private:
    static i64 es_(const EdgeType& edge) { if constexpr(isEdge1_<EdgeType>) { return edge.s; } return edge.start; }
    static i64 ee_(const EdgeType& edge) { if constexpr(isEdge1_<EdgeType>) { return edge.e; } return edge.end; }
public:
    i64 nodeCnt = 0; // (maxNodeNumber) + 1
    v2<EdgeType> child, parent, undir;
    bool unsafe = false; // increases performance when true
    Graph() = default;
    explicit Graph(ci64 maxNodeNum) { resize(maxNodeNum); }
    void resize(ci64 maxNodeNum) {
        nodeCnt = maxNodeNum + 1;
        child.resize(nodeCnt, v<EdgeType>());
        parent.resize(nodeCnt, v<EdgeType>());
        undir.resize(nodeCnt, v<EdgeType>());
    }
    void addUEdge(const EdgeType& edge) { undir[es_(edge)].eb(edge); undir[ee_(edge)].eb(ee_(edge), es_(edge)); }
    template <typename... Args> void addUEdge(Args&&... args) {
        EdgeType edge(std::forward<Args>(args)...);
        undir[es_(edge)].eb(edge); undir[ee_(edge)].eb(ee_(edge), es_(edge));
    }
    void addDEdge(const EdgeType& edge) { child[es_(edge)].eb(edge); parent[ee_(edge)].eb(edge); }
    template <typename... Args> void addDEdge(Args&&... args) {
        EdgeType edge(std::forward<Args>(args)...);
        child[es_(edge)].eb(edge); parent[ee_(edge)].eb(edge);
    }
    Graph& setUnsafe(bool _) { unsafe = _; return *this; }
};

template <typename EdgeType>
class Tree : public Graph<EdgeType> {
private:
    static i64 es_(const EdgeType& edge) { if constexpr(isEdge1_<EdgeType>) { return edge.s; } return edge.start; }
    static i64 ee_(const EdgeType& edge) { if constexpr(isEdge1_<EdgeType>) { return edge.e; } return edge.end; }
public:
    i64 root;
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
    /// euler tour technique (range: [1, n])
    pair<vl, vl> getInOut() {
        vl in(this->nodeCnt, -1), out = in;
        i64 cur = 0;
        fun<void(i64)> f = [&](i64 p) {
            in[p] = ++cur;
            for(const auto& e : this->child[p]) f(ee_(e));
            out[p] = cur;
        };
        f(root);
        return {in, out};
    }
};

#pragma endregion // Graph

#endif // !CPP17_MODE && !CPP11_MODE
#endif // ENABLE_MACRO
#pragma clang diagnostic pop
//@formatter:on
#pragma endregion //structs


i32 main() {
    fastio;
    in64(n, m);
    Graph g(n);
    i64 root = -1;
    forf(i, 1, n) {
        in64(p);
        if(p == -1) root = i;
        else g.addUEdge(p, i);
    }
    Tree t(root, g.setUnsafe(true));
    auto [in, out] = t.getInOut();
    Lazyprop lp(n);
    rep(m) {
        if(input() == 1) {
            in64(i, w);
            lp.update(in[i], out[i], w);
        } else println(lp.query(in[input()]));
    }
}
