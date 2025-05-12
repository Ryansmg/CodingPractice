#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<string> arr(h);
    for(int i = 0; i < h; i++) cin >> arr[i];

    vector<vector<int>> dist(h, vector<int>(w, 15571557));
    deque<pair<int, int>> bfs; // 0-1 bfs
    bfs.emplace_back(h-1, w-1); // == bfs.push_back({ h-1, w-1 });
    dist[h-1][w-1] = 1;

    int ans = 1;

    while(!bfs.empty()) {
        int r1 = bfs.front().first, c1 = bfs.front().second;
        bfs.pop_front();
        ans = max(ans, dist[r1][c1]);
        for(int i = 0; i < 4; i++) {
            int r2 = r1 + dy[i], c2 = c1 + dx[i];
            if(r2 < 0 || r2 >= h || c2 < 0 || c2 >= w || arr[r2][c2] == '.') continue;
            int w = arr[r2][c2] != arr[r1][c1];
            if(dist[r1][c1] + w < dist[r2][c2]) {
                dist[r2][c2] = dist[r1][c1] + w;
                if(w) bfs.emplace_back(r2, c2);
                else bfs.emplace_front(r2, c2);
            }
        }
    }

    cout << ans << '\n';
}
