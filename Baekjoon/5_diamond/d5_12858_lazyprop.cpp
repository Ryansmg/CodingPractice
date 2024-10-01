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

class iterSeg {
public:
    v<int> tree; int n=-1;
    iterSeg() = default;
    explicit iterSeg(const v<int> &arr) { n = (int) arr.size(); init(arr); }
    explicit iterSeg(cint i) { tree = v<int>(i*2+10, 0); n = i; }
    void inputInit() { tree = v<int>(2*n+10, 0); forf(i, n, 2*n-1) cin >> tree[i]; init(); }
    /// 0 <= tar < n
    void update(int tar, int val) {
        if(tar == -1 || tar == n) return;
        assert(0 <= tar && tar < n);
        tree[n+tar] += val;
        for(int i = n+tar; i>1; i>>=1) tree[i>>1] = gcd(abs(tree[i]), abs(tree[i^1]));
    }
    /// [l, r]
    int query(int left, int right) {
        assert(0 <= left && right < n);
        right++;
        int l = n+left, r = n+right, ans = abs(tree[l]);
        for(; l<r; l>>=1, r>>=1) {
            if(l&1) ans = gcd(ans, abs(tree[l++]));
            if(r&1) ans = gcd(ans, abs(tree[--r]));
        }
        return ans;
    }
private:
    void init() { for(int i=n-1; i>0; i--) tree[i] = gcd(abs(tree[i<<1]), abs(tree[i<<1|1])); }
    void init(const v<int> &arr) {
        tree = v<int>(2*n+10, 0);
        for(int i=n, j=0; i<2*n; i++, j++) tree[i] = arr[j];
        init();
    }
};

class lazyprop {
protected:
    v<int> tree, lazy; int n=-1;
    void push(int node, int start, int end) {
        tree[node] += lazy[node] * (end-start+1);
        if(start!=end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
public:
    lazyprop()=default;
    explicit lazyprop(int treeSize, bool inputInit = false) {
        lazy = tree = v<int>(4*treeSize, 0); n = treeSize;
        if(inputInit) { v<int> a; forn(i, n) a.push_back(input()); init(a, 1, 1, n); }
    }
    explicit lazyprop(const v<int> &a) : lazyprop((int) a.size()) { init(a, 1, 1, n); }
    lazyprop(const v<int> &a, int treeSize) : lazyprop(treeSize) { init(a, 1, 1, n); assert(a.size() == treeSize); }
    void update(int left, int right, int diff) { update(1, left, right, 1, n, diff); }
    int query(int left, int right) { return query(1, left, right, 1, n); }
protected:
    int init(const v<int> &a, int node, int start, int end) {
        if(start==end) return tree[node] = a[start-1];
        else return tree[node] = init(a, node*2, start, (start+end)/2) + init(a, node*2+1, (start+end)/2+1, end);
    }
    int update(int node, int left, int right, int start, int end, int diff) {
        push(node, start, end);
        if(end < left || right < start) return 0;
        if(left <= start && end <= right) {
            lazy[node] += diff;
            push(node, start, end);
            return tree[node];
        }
        return tree[node] = update(node*2, left, right, start, (start+end)/2, diff) +
                            update(node*2+1, left, right, (start+end)/2+1, end, diff);
    }
    int query(int node, int left, int right, int start, int end) {
        push(node, start, end);
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return tree[node];
        return query(node*2, left, right, start, (start+end)/2) + query(node*2+1, left, right, (start+end)/2+1, end);
    }
};

i32 main() {
    fastio;
    invar(n);
    vl o = inArr(n);
    vl diffArr; forn(i, n-1) diffArr.eb(o[i] - o[i+1]);
    iterSeg seg(diffArr);
    lazyprop lp(o);
    inRep() {
        invar(t, a, b);
        a--, b--;
        if(t) {
            seg.update(a-1, -t);
            seg.update(b, t);
            lp.update(a+1, b+1, t);
        } else {
            if(a == b) println(lp.query(a+1, a+1));
            else println(gcd(lp.query(a+1, a+1), seg.query(a, b-1)));
        }
    }
}
