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

// 11377. 열혈강호 3
// #flow

signed main() {
    fastio;
    int n, m, k; cin >> n >> m >> k;
    // source : 0, sink = 2010
	// 일2명직원노드 = 2011
    // 직원 : 1 ~ 1000
    // 일 : 1001 ~ 2000

    v<v<int>> con(2024, v<int>());
    v<int> temp(2024, 0), visited(2024);
    v<v<int>> capacity(2024, temp); // 최대 유량
    v<v<int>> flow(2024, temp); // 현재 유량
	int maxFlow = 0, source = 0, sink = 2010;
	capacity[0][2011] = k;
	con[0].push_back(2011);
	con[2011].push_back(0);
    forf(i, 1, m) {
        capacity[i + 1000][sink] = 1;
        con[i+1000].push_back(sink);
        con[sink].push_back(i+1000);
    }
    forf(i, 1, n) {
        int z = input();
        capacity[0][i] = 1;
		capacity[2011][i] = 1;
	    con[i].push_back(0);
        con[0].push_back(i);
	    con[2011].push_back(i);
	    con[i].push_back(2011);
        forn(j, z) {
            int t = input();
            capacity[i][t+1000] = 1;
            con[i].push_back(t+1000);
            con[t+1000].push_back(i);
        }
    }

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
        // 모든 증가 경로를 찾은 경우
        if(visited[sink] == -1) break;

        // 백트래킹으로 최대 유량 확인
        int tempFlow = INF;
        for(int i = sink; i != source; i = visited[i])
            tempFlow = min(tempFlow, capacity[visited[i]][i] - flow[visited[i]][i]);

        // 유량 증가 & 유령 간선 만들기
        for(int i = sink; i != source; i = visited[i]) {
            flow[visited[i]][i] += tempFlow;
            flow[i][visited[i]] -= tempFlow;
        }

        maxFlow += tempFlow;
    }
    cout << maxFlow;
}
