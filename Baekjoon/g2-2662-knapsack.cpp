#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// 2662. 기업투자
// #dp #knapsack

signed main()
{
    fastio
    int n, m; cin >> n >> m;
    int dp[m][n+1];
    int backtrack[m][n+1];
    for(int i=0; i<m; i++)
        for(int j=0; j<n+1; j++)
            dp[i][j] = backtrack[i][j] = 0;
    int arr[m+1][n+1];
    int premax = -1, ansx, ansy;
    for(int j=0; j<m; j++) arr[j][0] = 0;
        for(int i=1; i<=n; i++) {
        int t; cin >> t;
        for(int j=0; j<m; j++) {
            cin >> t; arr[j][i] = t;
        }
    }
    for(int j=1; j<=n; j++) {
        dp[0][j] = arr[0][j];
        //cout << "[" << 0 << ", " << j << "]=" << j << endl;
        backtrack[0][j] = j;
    }
    for(int i=1; i<m; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=0; k<=n && j-k>=0; k++)
                if(dp[i][j] < dp[i-1][j-k] + arr[i][k]) {
                    dp[i][j] = dp[i-1][j-k] + arr[i][k];
                    backtrack[i][j] = k;
                    //cout << "[" << i << ", " << j << "]=" << k << endl;
                }
//            if(premax <= dp[i][j]) {
//                premax = dp[i][j];
//                ansx = j;
//                ansy = i;
//            }
        }
    }
    cout << dp[m-1][n] << "\n";
    stack<int> out;
    ansy = m-1; ansx = n;
    int answer = dp[m-1][n];
    while(dp[ansy][ansx-1] == answer) ansx--;
    while(ansy+1) {
        //cout << "[" << ansy << ", " << ansx << "]=" << backtrack[ansy][ansx] << endl;
        out.push(backtrack[ansy][ansx]);
        ansx -= backtrack[ansy][ansx];
        ansy--;
    }
    while(!out.empty()) {
        cout << out.top() << " ";
        out.pop();
    }
}
