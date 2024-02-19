#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long

struct edge {
    ll parent; //간선 시작점
    ll target; //간선 도착점
    ll weight; //가중치
    edge(ll a, ll b, ll c) {
        parent = a; target = b; weight = c;
    }
    edge(){}
    bool operator() (edge x, edge y) {
        return x.weight > y.weight;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, m, k; cin >> n >> m >> k;
    vector<int> powerplants;
    for(int i=0; i<k; i++) {
        ll a; cin >> a;
        powerplants.push_back(a);
    }
    vector<edge> temp;
    vector<vector<edge>> edges(n+1, temp);
    for(ll i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edge e1(a, b, c), e2(b, a, c);
        edges[a].push_back(e1);
        edges[b].push_back(e2);
    }
    priority_queue<edge, vector<edge>, edge> pq;
    vector<bool> visited(n+1, false);
    
    for(int i : powerplants) {
        visited[i] = true;
        for(edge e : edges[i]) if(!visited[e.target])  pq.push(e); 
    }
    ll citycnt = k;
    ll weightsum = 0;
    while(citycnt < n) { 
        edge top = pq.top(); pq.pop();
        if(visited[top.target]) continue;
        visited[top.target] = true;
        weightsum += top.weight;
        citycnt++;
        for(edge e : edges[top.target]) {
            if(!visited[e.target])  
                pq.push(e);
        }
    }
    cout << weightsum;
    return 0;
}