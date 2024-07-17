#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long INF = 1000000000000000000;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(name, val) for(int name = 0; name < val; name++)
template <typename T> using v = vector<T>;

signed main() {
    fastio;
    int T; cin >> T;
    forn(asdf, T) {
        int n, m, k; // 강, 점프, 수영
        cin >> n >> m >> k;
        string s; cin >> s;
        v<int> dp(n, INF);
        if(n<m) { cout << "YES"; goto end; }
        forn(i, m) dp[i] = s[i]=='C'?INF:(k==0&&s[i]=='W'?INF:s[i]=='W');
        forn(i, n-1) {
            if(s[i]=='C' || dp[i]==INF) continue;
            if(s[i]=='W') {
                if(s[i+1]=='L') { dp[i+1] = min(dp[i+1], dp[i]); continue; }
                if(s[i+1]=='C') continue;
                if(dp[i]<k && dp[i+1]>dp[i]+1) dp[i+1] = dp[i]+1;
            } else {
                if(n-m<=i) { cout << "YES"; goto end; }
                for(int j = min(n-1, i+m); j>i; j--) if(s[j]!='W' || dp[i]<k) dp[j] = min(dp[j], s[j]=='C'?INF:dp[i]+(s[j]=='W'));
            }
        }
        if((s[n-1]=='W' && dp[n-1] <= k) || (s[n-1]=='L' && dp[n-1]!=INF)) cout << "YES";
        else cout << "NO";
        end: cout << "\n";
    }
}
