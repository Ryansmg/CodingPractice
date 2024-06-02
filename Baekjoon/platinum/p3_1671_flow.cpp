#define USE_MACROS true
#define USE_INT false
#define USE_INT128 true
#define USE_DOUBLE false
#define GCC_OPTIMIZE_ENABLE false
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

template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T input() {T t; cin >> t; return t;} // explicit type, input<TYPE>()
int input() { int t; cin >> t; return t;} // default type : int
template <typename T> void print(const T &i, const string& end="") { cout << i << end; }
template <typename T> T pow_(T a, T b) { return pow_(a, b, intmax); }
template <typename T> T pow_(T a, T b, T mod) { a%=mod;T ans=1;while(b){if(b&1)ans=ans*a%mod;b>>=1;a=a*a%mod;} return ans; }
template <typename T> T gcd_(T a, T b) { if(a<b) swap(a, b); while(b) { T r = a % b; a = b; b = r; } return a; }
#if USE_INT128
#define lint __int128 // set USE_INT128 to false to disable
#define ll long long
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winteger-overflow"
lint LINTMAX = (lint(1)<<127)-1;
#pragma clang diagnostic pop
lint linput() { return (lint) input<long long>(); }
void print(const lint &i, const string& end="") {
    if(i==-LINTMAX-1){print(i/10);cout<<'8'<<end;return;}if(!i)cout<<'0';if(i<0){cout<<'-';print(-i);}if(i<=0){cout<<end;return;}
    lint t=1;forn(as,18)t*=10;string bs;lint a=i/(t*t);if(a){cout<<(ll)a;bs=to_string((ll)(i/t%(t*10)+t));forn(j,18)cout<<bs[j+1];
    bs=to_string((ll)((i%t)+t));forn(j,18)cout<<bs[j+1];}else{lint b=i/t%(t*10);if(b){cout<<(ll)b;bs=to_string((ll)((i%t)+t));
    forn(j,18)cout<<bs[j+1];}else{cout<<(ll)(i%t);}}cout<<end;}
#endif
#endif
#pragma endregion

// 1671. 상어의 저녁식사
// #flow

signed main() {
	fastio;
	int n = input();
	// source : 0, sink = 111
	// 먹는 상어 : 1~50
	// 먹히는 상어 : 51~100

	//입력 받기
	v<v<int>> con(123, v<int>());
	v<int> temp(123, 0), visited(123);
	v<v<int>> capacity(123, temp); // 최대 유량
	v<v<int>> flow(123, temp); // 현재 유량

	v<iii> sharks(1, {-1, -1, -1});
	forn(i, n) sharks.push_back({input(), input(), input()});

	forf(i, 1, n) {
		capacity[0][i] = 2;
		con[0].push_back(i);
		con[i].push_back(0);
		capacity[i+50][111] = 1;
		con[i+50].push_back(111);
		con[111].push_back(i+50);
	}
	forf(i, 1, n) forf(j, i+1, n) {
		if(sharks[i][0] <= sharks[j][0] &&
				sharks[i][1] <= sharks[j][1] &&
				sharks[i][2] <= sharks[j][2]) {
			capacity[j][i+50] = 1;
			con[j].push_back(i+50);
			con[i+50].push_back(j);
		} else if(sharks[j][0] <= sharks[i][0] &&
		          sharks[j][1] <= sharks[i][1] &&
		          sharks[j][2] <= sharks[i][2]) {
			capacity[i][j + 50] = 1;
			con[i].push_back(j + 50);
			con[j + 50].push_back(i);
		}
	}

	int maxFlow = 0, source = 0, sink = 111;
	// 모든 증가 경로 구하기
	while(true) {
		fill(all(visited), -1);
		queue<int> bfs;
		bfs.push(source);
		while(!bfs.empty()) {
			int cur = bfs.front(); bfs.pop();
			for(int i : con[cur]) {
				if(capacity[cur][i] - flow[cur][i] > 0 && visited[i] == -1) {
					bfs.push(i);
					visited[i] = cur;
					if(i == sink) break;
				}
			}
			if(visited[sink] != -1) break;
		}
		if(visited[sink] == -1) break;

		int tempFlow = INF;
		for(int i = sink; i != source; i = visited[i])
			tempFlow = min(tempFlow, capacity[visited[i]][i] - flow[visited[i]][i]);

		for(int i = sink; i != source; i = visited[i]) {
			flow[visited[i]][i] += tempFlow;
			flow[i][visited[i]] -= tempFlow;
		}

		maxFlow += tempFlow;
	}
	cout << n - maxFlow;
}
