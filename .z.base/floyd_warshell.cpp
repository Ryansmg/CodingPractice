#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define INF 21470000000
using namespace std;

//11404. 플로이드
//#floyd_warshell

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; //도시 개수, 버스 개수
    cin >> n >> m;
    vector<ll> temp(n+1, INF);
    vector<vector<ll>> graphs(n+1, temp); //graphs[a][b] == a->b 최소 비용
    //초기값 세팅
    for(int i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        graphs[a][b] = min(graphs[a][b], c);
    }
    for(int i=1; i<=n; i++) graphs[i][i] = 0;

    //플로이드-워셜
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                graphs[i][j] = min(graphs[i][j], graphs[i][k] + graphs[k][j]);
            }
        }
    }

    //print
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << (graphs[i][j] == INF ? 0 : graphs[i][j]) << " ";
        }
        cout << "\n";
    }
}