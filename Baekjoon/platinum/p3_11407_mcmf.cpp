#pragma region macros
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define int long long
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr) // enables fast input/output
#define all(vec) (vec).begin(), (vec).end()
#define forn(name, val) for(int name = 0; name < val; name++)
using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
using ii = array<int, 2>;
int input() { int t; cin >> t; return t;}
#pragma endregion

// 11407. 책 구매하기 3
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
    v2<int> maxc(m, v<int>());
    forn(i, m) forn(j, n) maxc[i].push_back(input());
    forn(i, m) forn(j, n) {
		int cost = input();
		edges[i+1001].push_back({j+1, cost});
		edges[j+1].push_back({i+1001, -cost});
		capacity[i+1001][j+1] = maxc[i][j];
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
	cout << maxFlow << '\n' << distSum;
}
