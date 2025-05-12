#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int br, bc;
        vector<pair<int, int>> targets;
        for(int r = 0; r < 8; r++)
            for(int c = 0; c < 8; c++) {
                char a; cin >> a;
                if(a == 'B') br = r, bc = c;
                if(a == 'T') targets.emplace_back(r, c);
            }

        bool impossible = false;
        for(int i = 0; i < 3; i++) {
            if((br + bc) % 2 != (targets[i].first + targets[i].second) % 2)
                impossible = true;
        }
        if(impossible) {
            cout << "-1\n";
            continue;
        }

        int ans = 1557 * 1557;
        do {
            int curR = br, curC = bc;
            int cans = 0;
            for(int i = 0; i < 3; i++) {
                if(curR + curC == targets[i].first + targets[i].second ||
                    curR - curC == targets[i].first - targets[i].second)
                    cans++; // 한 번에 갈 수 있음
                else cans += 2; // 한 번에 못 감

                curR = targets[i].first;
                curC = targets[i].second;
            }
            ans = min(ans, cans);
        } while(next_permutation(targets.begin(), targets.end()));
        cout << ans << '\n';
    }
}
