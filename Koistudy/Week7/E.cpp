#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int main() {
    int n, m;
    cin >> n >> m;
    int cheeseCnt = 0, time = 0;
    vector<vector<int>> cheese(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> cheese[i][j], cheeseCnt += cheese[i][j];

    while(cheeseCnt) {
        time++;
        vector<vector<bool>> vis(n, vector<bool>(m));
        vector<vector<int>> airCnt(n, vector<int>(m));

        queue<pair<int, int>> bfs; bfs.push({0, 0});
        while(!bfs.empty()) {
            int r = bfs.front().first, c = bfs.front().second;
            bfs.pop();

            for(int i = 0; i < 4; i++) {
                int r2 = r + dy[i], c2 = c + dx[i];
                if(r2 < 0 || c2 < 0 || r2 >= n || c2 >= m) continue;
                airCnt[r2][c2]++;
                if(!vis[r2][c2] && !cheese[r2][c2])
                    bfs.push({r2, c2}), vis[r2][c2] = true;
            }
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(cheese[i][j] && airCnt[i][j] >= 2)
                    cheeseCnt--, cheese[i][j] = false;
    }
    cout << time << "\n";
}
