#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define inf 2147000000

//네트워크 복구

struct TRI { 
    int node, //정점 번호
    dist, //최단 거리
    preNode; //이전 노드
    TRI(int a, int b, int c) {
        node = a; dist = b; preNode = c;
    }
    TRI(){}
} typedef tri;

struct NP {
    int node, //정점 번호
    weight; //가중치
    NP(int a, int b) {
        node = a; weight = b;
    }
    NP(){}
} typedef npair;

struct cmp {
    bool operator() (tri a, tri b){
        return a.dist>b.dist;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; //컴퓨터의 개수
    int m; //회선의 개수
    cin >> n >> m;
    vector<vector<npair>> child(n+1); //[컴퓨터 번호] -> {<자식 번호, 가중치>}
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        child[a].emplace_back(b, c);
        child[b].emplace_back(a, c);
    }

    vector<pair<int, int>> recovered;

        priority_queue<tri, vector<tri>, cmp> pq;
        vector<int> dist(n+1, inf);
        dist[1] = 0;
        for(auto pair : child[1]) {
            pq.emplace(pair.node, pair.weight, 1);
        }

        while(!pq.empty()) 
        {
            tri top = pq.top(); pq.pop();
            if(dist[top.node] != inf) continue;
            dist[top.node] = top.dist;
            recovered.push_back({top.preNode, top.node});
            
            for(auto pair : child[top.node]) 
            {
                if(dist[pair.node] <= top.dist + pair.weight) continue;
                pq.emplace(pair.node, top.dist + pair.weight, top.node);
            }
        }
    

    cout << recovered.size() << "\n";
    for(auto s : recovered) cout << s.first << " " << s.second << "\n";
}
