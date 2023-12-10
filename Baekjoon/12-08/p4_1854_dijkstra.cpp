#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
#define inf 9223372036854775800
using namespace std;

//k번째 최단경로 찾기

struct dijkpair {
    int node; ll distance;
    dijkpair(){}
    dijkpair(int a, ll b) {
        node = a; distance = b;
    }
} typedef djp;

struct djpcmp {
    bool operator() (djp a, djp b) {
        return a.distance > b.distance;
    }
};

struct llcmp {
    bool operator() (ll a, ll b) {
        return a < b;
    }
};

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int nodeN, edgeN, k;
    cin >> nodeN >> edgeN >> k;
    vector<vector<pair<int, int>>> child(nodeN+1); //nodeN->{childN, weight}

    for(int i=0; i<edgeN; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        child[a].emplace_back(b, c);
    }

    priority_queue<djp, vector<djp>, djpcmp> pq;
    priority_queue<ll, vector<ll>, llcmp> basedistvec;
    vector<priority_queue<ll, vector<ll>, llcmp>> dist(nodeN+1, basedistvec);
    pq.emplace(1, 0);

    while(!pq.empty()) {
        djp top = pq.top(); pq.pop();
        if(dist[top.node].size()==k && dist[top.node].top() <= top.distance) continue;
        dist[top.node].emplace(top.distance);
        if(dist[top.node].size()==k+1) dist[top.node].pop();

        for(auto pair : child[top.node]) {
            ll nextdis = top.distance + pair.second;
            if(dist[pair.first].size() == k && dist[pair.first].top() <= nextdis) continue;
            pq.emplace(pair.first, nextdis);
        }
    }

    for(int i=0; i<nodeN; i++) 
        cout << (dist[i+1].size() != k ? -1 : dist[i+1].top()) << "\n";
}
