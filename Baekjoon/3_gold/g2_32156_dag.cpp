#pragma region macros
//@formatter:off
#define GCC_OFAST_ENABLE false
#define DISABLE_KOISTUDY_ERROR false

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma ide diagnostic ignored "OCUnusedTypeAliasInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "UnreachableCallsOfFunction"

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
using std::max, std::min, std::gcd, std::lcm, std::pow, std::swap, std::abs;
using std::less, std::greater, std::less_equal, std::greater_equal, std::all_of, std::any_of, std::hash;
using std::stoi, std::stol, std::stoll, std::stoul, std::stoull, std::stof, std::stod, std::stold;
using std::sort, std::stable_sort, std::shuffle, std::uniform_int_distribution, std::mt19937, std::random_device;
using std::iota, std::prev, std::next, std::prev_permutation, std::next_permutation;

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
using f32 = float; using f64 = double; using f128 = long double; using F128 = __float128;
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

i64 iR_v_, iR_v2_;
#define inRep() input(iR_v_); forn(iR_v3_, iR_v_)
#define inRep2() input(iR_v2_); forn(iR_v4_, iR_v2_)

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
Tpl inline i64 Size(const T &t_) { return static_cast<i64>(t_.size()); }

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

Tpl inline T gcd(initializer_list<T> l_) {
    auto iter = l_.begin(); T ret = *iter; i64 sz_ = l_.size();
    forf(i_, 1, sz_-1) ret = std::gcd(ret, *(++iter));
    return ret;
}
Tpl inline T lcm(initializer_list<T> l_) {
    auto iter = l_.begin(); T ret = *iter / gcd(l_); i64 sz_ = l_.size();
    forf(i_, 1, sz_-1) ret *= *(++iter);
    return ret;
}
Tpl inline T max(const v<T> v_) {
    T ret = lim<T>::min(); for(const T &t_ : v_) ret = max(ret, t_);
    return ret;
}
Tpl inline T min(const v<T> v_) {
    T ret = lim<T>::max(); for(const T &t_ : v_) ret = min(ret, t_);
    return ret;
}

Tpl inline T lcm_(T a, T b) { return a / gcd_(a, b) * b; }
Tpl inline T sq_(const T &i) { return i * i; }

random_device macro_random_device_;
mt19937 mt19937_gen_(macro_random_device_());
uniform_int_distribution<i32> uni_i_dis_i32_(0, lim<i32>::max());
uniform_int_distribution<i64> uni_i_dis_i64_(0, lim<i64>::max());
#define rand() randi()
inline i32 randi() { return uni_i_dis_i32_(mt19937_gen_); }
inline i64 randl() { return uni_i_dis_i64_(mt19937_gen_); }
inline i64 randInt(ci64 l_, ci64 r_) { return randl() % (r_ - l_ + 1) + l_; } // inclusive

// I/O macros ///////////////////////////////////////////////////////////////
#ifdef LOCAL
#define lfastio print()
#else
#define lfastio fastio
#endif
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#ifdef LOCAL
#define fileio filein; fileout
#define filein freopen(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\input.txt)", "r", stdin)
#define fileout freopen(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "w", stdout)
#define inputout freopen(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\input.txt)", "w", stdout)
#define outputin freopen(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "r", stdin)
#define ansout freopen(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\ans.txt)", "w", stdout)
#else
#define fileio print()
#define filein print()
#define fileout print()
#define ansout print()
#define inputout print()
#define outputin print()
#endif // LOCAL
template <typename T = i64> inline T input() {T t; cin >> t; return t;}
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

struct Printf_ {
    str sep = " ", end;
    i32 precision = -1;
    i32 width = -1; char fill = ' ';
    void operator()() {}
    template <typename ...T> void operator()(const T&... _) { prf_imp_(_...); }
private:
    inline void prf_imp_preset_() const {
        if(precision != -1) cout << std::fixed, cout.precision(precision);
        if(width != -1) cout << std::setw(width) << std::setfill(fill);
    }
    Tpl void prf_imp_(const T& _) const { prf_imp_preset_(); cout << _ << end; }
    template <typename T1, typename ...T2> void prf_imp_(const T1& _, const T2&... b_) const {
        prf_imp_preset_(); cout << _ << sep; prf_imp_(b_...);
    }
};
#define printf(...) Printf_({__VA_ARGS__})

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

#pragma clang diagnostic pop
//@formatter:on
#pragma endregion

struct edge {
    i64 s, e, x;
    bool operator<(const edge& b) const {
        return x > b.x;
    }
};

i32 main() {
    fastio;
    invar(n, m, r);
    v2<edge> child(n+1, v<edge>());
    v2<edge> par = child;
    vl cnt(n+1, 0);
    rep(m) {
        invar(u, v, c);
        child[u].eb(u, v, c);
        cnt[u]++;
        par[v].eb(u, v, c);
    }
    i64 found = 0, ans = 0;
    vb vis(n+1, false);
    queue<edge> q;
    q.emplace(-1, r, 0);
    while(!q.empty()) {
        edge e = pop(q);
        if(vis[e.e]) continue;
        vis[e.e] = true;
        found++;
        for(auto &e2 : child[e.e]) {
            if(vis[e2.e]) continue;
            q.emplace(e2);
        }
    }
    if(found != n) printExit(-1);
    queue<i64> q2;
    forf(i, 1, n) vis[i] = false;
    found = 0;
    while(found != n) {
        forf(i, 1, n) if(cnt[i] == 0) q2.emplace(i);
        while(!q2.empty()) {
            i64 x = i64max, nxt = -1;
            i64 cur = pop(q2);
            if(vis[cur]) continue;
            vis[cur] = true;
            found++;
            if(cur == r) continue;
            for(auto &[s, _, k]: par[cur]) {
                if(k < x) nxt = s, x = k;
            }
            for(auto &[s, _, k]: par[cur]) {
                if(s != nxt) cnt[s]--;
            }
            q2.emplace(nxt);
            ans += x;
        }
    }
    println(ans);
}
