#pragma region macros
//@formatter:off
#define GCC_OPTIMIZE_ENABLE false
#define DISABLE_KOISTUDY_ERROR false

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#include <bits/stdc++.h>

// keyword reassign ///////////////////////////////////////////////////////////////
#if DISABLE_KOISTUDY_ERROR
using namespace std;
#else
using std::cin, std::cout, std::endl, std::istream, std::ostream;
using std::array, std::vector, std::stack, std::queue, std::deque, std::list, std::pair, std::tuple;
using std::set, std::multiset, std::map, std::initializer_list, std::bitset;
using std::max, std::min, std::gcd, std::lcm, std::pow, std::swap;
using std::less, std::greater, std::all_of, std::hash;
using std::stoi, std::stol, std::stoll, std::stoul, std::stoull, std::stof, std::stod, std::stold;
using std::sort, std::shuffle, std::uniform_int_distribution, std::mt19937, std::random_device;
using std::iota, std::prev, std::next, std::prev_permutation, std::next_permutation;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename Type, typename Cmp = less<>>
using pbds = __gnu_pbds::tree<Type, __gnu_pbds::null_type, Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
#endif

using i16 = short; using i32 = signed; using i64 = long long; using i128 = __int128;
using u16 = unsigned short; using u32 = unsigned; using u64 = unsigned long long; using u128 = unsigned __int128;
using f32 = float; using f64 = double; using f128 = long double; using F128 = __float128;
using str = std::string;
template <typename T, typename T2> using umap = std::unordered_map<T, T2>;
template <typename T> using uset = std::unordered_set<T>;
template <typename T> using v = std::vector<T>; template <typename T> using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>; using vi = v<i32>; using vb = v<bool>;
using ii = array<i64, 2>; using iii = array<i64, 3>;
template <typename T> using lim = std::numeric_limits<T>;
template <typename Signature> using fun = std::function<Signature>;
#define int i64
#define uint u64
#define ci64 const i64 &
#define cint ci64
#define ci32 const i32 &

// consts ///////////////////////////////////////////////////////////////
constexpr i64 i64max = 9223372036854775807,
    llmax  = i64max,
    INF    = 1000000000000000000,
    inf    = 3000000000;

// basic cpp macros ///////////////////////////////////////////////////////////////
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define forr(name, start, end) for(i64 name = start; name >= end; name--)
#define rep(n) forn(bit_Ly_S_, n)
#define rep2(n) forn(la_sh_Discord_, n)

i64 iR_v_, iR_v2_;
#define inRep() input(iR_v_); forn(iR_v3_, iR_v_)
#define inRep2() input(iR_v2_); forn(iR_v4_, iR_v2_)

// STL macros ///////////////////////////////////////////////////////////////
#if !DISABLE_KOISTUDY_ERROR
template <typename T=i64, typename T3=less<>> using pq = std::priority_queue<T, v<T>, T3>;
template <typename T, typename T3> T pop(pq<T, T3> &pq) { T t = pq.top(); pq.pop(); return t; }
#endif

#define all(vec) (vec).begin(), (vec).end()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
template <typename T> auto lb(const v<T> &r_, T i_) { return lower_bound(all(r_), i_); }
template <typename T> auto ub(const v<T> &r_, T i_) { return upper_bound(all(r_), i_); }
template <typename T> i64 sz(const T &t_) { return static_cast<i64>(t_.size()); }

template <typename T> T pop(stack<T> &st) { T t = st.top(); st.pop(); return t; }
template <typename T> T pop(queue<T> &q) { T t = q.front(); q.pop(); return q; }
template <typename T> void reverse(T &v) { reverse(all(v)); }
template <typename T> void sort(T &v) { sort(all(v)); }
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T reversed_copy(T arr) { reverse(all(arr)); return arr; }
template <typename T> T sorted_copy(T arr) { sort(all(arr)); return arr; }
template <typename T> T compressed_copy(T arr, const bool &autosort=true) { compress(arr, autosort); return arr; }
template <typename T> T idx(const T &val, const T &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }

template <typename Tp> Tp gcd(initializer_list<Tp> l_) {
    auto iter = l_.begin(); Tp ret = *iter; i64 sz_ = l_.size();
    forf(i_, 1, sz_-1) ret = gcd(ret, *(++iter)); return ret;
}
template <typename T> T lcm(initializer_list<T> l_) {
    auto iter = l_.begin(); T ret = *iter / gcd(l_); i64 sz_ = l_.size();
    forf(i_, 1, sz_-1) ret *= *(++iter); return ret;
}
template <typename T> T max(const v<T> v_) {
    T ret = lim<T>::min(); for(const T &t_ : v_) ret = max(ret, t_);
    return ret;
}
template <typename T> T min(const v<T> v_) {
    T ret = lim<T>::max(); for(const T &t_ : v_) ret = min(ret, t_);
    return ret;
}

