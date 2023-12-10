#include <iostream>
#include <vector>
#include <queue>
#define inf 2147483640
#define ll long long
using namespace std;

struct newpair {
    ll node; //노드 번호
    ll dist; //사용한 가격
    ll lowprice; //기름 최소 가격
    newpair(ll a, ll b, ll c)
    {
        node = a; dist = b; lowprice = c;
    }
    newpair(){}
} typedef tri;

struct cmp {
    bool operator() (tri a, tri b) {
        if(a.dist == b.dist) return a.lowprice > b.lowprice;
        return a.dist > b.dist;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    ll cityN, //도시의 개수
    roadN; //도로의 개수
    cin >> cityN >> roadN;
    vector<ll> price(cityN+1); //도시 번호 -> 리터당 가격
    vector<vector<pair<ll, ll>>> child(cityN+1); //도시 번호 -> {자식 노드, 가중치}
    for(ll i=0; i<cityN; i++)
    { ll a; cin >> a; price[i+1] = a; }
    for(ll i=0; i<roadN; i++)
    { 
        ll a, b, c; cin >> a >> b >> c;
        child[a].emplace_back(b, c);
        child[b].emplace_back(a, c);
    }

    priority_queue<tri, vector<tri>, cmp> pq;
    pq.emplace(1, 0, price[1]);

    vector<ll> dist(cityN+1, inf); //사용한 가격의 총합
    vector<ll> lowprice(cityN+1, inf); //그 도시까지의 최단 경로에서의 최소 가격

    while(!pq.empty()) 
    {
        tri top = pq.top(); pq.pop();
        if(lowprice[top.node] > top.lowprice) goto a;
        if(dist[top.node] != inf) continue;
        a:

        dist[top.node] = top.dist; lowprice[top.node] = top.lowprice;
        if(top.node == cityN) break;

        for(auto pair : child[top.node]) {
            ll nextPrice = top.dist + (pair.second*top.lowprice);
            ll lp = min(top.lowprice, price[pair.first]);
            if(nextPrice >= dist[pair.first] && lp >= lowprice[pair.first]) continue;
            pq.emplace(pair.first, nextPrice, lp);
        }
    }

    cout << dist[cityN];
}
