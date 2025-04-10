#include <bits/stdc++.h>
using namespace std;

int dr[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int main() {
    int h, w, ans = 0; cin >> h >> w;
    vector<vector<int>> shore(h+2, vector<int>()),
        cnt(h+2, vector<int>(w+2, 0));

    for(int i = 1; i <= h; i++) {
        shore[i].push_back(0);
        string s; cin >> s;
        for(int j = 0; j < w; j++) {
            shore[i].push_back(s[j] == '.' ? 0 : s[j] - '0');
            if (s[j] == '.') for(int k = 0; k < 8; k++) cnt[i + dr[k]][j + 1 + dc[k]]++;
        }
    }
    queue<pair<int, int>> cur, nxt;
    for(int r = 1; r <= h; r++) for(int c = 1; c <= w; c++) {
        if(shore[r][c] && shore[r][c] <= cnt[r][c]) shore[r][c] = 0, nxt.emplace(r, c);
    }
    while(!nxt.empty()) {
        ans++; cur = nxt; nxt = queue<pair<int, int>>();
        while(!cur.empty()) {
            int r = cur.front().first, c = cur.front().second;
            cur.pop();
            for(int j = 0; j < 8; j++) {
                int nxr = r + dr[j], nxc = c + dc[j];
                if (shore[nxr][nxc] && shore[nxr][nxc] <= ++cnt[nxr][nxc])
                    shore[nxr][nxc] = 0, nxt.emplace(nxr, nxc);
            }
        }
    }
    cout << ans;
}
