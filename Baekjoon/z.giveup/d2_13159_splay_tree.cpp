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

class Splay {
public:
    using ptr = i32;
    #define cptr const ptr &
    static constexpr ptr null = 0;
    struct nd {
        ptr l = null, r = null, p = null;
        i64 sz = 0;
        i64 val = 0, sum = 0, mx = 0, mn = INF;
        bool flip = false, dummy = false;
        nd()=default;
        nd(ptr L, ptr R, ptr Parent, i64 Value) : l(L), r(R), p(Parent), val(Value), sum(Value), mx(Value), mn(Value), sz(1) {}
    };
private:
    v<nd> mem; ptr root = null; ptr avail = 1;
    static constexpr ptr trashPtr = 2015571557;
    stack<ptr> free; i32 size_ = 0;
    ptr New(cptr l, cptr r, cptr p, const i64 &val) {
        if(!free.empty()) {
            ptr t = pop(free);
            mem[t] = nd(l, r, p, val);
            return t;
        }
        mem.eb(l, r, p, val);
        assert(avail + 1 < trashPtr);
        return avail++;
    }
    void Delete(cptr tar) {
        free.push(tar);
        l(tar) = r(tar) = p(tar) = trashPtr;
        val(tar) = {};
    }
    ptr& l(cptr x) { return mem[x].l; }
    ptr& r(cptr x) { return mem[x].r; }
    ptr& p(cptr x) { return mem[x].p; }
    i64& sz(cptr x) { return mem[x].sz; }
    i64& val(cptr x) { return mem[x].val; }
    i64& sum(cptr x) { return mem[x].sum; }
    i64& mx(cptr x) { return mem[x].mx; }
    i64& mn(cptr x) { return mem[x].mn; }
    bool& flip(cptr x) { return mem[x].flip; }
    void update(cptr x) {
        sz(x) = 1 + sz(l(x)) + sz(r(x));
        sum(x) = val(x) + sum(l(x)) + sum(r(x));
        mn(x) = min({val(x), mn(l(x)), mn(r(x))});
        mx(x) = min({val(x), mx(l(x)), mx(r(x))});
    }
    void push(cptr x) {
        if(!flip(x)) return;
        swap(l(x), r(x));
        if(l(x)) flip(l(x)) = !flip(l(x));
        if(r(x)) flip(r(x)) = !flip(r(x));
        flip(x) = false;
    }
    void rotate(cptr x) {
        if(x == root) return;
        ptr P = p(x), G = p(P);
        push(P); push(x);
        if(l(p(x)) == x) {
            l(p(x)) = r(x);
            p(r(x)) = p(x);
            r(x) = p(x);
        } else {
            r(p(x)) = l(x);
            p(l(x)) = p(x);
            l(x) = p(x);
        }
        p(x) = G;
        p(P) = x;
        if(l(G) == P) l(G) = x;
        else if(G) r(G) = x;
        if(p(x) == null) root = x;
        update(P); update(x);
    }
    void splay(cptr x, cptr g = null) {
        while( p(x) != g ) {
            if(p(p(x)) == g) { rotate(x); break; }
            if( (x == l(p(x)) ) == ( p(x) == l(p(p(x))) ) ) rotate(p(x));
            else rotate(x);
            rotate(x);
        }
        if(!g) assert(root == x);
    }
public:
    Splay() {
        mem = v<nd>(1, {0, 0, 0, {}});
        mem[0].sz = 0;
        root = null;
    }
    explicit Splay(const vl &arr) : Splay() {
        i64 n_ = arr.size();
        root = New(null, null, null, arr[0]);
        ptr cur = root;
        v<ptr> t_(1, root);
        forf(i, 1, n_ - 1) {
            ptr nxt = New(null, null, cur, arr[i]);
            r(cur) = nxt; cur = nxt;
            t_.eb(cur);
        }
        l(root) = New(null, null, cur, 0);
        mem[l(root)].dummy = true;
        r(cur) = New(null, null, cur, 0);
        mem[r(cur)].dummy = true;
        assert(t_.size() == n_); size_ = n_;
        forr(i, n_-1, 0) update(t_[i]);
    }
    nd getMem(cptr i) { return mem[i]; }
    ptr rootPtr() const { return root; }
    void reserve(u64 sz) { mem.reserve(sz); }
    
