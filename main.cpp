#include <bits/stdc++.h>
using namespace std;

int main() {
    int cur, pw, secc;
    cin >> cur >> pw >> secc;
    vector<bool> secure(10000);
    for(int i = 0; i < secc; i++) {
        int s; cin >> s; secure[s] = true;
    }
    vector<bool> visited(10000);
    queue<pair<int, int>> bfs; // number, ans
    bfs.emplace(cur, 0);
    visited[cur] = true;
    while(!bfs.empty()) {
        cur = bfs.front().first;
        int cans = bfs.front().second;
        bfs.pop();
        if(cur == pw) {
            cout << cans << "\n";
            return 0;
        }
        for(int i = 1; i <= 1000; i *= 10) {
            if(!visited[(cur + i) % 10000] && !secure[(cur + i) % 10000])
                bfs.emplace((cur + i) % 10000, cans + 1),
                visited[(cur + i) % 10000] = true;
            if(!visited[(cur - i + 10000) % 10000] && !secure[(cur - i + 10000) % 10000])
                bfs.emplace((cur - i + 10000) % 10000, cans + 1),
                visited[(cur - i + 10000) % 10000] = true;
        }
    }
    cout << "-1\n";
}