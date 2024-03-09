#include <iostream>
#include <vector>
#define INF 2147000000
using namespace std;

//13141. Ignition
//#floyd_warshell

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> temp(n+1, INF);
    vector<vector<int>> dist(n+1, temp);
    for(int i=1; i<=n; i++) dist[i][i] = 0;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    
}