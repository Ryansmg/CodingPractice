#include <bits/stdc++.h>
using namespace std;

int n;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<vector<bool>> arr, vis;
vector<int> ans;

int main() {
    cin >> n;
    arr = vis = vector<vector<bool>>(n, vector<bool>(n));
    char c;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        cin >> c;
        arr[i][j] = c == '1';
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        if(vis[i][j] || !arr[i][j]) continue;
        queue<array<int, 2>> q;
        q.push({i, j}); vis[i][j] = true;
        int cans = 1;
        while(!q.empty()) {
            int ci = q.front()[0], cj = q.front()[1];
            q.pop();
            for(int k = 0; k < 4; k++) {
                int ni = ci + dx[k], nj = cj + dy[k];
                if(ni < 0 || nj < 0 || ni >= n || nj >= n || !arr[ni][nj] || vis[ni][nj]) continue;
                cans++; vis[ni][nj] = true;
                q.push({ni, nj});
            }
        }
        ans.push_back(cans);
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(int i : ans) cout << i << '\n';
}
