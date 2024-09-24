#pragma region macros
//@formatter:off
#define GCC_OPTIMIZE_ENABLE false
#define ENABLE_CPP20_MACRO true

#include <bits/stdc++.h>
// using namespace std;
using std::cin, std::cout, std::endl, std::istream, std::ostream;
using std::array, std::vector, std::stack, std::queue, std::deque, std::list;
using std::max, std::min, std::gcd, std::lcm, std::pow;
using std::less, std::greater;
using std::stoi, std::stol, std::stoll, std::stoul, std::stoull;
using std::sort, std::shuffle, std::uniform_int_distribution, std::mt19937, std::random_device;

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
using str = std::string;
template <typename T, typename T2> using umap = std::unordered_map<T, T2>;
template <typename T> using uset = std::unordered_set<T>;
#define int i64
#define uint u64
#define ci64 const i64 &
#define cint ci64
#define ci32 const i32 &
constexpr i64 i64max = 9223372036854775807,
    llmax  = i64max,
    INF    = 1000000000000000000,
    inf    = 3000000000;
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define forr(name, start, end) for(i64 name = start; name >= end; name--)
#define rep(n) forn(bit_Ly_S, n)
#define rep2(n) forn(la_sh_Discord, n)

i64 iR_v_, iR_v2_;
#define inRep() input(inRep_v_); forn(inRep_var_3_, inRep_var_)
#define inRep2() input(inRep_var_2_); forn(inRep_var_4_, inRep_var_2_)

#define all(vec) (vec).begin(), (vec).end()
template <typename T> using v = std::vector<T>; template <typename T> using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>; using vi = v<i32>; using vb = v<bool>;
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ef emplace_front
#define lb(r, i) lower_bound(all(r), i)
#define ub(r, i) upper_bound(all(r), i)
using ii = array<i64, 2>; using iii = array<i64, 3>;
template <typename T> using lim = std::numeric_limits<T>;
template <typename Signature> using fun = std::function<Signature>;

template <typename T = i64> T input() {T t; cin >> t; return t;}
template <typename T = i64> T in() {T t; cin >> t; return t;}
template <typename T> str toStr(T t) { return std::to_string(t); }
str readline() { char c = '\n'; while(c == '\n') cin.get(c); str s; getline(cin, s); s = c + s; return s; }
#if ENABLE_CPP20_MACRO
template <typename T=i64, typename T2=v<T>, typename T3=less<>> using pq = std::priority_queue<T, T2, T3>;
template <typename T> T::value_type fpop(T &que) { auto t = que.front(); que.pop(); return t; }
template <typename T> T::value_type tpop(T &st) { auto t = st.top(); st.pop(); return t; }
template <typename T, typename T2, typename T3> T pop(pq<T, T2, T3> &pq) { T t = pq.top(); pq.pop(); return t; }
#endif
template <typename T> T pop(stack<T> &st) { T t = st.top(); st.pop(); return t; }
template <typename T> T pop(queue<T> &q) { T t = q.front(); q.pop(); return q; }
template <typename T> void reverse(T &v) { reverse(all(v)); }
template <typename T> void sort(T &v) { sort(all(v)); }
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
template <typename T> T lcm_(T a, T b) { return a / gcd_(a, b) * b; }
template <typename T> T sq_(const T &i) { return i * i; }
template <typename T = i64> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz) a.push_back(input<T>()); return a; }
template <typename T = i64> v<T> inArr(i64 sz) { v<T> a; forn(i,sz) a.push_back(in<T>()); return a; }
template <typename T> void inputArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.push_back(input<T>()); }
template <typename T> T reversed_copy(T arr) { reverse(all(arr)); return arr; }
template <typename T> v<T> sorted_copy(T arr) { sort(all(arr)); return arr; }
template <typename T> v<T> compressed_copy(v<T> arr, const bool &autosort=true) { compress(arr, autosort); return arr; }

enum Nl_{} nl_; istream& operator>>(istream& i, const Nl_&) { return i; } ostream& operator<<(ostream& i, const Nl_&) { return i; }

