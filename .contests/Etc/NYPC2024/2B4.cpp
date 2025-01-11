#pragma region macros
//@formatter:off
#define GCC_OPTIMIZE_ENABLE false

#include <bits/stdc++.h>
using namespace std;
#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#ifdef LOCAL
#define DEBUG_PRINT_ if(c==cdbg) cerr << t; else cout << t;
#define lfastio print()
#else
#define DEBUG_PRINT_
#define lfastio fastio
#endif
using i16 = short; using i32 = signed; using i64 = long long; using i128 = __int128;
using u16 = unsigned short; using u32 = unsigned; using u64 = unsigned long long; using u128 = unsigned __int128;
using f32 = float; using f64 = double; using f128 = long double;
#define int i64
#define uint u64
#define ci64 const i64 &
#define cint ci64
#define ci32 const i32 &
const long long llmax = 9223372036854775807, INF = 1000000000000000000, inf = 3000000000;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define all(vec) (vec).begin(), (vec).end()
template <typename T> using v = vector<T>; template <typename T> using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>;
template <typename T, typename T2=v<T>, typename T3=less<>> using pq = priority_queue<T, T2, T3>;
using ii = array<i64, 2>; using iii = array<i64, 3>;
template <typename T> using lim = std::numeric_limits<T>;

template <typename T = i64> T input() {T t; cin >> t; return t;}
template <typename T> T::value_type fpop(T &que) { auto t = que.front(); que.pop(); return t; }
template <typename T> T::value_type tpop(T &st) { auto t = st.top(); st.pop(); return t; }
template <typename T> void sort(v<T> &v) { sort(all(v)); }
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
template <typename T> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz)a.push_back(input<T>()); return a; }
template <typename T> void inputArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.push_back(input<T>()); }
template <typename T> v<T> sorted_copy(v<T> arr) { sort(all(arr)); return arr; }
template <typename T> v<T> compressed_copy(v<T> arr, const bool &autosort=true) { compress(arr, autosort); return arr; }
template <typename T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <typename T> T min(T a, T b, T c, T d, T e=lim<T>::max(), T f=lim<T>::max()) { return min(min(a, b), min(c, d), min(e, f)); }
template <typename T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <typename T> T max(T a, T b, T c, T d, T e=lim<T>::min(), T f=lim<T>::min()) { return max(max(a, b), max(c, d), max(e, f)); }

enum Null_{} nl_; enum cdbg_{ useCerr, useCout } cdbg=useCerr, cloc=useCout;
istream& operator>>(istream& i, const Null_&) { return i; } ostream& operator<<(ostream& i, const Null_&) { return i; }
template <typename T> cdbg_& operator<<(cdbg_& c, const T& t) {
    DEBUG_PRINT_
    return c;
}

template <class A, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_>
void input(A &a, B &b=nl_, C &c=nl_, D &d=nl_, E &e=nl_, F &f=nl_, G &g=nl_) {
    cin >> a >> b >> c >> d >> e >> f >> g;
}
template <class A=Null_, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_, class H=Null_, class I=Null_, class J=Null_>
void print(A a=nl_, B b=nl_, C c=nl_, D d=nl_, E e=nl_, F f=nl_, G g=nl_, H h=nl_, I i=nl_, J j=nl_) {
    cout << a << b << c << d << e << f << g << h << i << j;
}
template <class A=Null_, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_, class H=Null_, class I=Null_, class J=Null_>
void println(A a=nl_, B b=nl_, C c=nl_, D d=nl_, E e=nl_, F f=nl_, G g=nl_, H h=nl_, I i=nl_, J j=nl_) {
    print(a, b, c, d, e, f, g, h, i, j); cout << '\n';
}
template <typename T>
void printArr(const v<T> &v, const string &sep = " ", const string &end = "\n") {
    for(T i : v) cout << i << sep; cout << end;
}
//@formatter:on
#pragma endregion

class iterSeg {
public:
    v<int> tree; int n=-1;
    iterSeg() = default;
    explicit iterSeg(const v<int> &arr) { n = (int) arr.size(); init(arr); }
    explicit iterSeg(cint i) { tree = v<int>(i*2+10, 0); n = i; }
    void inputInit() { tree = v<int>(2*n+10, 0); forf(i, n, 2*n-1) cin >> tree[i]; init(); }
    /// 1 <= tar <= n
    void update(int tar, int val) {
        tar--;
        assert(0 <= tar && tar < n);
        tree[n+tar] = val;
        for(int i = n+tar; i>1; i>>=1) tree[i>>1] = tree[i] + tree[i^1];
    }
    /// [l, r]
    int query(int left, int right) {
        left--; right--;
        assert(0 <= left && right < n);
        right++;
        int l = n+left, r = n+right, ans = 0;
        for(; l<r; l>>=1, r>>=1) {
            if(l&1) ans += tree[l++];
            if(r&1) ans += tree[--r];
        }
        return ans;
    }
private:
    void init() { for(int i=n-1; i>0; i--) tree[i] = tree[i<<1] + tree[i<<1|1]; }
    void init(const v<int> &arr) {
        tree = v<int>(2*n+10, 0);
        for(int i=n, j=0; i<2*n; i++, j++) tree[i] = arr[j];
        init();
    }
};

i32 main() {
    lfastio;
    i64 n, q; cin >> n >> q;
    string str = input<string>();
    v<i64> segInit;
    set<i64> humans;
    for(const char& c : str)
        segInit.emplace_back(c == 'e');
    forn(i, n-1) if(str[i] == 'h') humans.insert(i+1);
    iterSeg elf(segInit);
    forn(qi, q) {
        i64 x; char v; i64 s, e;
        cin >> x >> v >> s >> e;
        str[x-1] = v;
        elf.update(x, v=='e');
        if(v == 'h') humans.insert(x);
        else humans.erase(x);
        while(s <= n && str[s-1] == 'h') s++;
        if(s == n+1) {
            println(0);
            continue;
        }

        auto ptr1 = humans.lower_bound(s);
        auto ptr2 = humans.upper_bound(e);
        if(ptr1 == ptr2) {
            i64 elfs = elf.query(s, e);
            println(min(elfs, e-s+1-elfs));
            continue;
        }
        i64 ans = 0;
        for(auto ptr = ptr1; ptr1 != ptr2; ptr1++) {
            if(s > *ptr) continue;
            i64 elfs = elf.query(s, *ptr-1);
            ans += min(elfs, *ptr-s-elfs);
            s = *ptr;
            while(s <= n && str[s-1] == 'h') s++;
        }
        if(s < e) {
            i64 elfs = elf.query(s, e);
            ans += min(elfs, e-s+1-elfs);
        }
        println(ans);
    }
}
