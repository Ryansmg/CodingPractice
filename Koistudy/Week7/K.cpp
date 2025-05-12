#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    vector<string> arr(n);
    int sr, sc, gr, gc, tr, tc;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 'S') sr = i, sc = j;
            if(arr[i][j] == 'T') tr = i, tc = j;
            if(arr[i][j] == 'G') gr = i, gc = j;
        }
    }

    int ans = 0;

    /// S -> T
    {
        vector<vector<int>> dist(n, vector<int>(n, 1557 * 1557));
        queue<pair<int, int>> bfs;
        bfs.emplace(sr, sc);
        dist[sr][sc] = 0;

        while(!bfs.empty()) {
            int r1 = bfs.front().first, c1 = bfs.front().second;
            bfs.pop();
            for(int i = 0; i < 4; i++) {
                int r2 = r1 + dr[i], c2 = c1 + dc[i];
                if(r2 < 0 || c2 < 0 || r2 >= n || c2 >= n || arr[r2][c2] == '#') continue;
                if(dist[r1][c1] + 1 < dist[r2][c2]) {
                    dist[r2][c2] = dist[r1][c1] + 1;
                    bfs.emplace(r2, c2);
                }
            }
        }

        ans += dist[tr][tc];
    }

    /// T -> G
    {
        vector<vector<int>> dist(n, vector<int>(n, 1557 * 1557));
        queue<pair<int, int>> bfs;
        bfs.emplace(tr, tc);
        dist[tr][tc] = 0;

        while(!bfs.empty()) {
            int r1 = bfs.front().first, c1 = bfs.front().second;
            bfs.pop();
            for(int i = 0; i < 4; i++) {
                int r2 = r1 + dr[i], c2 = c1 + dc[i];
                if(r2 < 0 || c2 < 0 || r2 >= n || c2 >= n || arr[r2][c2] == '#') continue;
                if(dist[r1][c1] + 1 < dist[r2][c2]) {
                    dist[r2][c2] = dist[r1][c1] + 1;
                    bfs.emplace(r2, c2);
                }
            }
        }

        ans += dist[gr][gc];
    }

    cout << ans << '\n';
}
