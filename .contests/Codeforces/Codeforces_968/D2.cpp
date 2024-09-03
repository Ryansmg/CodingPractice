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
using str = string;
#define int i64
#define uint u64
#define ci64 const i64 &
#define cint ci64
#define ci32 const i32 &
const long long llmax = 9223372036854775807, INF = 1000000000000000000, inf = 3000000000;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define forr(name, start, end) for(i64 name = start; name >= end; name--)
#define all(vec) (vec).begin(), (vec).end()
template <typename T> using v = vector<T>; template <typename T> using v2 = v<v<T>>;
using vl = v<i64>; using v2l = v2<i64>;
template <typename T, typename T2=v<T>, typename T3=less<>> using pq = priority_queue<T, T2, T3>;
using ii = array<i64, 2>; using iii = array<i64, 3>;
template <typename T> using lim = std::numeric_limits<T>;

template <typename T = i64> T input() {T t; cin >> t; return t;}
template <typename T> T::value_type fpop(T &que) { auto t = que.front(); que.pop(); return t; }
template <typename T> T::value_type tpop(T &st) { auto t = st.top(); st.pop(); return t; }
template <typename T> void sort(T &v) { sort(all(v)); }
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T pow_(T a, T b, T mod=lim<T>::max()) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
template <typename T> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz)a.push_back(input<T>()); return a; }
template <typename T> void inputArr(v<T> &arr, i64 sz, bool clear = true) { if(clear) arr.clear(); forn(i,sz) arr.push_back(input<T>()); }
template <typename T> T sorted_copy(T arr) { sort(all(arr)); return arr; }
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

int findRoot(v<int> &parent, int n) {
    if(parent[n] == n) return n;
    return parent[n] = findRoot(parent, parent[n]);
}
/// a에 b를 연결
bool unionRoot(v<int> &parent, int a, int b) {
    if(findRoot(parent, a) == findRoot(parent, b)) return false;
    parent[findRoot(parent,b)] = findRoot(parent, a); return true;
}


i32 main() {
    fastio;
    i64 T = input();
    forn(asdf, T) {
        i64 n, m; cin >> n >> m;
        i64 max_mex1 = 0, max_mex2 = 0;
        bool use_mex2 = true;
        i64 tem;
        map<i64, i64> mex2m;
        i64 ans = 0;
        forn(i, n) {
            i64 l = input();
            vl arr; inputArr(arr, l); compress(arr);
            i64 mex1 = -1, mex2 = -1;
            i64 pre = 0;
            for(ci64 j : arr) {
                if(j == pre) { pre++; continue; }
                while(j != pre) {
                    if(mex1 == -1) mex1 = pre;
                    else { mex2 = pre; goto end; }
                    pre++;
                }
                pre++;
            }
            if(mex1 == -1) { mex1 = arr.back()+1, mex2 = arr.back()+2; }
            else { mex2 = arr.back()+1; }
            end:
            if(mex1 == 0) { use_mex2 = true; }
            max_mex1 = max(max_mex1, mex1);
            if(max_mex2 < mex2 && mex1 == 0) {
                tem = 1;
            } else if(max_mex2 == mex2) {
                tem = 0;
            }
            max_mex2 = max(max_mex2, mex2);
            mex2m[mex1] = max(mex2m[mex1], mex2);
        }
        if(use_mex2) {
            ans -= max_mex1*tem;
            if(m <= max_mex2) println(ans+(m+1)*max_mex2);
            else println(ans+(max_mex2+1)*max_mex2 + (max_mex2+m+1)*(m-max_mex2)/2);
            continue;
        }

        if(m <= max_mex1) ans += (m+1)*max_mex1;
        else ans += (max_mex1+1)*max_mex1 + (max_mex1+m+1)*(m-max_mex1)/2;
        for(auto [a, b] : mex2m) {
            if(a > m) break;
            while(mex2m.find(b) != mex2m.end()) b = mex2m[b];
            if(a <= max_mex1) {
                if(b <= max_mex1) continue;
                ans += b - max_mex1;
            } else {
                ans += b-a;
            }
        }
        println(ans);
    }
}
