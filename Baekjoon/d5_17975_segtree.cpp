#pragma region macros
//@formatter:off
#define GCC_OPTIMIZE_ENABLE false
#define ENABLE_CPP20_MACRO true

#include <bits/stdc++.h>
using namespace std;
#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#ifdef LOCAL
#define lfastio print()
#else
#define lfastio fastio
#endif
using i16 = short; using i32 = signed; using i64 = long long; using i128 = __int128;
using u16 = unsigned short; using u32 = unsigned; using u64 = unsigned long long; using u128 = unsigned __int128;
using f32 = float; using f64 = double; using f128 = long double; using F128 = __float128;
using str = string;
#define int i64
#define uint u64
#define ci64 const i64 &
#define cint ci64
#define ci32 const i32 &
constexpr i64 llmax = 9223372036854775807, INF = 1000000000000000000, inf = 3000000000;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define forr(name, start, end) for(i64 name = start; name >= end; name--)
#define rep(n) forn(bit_Ly_S, n)
#define rep2(n) forn(la_sh_Discord, n)

i64 inRep_var_, inRep_var_2_;
#define inRep() input(inRep_var_); forn(inRep_var_3_, inRep_var_)
#define inRep2() input(inRep_var_2_); forn(inRep_var_4_, inRep_var_2_)

#define all(vec) (vec).begin(), (vec).end()
template <typename T> using v = vector<T>; template <typename T> using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>; using vi = v<i32>;
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
using ii = array<i64, 2>; using iii = array<i64, 3>;
template <typename T> using lim = std::numeric_limits<T>;
template <typename Signature> using func = function<Signature>;

template <typename T = i64> T input() {T t; cin >> t; return t;} template <typename T = i64> T in() {T t; cin >> t; return t;}
string readline() { string s; getline(cin, s); return s; }
#if ENABLE_CPP20_MACRO
template <typename T=i64, typename T2=v<T>, typename T3=less<>> using pq = priority_queue<T, T2, T3>;
template <typename T> T::value_type fpop(T &que) { auto t = que.front(); que.pop(); return t; }
template <typename T> T::value_type tpop(T &st) { auto t = st.top(); st.pop(); return t; }
#endif
template <typename T> void reverse(v<T> &v) { reverse(all(v)); }
template <typename T> void sort(v<T> &v) { sort(all(v)); }
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
template <typename T = i64> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz) a.push_back(input<T>()); return a; }
template <typename T = i64> v<T> inArr(i64 sz) { v<T> a; forn(i,sz) a.push_back(in<T>()); return a; }
template <typename T> void inputArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.push_back(input<T>()); }
template <typename T> v<T> sorted_copy(v<T> arr) { sort(all(arr)); return arr; }
template <typename T> v<T> compressed_copy(v<T> arr, const bool &autosort=true) { compress(arr, autosort); return arr; }

enum Nl_{} nl_; istream& operator>>(istream& i, const Nl_&) { return i; } ostream& operator<<(ostream& i, const Nl_&) { return i; }

template <class A, class B=Nl_, class C=Nl_, class D=Nl_, class E=Nl_, class F=Nl_, class G=Nl_>
void input(A &a, B &b=nl_, C &c=nl_, D &d=nl_, E &e=nl_, F &f=nl_, G &g=nl_) { cin >> a >> b >> c >> d >> e >> f >> g; }
template <class A, class B=Nl_, class C=Nl_, class D=Nl_, class E=Nl_, class F=Nl_, class G=Nl_>
void in(A &a, B &b=nl_, C &c=nl_, D &d=nl_, E &e=nl_, F &f=nl_, G &g=nl_) { cin >> a >> b >> c >> d >> e >> f >> g; }
template <class A=Nl_, class B=Nl_, class C=Nl_, class D=Nl_, class E=Nl_, class F=Nl_, class G=Nl_, class H=Nl_, class I=Nl_, class J=Nl_>
void print(A a=nl_, B b=nl_, C c=nl_, D d=nl_, E e=nl_, F f=nl_, G g=nl_, H h=nl_, I i=nl_, J j=nl_) { cout << a << b << c << d << e << f << g << h << i << j; }
template <class A=Nl_, class B=Nl_, class C=Nl_, class D=Nl_, class E=Nl_, class F=Nl_, class G=Nl_, class H=Nl_, class I=Nl_, class J=Nl_>
void println(A a=nl_, B b=nl_, C c=nl_, D d=nl_, E e=nl_, F f=nl_, G g=nl_, H h=nl_, I i=nl_, J j=nl_) { print(a, b, c, d, e, f, g, h, i, j); cout << '\n'; }
template <typename T>
void printArr(const v<T> &v, const string &sep = " ", const string &end = "\n") { for(const T &i : v) cout << i << sep; cout << end; }
//@formatter:on
#pragma endregion

