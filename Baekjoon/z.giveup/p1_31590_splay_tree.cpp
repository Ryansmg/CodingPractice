#pragma region macros
//@formatter:off
#define GCC_OPTIMIZE_ENABLE false
#define DISABLE_KOISTUDY_ERROR false

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#include <bits/stdc++.h>
#if DISABLE_KOISTUDY_ERROR
using namespace std;
#else
using std::cin, std::cout, std::endl, std::istream, std::ostream;
using std::array, std::vector, std::stack, std::queue, std::deque, std::list, std::pair, std::tuple;
using std::set, std::map;
using std::max, std::min, std::gcd, std::lcm, std::pow, std::swap;
using std::less, std::greater, std::all_of, std::hash;
using std::stoi, std::stol, std::stoll, std::stoul, std::stoull;
using std::sort, std::shuffle, std::uniform_int_distribution, std::mt19937, std::random_device;

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
constexpr i64 i64max = 9223372036854775807,
    llmax  = i64max,
    INF    = 1000000000000000000,
    inf    = 3000000000;

#ifdef LOCAL
#define lfastio print()
#else
#define lfastio fastio
#endif
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define forr(name, start, end) for(i64 name = start; name >= end; name--)
#define rep(n) forn(bit_Ly_S, n)
#define rep2(n) forn(la_sh_Discord, n)
#define elif else if

i64 iR_v_, iR_v2_;
#define inRep() input(iR_v_); forn(iR_v3_, iR_v_)
#define inRep2() input(iR_v2_); forn(iR_v4_, iR_v2_)

#define all(vec) (vec).begin(), (vec).end()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
#define lb(r, i) lower_bound(all(r), i)
#define ub(r, i) upper_bound(all(r), i)

template <typename T = i64> T input() {T t; cin >> t; return t;}
template <typename T = i64> T in() {T t; cin >> t; return t;}
template <typename T = i64> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz) a.eb(in<T>()); return a; }
template <typename T> void inputArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.eb(in<T>()); }
template <typename T> void inArr(v<T> &arr, i64 sz, bool clear = true) { inputArr(arr, sz, clear); }
template <typename T = i64> v<T> inArr(i64 sz) { v<T> a; forn(i,sz) a.eb(in<T>()); return a; }
template <typename T = i64> v<T> inArr() { return inArr(in()); }
str readline() { char c = '\n'; while(c == '\n') cin.get(c); str s; getline(cin, s); s = c + s; return s; }
template <typename T>
void printArr(const v<T> &v, const str &sep = " ", const str &end = "\n") {
    if(v.empty()) return;
    i64 paSz_ = v.size(); forn(i, paSz_-1) cout << v[i] << sep; cout << v[paSz_-1] << end;
}
#if !DISABLE_KOISTUDY_ERROR
template <typename ...T> void print(const T&... a_) { (cout << ... << a_); }
template <typename ...T> void println(const T&... a_) { (cout << ... << a_); cout << '\n'; }
template <typename ...T> void input(T&... a_) { (cin >> ... >> a_); }
template <typename ...T> void in(T&... a_) { (cin >> ... >> a_); }

template <typename T=i64, typename T2=v<T>, typename T3=less<>> using pq = std::priority_queue<T, T2, T3>;
template <typename T> T::value_type fpop(T &que) { auto t = que.front(); que.pop(); return t; }
template <typename T> T::value_type tpop(T &st) { auto t = st.top(); st.pop(); return t; }
template <typename T, typename T2, typename T3> T pop(pq<T, T2, T3> &pq) { T t = pq.top(); pq.pop(); return t; }
#endif
template <typename T> T pop(stack<T> &st) { T t = st.top(); st.pop(); return t; }
template <typename T> T pop(queue<T> &q) { T t = q.front(); q.pop(); return q; }
template <typename T> str toStr(T t) { return std::to_string(t); }
template <typename T> void reverse(T &v) { reverse(all(v)); }
template <typename T> void sort(T &v) { sort(all(v)); }
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T reversed_copy(T arr) { reverse(all(arr)); return arr; }
template <typename T> v<T> sorted_copy(T arr) { sort(all(arr)); return arr; }
template <typename T> v<T> compressed_copy(v<T> arr, const bool &autosort=true) { compress(arr, autosort); return arr; }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
template <typename T> T lcm_(T a, T b) { return a / gcd_(a, b) * b; }
template <typename T> T sq_(const T &i) { return i * i; }