template <typename T> T lcm_(T a, T b) { return a / gcd_(a, b) * b; }
template <typename T> T sq_(const T &i) { return i * i; }

// I/O macros ///////////////////////////////////////////////////////////////
#ifdef LOCAL
#define lfastio print()
#else
#define lfastio fastio
#endif
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
template <typename T = i64> T input() {T t; cin >> t; return t;}
template <typename T = i64> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz) a.eb(input<T>()); return a; }
template <typename T> void inputArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.eb(input<T>()); }
template <typename T> void inArr(v<T> &arr, i64 sz, bool clear = true) { inputArr(arr, sz, clear); }
template <typename T = i64> v<T> inArr(i64 sz) { v<T> a; forn(i,sz) a.eb(input<T>()); return a; }
template <typename T = i64> v<T> inArr() { return inArr(input()); }
str readline() { char c = '\n'; while(c == '\n') cin.get(c); str s; getline(cin, s); s = c + s; return s; }
template <typename T>
void printArr(const v<T> &v, const str &sep = " ", const str &end = "\n") {
    if(v.empty()) return;
    i64 paSz_ = v.size(); forn(i, paSz_-1) cout << v[i] << sep; cout << v[paSz_-1] << end;
}
void fixPrecision(i32 a_) { cout << std::fixed; cout.precision(a_); }

#if !DISABLE_KOISTUDY_ERROR
template <typename ...T> void print(const T&... a_) { (cout << ... << a_); }
void print() {}
template <typename ...T> void println(const T&... a_) { (cout << ... << a_); cout << '\n'; }
void println() { cout << '\n'; }
template <typename ...T> void printExit(const T&... a_) { (cout << ... << a_); cout << '\n'; exit(0); }
template <typename ...T> void input(T&... a_) { (cin >> ... >> a_); }
#endif
#define invar(...) i64 __VA_ARGS__; input(__VA_ARGS__)

// conversions ///////////////////////////////////////////////////////////////
template <typename T> str tostr(const T &t) { return std::to_string(t); }
template <typename T> i128 toi128(const T &t) { return static_cast<i128>(t); }
i128 toi128(const str &t) { return static_cast<i128>(stoull(t)); }
template <typename T> i64 toi64(const T &t) { return static_cast<i64>(t); }
i64 toi64(const str &t) { return stoll(t); }
template <typename T> i32 toi32(const T &t) { return static_cast<i32>(t); }
i32 toi32(const str &t) { return stoi(t); }
template <typename T> u64 tou64(const T &t) { return static_cast<u64>(t); }
u64 tou64(const str &t) { return stoull(t); }
template <typename T> f64 tof64(const T &t) { return static_cast<f64>(t); }
f64 tof64(const str &t) { return stod(t); }
template <typename T> f128 tof128(const T &t) { return static_cast<f128>(t); }
f128 tof128(const str &t) { return stold(t); }

//@formatter:on
#pragma endregion

i64 n, m, C, cur = 0;
i64 mod = 1000000007;
vl in, out, colors, colraw;
v2l con, child;

void makeTree(i64 node = 1, i64 par = 0) {
    for(ci64 i : con[node]) {
        if(i == par) continue;
        child[node].eb(i);
        makeTree(i, node);
    }
}

void makeEtt(i64 node = 1) {
    in[node] = ++cur;
    for(ci64 i : child[node]) makeEtt(i);
    out[node] = cur;
}

v2l tree;

void makeMST(i64 l = 1, i64 r = n, i64 node = 1) {
    if(l == r) {
        tree[node].eb(colors[l]);
        return;
    }
    i64 mm = (l + r) >> 1;
    makeMST(l, mm, node*2); makeMST(mm+1, r, node*2+1);
    tree[node].resize(tree[node*2].size() + tree[node*2+1].size());
    std::merge(all(tree[node*2]), all(tree[node*2+1]), tree[node].begin());
}

i64 query(i64 l, i64 r, i64 c, i64 s = 1, i64 e = n, i64 node = 1) {
    if(e < l || r < s) return 0;
    if(l <= s && e <= r) return ub(tree[node], c) - tree[node].begin();
    i64 mm = (s + e) >> 1;
    return query(l, r, c, s, mm, node*2) + query(l, r, c, mm+1, e, node*2+1);
}

i32 main() {
    fastio;
    input(n, m, C);
    i64 a, b;
    in = out = colors = vl(n+1);
    con = child = v2l(n+1, vl());
    tree = v2l(4*n, vl());
    colraw.pb(-1); rep(n) colraw.eb(input());
    rep(n-1) {
        input(a, b);
        con[a].eb(b); con[b].eb(a);
    }
    makeTree(); makeEtt();
    forf(i, 1, n) colors[in[i]] = colraw[i];
    makeMST();
    i64 ans = 0;
    rep(m) {
        invar(V, c);
        ans += query(in[V], out[V], c);
        ans %= mod;
    }
    println(ans);
}
