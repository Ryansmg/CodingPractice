#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define inf 2147000000
using namespace std;

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int dijk(vector<vector<pair<int, int>>> &child, int start, int end, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; //{target, dist}
    vector<int> mindist(n+1, inf);
    pq.emplace(start, 0);
    while(!pq.empty()) {
        auto top = pq.top(); pq.pop();
        if(mindist[top.first] != inf) continue;
        mindist[top.first] = top.second;
        if(top.first == end) break;
        for(auto p : child[top.first]) {
            pq.emplace(p.first, top.second + p.second);
        }
    }
    return mindist[end];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, e; cin >> n >> e;
    vector<vector<pair<int, int>>> child(n+1);
    for(int i=0; i<e; i++) {
        int a, b, c; cin >> a >> b >> c;
        child[a].emplace_back(b, c);
        child[b].emplace_back(a, c);
    }
    int v1, v2; cin >> v1 >> v2;

    int ans1 = dijk(child, v1, v2, n);
    if(ans1 == inf) { cout << -1; return 0; }
    int ans21 = dijk(child, 1, v1, n);
    int ans22 = dijk(child, v2, n, n);
    bool av2 = !((ans21==inf) || (ans22==inf));
    int ans23;
    if(av2) ans23 = ans21 + ans22;
    int ans31 = dijk(child, 1, v2, n);
    int ans32 = dijk(child, v1, n, n);
    bool av3 = !((ans31==inf) || (ans32==inf));
    int ans33;
    if(av3) ans33 = ans31 + ans32;
    if(av2&&av3) {
        cout << ans1 + min(ans23, ans33);
    } 
    else if(av2) {
        cout << ans1 + ans23;
    }
    else if(av3) {
        cout << ans1 + ans33;
    }
    else {
        cout << -1;
    }
}