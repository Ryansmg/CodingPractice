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

// 수열과 쿼리 15
// #segtree

class segtree_ {
#define MID ((start+end)/2)
public:
    class T {
    public:
        int val = 0, idx = -1;
        T()=default;
        explicit T(int v, int i) : val(v), idx(i) {}
        T operator+(const T &t2) const {
            if(val<t2.val) return T(val, idx);
            if(t2.val<val) return T(t2.val, t2.idx);
            return T(val, min(idx, t2.idx));
        }
        T& operator=(cint i) { val = i; return *this; }
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
        assert(a.size() == treeSize);
    }
    void update(int tar, int val) { update(tar, tar, val); }
    T query(int left, int right) { return query(1, left, right, 1, n); }
protected:
    void update(int left, int right, int diff) { update(1, left, right, 1, n, diff); }
    T init(const v<int> &a, int node, int start, int end) {
        if (start == end) return tree[node] = T(a[start - 1], start);
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

signed main() {
    fastio;
    int n = input();
    segtree_ seg(n, true);
    int m = input();
    forn(asdf, m) {
        int t = input();
        if(t==2) {
            cout << seg.query(1, n).idx << '\n';
        } else {
            int i, v; cin >> i >> v;
            seg.update(i, v);
        }
    }
}
