#include <iostream>
#include <vector>
#include <stack>
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
    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        reverse(adj[i].begin(), adj[i].end());
    }

    stack<int> dfs;
    dfs.push(1);
    while(!dfs.empty()) {
        int cur = dfs.top(); dfs.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        cout << cur << " ";
        for(int i : adj[cur]) {
            if(visited[i]) continue;
            dfs.push(i);
        }
    }
}
