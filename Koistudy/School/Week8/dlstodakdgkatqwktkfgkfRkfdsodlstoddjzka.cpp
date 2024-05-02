#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int h, w, n; cin >> h >> w >> n;
    vector<int> asdf(w+1,0);
    vector<vector<int>> m(h+1, asdf);
    for(int i=0; i<n; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(b) {
            for(int j = c; j<c+a && j<=h; j++) {
                m[j][d] = 1;
            }
        } else {
            for(int j = d; j<d+a && j<=w; j++) 
                m[c][j]=1;
        }
    }
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}