class nd {
public:
    int lval, rval, val, allval;
    nd(int a, int b, int c, int d) : lval(a), rval(b), val(c), allval(d){}
};
class goldmineSeg {
    vector<nd> tree;
    int n;
public:
    explicit goldmineSeg(const int &treeSize) {
        tree = v<nd>(4*treeSize, {0, 0, 0, 0});
        n = treeSize;
    }
    explicit goldmineSeg(const v<int> &a) : goldmineSeg((int) a.size()) {
        init(a, 1, 1, n);
    }
    goldmineSeg(const v<int> &a, const int &treeSize) : goldmineSeg(treeSize) {
        assert(a.size() == treeSize);
        init(a, 1, 1, n);
    }
    void update(const int &tar, const int &diff) { update(1, 1, n, tar, diff); }
    nd query(const int &left, const int &right) { return query(1, 1, n, left, right); }
protected:
    void init(const vector<int> &a, int node, int start, int end) {
        if(start==end) {
            tree[node] = {a[start-1], a[start-1], a[start-1], a[start-1]};
        } else {
            init(a, node*2, start, (start+end)/2);
            init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = {0,0,0,0};
            tree[node].lval = max(tree[node*2].lval, tree[node*2].allval + tree[node*2+1].lval);
            tree[node].rval = max(tree[node*2+1].rval, tree[node*2+1].allval + tree[node*2].rval);
            tree[node].val = max(max(tree[node*2].val, tree[node*2+1].val), tree[node*2].rval + tree[node*2+1].lval);
            tree[node].allval = tree[node*2].allval + tree[node*2+1].allval;
        }
    }
    void update(int node, int start, int end, const int &index, const int &diff) {
        if(index<start || end<index) return;
        if(start==end) {
            tree[node].lval += diff;
            tree[node].rval += diff;
            tree[node].val += diff;
            tree[node].allval += diff;
        } else {
            update(node*2, start, (start+end)/2, index, diff);
            update(node*2+1, (start+end)/2+1, end, index, diff);
            tree[node] = {0,0,0,0};
            tree[node].lval = max(tree[node*2].lval, tree[node*2].allval + tree[node*2+1].lval);
            tree[node].rval = max(tree[node*2+1].rval, tree[node*2+1].allval + tree[node*2].rval);
            tree[node].val = max(max(tree[node*2].val, tree[node*2+1].val), tree[node*2].rval + tree[node*2+1].lval);
            tree[node].allval = tree[node*2].allval + tree[node*2+1].allval;
        }
    }
    nd query(int node, int start, int end, const int &left, const int &right) {
        if(end < left || right < start) return {0, -inf, -inf, -inf};
        if(left <= start && end <= right) return tree[node];
        nd f = query(node*2, start, (start+end)/2, left, right);
        nd s = query(node*2+1, (start+end)/2+1, end, left, right);
        nd c = {0, 0, 0, 0};
        c.lval = max(f.lval, f.allval + s.lval);
        c.rval = max(s.rval, s.allval + f.rval);
        c.val = max(max(f.val, s.val), f.rval + s.lval);
        c.allval = f.allval + s.allval;
        return c;
    }

};

// #17975. Strike Zone
// #coordinate_compression #sweeping #segtree

signed main() {
    fastio;
    v<int> compx, compy;
    int a, b, c;
    queue<ii> p1, p2;
    i64 n1, n2; cin >> n1;
    rep(n1) in(a, b), p1.push({a, b});
    in(n2);
    rep(n2) in(a, b), p2.push({a, b});
    i64 c1, c2; in(c1, c2);
    v<iii> tmines;
    rep(n1) {
        auto [A, B] = fpop(p1);
        tmines.push_back({A, B, c1});
        compx.push_back(A);
        compy.push_back(B);
    }
    rep(n2) {
        auto [A, B] = fpop(p2);
        tmines.push_back({A, B, -c2});
        compx.push_back(A);
        compy.push_back(B);
    }
    compress(compx); compress(compy);
    int xsz = (int) compx.size(), ysz = (int) compy.size();
    v2<ii> mines(ysz, v<ii>());
    for(iii mine : tmines)
        mines[idx(mine[1], compy)].push_back({idx(mine[0], compx)+1, mine[2]});
    int ans = 0;
    forn(st, ysz) {
        goldmineSeg gms(xsz);
        forf(i, st, ysz-1) {
            for(ii mine : mines[i])
                gms.update(mine[0], mine[1]);
            ans = max(ans, gms.query(1, xsz).val);
        }
    }
    cout << ans;
}
