#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, P;

#define pll pair<ll, ll>

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >>N >>P;

    ll I, F;
    cin >>I >> F;
    I -= 1;
    F -= 1;


    vector<ll> adj[N];

    for (ll i = 1;i<=N;i++) {
        ll L;
        cin >> L;
        for (ll j = 1;j<=L;j++) {
            ll c;
            cin >> c;
            adj[i-1].push_back(c-1);// 일로 점프 가능
        }
    }

    ll dist[N][N][2];
    for (ll i = 0;i<N;i++) for (ll j = 0;j<N;j++)for(ll k = 0;k<2;k++) dist[i][j][k] = (ll)1e18;// 1 : 먹은거 && 0 : 뺏어온거

    priority_queue<pair<ll, array<int, 3>>, vector<pair<ll, array<int, 3>>>, greater<>> pq;
    pq.push({1,  {(int)I, 1, 0}});// 위치 : 시간
    dist[I][1][1] = 1;

    while (!pq.empty()) {
        auto [cost, xx] = pq.top();
        pq.pop();
        auto [at, time, t] = xx;
        if (cost > P) break;
        if (dist[at][time][t] < cost) continue;
        if (at == F && time == P%N && t == 1) break;
        if (dist[(at+1)%N][(time+1)%N][1] > cost+1) {
            dist[(at+1)%N][(time+1)%N][1] = cost+1;
            pq.push({(ll)cost+1,(array<int, 3>) {(int) ((at+1)%N), (int)((time+1)%N),(int) 1}});
        }

        for (auto i : adj[at]) {
            if (dist[i][time][0] > cost) {
                dist[i][time][0] = cost;
                pq.push({cost, {(int)i, (int)time, 0}});
            }
        }
    }

    cout << (dist[F][P%N][1] <= P ? "Tsumo":"Ryuukyoku");
    return 0;
}

