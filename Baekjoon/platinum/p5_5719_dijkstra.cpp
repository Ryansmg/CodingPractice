#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#define ll long long
#define inf 9223372036854775800
using namespace std;

//거의 최단 경로

struct dbstr {
    ll node;
    ll dist;
    ll prenode;
    dbstr(){}
    dbstr(ll a, ll b, ll c) {
        node = a; dist = b; prenode = c;
    }
} typedef tri;

struct dbcmp {
    bool operator() (tri a, tri b){
        return a.dist > b.dist;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    vector<ll> ans;

    while(true){
        //input
        ll nodeN, edgeN; cin >> nodeN >> edgeN;
        if(nodeN==0 && edgeN==0) break;
        ll start, destination; cin >> start >> destination;
        vector<vector<pair<ll, ll>>> child(nodeN); //{<자식 노드, 가중치>}
        vector<vector<pair<ll, ll>>> parent(nodeN);
        for(ll i=0; i<edgeN; i++)
        {
            ll a, b, c; cin >> a >> b >> c;
            child[a].emplace_back(b, c);
            parent[b].emplace_back(a, c);
        }

        //dijkstra (remove minpath)
        priority_queue<tri, vector<tri>, dbcmp> pq;
        vector<ll> dist(nodeN, inf);
        vector<ll> prenode(nodeN, inf);
        pq.emplace(start, 0, -1);

        while(!pq.empty()) {
            tri top = pq.top(); pq.pop();
            if(dist[top.node] != inf) continue;
            dist[top.node] = top.dist;
            prenode[top.node] = top.prenode;
            for(auto pair : child[top.node]) {
                if(dist[pair.first] <= top.dist + pair.second) continue;
                pq.emplace(pair.first, top.dist + pair.second, top.node);
            }
        }

        //bfs로 최단경로 탐색 & 제거
        vector<bool> visited(nodeN, false);
        queue<pair<ll, ll>> q;
        q.emplace(destination, -1);

        while(!q.empty()) {
            auto front = q.front(); q.pop();
            ll parentn = front.first; ll childn = front.second;
            if(childn != -1) {
                for(auto iter = child[parentn].begin(); iter < child[parentn].end(); iter++) {
                    if(iter->first == childn) {
                        child[parentn].erase(iter);
                    }
                }
            }
            if(visited[parentn]) continue;
            visited[parentn] = true;
            for(auto pair : parent[parentn]) {
                if(dist[pair.first] + pair.second == dist[parentn]) {
                    q.emplace(pair.first, parentn);
                }
            }
        }

        dist.clear(); prenode.clear();

        // ll length = child.size();
        // for(ll i = 0; i<length; i++) {
        //     cout << i << ": ";
        //     for(auto pair : child[i]) {
        //         cout << pair.first << " ";
        //     }
        //     cout << endl;
        // } //none-erased nodes check

        //dijkstra (almost shortest path)
        priority_queue<tri, vector<tri>, dbcmp> asppq;
        vector<ll> aspdist(nodeN, inf);
        asppq.emplace(start, 0, -1);

        while(!asppq.empty()) {
            tri top = asppq.top(); asppq.pop();
            if(aspdist[top.node] != inf) continue;
            aspdist[top.node] = top.dist;
            // cout << "dijkstra: " << top.node << ", " << top.dist << "\n";

            for(auto pair : child[top.node] ) {
                if(aspdist[pair.first] <= top.dist + pair.second) continue;
                asppq.emplace(pair.first, top.dist + pair.second, -1);
            }
        }

        ans.push_back(aspdist[destination] == inf ? -1 : aspdist[destination]);
    }

    for(ll l : ans) cout << l << "\n";
}
