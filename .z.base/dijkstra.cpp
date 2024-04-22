#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define inf 2147483640
#define ll long long

//O(NlogN)
//1916. <g2> 최소비용 구하기

struct path
{
    ll target;
    ll weight;
    path(){};
    path(ll a, ll b)
    {
        target = a;
        weight = b;
    }
};

struct pqi
{
    ll target;
    ll length;
    pqi(){};
    pqi(ll a, ll b)
    {
        target = a;
        length = b;
    }
};

struct pqcmp
{
    bool operator()(pqi a, pqi b)
    {
        return a.length > b.length;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, m; cin >> n >> m;
    vector<vector<path>> pv(n+1);
    for(ll i=0; i<m; i++){
        ll a, b, c; cin >> a >> b >> c;
        pv[a].emplace_back(b, c);
    }
    ll start, end; cin >> start >> end;
    priority_queue<pqi, vector<pqi>, pqcmp> toP;
    vector<int> minDist(n + 1, inf);
    pqi tpq(start, 0); toP.push(tpq);
    while (!toP.empty())
    {
        pqi top = toP.top(); toP.pop();
        if (minDist[top.target] != inf) continue;
        minDist[top.target] = top.length;
        if(top.target == end) break;
        for (path i : pv[top.target])
            toP.emplace(i.target, top.length + i.weight);
    }
    cout << minDist[end];
}
