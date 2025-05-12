#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n+1); visited.resize(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());

    queue<int> bfs;
    bfs.push(1);
    visited[1] = true;

    while(!bfs.empty()) {
        int cur = bfs.front(); bfs.pop();
        cout << cur << " ";
        for(int i : adj[cur]) {
            if(visited[i]) continue;
            visited[i] = true;
            bfs.push(i);
        }
    }
}
