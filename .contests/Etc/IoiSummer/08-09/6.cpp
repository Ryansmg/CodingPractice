#pragma region macros
//@formatter:off
#define GCC_OPTIMIZE_ENABLE false

#include <bits/stdc++.h>
using namespace std;

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

using i16 = short;
using i32 = signed;
using i64 = long long;
using i128 = __int128;
using u16 = unsigned short;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using f32 = float;
using f64 = double;
using f128 = long double;

#define int i64
#define uint u64
//#define double long double
#define ci64 const i64 &
#define cint ci64
#define ci32 const i32 &

const long long llmax = 9223372036854775807; // 2^63-1
const long long INF = 1000000000000000000; // INF * INF > 2^63
const long long inf = 3000000000; // inf > 2^31, inf * inf < 2^63
const signed smax = 2147483647;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(i64 name = 0; name < val; name++)
#define forf(name, start, end) for(i64 name = start; name <= end; name++)
#define pass {cout << "";} // do nothing

#ifndef ONLINE_JUDGE
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)
#else
#define filein cout << ""
#define fileout filein
#endif
#define fileio filein; fileout

template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<i64, 2>;
using iii = array<i64, 3>;
template <typename T> using lim = std::numeric_limits<T>;

const i128 LINTMAX = lim<i128>::max();
const i128 LINTMIN = lim<i128>::min();
__int128 operator ""_I(const char* str, size_t len) {
    __int128 t = 0; i64 st=0, sign=1; if(*str == '-') sign=-1, st=1;
    for(i64 i=st; i < len; i++) { t *= 10; t += (*(str + i) - '0'); }
    return t*sign;
}
istream &operator>>(istream &in, __int128 &l) {
    string s; in >> s; size_t len = s.size(); i64 sign = 1, st = 0; l=0;
    if(s[0]=='-') sign=-1, st=1; for(i64 i=st; i<len; i++) { l *= 10; l += s[i]-'0'; }
    l*=sign; return in;
}
ostream &operator<<(ostream &out,const __int128 &i) {
    if(i==LINTMIN) { out << "-170141183460469231731687303715884105728"; return out; }
    __int128 t = i<0?-i:i; if(!t) out << 0; if(i<0) out << '-';
    stack<char> st; while(t) { st.push((char)((t%10)+'0')); t/=10; }
    while(!st.empty()){out<<st.top();st.pop();} return out;
}

template <typename T = i64> T input() {T t; cin >> t; return t;}

#define all(vec) (vec).begin(), (vec).end()
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

template <typename T> T pow_(T a, T b) { return pow_(a, b, numeric_limits<T>::max()); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }

template <typename T> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz)a.push_back(input<T>()); return a; }
template <typename T> void inputArr(v<T> &arr, i64 sz) { forn(i,sz) arr.push_back(input<T>()); }
template <typename T> v<T> sorted_copy(v<T> arr) { sort(all(arr)); return arr; }
template <typename T> v<T> compressed_copy(v<T> arr, const bool &autosort=true) { compress(arr, autosort); return arr; }

template <typename T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <typename T> T min(T a, T b, T c, T d) { return min(min(a, b), min(c, d)); }
template <typename T> T min(T a, T b, T c, T d, T e) { return min(min(a, b), min(c, d), e); }
template <typename T> T min(T a, T b, T c, T d, T e, T f) { return min(min(a, b), min(c, d), min(e, f)); }
template <typename T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <typename T> T max(T a, T b, T c, T d) { return max(max(a, b), max(c, d)); }
template <typename T> T max(T a, T b, T c, T d, T e) { return max(max(a, b), max(c, d), e); }
template <typename T> T max(T a, T b, T c, T d, T e, T f) { return max(max(a, b), max(c, d), max(e, f)); }

enum Null_{} null_;
istream& operator>>(istream& i, const Null_&) { return i; }
ostream& operator<<(ostream& i, const Null_&) { return i; }
template <typename T> bool isNull() { return typeid(T)==typeid(Null_); }
template <typename T> bool isNull(T) { return typeid(T)==typeid(Null_); }

