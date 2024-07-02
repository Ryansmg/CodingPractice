#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#include <queue>
using namespace std;

struct line {
    ll start, end, weight;
    line(){}
    line(ll a, ll b, ll c) {
        start=a; end=b; weight=c;
    }
    bool operator() (line a, line b) {
        return a.weight < b.weight;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<line> temp;
    vector<vector<line>> childs(n+1);
    for(ll i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        childs[a].emplace_back(a, b, c);
        childs[b].emplace_back(b, a, c);
    }
    ll start, end;
    cin >> start >> end;
    priority_queue<line, vector<line>, line> pq; //end, 의미x, 최대 무게
    vector<ll> visited(n+1, false);
    pq.push({start, 0, 2148000000LL});
    while(!pq.empty()) {
        line top = pq.top(); pq.pop();
        if(top.start == end) {
            cout << top.weight;
            return 0;
        }
        if(visited[top.start]) continue;
        visited[top.start] = true;
        for(line l : childs[top.start]) {
            pq.push({l.end, l.weight, min(top.weight, l.weight)});
        }
    }
}
