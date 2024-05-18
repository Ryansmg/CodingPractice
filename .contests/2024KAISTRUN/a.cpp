#include <bits/stdc++.h>
#define int long long
#define llmax 9223372036854775807
#define inf 5000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

signed main()
{   fastio
    int tt; cin >> tt;
    for(int tc=0; tc<tt; tc++) {
        int n, k;
        cin >> n >> k;
        vector<int> ans;
        while(k>0) {
            int d = 1, e, cn = 1;
            int t = 1; n = 0;
            while(t<=k) {
                t *= 10; n++;
            } 
            while(cn<n) 
            {
                d = d*10+1;
                cn++;
            }
            e=d;
            while(e<=k) e += d;
            e-=d;
            if(e==0) {
                d /= 10; 
                e = d;
                while(e<=k && e<t/10) e += d;
                e-=d;
            }
            ans.push_back(e); k-=e;
        }
        cout << ans.size() << "\n";
        for(int i : ans) cout << i << " ";
        cout << "\n";
    }
}