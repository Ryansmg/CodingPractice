#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define F first
#define S second
#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, m, x, y;
vi eda[200003], edb[200003]; //a 인접리스트, b 인접리스트
int va[3][200003], vb[3][200003]; //va[0, 1][i] : 텐서, va[2][i] : 데카르트 

int a, b, c, q;
signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i <= 200001; i++) 
        for (int j = 0; j < 3; j++) va[j][i] = vb[j][i] = -1;
    cin >> n >> x;
    for (int i = 1; i <= x; i++) {

        cin >> a >> b;
        eda[a].pb(b);
        eda[b].pb(a);

    }
    cin >> m >> y;
    for (int i = 1; i <= y; i++) {

        cin >> a >> b;
        edb[a].pb(b);
        edb[b].pb(a);

    }

    queue<int> qu;
    qu.push(1); va[2][1] = 0;
    while (!qu.empty()) {

        int cur = qu.front(); qu.pop();
        for (int nxt : eda[cur]) {

            if (va[2][nxt] == -1) {

                va[2][nxt] = va[2][cur] + 1;
                qu.push(nxt);

            }

        }

    }
    qu.push(1); vb[2][1] = 0;
    while (!qu.empty()) {

        int cur = qu.front(); qu.pop();
        for (int nxt : edb[cur]) {

            if (vb[2][nxt] == -1) {

                vb[2][nxt] = vb[2][cur] + 1;
                qu.push(nxt);

            }

        }

    }

    queue<pii> quy;
    quy.push({0, 1}); va[0][1] = 0;
    while (!quy.empty()) {

        int cur = quy.front().S; int bn = quy.front().F; quy.pop();
        for (int nxt : eda[cur]) {

            if (va[bn^1][nxt] == -1) {

                va[bn^1][nxt] = va[bn][cur] + 1;
                quy.push({bn^1, nxt});

            }

        }

    }
    quy.push({0, 1}); vb[0][1] = 0;
    while (!quy.empty()) {

        int cur = quy.front().S; int bn = quy.front().F; quy.pop();
        for (int nxt : edb[cur]) {

            if (vb[bn^1][nxt] == -1) {

                vb[bn^1][nxt] = vb[bn][cur] + 1;
                quy.push({bn^1, nxt});

            }

        }

    }
    /*for (int j = 0; j < 3; j++) {
        for (int i = 1; i <= n; i++) cout << va[j][i] << ' ';
        cout << endl;
    }
    for (int j = 0; j < 3; j++) {
        for (int i = 1; i <= m; i++) cout << vb[j][i] << ' ';
        cout << endl;
    }*/

    cin >> q;
    while (q--) {

        cin >> a >> b >> c;
        if (a == 1) {
            
            if (va[2][b] == -1 || vb[2][c] == -1) cout << -1 << endl;
            else cout << va[2][b] + vb[2][c] << endl;

        }
        if (a == 2) {

            if (va[0][b] == -1 || vb[0][c] == -1) {

                if (va[1][b] == -1 || vb[1][c] == -1) cout << -1 << endl;
                else cout << max(va[1][b], vb[1][c]) << endl;

            }
            else {
                
                if (va[1][b] == -1 || vb[1][c] == -1) cout << max(va[0][b], vb[0][c]) << endl;
                else cout << min(max(va[0][b], vb[0][c]), max(va[1][b], vb[1][c])) << endl;

            }

        }
        if (a == 3) {

            if (va[2][b] == -1 || vb[2][c] == -1)  {

                if (va[0][b] == -1 || vb[0][c] == -1) {

                    if (va[1][b] == -1 || vb[1][c] == -1) cout << -1 << endl;
                    else cout << max(va[1][b], vb[1][c]) << endl;

                }
                else {
                
                    if (va[1][b] == -1 || vb[1][c] == -1) cout << max(va[0][b], vb[0][c]) << endl;
                    else cout << min(max(va[0][b], vb[0][c]), max(va[1][b], vb[1][c])) << endl;

                }

            }
            else cout << max(va[2][b], vb[2][c]) << endl;

        }

    }

}