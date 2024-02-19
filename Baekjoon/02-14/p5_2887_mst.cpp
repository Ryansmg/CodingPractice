// 2887. 행성 터널 (mst)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define ll long long
#define LINF 100000000000ll
#define INF 2147483000
using namespace std;
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
struct p3d
{
    ll x, y, z;
    int id;
    p3d() {}
    p3d(ll a, ll b, ll c, int i)
    {
        x = a;
        y = b;
        z = c;
        id = i;
    }
};
bool p3dsx(p3d a, p3d b) { return a.x < b.x; }
bool p3dsy(p3d a, p3d b) { return a.y < b.y; }
bool p3dsz(p3d a, p3d b) { return a.z < b.z; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<p3d> xp, yp, zp;
    for (int i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        xp.emplace_back(a, b, c, i);
        yp.emplace_back(a, b, c, i);
        zp.emplace_back(a, b, c, i);
    }
    sort(xp.begin(), xp.end(), p3dsx);
    sort(yp.begin(), yp.end(), p3dsy);
    sort(zp.begin(), zp.end(), p3dsz);
    vector<vector<edge>> edges(n);
    int dd[] = {-1, 1};
    for(int i=0; i<n; i++) {
        for(int d : dd) if(i+d>=0 && i+d<n) {
            edges[xp[i].id].push_back({xp[i].id, xp[i+d].id, abs(xp[i].x - xp[i+d].x)});
            edges[yp[i].id].push_back({yp[i].id, yp[i+d].id, abs(yp[i].y - yp[i+d].y)});
            edges[zp[i].id].push_back({zp[i].id, zp[i+d].id, abs(zp[i].z - zp[i+d].z)});
        }
    }

    //prim
    priority_queue<edge, vector<edge>, edge> pq;
    vector<bool> visited(n, false);
    visited[0] = true;
    for(edge e : edges[0]) pq.push(e); 

    ll edgecount = 0;
    ll weightsum = 0;
    while(edgecount < n-1) { 
        edge top = pq.top(); pq.pop();
        if(visited[top.target]) continue;
        visited[top.target] = true;
        weightsum += top.weight;
        edgecount++;
        for(edge e : edges[top.target]) {
            if(!visited[e.target])  
                pq.push(e);
        }
    }
    cout << weightsum;
}