    i32 size() const { return size_; }
    
    // [s, e], s >= 0
    ptr gather(i32 s, i32 e) {
        kth(e+1);
        ptr t = root;
        kth(s-1);
        splay(t, root);
        return l(r(root));
    }
    
    void flip(i32 s, i32 e) {
        ptr x = gather(s, e);
        flip(x) = !flip(x);
    }
    
    void shift(i32 s, i32 e, i32 k) {
        if(k >= 0) {
            k %= e - s + 1; if(!k) return;
            flip(s, e); flip(s, s+k-1); flip(s+k, e);
        } else {
            k *= -1; k %= e - s + 1; if(!k) return;
            flip(s, e); flip(s, e-k); flip(e-k+1, e);
        }
    }
    
    ptr operator[](i32 k) {
        splay(k+1);
        return root;
    }
    
    /// k >= 0
    void kth(i32 k) {
        ptr x = root;
        while(true) {
            while(l(x) && sz(l(x)) > k) x = l(x);
            k -= sz(l(x));
            if(!k--) break;
            x = r(x);
        }
        splay(x);
    }
    
    template <typename Callable>
    void forEach(const Callable &f, ptr tar = -1) {
        fun<void(ptr)> recF_ = [&](const ptr &i) {
            if(!i) return;
            push(i);
            if(l(i)) recF_(l(i));
            f(mem[i]);
            if(r(i)) recF_(r(i));
        };
        if(tar == -1) tar = root;
        recF_(tar);
    }
};

// 13159. 배열
// #splay_tree

i32 main() {
    lfastio;
    invar(n, q);
    vl init; forf(i, 1, n) init.eb(i);
    Splay splay(init);
    rep(q) {
        invar(op);
        if(op == 1) {
            invar(s, e);
            splay.flip(s-1, e-1);
            Splay::nd x = splay.getMem(splay.gather(s-1, e-1));
            println(x.mn, " ", x.mx, " ", x.sum);
        }
        else if(op == 2) {
            invar(s, e, k);
            Splay::nd x = splay.getMem(splay.gather(s-1, e-1));
            println(x.mn, " ", x.mx, " ", x.sum);
            splay.shift(s-1, e-1, k);
        }
        else if(op == 3) {
            splay.kth(input());
            println(splay.getMem(splay.rootPtr()).val);
        }
        else {
            i32 x = splay[input()-1];
            println(splay.getMem(splay.getMem(x).l).sz);
        }
    }
    splay.forEach([&](Splay::nd n) {
        print(n.val, " ");
    });
}

// std::set 구현
//void insert(const i64 &key) {
//    ptr newNd = New(0, 0, 0, key);
//    if(root == null) { root = newNd; size_++; return; }
//    ptr cur = root;
//    while(true) {
//        if(val(cur) == key) return; // 중복
//        if(key < val(cur)) {
//            if(l(cur) == null) {
//                l(cur) = newNd; p(newNd) = cur;
//                break;
//            }
//            cur = l(cur);
//        } else {
//            if(r(cur) == null) {
//                r(cur) = newNd; p(newNd) = cur;
//                break;
//            }
//            cur = r(cur);
//        }
//    }
//    size_++; splay(newNd);
//}
//bool find(const i64 &key) {
//    ptr cur = root;
//    if(root == null) return false;
//    while(cur) {
//        if(key == val(cur)) break;
//        if(key < val(cur)) {
//            if(l(cur) == null) break;
//            cur = l(cur);
//        }
//        else {
//            if(r(cur) == null) break;
//            cur = r(cur);
//        }
//    }
//    splay(cur);
//    return key == val(cur);
//}
//void erase(const i64 &key) {
//    if(!find(key)) return;
//    size_--; ptr pre = root;
//    if(l(root) && r(root)) {
//        root = l(root);
//        p(root) = null;
//
//        ptr cur = root;
//        while(r(cur)) cur = r(cur);
//        r(cur) = r(pre); p(r(pre)) = cur;
//        Delete(pre);
//        return;
//    }
//    if(l(root)) {
//        root = l(root);
//        p(root) = null;
//        Delete(pre);
//        return;
//    }
//    if(r(root)) {
//        root = r(root);
//        p(root) = null;
//        Delete(pre);
//        return;
//    }
//    Delete(pre); root = null;
//}
//