void fixPrecision(i32 a_) { cout << std::fixed; cout.precision(a_); }
//@formatter:on
#pragma endregion

template <typename Type = i64>
class Splay {
public:
    using ptr = i32;
    #define cptr const ptr &
    static constexpr ptr null = 0;
    struct nd {
        ptr l = null, r = null, p = null;
        i64 sz = 0;
        Type val;
        nd()=default;
        nd(ptr L, ptr R, ptr Parent, Type Value) : l(L), r(R), p(Parent), val(std::move(Value)) {}
    };
private:
    v<nd> mem; ptr root = null; ptr avail = 1;
    static constexpr ptr trashPtr = 2015571557;
    stack<ptr> free; i32 size_ = 0;
    ptr New(cptr l, cptr r, cptr p, const Type &val) {
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
    Type& val(cptr x) { return mem[x].val; }
    void updateSz(cptr x) { sz(x) = 1 + sz(l(x)) + sz(r(x)); }
    void rotate(cptr x) {
        if(x == root) return;
        ptr P = p(x), G = p(P);
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
        else r(G) = x;
        if(p(x) == null) root = x;
        updateSz(P); updateSz(x);
    }
    void splay(cptr x) {
        while( x != root ) {
            if(p(x) == root) { rotate(x); break; }
            if( (x == l(p(x)) ) == ( p(x) == l(p(p(x))) ) ) rotate(p(x));
            else rotate(x);
            rotate(x);
        }
    }
public:
    Splay() {
        mem = v<nd>(1, {0, 0, 0, {}});
        root = null;
    }
    nd getMem(cptr i) { return mem[i]; }
    ptr rootPtr() { return root; }
    void reserve(u64 sz) { mem.reserve(sz); }
    void insert(const Type &key) {
        ptr newNd = New(0, 0, 0, key);
        if(root == null) {
            root = newNd; size_++; return;
        }
        ptr cur = root;
        while(true) {
            if(val(cur) == key) return; // 중복
            if(key < val(cur)) {
                if(l(cur) == null) {
                    l(cur) = newNd;
                    p(newNd) = cur;
                    break;
                }
                cur = l(cur);
            } else {
                if(r(cur) == null) {
                    r(cur) = newNd;
                    p(newNd) = cur;
                    break;
                }
                cur = r(cur);
            }
        }
        size_++;
        splay(newNd);
    }
    bool find(const Type &key) {
        ptr cur = root;
        if(root == null) return false;
        while(cur) {
            if(key == val(cur)) break;
            if(key < val(cur)) {
                if(l(cur) == null) break;
                cur = l(cur);
            }
            else {
                if(r(cur) == null) break;
                cur = r(cur);
            }
        }
        splay(cur);
        return key == val(cur);
    }
    void erase(const Type &key) {
        if(!find(key)) return;
        size_--; ptr pre = root;
        if(l(root) && r(root)) {
            root = l(root);
            p(root) = null;
            
            ptr cur = root;
            while(r(cur)) cur = r(cur);
            r(cur) = r(pre); p(r(pre)) = cur;
            Delete(pre);
            return;
        }
        if(l(root)) {
            root = l(root);
            p(root) = null;
            Delete(pre);
            return;
        }
        if(r(root)) {
            root = r(root);
            p(root) = null;
            Delete(pre);
            return;
        }
        Delete(pre); root = null;
    }
    i32 size() { return size_; }
    
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
            if(l(i)) recF_(l(i));
            f(mem[i]);
            if(r(i)) recF_(r(i));
        };
        if(tar == -1) tar = root;
        recF_(tar);
    }
    
    template <typename Callable>
    void forEachRev(const Callable &f, ptr tar = -1) {
        fun<void(ptr)> recF_ = [&](const ptr &i) {
            if(!i) return;
            if(r(i)) recF_(r(i));
            f(mem[i]);
            if(l(i)) recF_(l(i));
        };
        if(tar == -1) tar = root;
        recF_(tar);
    }
};

// 31590. Candy Compress
// #splay_tree?

i32 main() {
    fastio;
    Splay splay;
    splay.reserve(500000);
    i64 n, m; in(n, m);
    rep(n) splay.insert(in());
    rep(m) splay.erase(in());
    println(splay.size());
    splay.forEach([](const Splay<>::nd& n) {
        print(n.val, " ");
    });
}
