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
class nd {
public:
    int lval, rval, val, allval;
    nd(int a, int b, int c, int d) : lval(a), rval(b), val(c), allval(d){}
};
class goldmineSeg {
    vector<nd> tree;
    int n;
public:
    explicit goldmineSeg(const int &treeSize) {
        tree = v<nd>(4*treeSize, {0, 0, 0, 0});
        n = treeSize;
    }
    explicit goldmineSeg(const v<int> &a) : goldmineSeg((int) a.size()) {
        init(a, 1, 1, n);
    }
    goldmineSeg(const v<int> &a, const int &treeSize) : goldmineSeg(treeSize) {
        assert(a.size() == treeSize);
        init(a, 1, 1, n);
    }
    void update(const int &tar, const int &diff) { update(1, 1, n, tar, diff); }
    nd query(const int &left, const int &right) { return query(1, 1, n, left, right); }
protected:
    void init(const vector<int> &a, int node, int start, int end) {
        if(start==end) {
            tree[node] = {a[start-1], a[start-1], a[start-1], a[start-1]};
        } else {
            init(a, node*2, start, (start+end)/2);
            init(a, node*2+1, (start+end)/2+1, end);
            tree[node] = {0,0,0,0};
            tree[node].lval = max(tree[node*2].lval, tree[node*2].allval + tree[node*2+1].lval);
            tree[node].rval = max(tree[node*2+1].rval, tree[node*2+1].allval + tree[node*2].rval);
            tree[node].val = max(max(tree[node*2].val, tree[node*2+1].val), tree[node*2].rval + tree[node*2+1].lval);
            tree[node].allval = tree[node*2].allval + tree[node*2+1].allval;
        }
    }
    void update(int node, int start, int end, const int &index, const int &diff) {
        if(index<start || end<index) return;
        if(start==end) {
            tree[node].lval += diff;
            tree[node].rval += diff;
            tree[node].val += diff;
            tree[node].allval += diff;
        } else {
            update(node*2, start, (start+end)/2, index, diff);
            update(node*2+1, (start+end)/2+1, end, index, diff);
            tree[node] = {0,0,0,0};
            tree[node].lval = max(tree[node*2].lval, tree[node*2].allval + tree[node*2+1].lval);
            tree[node].rval = max(tree[node*2+1].rval, tree[node*2+1].allval + tree[node*2].rval);
            tree[node].val = max(max(tree[node*2].val, tree[node*2+1].val), tree[node*2].rval + tree[node*2+1].lval);
            tree[node].allval = tree[node*2].allval + tree[node*2+1].allval;
        }
    }
    nd query(int node, int start, int end, const int &left, const int &right) {
        if(end < left || right < start) return {0, -inf, -inf, -inf};
        if(left <= start && end <= right) return tree[node];
        nd f = query(node*2, start, (start+end)/2, left, right);
        nd s = query(node*2+1, (start+end)/2+1, end, left, right);
        nd c = {0, 0, 0, 0};
        c.lval = max(f.lval, f.allval + s.lval);
        c.rval = max(s.rval, s.allval + f.rval);
        c.val = max(max(f.val, s.val), f.rval + s.lval);
        c.allval = f.allval + s.allval;
        return c;
    }

};

// #10167. 금광
// #coordinate_compression #sweeping #segtree

signed main() {
    fastio;
    v<int> compx, compy;
    int n = input(), a, b, c;
    v<iii> tmines;
    forn(i, n) {
        cin >> a >> b >> c;
        tmines.push_back({a, b, c});
        compx.push_back(a);
        compy.push_back(b);
    }
    compress(compx); compress(compy);
    int xsz = (int) compx.size(), ysz = (int) compy.size();
    v2<ii> mines(ysz, v<ii>());
    for(iii mine : tmines)
        mines[idx(mine[1], compy)].push_back({idx(mine[0], compx)+1, mine[2]});
    int ans = 0;
    forn(st, ysz) {
        goldmineSeg gms(xsz);
        forf(i, st, ysz-1) {
            for(ii mine : mines[i])
                gms.update(mine[0], mine[1]);
            ans = max(ans, gms.query(1, xsz).val);
        }
    }
    cout << ans;
}
