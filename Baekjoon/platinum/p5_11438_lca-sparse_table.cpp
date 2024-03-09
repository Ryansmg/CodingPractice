//11438. LCA 2
//#lca #sparse_table
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> depth(n+1);
    vector<int> temp;
    vector<vector<int>> child(n+1);
    vector<int> parent(n+1, 0);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        child[a].emplace_back(b);
        child[b].emplace_back(a);
    }
    queue<int> bfs;
    int maxdepth = 1;
    bfs.push(1);
    depth[1] = 0;
    parent[1] = 1;
    while(!bfs.empty()) {
        int top = bfs.front(); bfs.pop();
        depth[top] = depth[parent[top]] + 1;
        maxdepth = max(depth[top], maxdepth);
        for(int i : child[top]) {
            if(parent[top] == i) continue;
            parent[i] = top;
            bfs.emplace(i);
        }
    }
    int tmplen = log2(maxdepth);
    vector<int> temp2(tmplen+1);
    vector<vector<int>> sparse(n+1, temp2); //[a][b] = a에서 2^b 이동 (부모 방향)
    for(int i=1; i<=n; i++) {
        sparse[i][0] = parent[i];
    }
    for(int i=1; i<=tmplen; i++) {
        for(int j=1; j<=n; j++) {
            sparse[j][i] = sparse[sparse[j][i-1]][i-1];
        }
    }
    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(depth[a] < depth[b]) swap(a, b);
        int depdiff = depth[a] - depth[b];
        while(depdiff != 0) {
            a = sparse[a][log2(depdiff)];
            depdiff = depth[a] - depth[b];
        }
        int d = tmplen;
        while(a != b) {
            while(sparse[a][d] == sparse[b][d] && d>0) d--;
            a = sparse[a][d];
            b = sparse[b][d];
        }
        cout << a << "\n";
    }
}
