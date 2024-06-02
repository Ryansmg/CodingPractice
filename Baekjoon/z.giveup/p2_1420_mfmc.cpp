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

// 1420. 학교 가지마!
// #mfmc

signed main() {
    fastio;
    int n, m; cin >> n >> m;
	v<string> city;
	ii source, sink;
	forn(i, n) {
		city.push_back(input<string>());
		forn(j, m) {
			if(city[i][j]=='K') source = {i, j};
			if(city[i][j]=='H') sink = {i, j};
		}
	}
	v2<array<int, 4>> capacity(n, v<array<int, 4>>(m, {1,1,1,1}));
	v2<array<int, 4>> flow(n, v<array<int, 4>>(m, {0,0,0,0}));
	ii visF = {-1, -1};
	v2<ii> visited(n, v<ii>(m, visF));
	v2<int> vis2(n, v<int>(m, -1));

	int maxFlow = 0;
	const int dx[] = {0, -1, 0, 1};
	const int dy[] = {-1, 0, 1, 0};
	bool check = true;
    while(true) {
		for(auto &v : visited)
            fill(all(v), visF);
        queue<ii> bfs;
        bfs.push(source);
        while(!bfs.empty()) {
            ii cur = bfs.front(); bfs.pop();
            forn(i, 4) {
				if(cur[0]+dy[i]<0 || cur[0]+dy[i]>=n || cur[1]+dx[i]<0 || cur[1]+dx[i]>=m) continue;
				if(check && city[cur[0]+dy[i]][cur[1]+dx[i]]=='H') {
					cout << -1; return 0;
				}
				if(city[cur[0]+dy[i]][cur[1]+dx[i]]=='#') continue;
                if(capacity[cur[0]][cur[1]][i] - flow[cur[0]][cur[1]][i] > 0
					&& visited[cur[0]+dy[i]][cur[1]+dx[i]] == visF) {
                    bfs.push({cur[0]+dy[i], cur[1]+dx[i]});
                    visited[cur[0]+dy[i]][cur[1]+dx[i]] = cur;
					vis2[cur[0]+dy[i]][cur[1]+dx[i]] = i;
					ii nxt = {cur[0]+dy[i], cur[1]+dx[i]};
                    if(nxt == sink) break;
                }
            }
			check = false;
            if(visited[sink[0]][sink[1]] != visF) break;
        }
        if(visited[sink[0]][sink[1]] == visF) break;

        for(ii i = sink; i != source; i = visited[i[0]][i[1]]) {
			ii j = visited[i[0]][i[1]];
			int vis2i = vis2[i[0]][i[1]];
            flow[j[0]][j[1]][vis2i]++;
            flow[i[0]][i[1]][(vis2i+2)%4]--;
        }

        maxFlow++;
    }
    cout << maxFlow;
}
