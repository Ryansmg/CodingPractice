#include <bits/stdc++.h>
using namespace std;

long long dp[21], n;

int main() {
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= 20; i++) {
        for(int l = 0; l <= i-1; l++) {
            dp[i] += dp[l] * dp[i - l - 1];
        }
    }
    cin >> n;
    cout << dp[n];
}
