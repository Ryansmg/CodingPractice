#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;

// Week3 F. [중급200p] 격자길
int main() {
    i64 n, m; cin >> n >> m;
    vector<vector<i64>> dp(n+1, vector<i64>(m+1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(j * n > m * i) continue; // j * n / m > i 인 경우 갈 수 없음.
            dp[i][j] = dp[i-1][j] + (j ? dp[i][j-1] : 0);
        }
    }
    cout << dp[n][m] << '\n';
}
