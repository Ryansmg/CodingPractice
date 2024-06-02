#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
vector<vector<int>> dp(1010, vector<int>(1010, -1));
int d = 1000000007;

int f(int p, int q) {
    if(q>k) return 0;
    if(dp[p][q]!=-1) return dp[p][q];
    if(p==n+1) {
        if(q==k) return dp[p][q]=1;
        else return dp[p][q]=0;
    }
    return dp[p][q] = ((q*f(p+1, q))%d + f(p+1, q+1))%d;
}

signed main() {
    cin >> n >> k;
    cout << f(1, 0);
}