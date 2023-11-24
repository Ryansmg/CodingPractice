#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define inf 2140000000

//최단경로

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int v; //정점의 개수
    int e; //간선의 개수
    int k; //시작 정점
    cin >> v >> e >> k;
    vector<vector<pair<int, int>>> child(v+1); //[노드 번호] => <자식 노드, 가중치>
    for(int i=0; i<e; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        child[a].emplace_back(b, c);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; //자식 노드, 최단거리
    vector<bool> visited(v+1, false);
    vector<int> dis(v+1, inf); //[노드 번호] => 최단거리
    dis[k] = 0; visited[k] = true;
    for(auto pair : child[k]) {
        pq.push(pair);
        dis[pair.first] = min(pair.second, dis[pair.first]);
    }
    
    while(!pq.empty())
    {
        auto top = pq.top(); pq.pop();
        if(visited[top.first]) continue;
        visited[top.first] = true;
        for(auto pair : child[top.first]) {
            if(dis[pair.first] <= top.second + pair.second) continue;
            dis[pair.first] = top.second + pair.second;
            pq.emplace(pair.first, dis[pair.first]);
        }
    }

    for(int i=1; i<=v; i++) {
        if(dis[i] == inf) cout << "INF\n";
        else cout << dis[i] << "\n";
    }
}