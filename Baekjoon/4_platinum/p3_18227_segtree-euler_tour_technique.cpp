#define USE_MACROS true
#define USE_INT false
#define USE_INT128 true
#define USE_DOUBLE false
#define GCC_OPTIMIZE_ENABLE true
#pragma region macros
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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winteger-overflow"
lint LINTMAX = (lint(1)<<127)-1;
#pragma clang diagnostic pop
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

// 18227. 성대나라의 물탱크
// #segtree #euler_path_technique

void update(v<int> &tree, int node, int start, int end, const int &index, int val)
{
    if(index<start || end<index) return;
    if(start==end) {
        tree[node] += val;
    } else {
        update(tree, node*2, start, (start+end)/2, index, val);
        update(tree, node*2+1, (start+end)/2+1, end, index, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

int query(v<int> &tree, int node, int start, int end, const int &left, const int &right) {
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    return query(tree, node*2, start, (start+end)/2, left, right)
           + query(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int curEn = 0;
void dfs(int top, int d, v<bool> &visited, v<int> &en, v<ii> &range, v2<int> &con, v<int> &dist) {
    en[top] = ++curEn;
    dist[top] = d;
    for(int i : con[top]) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i, d+1, visited, en, range, con, dist);
    }
    range[top] = {en[top], curEn};
}

signed main() {
    fastio;
    int n, c; cin >> n >> c;
    v2<int> con(n+1, v<int>());
    v<int> en(n+1);
    v<ii> range(n+1);
    v<int> dist(n+1); // 수도까지의 거리 + 1
    forn(i, n-1) {
        int x, y; cin >> x >> y;
        con[x].push_back(y);
        con[y].push_back(x);
    }

    // dfs를 통해 부모 노드 - 자식 노드에 연속한 수를 부여, 자신 + 자식 노드의 수 범위를 저장
    v<bool> visited(n+1, false); visited[c] = true;
    dfs(c, 1, visited, en, range, con, dist);
    assert(curEn == n);

    // 쿼리 처리
    v<int> tree(4*n+10, 0);
    int q = input();
    forn(qi, q) {
        int type, a; cin >> type >> a;
        if(type == 1) { //update
            update(tree, 1, 1, n, en[a], 1);
        } else {
            cout << query(tree, 1, 1, n, range[a][0], range[a][1]) * dist[a] << '\n';
        }
    }
}
