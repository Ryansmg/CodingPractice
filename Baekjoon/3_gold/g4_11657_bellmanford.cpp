#include <bits/stdc++.h>
#define int long long
#define INF 214748364700
using namespace std;

// 11657. 타임머신
// #bellman_ford

struct edge {
    int start, end, weight;
    edge(){}
    edge(int a, int b, int c) : start(a), end(b), weight(c) {};
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; //노드, 간선 개수
    cin >> n >> m;
    vector<int> dist(n+1, INF);
    dist[1] = 0;
    vector<edge> edges;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a,b,c);
    }
    //모든 간선을 체크하는 것을 n번 반복한다.
    //최단거리는 negative cycle이 없는 경우 최대 n-1개의 노드를 지남
    // => n번째에 갱신되는 값이 있으면 negative cycle 존재
    bool hasNegativeCycle = false;
    for(int i=0; i<n; i++) { 
        for(edge e : edges) {
            if(dist[e.start] == INF) continue;
            if(dist[e.end] > dist[e.start] + e.weight) {
                if(i==n-1) {
                    hasNegativeCycle = true;
                    break;
                }
                dist[e.end] = dist[e.start] + e.weight;
            }
        }
    }
    if(hasNegativeCycle) {
        cout << -1; return 0;
    }
    for(int i=2; i<=n; i++) {
        cout << (dist[i]==INF ? -1 : dist[i]) << "\n";
    }
}