template <class A, class B=Nl_, class C=Nl_, class D=Nl_, class E=Nl_, class F=Nl_, class G=Nl_>
void input(A &a, B &b=nl_, C &c=nl_, D &d=nl_, E &e=nl_, F &f=nl_, G &g=nl_) { cin >> a >> b >> c >> d >> e >> f >> g; }
template <class A, class B=Nl_, class C=Nl_, class D=Nl_, class E=Nl_, class F=Nl_, class G=Nl_>
void in(A &a, B &b=nl_, C &c=nl_, D &d=nl_, E &e=nl_, F &f=nl_, G &g=nl_) { cin >> a >> b >> c >> d >> e >> f >> g; }
template <class A=Nl_, class B=Nl_, class C=Nl_, class D=Nl_, class E=Nl_, class F=Nl_, class G=Nl_>
void print(A a=nl_, B b=nl_, C c=nl_, D d=nl_, E e=nl_, F f=nl_, G g=nl_) { cout << a << b << c << d << e << f << g; }
template <class A=Nl_, class B=Nl_, class C=Nl_, class D=Nl_, class E=Nl_, class F=Nl_, class G=Nl_>
void println(A a=nl_, B b=nl_, C c=nl_, D d=nl_, E e=nl_, F f=nl_, G g=nl_) { print(a, b, c, d, e, f, g); cout << '\n'; }
template <typename T>
void printArr(const v<T> &v, const str &sep = " ", const str &end = "\n") {
    if(v.empty()) return;
    i64 paSz_ = v.size(); forn(i, paSz_-1) cout << v[i] << sep; cout << v[paSz_-1] << end;
}
void fixPrecision(i32 a_) { cout << std::fixed; cout.precision(a_); }
//@formatter:on
#pragma endregion

// 두 수 XOR
// #trie

class trie {
    struct node {
        // 0, 1, val
        i32 a=0, b=0, val=0;
        [[nodiscard]] bool empty() const {
            return !a && !b;
        }
        [[nodiscard]] i32 size() const {
            i32 ret = 0;
            if(a) ret++;
            if(b) ret++;
            return ret;
        }
        [[nodiscard]] i32 getNonnull() const {
            if(a) return a;
            if(b) return b;
            assert(false);
        }
        node()=default;
        node(i32 c, i32 d, i32 e) : a(c), b(d), val(e) {}
    };
    v<node> mem;
    i32 avail_ = 2;
    i32 New(i32 val) {
        mem.eb(0, 0, val);
        return avail_++;
    }
public:
    trie() : mem(2, {0, 0, 0}){ }
    i32 find(i32 tar, i32 ret = 0, i32 curBit = 31, i32 pos = 1) {
        i32 mask = 1 << curBit;
        if((mask&tar) != mem[pos].val*mask) ret ^= mask;
        if(curBit == 0) return ret;
        if(mem[pos].size() == 1) return find(tar, ret, curBit-1, mem[pos].getNonnull());
        
        mask >>= 1;
        if(tar & mask) return find(tar, ret, curBit-1, mem[pos].a);
        else return find(tar, ret, curBit-1, mem[pos].b);
    }
    void insert(i32 tar, i32 curBit = 30, i32 pos = 1) {
        if(curBit < 0) return;
        i32 mask = 1 << curBit;
        if(tar & mask) {
            if(!mem[pos].b) mem[pos].b = New(1);
            insert(tar, curBit-1, mem[pos].b);
        } else {
            if(!mem[pos].a) mem[pos].a = New(0);
            insert(tar, curBit-1, mem[pos].a);
        }
    }
    void remove(i32 tar, i32 curBit = 30, i32 pos = 1, i32 par = 0) {
        if(curBit < 0) {
            if(tar & mem[pos].val) mem[par].b = 0;
            else mem[par].a = 0;
            return;
        }
        i32 mask = 1 << curBit;
        remove(tar, curBit-1, tar&mask?mem[pos].b:mem[pos].a, pos);
        if(!mem[pos].empty()) return;
        if(mem[pos].val) mem[par].b = 0;
        else mem[par].a = 0;
    }
};

i32 main() {
    fastio;
    umap<i32, i32> chk; trie trie;
    i32 ans = 0;
    inRep() {
        i32 x; in(x);
        if(!chk[x]++) trie.insert(x);
        ans = max(ans, trie.find(x));
    }
    println(ans);
}
