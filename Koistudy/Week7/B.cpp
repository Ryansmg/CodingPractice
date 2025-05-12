#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int cur) {
    visited[cur] = true;
    cout << cur << " ";
    for(int i : adj[cur])
        if(!visited[i]) dfs(i);
}

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
    dfs(1);
}