template <class A, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_>
void input(A &a, B &b=null_, C &c=null_, D &d=null_, E &e=null_, F &f=null_, G &g=null_) {
    if(!isNull<G>()) cin >> a >> b >> c >> d >> e >> f >> g;
    else if(!isNull(f)) cin >> a >> b >> c >> d >> e >> f;
    else if(!isNull(g)) cin >> a >> b >> c >> d >> e;
    else if(!isNull(d)) cin >> a >> b >> c >> d;
    else if(!isNull(c)) cin >> a >> b >> c;
    else if(!isNull(b)) cin >> a >> b;
    else cin >> a;
}

template <class A=Null_, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_, class H=Null_, class I=Null_, class J=Null_>
void print(A a=null_, B b=null_, C c=null_, D d=null_, E e=null_, F f=null_, G g=null_, H h=null_, I i=null_, J j=null_) {
    if(!isNull(j)) cout << a << b << c << d << e << f << h << i << j;
    else if(!isNull(i)) cout << a << b << c << d << e << f << h << i;
    else if(!isNull(h)) cout << a << b << c << d << e << f << h;
    else if(!isNull(g)) cout << a << b << c << d << e << f << g;
    else if(!isNull(f)) cout << a << b << c << d << e << f;
    else if(!isNull(e)) cout << a << b << c << d << e;
    else if(!isNull(d)) cout << a << b << c << d;
    else if(!isNull(c)) cout << a << b << c;
    else if(!isNull(b)) cout << a << b;
    else cout << a;
}
template <class A=Null_, class B=Null_, class C=Null_, class D=Null_, class E=Null_, class F=Null_, class G=Null_, class H=Null_, class I=Null_, class J=Null_>
void println(A a=null_, B b=null_, C c=null_, D d=null_, E e=null_, F f=null_, G g=null_, H h=null_, I i=null_, J j=null_) {
    print(a, b, c, d, e, f, g, h, i, j); cout << '\n';
}
template <typename T>
void printArr(const v<T> &v, const string &sep = " ", const string &end = "\n") {
    for(T i : v) cout << i << sep; cout << end;
}
template <typename T>
void prefixSum(v<T> &arr) {
    for(auto iter = arr.begin()+1; iter!=arr.end(); iter++) *iter += *(iter-1);
}

//@formatter:on
#pragma endregion

struct coach {
    i64 x, y, z;
    coach(i64 a, i64 b, i64 c) { x = a, y = b, z = c; }
    bool operator<(const coach& other) const {
        if(z!=other.z) return z > other.z;
        if(y!=other.y) return y > other.y;
        return x < other.x;
    }
};

#pragma region disable c-style types
#define float
#undef int
#define int
#undef double
#define double
#pragma endregion
i32 main() {
    fastio; i64 n = input();
    v<coach> arr;
    forn(i, n) {
        i64 a, b, c; cin >> a >> b >> c;
        arr.emplace_back(a, b, c);
    }
    sort(all(arr));
    i64 ans = 0, cur = 0, curZ = inf;
    set<coach> s;
    s.insert({0, inf, 0});
    s.insert({inf, 0, 0});
    for(const coach &c : arr) {
        ans += cur * (curZ - c.z);
        curZ = c.z;
        coach d = coach(c.x, c.y, 0);
        auto nxt = s.lower_bound(d);
        auto pre = nxt; pre--;
        if(pre->x >= d.x) continue;
        i64 preX = pre->x;
        while(nxt->x <= d.x) {
            cur += (nxt->x - preX) * (d.y - nxt->y);
            preX = nxt->x;
            nxt = s.erase(nxt);
        }
        cur += (d.x - preX) * (d.y - nxt->y);
        s.insert(d);
    }
    ans += cur * curZ;
    cout << ans;
}
