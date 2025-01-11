#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define F first
#define S second
#define pb push_back
typedef pair<int, int> pii;
int n, c = 1;
vector<int> vi[2003];
bool xy[2003];
pair<pii, pii> p[2003];
int v[2003][2003];

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        
        cin >> p[i].F.F >> p[i].F.S >> p[i].S.F >> p[i].S.S;
        if (p[i].F.F == p[i].S.F) xy[i] = true;
        for (int j = 1; j <= n; j++) v[i][j] = -1;
        //cout << xy[i] << ' ';

    }
    for (int i = 1; i <= n; i++) {

        for (int j = i+1; j <= n; j++) {

            if (xy[i] == xy[j]) continue;
            if (xy[i]) { //i가 y축과 평행(p[i].F.F == p[i].S.F)

                if (min(p[i].F.S, p[i].S.S) <= p[j].F.S && p[j].F.S <= max(p[i].F.S, p[i].S.S))
                    if (min(p[j].F.F, p[j].S.F) <= p[i].F.F && p[i].F.F <= max(p[j].F.F, p[j].S.F)) {

                        vi[i].pb(j);
                        vi[j].pb(i);

                    }

            }
            else {

                if (min(p[j].F.S, p[j].S.S) <= p[i].F.S && p[i].F.S <= max(p[j].F.S, p[j].S.S))
                    if (min(p[i].F.F, p[i].S.F) <= p[j].F.F && p[j].F.F <= max(p[i].F.F, p[i].S.F)) {

                        vi[i].pb(j);
                        vi[j].pb(i);

                    }

            }

        }

    }
    /*for (int i = 1; i <= n; i++) {
        for (int j : vi[i]) cout << j << ' ';
        cout << endl;
    }*/

    queue<int> qu;
    for (int i = 1; i <= n; i++) {

        while (!qu.empty()) qu.pop();
        qu.push(i); v[i][i] = 0;
        while (!qu.empty()) {

            int cur = qu.front(); qu.pop();
            for (int nxt : vi[cur]) {

                if (v[i][nxt] == -1) {

                    v[i][nxt] = v[i][cur] + 1;
                    qu.push(nxt);

                }

            }

        }

    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << v[i][j] << ' ';
        cout << endl;
    }


}