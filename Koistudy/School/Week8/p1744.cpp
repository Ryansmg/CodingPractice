#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int a, c, b; cin >> a >> c >> b;
    vector<int> temp(c+9, 0);
    vector<vector<int>> ans(a+9, temp);
    for(int i=0; i<b; i++) {
        int c, d, e, f, g; cin >> c >> d >> e >> f >> g;
        ans[c-1][d-1] += g;
        ans[e][d-1] -= g;
        ans[c-1][f] -= g;
        ans[e][f] += g;
    }
    int sum = 0;
    for(int i=0; i<a; i++) {
        for(int j=0; j<c; j++) cout << ans[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
    for(int i=0; i<a; i++)
        for(int j=1; j<c; j++)
            ans[i][j] += ans[i][j-1];
    for(int j=0; j<c; j++) 
        cout << ans[0][j] << " ";
    cout << "\n";
    for(int i=1; i<a; i++) {
        for(int j=0; j<c; j++) {
            ans[i][j] += ans[i-1][j];
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}