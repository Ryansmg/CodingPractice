#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    string s1 = "gshs", s2 = "shsg";
    int dy[] = { 0, 1, 1, 1 };
    int dx[] = { 1, 0, -1, 1 };

    int ans = 0;

    for(int r = 0; r < n; r++)
        for(int c = 0; c < n; c++) {
            for(int i = 0; i < 4; i++) {
                string s;
                int r2 = r, c2 = c;
                for(int j = 0; j < 4; j++) {
                    if(r2 < 0 || c2 < 0 || r2 >= n || c2 >= n) break;
                    s.push_back(arr[r2][c2]);
                    r2 += dy[i]; c2 += dx[i];
                }
                ans += (s == s1);
                ans += (s == s2);
            }
        }

    cout << ans << '\n';
}
