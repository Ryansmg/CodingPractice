#include <iostream>
#include <queue>
#include <vector>
#define inf 2147000000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> child(n+1);
    for(int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        child[a].push_back(b);
        child[b].push_back(a);
    }
    vector<int> parent(n+1, inf); //target, parent
    queue<pair<int, int>> q;
    q.emplace(1, 1);
    while(!q.empty()) 
    {
        auto f = q.front(); q.pop();
        if(parent[f.first] != inf) continue;
        parent[f.first] = f.second;
        for(int c : child[f.first]) {
            if(parent[c]!=inf) continue;
            q.emplace(c, f.first);
        }
    }
    for(int i=2; i<=n; i++)
    cout << parent[i] << "\n";
}