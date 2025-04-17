#include <bits/stdc++.h>
using namespace std;

const int mod = 9901;

// 높이가 i이고 노드가 j개인 트리의 개수 : dp[i][j]
int dp[101][201];

int main() {
    dp[1][1] = 1;
    for(int i = 2; i <= 100; i++) {
        for(int j = 2; j <= 200; j++) {
            // 왼쪽 깊이가 i-1이고 오른쪽 깊이가 <i-1인 경우
            // 왼쪽 트리 노드 수가 k개, 오른쪽 트리 노드 수는 j - k - 1개
            for(int k = 1; k < j - 1; k++) {
                for(int d = 1; d < i-1; d++)
                    dp[i][j] = (dp[i][j] + dp[i-1][k] * dp[d][j - k - 1] % mod) % mod;
            }
            //왼쪽 깊이가 <i-1이고 오른쪽 깊이가 i-1인 경우 : 위와 같음
            dp[i][j] <<= 1;
            // 왼쪽 깊이가 i-1이고 오른쪽 깊이도 i-1인 경우
            // 왼쪽 트리 노드 수가 k개, 오른쪽 트리 노드 수는 j - k - 1개
            for(int k = 1; k < j - 1; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][k] * dp[i-1][j - k - 1] % mod) % mod;
            }
        }
    }
    int n, k; cin >> n >> k;
    cout << dp[k][n] << "\n";
}
