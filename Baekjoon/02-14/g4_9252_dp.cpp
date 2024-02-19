#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;
    int al = a.length(), bl = b.length();
    
    vector<int> temp (al+1, 0);
    vector<vector<int>> dp(bl+1, temp);
    for(int i=1; i<=bl; i++) {
        for(int j=1; j<=al; j++) {
            if(a[j-1] == b[i-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    } 
    cout << dp[bl][al];
    if(dp[bl][al] != 0) {
        string ans = "";
        int found = 0;
        int x=al, y=bl;
        while(found < dp[bl][al]) {
            if(x<0 || y<0) break;
            if(a[x-1] == b[y-1]) {
                ans = a[x-1] + ans;
                x--;
                y--;
                found++;
            } else if(dp[y][x-1] > dp[y-1][x]) x--;
            else y--;
        }
        cout << "\n" << ans << endl;
    }
}