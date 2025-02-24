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
using std::sort, std::stable_sort, std::shuffle, std::uniform_int_distribution, std::mt19937, std::random_device;
using std::iota, std::prev, std::next, std::prev_permutation, std::next_permutation;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename Type, typename Cmp = less<>>
using pbds = __gnu_pbds::tree<Type, __gnu_pbds::null_type, Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
#endif

using i16 = short; using i32 = signed; using i64 = long long; using i128 = __int128;
using u16 = unsigned short; using u32 = unsigned; using u64 = unsigned long long; using u128 = unsigned __int128;
using f32 = float; using f64 = double; using f128 = long double;
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
#define cast static_cast

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
template <typename T> i64 Size(const T &t_) { return static_cast<i64>(t_.size()); }

template <typename T> T pop(stack<T> &st) { T t = st.top(); st.pop(); return t; }
template <typename T> T pop(queue<T> &q) { T t = q.front(); q.pop(); return q; }
template <typename T> void reverse(T &v) { reverse(all(v)); }
template <typename T> void sort(T &v) { sort(all(v)); }
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T reversed_copy(T arr) { reverse(all(arr)); return arr; }
template <typename T> T sorted_copy(T arr) { sort(all(arr)); return arr; }
template <typename T> T compressed_copy(T arr, const bool &autosort=true) { compress(arr, autosort); return arr; }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
i64 pow_(i64 a, i64 b, i64 mod=lim<i64>::max()) { a%=mod;i64 ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
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
#ifdef LOCAL
#define fileio filein; fileout
#define filein freopen(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\input.txt)", "r", stdin)
#define fileout freopen(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "w", stdout)
#else
#define fileio print()
#define filein print()
#define fileout print()
#endif
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

using lz = array<char, 10>;
using tr = array<i32, 10>;
constexpr i32 mod = 998244353;
tr tree[4000000]; lz lazy[4000000]; tr lazy2[4000000];
i32 L;

i32 inline mul(ci32 a, ci32 b) { return cast<i32>(a * (i64) b % mod); }

tr mergeTr(const tr &l, const tr &r, i32 s, i32 e) {
    i32 rightRangeLen = e - ((s + e) / 2 + 1) + 1;
    i64 leftOffset = pow_(10LL, rightRangeLen, mod);
    tr ret;
    forn(i, 10) ret[i] = cast<i32>((l[i] * leftOffset % mod + r[i]) % mod);
    return ret;
}

void push(i32 ptr, i32 start, i32 end) {
    tr res = tree[ptr];
    forn(i, 10) {
        if(lazy[ptr][i] == i) continue; // 변경 없음
        // i를 lazy[ptr][i]로 변경
        res[lazy[ptr][i]] += tree[ptr][i];
        res[i] = (res[i] + mod - tree[ptr][i]) % mod;
        res[lazy[ptr][i]] %= mod;
        forf(nxtp, ptr*2, ptr*2+1) {
            if(start == end) break;
            forn(j, 10) if(lazy[nxtp][j] == i && lazy2[nxtp][j] < lazy2[ptr][i]) {
                lazy[nxtp][j] = lazy[ptr][i];
                lazy2[nxtp][j] = lazy2[ptr][i];
            }
        }
        lazy[ptr][i] = i;
        lazy2[ptr][i] = -1;
    }
    tree[ptr] = res;
}

void update(i32 l, i32 r, i32 from, i32 to, i32 qidx, i32 node = 1, i32 start = 1, i32 end = L) {
    push(node, start, end);
    if(r < start || end < l) return;
    if(l <= start && end <= r) {
        lazy[node][from] = to;
        lazy2[node][from] = qidx;
        push(node, start, end);
        return;
    }
    
    update(l, r, from, to, qidx, node*2, start, (start+end)/2);
    update(l, r, from, to, qidx, node*2+1, (start+end)/2+1, end);
    
    tree[node] = mergeTr(tree[node*2], tree[node*2+1], start, end);
}

i32 query(i32 l, i32 r, i32 node = 1, i32 start = 1, i32 end = L) {
    push(node, start, end);
    if(r < start || end < l) return 0;
    if(l <= start && end <= r) {
        i32 raw = 0;
        forn(i, 10) raw += mul(tree[node][i], i), raw %= mod;
        i64 offset = pow_(10LL, r - end, mod);
        return cast<i32>(raw * offset % mod);
    }
    return (query(l, r, node*2, start, (start+end)/2) + query(l, r, node*2+1, (start+end)/2+1, end)) % mod;
}

str s;

void init(i32 node = 1, i32 start = 1, i32 end = L) {
    if(start == end) {
        tree[node][s[start-1]-'0'] = 1;
        return;
    }
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    tree[node] = mergeTr(tree[node*2], tree[node*2+1], start, end);
}

i32 main() {
//    fileio;
    fastio;
    i64 q; input(s, q);
    L = Size(s);
    for(tr &t : tree) t = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    for(tr &t : lazy2) t = { -1, -1, -1, -1, -1, -1, -1, -1 };
    for(lz &l : lazy) l = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    init();
    forn(qi, q) {
        invar(qtype);
        if(qtype == 1) {
            invar(i, j, from, to);
            update(i, j, from, to, qi);
        } else {
            invar(i, j);
            println(query(i, j));
        }
    }
}
