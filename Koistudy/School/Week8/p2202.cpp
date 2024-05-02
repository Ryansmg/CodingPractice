#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int a, b; cin >> a >> b;
    vector<int> temp(a, 0);
    vector<vector<int>> ans(a, temp);
    for(int i=0; i<b; i++) {
        int c, d, e, f, g; cin >> c >> d >> e >> f >> g;
        ans[c-1][d-1] += g;
        if(e!=a) ans[e][d-1] -= g;
        if(f!=a) ans[c-1][f] -= g;
        if(e!=a && f!=a) ans[e][f] += g;
    }
    int sum = 0;
    for(int i=0; i<a; i++)
        for(int j=1; j<a; j++)
            ans[i][j] += ans[i][j-1];
    for(int j=0; j<a; j++) 
        cout << ans[0][j] << " ";
    cout << "\n";
    for(int i=1; i<a; i++) {
        for(int j=0; j<a; j++) {
            ans[i][j] += ans[i-1][j];
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}