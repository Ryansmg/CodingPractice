#pragma region macros
#define USE_MACROS true
#define USE_INT false
#define USE_INT128 true
#define USE_DOUBLE false
#define GCC_OPTIMIZE_ENABLE false
#if USE_MACROS
#include <bits/stdc++.h>
#if GCC_OPTIMIZE_ENABLE
// #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#if !USE_INT
#define int long long // set USE_INT to true to disable
#endif
#if !USE_DOUBLE
#define double long double // set USE_DOUBLE to true to disable
#endif
#define llmax 9223372036854775807 // 2^63-1
#if USE_INT
#define intmax 2147483647
#else
#define intmax llmax
#endif
#define INF 1000000000000000000 // INF * INF > 2^63
#define inf 3000000000 // inf > 2^31, inf * inf < 2^63
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr) // enables fast input/output
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin) // stdin <- Coding/Baekjoon/input.txt
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout) // stdout <- Coding/Baekjoon/output.txt
#define all(vec) (vec).begin(), (vec).end()
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)
#define pass print("") // do nothing

using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

#if USE_INT128
#define lint __int128 // to disable lint, set USE_INT128 to false
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
#endif

template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T input() {T t; cin >> t; return t;} // explicit type, input<TYPE>()
int input() { int t; cin >> t; return t;} // default type : int
template <typename T> void print(const T &i, const string& end="") { cout << i << end; }
template <typename T> T pow_(T a, T b) { return pow_(a, b, intmax); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
#endif
#pragma endregion

// 17474. 수열과 쿼리 26
// #lazyprop (세그비츠)


struct Node {
    int mx, mx2, mxcnt, sum;
    Node()=default;
    Node(int a, int b, int c, int d) : mx(a), mx2(b), mxcnt(c), sum(d){};
};
class segbeats {
public:
    explicit segbeats(int treeSize) {
        lazy = tree = v<Node>(4*treeSize);
        n = treeSize;
    }
    explicit segbeats(const v<int> &a) : segbeats((int)a.size()) {
        init(a, 1, 1, n);
    }
    segbeats(const v<int> &a, int treeSize) : segbeats(treeSize) {
        init(a, 1, 1, n);
        assert(a.size() == treeSize);
    }
    void update(int tar, int diff) { update(tar, tar, diff); }
    void update(int left, int right, int diff) { update(1, left, right, 1, n, diff); }
    Node query(int left, int right) { return query(1, left, right, 1, n); }
    int query_sum(int left, int right) { return query_sum(1, left, right, 1, n); }
    int query_max(int left, int right) { return query_max(1, left, right, 1, n); }
protected:
    vector<Node> tree, lazy;
    int n;
    void update_lazy(int node, int start, int end) {
        if(start==end) return;
        for(int i : {node*2, node*2+1}) {
            if(tree[node].mx < tree[i].mx) {
                tree[i].sum -= tree[i].mxcnt * (tree[i].mx - tree[node].mx);
                tree[i].mx = tree[node].mx;
            }
        }
    }
    static Node merge_node(const Node &a, const Node &b) {
        Node ret(a.mx, a.mx2, a.mxcnt, a.sum + b.sum);
        if(ret.mx == b.mx) ret.mxcnt += b.mxcnt;
        for(const int &i : {b.mx, b.mx2}) {
            if(ret.mx < i) {
                ret.mx2 = ret.mx;
                ret.mx = i;
                ret.mxcnt = b.mxcnt;
            } else if (ret.mx > i && ret.mx2 < i) {
                ret.mx2 = i;
            }
        }
        return ret;
    }
    void init(const v<int> &a, int node, int start, int end) {
        if(start==end) {
            tree[node] = {a[start-1], -1, 1, a[start-1]};
        } else {
            init(a, node*2, start, (start+end)/2);
            init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = merge_node(tree[node*2], tree[node*2+1]);
        }
    }
    void update(int node, int left, int right, int start, int end, int diff) {
        update_lazy(node, start, end);
        if((end<left || right < start) || tree[node].mx <= diff) return;
        if(left <= start && end <= right && tree[node].mx2 < diff) {
            tree[node].sum -= tree[node].mxcnt * (tree[node].mx - diff);
            tree[node].mx = diff;
            update_lazy(node, start, end);
            return;
        }
        update(node*2, left, right, start, (start+end)/2, diff);
        update(node*2+1, left, right, (start+end)/2+1, end, diff);
        tree[node] = merge_node(tree[node*2], tree[node*2+1]);
    }
    Node query(int node, int left, int right, int start, int end) {
        update_lazy(node, start, end);
        if(right < start || end < left) return {-1, -1, -1, 0};
        if(left <= start && end <= right) return tree[node];
        return merge_node(query(node*2, left, right, start, (start+end)/2),
               query(node*2+1, left, right, (start+end)/2+1, end));
    }
    int query_sum(int node, int left, int right, int start, int end) {
        update_lazy(node, start, end);
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return tree[node].sum;
        return query_sum(node*2, left, right, start, (start+end)/2) +
                          query_sum(node*2+1, left, right, (start+end)/2+1, end);
    }
    int query_max(int node, int left, int right, int start, int end) {
        update_lazy(node, start, end);
        if(right < start || end < left) return -1;
        if(left <= start && end <= right) return tree[node].mx;
        return max(query_max(node*2, left, right, start, (start+end)/2),
               query_max(node*2+1, left, right, (start+end)/2+1, end));
    }
};

signed main() {
    fastio;
    int n = input();
    v<int> a;
    forn(i, n) a.push_back(input());
    segbeats lp(a, n);
    int m = input();
    forn(q, m) {
        int qtype = input(), l, r, x;
        if(qtype == 1) {
            cin >> l >> r >> x;
            lp.update(l, r, x);
        }
        else if(qtype == 2) {
            cin >> l >> r;
            cout << lp.query_max(l, r) << '\n';
        } else {
            cin >> l >> r;
            cout << lp.query_sum(l, r) << '\n';
        }
    }
}
