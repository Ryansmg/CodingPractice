#pragma region macros
#define GCC_OPTIMIZE_ENABLE false

#include <bits/stdc++.h>
using namespace std;

#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif

#define int long long
#define double long double
#define cint const int &

#define llmax 9223372036854775807 // 2^63-1
#define INF 1000000000000000000 // INF * INF > 2^63
#define inf 3000000000 // inf > 2^31, inf * inf < 2^63
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)

#define pass {cout << "";} // do nothing
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)

template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

#ifndef int
#define intmax 2147483647
#else
#define intmax llmax
#endif

#pragma region lint
#define lint __int128
#define ll long long
lint LINTMAX = ((lint(1)<<126)-1)*2+1;
string lint2str(const lint &i) {string ret,bs;if(i==-LINTMAX-1)return lint2str(i/10)+"8";if(!i)return "0";if(i<0)return "-"+lint2str(-i);
	lint t=1; forn(as, 18)t*=10;lint a=i/(t*t);if(a){ret += to_string((ll) a);bs = to_string((ll) (i / t % (t * 10) + t));
		forn(j, 18) ret += bs[j + 1];bs = to_string((ll) ((i % t) + t));forn(j, 18) ret += bs[j + 1];
	} else {lint b = i / t % (t * 10);if (b) {ret += to_string((ll) b);bs = to_string((ll) ((i % t) + t));
			forn(j, 18) ret += bs[j + 1];} else { ret += to_string((ll) (i % t)); }}return ret;}
istream &operator>>(istream &in, lint &l) {string s;in>>s;lint t=l=0,size=s.size(),k=1;if(s[0]=='-')t=1;
	for(lint i=size-1;i>=t;i--){if(!t)l+=(s[i]-'0')*k;else l-=(s[i]-'0')*k;k*=10;}return in;}
ostream &operator<<(ostream &out,const lint &i){ out << lint2str(i); return out; }
#pragma endregion

template <typename T = int> T input() {T t; cin >> t; return t;}

#define all(vec) (vec).begin(), (vec).end()
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

template <typename T> T pow_(T a, T b) { return pow_(a, b, intmax); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
#pragma endregion
const int mod = 1e9+7;

// 13925. 수열과 쿼리 13
// #lazyprop

class lazyprop {
public:
    class L {
    public:
        int plus = 0, times = 1;
        L()=default;
        explicit L(int p, int t) : plus(p%mod), times(t%mod) {}
        void operator+=(const L &i) {
            times *= i.times; plus *= i.times; plus += i.plus;
            times %= mod; plus %= mod;
        }
        L operator*(cint i) const { return L(plus*i, times); }
        void operator*=(const int &i) { plus *= i; plus %= mod; }
        L& operator=(const L &i) = default;
    };
    class T {
    public:
        int val = 0;
        T()=default;
        explicit T(int v) : val(v%mod) {}
        T operator+(const T &t2) const { return T(val + t2.val); }
        void operator+=(const T &i) { val += i.val; val %= mod; }
        T& operator=(cint i) { val = i; return *this; }
        void operator+=(const L &i) { val *= i.times; val += i.plus; val %= mod; }
        T operator%(const int &i) const { return T(val%i); }
    };
protected:
    v<T> tree; v<L> lazy;
    int n;
    void update_lazy(int node, int start, int end) {
        tree[node] += lazy[node] * (end-start+1);
        if(start!=end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = {};
    }
public:
    explicit lazyprop(int treeSize, bool inputInit = false) {
        lazy = v<L>(4*treeSize, L());
        tree = v<T>(4*treeSize, T());
        n = treeSize;
        if(inputInit) {
            v<int> a; forn(i, n) a.push_back(input()%mod);
            init(a, 1, 1, n);
        }
    }
    explicit lazyprop(const v<int> &a) : lazyprop((int) a.size()) {
        init(a, 1, 1, n);
    }
    lazyprop(const v<int> &a, int treeSize) : lazyprop(treeSize) {
        init(a, 1, 1, n);
        assert(a.size() == treeSize);
    }
    void update(int left, int right, L diff) { update(1, left, right, 1, n, diff); }
    T query(int tar) { return query(tar, tar); }
    T query(int left, int right) { return query(1, left, right, 1, n); }
protected:
    void init(const v<int> &a, int node, int start, int end) {
        if(start==end) {
            tree[node] = a[start-1];
        } else {
            init(a, node*2, start, (start+end)/2);
            init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }
    void update(int node, int left, int right, int start, int end, L diff) {
        update_lazy(node, start, end);
        if(end<left || right < start) return;
        if(left <= start && end <= right) {
            tree[node] += diff * (end-start+1);
            if(start!=end) {
                lazy[node*2] += diff;
                lazy[node*2+1] += diff;
            }
            return;
        }
        update(node*2, left, right, start, (start+end)/2, diff);
        update(node*2+1, left, right, (start+end)/2+1, end, diff);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    T query(int node, int left, int right, int start, int end) {
        update_lazy(node, start, end);
        if(right < start || end < left) return {};
        if(left <= start && end <= right) return tree[node];
        return (query(node*2, left, right, start, (start+end)/2) +
               query(node*2+1, left, right, (start+end)/2+1, end)) % mod;
    }
};

signed main() {
    fastio;
    int n = input();
    lazyprop lp(n, true);
    int m = input();
    forn(i, m) {
        int t, x, y; cin >> t >> x >> y;
        if(t==1) lp.update(x, y, lazyprop::L(input(), 1));
        if(t==2) lp.update(x, y, lazyprop::L(0, input()));
        if(t==3) lp.update(x, y, lazyprop::L(input(), 0));
        if(t==4) cout << lp.query(x, y).val%mod << '\n';
    }
}
