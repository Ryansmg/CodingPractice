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

// 13546. 수열과 쿼리 0
// #mo #sqrt_decomposition

i64 sqrtSize;
struct query {
    i64 l, r, x;
    bool operator<(const query& other) const {
        if(l/sqrtSize == other.l/sqrtSize)
            return r/sqrtSize < other.r/sqrtSize;
        return l/sqrtSize < other.l/sqrtSize;
    }
};

class sqrtArray {
    int n, sq;
    v<int> arr, bucket;
public:
    explicit sqrtArray(int size, int bucketSize=-1) :
            n(size), sq(bucketSize==-1?(int)sqrt(size):bucketSize){
        arr = v<int>(n+1,0);
        bucket = v<int>(n/sq+2,0);
    }
    void add(int pos, int val) {
        if(!pos) return;
        bucket[pos/sq] += val;
        arr[pos] += val;
    }
    int query() {
        forr(i, n/sq+1, 0) {
            if(bucket[i]) {
                forr(j, i*sq+sq-1, i*sq) {
                    if(j > n) continue;
                    if(arr[j]) return j;
                }
            }
        }
        return 0;
    }
};

i32 main() {
    fastio;
    i64 n, k; in(n);
    vl arr(1, 100001); rep(n) arr.emplace_back(in());
    forf(i, 1, arr.size()-1) arr[i] += arr[i-1];
    sqrtSize = sqrt(n);
    i64 m = in();
    v<query> queries;
    vl ans(m);
    forn(i, m) { i64 a, b; in(a, b); queries.eb(a-1, b, i); }
    sort(queries);
    v<deque<i64>> indDqs(200002, deque<i64>());
    sqrtArray sq(200002);

    auto sub = [&](i64 i) -> i64{
        if(indDqs[arr[i]].empty()) return 0;
        return indDqs[arr[i]].back() - indDqs[arr[i]].front();
    };

    forf(i, queries[0].l, queries[0].r) {
        sq.add(sub(i), -1);
        indDqs[arr[i]].eb(i);
        sq.add(sub(i), 1);
        ans[queries[0].x] = sq.query();
    }
    auto [l, r, _] = queries[0];

    forf(i, 1, m-1) {
        auto [nl, nr, x] = queries[i];
        while(l > nl) {
            l--;
            sq.add(sub(l), -1);
            indDqs[arr[l]].ef(l);
            sq.add(sub(l), 1);
        }
        while(r < nr) {
            r++;
            sq.add(sub(r), -1);
            indDqs[arr[r]].eb(r);
            sq.add(sub(r), 1);
        }
        while(l < nl) {
            assert(indDqs[arr[l]].front() == l);
            sq.add(sub(l), -1);
            indDqs[arr[l]].pop_front();
            sq.add(sub(l), 1);
            l++;
        }
        while(r > nr) {
            assert(indDqs[arr[r]].back() == r);
            sq.add(sub(r), -1);
            indDqs[arr[r]].pop_back();
            sq.add(sub(r), 1);
            r--;
        }
        ans[x] = sq.query();
    }
    printArr(ans, "\n");
}
