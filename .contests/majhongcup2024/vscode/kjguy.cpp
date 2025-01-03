#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, P;
ll cal(ll x) {
    return (x+N*10000000)%N;
}

signed main() {
    cin >>N >>P;

    ll I, F;
    cin >>I >> F;
    I--;
    F--;
    I = cal(I-1);
    ll dist[N];
    for (ll i = 0;i<N;i++) dist[i] = 1e15;

    vector<ll> adj[N];
    
    for (ll i = 1;i<=N;i++) {
        ll L;
        cin >> L;
        for (ll j = 1;j<=L;j++) {
            ll c;
            cin >> c;
            adj[i-1].push_back(c-1);
        }
    }

    // cout << "start" << I << endl;
    dist[cal(0-I)] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, cal(0-I)});

    while (!pq.empty()) {
        auto [cost, atT] = pq.top();
        pq.pop();
        if (dist[atT] < cost) continue;
        ll at = cal(cost - atT);// atT = 시간 - 위치
        // cost : 시간
        // at : 실제 위치

        for (ll i = 1;i<N;i++) {
            // i번 전진하는 경우
            ll to = (at+i)%N;// to로 감 일단
            ll cost2 = cost+i;// i회 증가 (그 다음 사람도 턴 써야함)
            for (auto to2 : adj[to]) {
                // to2로 감 => 뭘로 바뀌지?
                // 비용 = cost2임
                ll TO = cal(cost2-to2);// 실제론 TO로 감 && 위치는 to2임
                // cout << at << " to " << to << " : " << to2 << endl;
                if (dist[TO] > cost2) {
                    dist[TO] = cost2;
                    pq.push({cost2, TO});
                }
            }
        }
    }


    // for (ll i = 0;i<N;i++) cout << dist[i] << " ";
    // cout << endl;

    cout << (dist[cal(P-F)] < P ? "Tsumo" : "Ryuukyoku") << endl;








    return 0;    
}

