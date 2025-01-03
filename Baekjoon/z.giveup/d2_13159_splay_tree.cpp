#pragma region macros
#include <bits/stdc++.h>
using namespace std;

using i16 = short; using i32 = signed; using i64 = long long; using u64 = unsigned long long;
template <typename T> using v = std::vector<T>; template <typename T> using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>; using vi = v<i32>; using vb = v<bool>;
template <typename Signature> using fun = std::function<Signature>;

constexpr i64 INF = 1000000000000000000, inf = 3000000000;

#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define forr(name, start, end) for(i64 name = start; name >= end; name--)
#define rep(n) forn(bit_Ly_S_, n)

template <typename T=i64, typename T3=less<>> using pq = std::priority_queue<T, v<T>, T3>;
template <typename T, typename T3> T pop(pq<T, T3> &pq) { T t = pq.top(); pq.pop(); return t; }

#define all(vec) (vec).begin(), (vec).end()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
template <typename T> i64 Size(const T &t_) { return static_cast<i64>(t_.size()); }

template <typename T> T pop(stack<T> &st) { T t = st.top(); st.pop(); return t; }
template <typename T> T pop(queue<T> &q) { T t = q.front(); q.pop(); return q; }

#ifdef LOCAL
#define lfastio print()
#else
#define lfastio fastio
#endif
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
template <typename T = i64> T input() {T t; cin >> t; return t;}

template <typename ...T> void print(const T&... a_) { (cout << ... << a_); }
void print() {}
template <typename ...T> void println(const T&... a_) { (cout << ... << a_); cout << '\n'; }
void println() { cout << '\n'; }
template <typename ...T> void input(T&... a_) { (cin >> ... >> a_); }
#define invar(...) i64 __VA_ARGS__; input(__VA_ARGS__)

//@formatter:on
#pragma endregion

class Splay {
public:
    using ptr = i32;
    #define cptr const ptr &
    static constexpr ptr null = 0;
    struct nd {
        ptr l = null, r = null, p = null;
        i64 sz = 1;
        i64 val = 0, sum = 0, mx = 0, mn = INF;
        bool flip = false, dummy = false;
        nd()=default;
        explicit nd(i64 val) { sum = mx = mn = val; }
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
    inline void checkNullPtrVal() {
#ifdef LOCAL
        assert(sz(null) == 0);
        assert(l(null) == null);
        assert(r(null) == null);
        assert(p(null) == null);
        assert(val(null) == 0);
        assert(sum(null) == 0);
        assert(mx(null) == 0);
        assert(mn(null) == INF);
        assert(flip(null) == false);
        assert(mem[null].dummy == false);
#endif
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

    void update(cptr x) { assert(x);
        checkNullPtrVal();
        sz(x) = 1 + sz(l(x)) + sz(r(x));
        sum(x) = val(x) + sum(l(x)) + sum(r(x));
        mn(x) = min({val(x), mn(l(x)), mn(r(x))});
        mx(x) = max({val(x), mx(l(x)), mx(r(x))});
    }
    void push(cptr x) { // assert(x);
        checkNullPtrVal();
        if(!flip(x)) return;
        swap(l(x), r(x));
        if(l(x)) flip(l(x)) = !flip(l(x));
        if(r(x)) flip(r(x)) = !flip(r(x));
        flip(x) = false;
    }
    void rotate(cptr x) {
        if(x == root) return;
        ptr P = p(x); ptr y = null;
        push(P); push(x);
        if(l(P) == x) {
            l(P) = y = r(x);
            r(x) = P;
        } else {
            r(P) = y = l(x);
            l(x) = P;
        }
        p(x) = p(P); p(P) = x;
        if(y) p(y) = P;
        if(p(x)) {
            if(P == l(p(x))) l(p(x)) = x;
            else r(p(x)) = x;
        }
        else root = x;
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
        mem = v<nd>(1, nd());
        mem[0].sz = 0;
        root = null;
    }
    explicit Splay(const vl &arr) : Splay() {
        i64 n_ = arr.size();
        root = New(null, null, null, -INF);
        mem[root].dummy = true; sz(root) = 0;
        ptr cur = root;
        v<ptr> t_;
        forf(i, 0, n_ - 1) {
            ptr nxt = New(null, null, cur, arr[i]);
            r(cur) = nxt; cur = nxt;
            t_.eb(cur);
        }
        r(cur) = New(null, null, cur, INF);
        mem[r(cur)].dummy = true; mem[r(cur)].sz = 0;
        assert(t_.size() == n_); size_ = n_;
        forr(i, n_-1, 0) update(t_[i]);
        splay(t_[n_/2]);
    }
    nd getMem(cptr i) { return mem[i]; }
    ptr rootPtr() const { return root; }
    void reserve(u64 sz) { mem.reserve(sz); }
    
    i32 size() const { return size_; }
    
    // [s, e], s >= 0
    ptr gather(i32 s, i32 e) {
        kth(e);
        ptr t = root;
        kth(s);
        splay(t, root);
        return l(r(root));
    }
    
    void flip(i32 s, i32 e) {
        ptr x = gather(s, e);
        assert(x);
        flip(x) = !flip(x);
    }
    
    void shift(i32 s, i32 e, i32 k) {
        ptr x = gather(s, e);
        println(mn(x), " ", mx(x), " ", sum(x));
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
        push(x);
        while(true) {
            while(l(x) && sz(l(x)) > k) x = l(x), push(x);
            k -= sz(l(x));
            if(!k--) break;
            x = r(x); push(x);
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
