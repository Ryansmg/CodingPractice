#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> n, int cnt, int ii) {
    for(int i=0; i<ii; i++) { if(n[i]) cnt--; else cnt++; n[i] ^= 1; }
    int ans = 0;
    if(ii) ans++;
    if(cnt==0) return ans;
        for(int i=0; i<19; i++) {
            if(n[i]==0) continue;
            ans++;
            for(int j=0; j<3 && i+j<20; j++)  {
                if(n[i+j]) { n[i+j] = 0; cnt--; }
                else { n[i+j] = 1; cnt++; }
            }
        }
        if(cnt==0) return ans;
        
        for(int i=0; i<19; i++) {
            if(n[i]==0) continue;
            ans++;
            for(int j=0; j<3 && i+j<20; j++)  {
                if(n[i+j]) { n[i+j] = 0; cnt--; }
                else { n[i+j] = 1; cnt++; }
            }
        }
    
    return cnt>0?2147483647:ans;
}

int main()
{
    vector<int> n; int ans = 1247483647, cnt = 0;
    for(int i=0; i<20; i++) {
        int t; cin >> t; n.push_back(t);
        if(t) cnt++;
    }
    for(int i=0; i<2; i++) ans = min(ans, solve(n, cnt, i*2));
    cout << ans;
}
