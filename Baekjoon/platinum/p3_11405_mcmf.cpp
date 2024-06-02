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

// 11405. 책 구매하기
// #mcmf #flow

signed main() {
	fastio;
	int n, m; // 사람의 수, 서점의 수
	cin >> n >> m;
	int source = 0, sink = 1111; //사람 1~100, 서점 1001~1100
	v2<ii> edges(1420, v<ii>()); // [출발 노드] {도착 노드, 비용}
	v2<int> capacity(1420, v<int>(1420, 0)),
	flow(1420, v<int>(1420, 0));
	forn(i, n) {
		capacity[i+1][sink] = input();
		edges[sink].push_back({i + 1, 0});
		edges[i+1].push_back({sink, 0});
	}
	forn(i, m) {
		capacity[source][i+1001] = input();
		edges[i+1001].push_back({source, 0});
		edges[source].push_back({i + 1001, 0});
	}
	forn(i, m) forn(j, n) {
		int cost = input();
		edges[i+1001].push_back({j+1, cost});
		edges[j+1].push_back({i+1001, -cost});
		capacity[i+1001][j+1] = INF;
	}
	int maxFlow = 0; int distSum = 0;

	while(true) {
		v<int> dist(1420, INF), pre(1420, -1);
		bool inQueue[1420] = {false};
		int cycle[1420] = {0};
		queue<int> spfa;
		spfa.push(source);
		dist[source] = 0;
		while(!spfa.empty()) {
			int front = spfa.front(); spfa.pop();
			inQueue[front] = false;
			cycle[front]++;
			if(cycle[front] >= n+m+2)
				assert(false); // 음수 사이클이 존재
			for(auto edge : edges[front]) {
				if(capacity[front][edge[0]] - flow[front][edge[0]] > 0 &&
					dist[edge[0]] > dist[front] + edge[1]) {
					dist[edge[0]] = dist[front] + edge[1];
					pre[edge[0]] = front;
					if(!inQueue[edge[0]]) {
						spfa.push(edge[0]);
						inQueue[edge[0]] = true;
					}
				}
			}
		}
		if(pre[sink] == -1) break;

		int tempFlow = INF;
		for(int i = sink; i != source; i = pre[i])
			tempFlow = min(tempFlow, capacity[pre[i]][i] - flow[pre[i]][i]);

		for(int i = sink; i != source; i = pre[i]) {
			flow[pre[i]][i] += tempFlow;
			flow[i][pre[i]] -= tempFlow;
		}
		maxFlow += tempFlow;
		distSum += dist[sink] * tempFlow;
	}
	cout << distSum;
}
