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
template <typename T> void reverse(T &v) { reverse(all(v)); }
template <typename T> void sort(v<T> &v) { sort(all(v)); }
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
template <typename T> T lcm_(T a, T b) { return a / gcd_(a, b) * b; }
template <typename T = i64> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz) a.push_back(input<T>()); return a; }
template <typename T = i64> v<T> inArr(i64 sz) { v<T> a; forn(i,sz) a.push_back(in<T>()); return a; }
template <typename T> void inputArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.push_back(input<T>()); }
template <typename T> T reversed_copy(T arr) { reverse(all(arr)); return arr; }
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
void printArr(const v<T> &v, const string &sep = " ", const string &end = "\n") {
    i64 paSz_ = v.size(); forn(i, paSz_-1) cout << v[i] << sep; cout << v[paSz_-1] << end;
}
//@formatter:on
#pragma endregion

// 1849. 순열
// #segtree

class segtree {
protected:
    vector<int> tree; int n;
public:
    explicit segtree(cint treeSize, bool inputInit = false) {
        tree = v<int>(4*treeSize, 0); n = treeSize;
        if(inputInit) { v<int> arr; forn(i, n) arr.push_back(input()); init(arr, 1, 1, n); }
    }
    explicit segtree(const v<int> &a) : segtree((int)a.size()) { init(a, 1, 1, n); }
    void update(cint tar, cint diff) { update(1, tar, 1, n, diff); }
    int query(cint tar) { return query(1, 1, n, tar); }
protected:
    int init(const v<int> &a, int node, int start, int end) {
        if(start==end) return tree[node] = a[start-1];
        else return tree[node] = init(a, node*2, start, (start+end)/2)
                                 + init(a, node*2+1, (start+end)/2+1, end);
    }
    int update(int node, int tar, int start, int end, int diff) {
        if(end < tar || tar < start) return tree[node];
        if(start == end) return tree[node] = diff;
        return tree[node] = update(node*2, tar, start, (start+end)/2, diff)
                            + update(node*2+1, tar, (start+end)/2+1, end, diff);
    }
    int query(int node, int start, int end, int tar) {
        if(start == end) return start;
        if(tree[node*2] >= tar) return query(node*2, start, (start+end)/2, tar);
        return query(node*2+1, (start+end)/2+1, end, tar - tree[node*2]);
    }
};

i32 main() {
    fastio;
    i64 n = in();
    segtree seg(vl(n, 1));
    v<i64> ans(n);
    forn(i, n) {
        i64 j = in() + 1;
        i64 t = seg.query(j);
        ans[t-1] = i+1;
        seg.update(t, 0);
    }
    printArr(ans, "\n");
}
