#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    freopen(R"(C:\Users\ryans\Desktop\Coding\RandE\input.txt)", "r", stdin);
    int height, width; cin >> width >> height;
    vector<int> temp;
    vector<vector<int>> hmap(height, temp);
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++) {
            int t;
            cin >> t;
            hmap[i].push_back(t);
        }
    }
    freopen(R"(C:\Users\ryans\Desktop\Coding\RandE\input2.txt)", "r", stdin);
    long double ans = 0;
    int cnt; cin >> cnt;
    for(int i=0; i<cnt; i++) {
        int x, y; long double h; cin >> x >> y >> h;
        ans += abs(hmap[y][x] - h)*abs(hmap[y][x] - h);
    }
    cout << sqrt(ans/cnt);
}
