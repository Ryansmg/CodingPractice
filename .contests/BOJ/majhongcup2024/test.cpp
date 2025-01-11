#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, P;
ll cal(ll x) {
    return (x+N*100000000000LL)%N;
}

signed main() {
    cin >>N >>P;

    ll I, F;
    cin >>I >> F;
    I = cal(I-2);
    F = cal(F-1);
    ll dist[N];
    for (ll i = 0;i<N;i++) dist[i] = (ll)1e18;

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

    // cout << "start" << I << endl;
    dist[cal(0-I)] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.emplace(0, cal(0-I));

    while (!pq.empty()) {
        auto [cost, atT] = pq.top();
        pq.pop();
        if (dist[atT] < cost) continue;// ㅄ?
        ll at = cal(cost - atT);// atT = 시간 - 위치
        if (cost > P) break;// 이제 끝임
        // cost : 시간
        // at : 실제 위치

        for (ll i = (cost == 0 ? 1 : 0) ;i<N;i++) {
            // i번 전진하는 경우
            ll to = cal(at+i);// to로 감 일단
            ll cost2 = cost+i;// i회 증가 (그 다음 사람도 턴 써야함)
            for (auto to2 : adj[to]) {
                // to2로 감 => 뭘로 바뀌지?
                // 비용 = cost2임
                ll TO = cal(cost2-to2);// 실제론 TO로 감 && 위치는 to2임
                // cout << at << " to " << to << " : " << to2 << endl;
                if (dist[TO] > cost2) {
                    dist[TO] = cost2;
                    pq.emplace(cost2, TO);
                }
            }
        }
    }


    // for (ll i = 0;i<N;i++) cout << dist[i] << " ";
    // cout << endl;

    cout << (dist[cal(P-F)] < P ? "Tsumo" : "Ryuukyoku") << endl;
    return 0;
}

