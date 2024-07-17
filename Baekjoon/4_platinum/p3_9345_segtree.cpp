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
#define cint const i64 &
#define ci64 cint
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

const i128 LINTMAX = ((i128(1)<<126)-1)*2+1;
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

template <typename T> v<T> inputArr(i64 sz) { v<T> a; forn(i,sz)a.push_back(input()); return a; }
template <typename T> void inputArr(v<T> &arr, i64 sz) { forn(i,sz) arr.push_back(input()); }
template <typename T> v<T> sorted_copy(v<T> arr) { sort(all(arr)); return arr; }
template <typename T> v<T> compressed_copy(v<T> arr, const bool &autosort=true) { compress(arr, autosort); return arr; }

enum Null{} null;
istream& operator>>(istream& i, const Null&) { return i; }
ostream& operator<<(ostream& i, const Null&) { return i; }
template <typename T> bool isNull() { return typeid(T)==typeid(Null); }
template <typename T> bool isNull(T) { return typeid(T)==typeid(Null); }

template <class A, class B=Null, class C=Null, class D=Null, class E=Null, class F=Null, class G=Null>
void input(A &a, B &b=null, C &c=null, D &d=null, E &e=null, F &f=null, G &g=null) {
    if(typeid(g)!=typeid(null)) cin >> a >> b >> c >> d >> e >> f >> g;
    else if(typeid(f)!=typeid(null)) cin >> a >> b >> c >> d >> e >> f;
    else if(typeid(e)!=typeid(null)) cin >> a >> b >> c >> d >> e;
    else if(typeid(d)!=typeid(null)) cin >> a >> b >> c >> d;
    else if(typeid(c)!=typeid(null)) cin >> a >> b >> c;
    else if(typeid(b)!=typeid(null)) cin >> a >> b;
    else cin >> a;
}

template <class A=Null, class B=Null, class C=Null, class D=Null, class E=Null, class F=Null, class G=Null, class H=Null, class I=Null, class J=Null>
void print(A a=null, B b=null, C c=null, D d=null, E e=null, F f=null, G g=null, H h=null, I i=null, J j=null) {
    if(typeid(j)!=typeid(null)) cout << a << b << c << d << e << f << h << i << j;
    else if(typeid(i)!=typeid(null)) cout << a << b << c << d << e << f << h << i;
    else if(typeid(h)!=typeid(null)) cout << a << b << c << d << e << f << h;
    else if(typeid(g)!=typeid(null)) cout << a << b << c << d << e << f << g;
    else if(typeid(f)!=typeid(null)) cout << a << b << c << d << e << f;
    else if(typeid(e)!=typeid(null)) cout << a << b << c << d << e;
    else if(typeid(d)!=typeid(null)) cout << a << b << c << d;
    else if(typeid(c)!=typeid(null)) cout << a << b << c;
    else if(typeid(b)!=typeid(null)) cout << a << b;
    else cout << a;
}
template <class A=Null, class B=Null, class C=Null, class D=Null, class E=Null, class F=Null, class G=Null, class H=Null, class I=Null, class J=Null>
void println(A a=null, B b=null, C c=null, D d=null, E e=null, F f=null, G g=null, H h=null, I i=null, J j=null) {
    print(a, b, c, d, e, f, g, h, i, j); cout << '\n';
}
//@formatter:on
#pragma endregion

// 디지털 비디오 디스크(DVDs)
// #segtree

class segtree_ {
#define MID ((start+end)/2)
public:
    class T {
    public:
        i64 mx = -1, mn = INF;
        T()=default;
        explicit T(int v) : mx(v), mn(v) {}
        explicit T(int x, int nn) : mx(x), mn(nn) {}
        T operator+(const T &t2) const { return T(max(mx, t2.mx), min(mn, t2.mn)); }
        T operator+(const int &i) const { return T(max(mx, i), min(mn, i)); }
        void operator+=(const T &i) { mx = max(mx, i.mx); mn = min(mn, i.mn); }
        void operator+=(const int &i) { mx = max(mx, i); mn = min(mn, i); }
        T& operator=(cint i) { mx = mn = i; return *this; }
        T& operator=(const T &i) = default;
    };
    vector<T> tree;
    int n;
    explicit segtree_(int treeSize, bool inputInit = false) {
        n = treeSize;
        tree = v<T>(4*treeSize, T());
        if(inputInit) {
            v<int> a;
            forn(i, treeSize) a.push_back(input());
            init(a, 1, 1, n);
        }
    }
    explicit segtree_(const v<int> &a) : segtree_((int) a.size()) {
        init(a, 1, 1, n);
    }
    segtree_(const v<int> &a, int treeSize) : segtree_(treeSize) {
        init(a, 1, 1, n);
#if LOCAL
        assert(a.size() == treeSize);
#endif
    }
    void update(int tar, int diff) { update(tar, tar, diff); }
    T query_node(int tar) { return query(tar, tar); }
//    int query(int tar) { return query(tar, tar).val; }
    T query(int left, int right) { return query(1, left, right, 1, n); }
protected:
    void update(int left, int right, int diff) { update(1, left, right, 1, n, diff); }
    T init(const v<int> &a, int node, int start, int end) {
        if (start == end) return tree[node] = a[start - 1];
        return tree[node] = init(a, node * 2, start, MID) +
                            init(a, node * 2 + 1, MID + 1, end);
    }
    void update(int node, int left, int right, int start, int end, int diff) {
        if(end<left || right < start) return;
        if(left <= start && end <= right) { tree[node] = diff; return; }
        update(node*2, left, right, start, MID, diff);
        update(node*2+1, left, right, MID+1, end, diff);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    T query(int node, int left, int right, int start, int end) {
        if(right < start || end < left) return {};
        if(left <= start && end <= right) return tree[node];
        return query(node*2, left, right, start, MID) +
               query(node*2+1, left, right, MID+1, end);
    }
};

i32 main() {
    fastio;
    i32 T = input<i32>();
    while(T--) {
        i64 n, k; cin >> n >> k;
        v<i64> arr(n);
        forf(i, 0, n-1) arr[i]=i;
        segtree_ seg(arr, n);
        forn(i, k) {
            i64 q, a, b;
            input(q, a, b);
            if(q) {
                auto t = seg.query(a+1, b+1);
                if(t.mx==b && t.mn==a) println("YES");
                else println("NO");
            } else {
                int temp = seg.query_node(a+1).mx;
                seg.update(a+1, seg.query_node(b+1).mx);
                seg.update(b+1, temp);
            }
        }
    }
}
