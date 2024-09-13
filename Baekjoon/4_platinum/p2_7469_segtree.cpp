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

namespace PST {
    constexpr i64 n = 100010;
    constexpr i32 null = 0;
    i64 avail = 1;
    using ptr = i32;
    struct pnd { ptr l = null, r = null; i64 val = 0; };
    pnd mem[15000000];

    class pst {
    public:
        ptr pos = null;
        pst() : pos(avail++) {}
        static pst newFrom(const pst &prev) {
            pst t;
            mem[t.pos].l = mem[prev.pos].l;
            mem[t.pos].r = mem[prev.pos].r;
            return t;
        }
        void init(vl *arr = nullptr) const {
            init(pos, 1, n, arr);
        }
        void add(pst prv, i64 t, i64 d) const {
            add(prv.pos, t, d);
        }
        void add(ptr prv, i64 t, i64 d) const {
            add(prv, pos, t, d, 1, n);
        }
        i64 query(i64 l, i64 r) const {
            return query(pos, l, r, 1, n);
        }
    private:
        static void add(ptr prv, ptr cur, i64 t, i64 d, i64 s, i64 e) {
            if(s == e) {
                mem[cur].val += d;
                return;
            }
            i64 m = (s + e) >> 1;
            if(t <= m) {
                if(!mem[cur].l || mem[cur].l == mem[prv].l) {
                    mem[cur].l = avail++;
                    mem[mem[cur].l].val = mem[mem[prv].l].val;
                }
                if(!mem[cur].r) mem[cur].r = mem[prv].r;
                add(mem[prv].l, mem[cur].l, t, d, s, m);
            } else {
                if(!mem[cur].l) mem[cur].l = mem[prv].l;
                if(!mem[cur].r || mem[cur].r == mem[prv].r) {
                    mem[cur].r = avail++;
                    mem[mem[cur].r].val = mem[mem[prv].r].val;
                }
                add(mem[prv].r, mem[cur].r, t, d, m+1, e);
            }
            mem[cur].val = mem[mem[cur].l].val + mem[mem[cur].r].val;
        }
        static i64 query(ptr cur, i64 l, i64 r, i64 s, i64 e) {
            if(r < s || e < l) return 0;
            if(l <= s && e <= r) return mem[cur].val;
            i64 m = (s + e) >> 1;
            return query(mem[cur].l, l, r, s, m) + query(mem[cur].r, l, r, m+1, e);
        }
        static void init(ptr node, i64 s, i64 e, vl *arr) {
            if (s == e) {
                mem[node].val = arr ? (*arr)[s-1] : 0;
                return;
            }
            i64 m = (s + e) >> 1;
            mem[node].l = avail++;
            mem[node].r = avail++;
            init(mem[node].l, s, m, arr);
            init(mem[node].r, m+1, e, arr);
            mem[node].val = mem[mem[node].l].val + mem[mem[node].r].val;
        }
    };
}
using pst = PST::pst;
using ptr = PST::ptr;
using PST::mem;

i32 main() {
    fastio;
    i64 n, m, a, b, c; in(n, m);
    vl comp; vl arr;
    rep(n) in(a), comp.pb(a), arr.pb(a);
    compress(comp);
    for(i64 &i : arr) i = idx(i, comp) + 1;
    v<pst> psts(1, pst());
    forn(i, n) {
        pst p = pst::newFrom(psts.back());
        p.add(psts.back(), arr[i], 1);
        psts.eb(p);
    }
    func<i64(ptr, ptr, i64, i64, i64)> q = [&](ptr l, ptr r, i64 s, i64 e, i64 k) -> i64 {
        if(s == e) return s;
        i64 lcnt = 0;
        lcnt -= mem[mem[l].l].val;
        lcnt += mem[mem[r].l].val;
        i64 m = (s+e)>>1;
        if(k <= lcnt) return q(mem[l].l, mem[r].l, s, m, k);
        else return q(mem[l].r, mem[r].r, m+1, e, k-lcnt);
    };
    rep(m) in(a, b, c), println(comp[q(psts[a-1].pos, psts[b].pos, 1, 100010, c)-1]);
}
