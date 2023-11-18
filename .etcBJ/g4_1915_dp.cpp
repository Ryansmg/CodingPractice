#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//가장 큰 정사각형

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int height, width;
    cin >> height >> width;
    vector<bool> temp(width);
    vector<vector<bool>> map(height, temp);
    vector<int> temp2(width);
    vector<vector<int>> max(height, temp2);
    for(int i=0; i<height; i++) {
        string s;
        cin >> s;
        int j = 0;
        for(char c : s)
            map[i][j++] = c=='1';
    }

    int ans = 0;
    for(int i=0; i<height; i++) {
        int t = map[i][0]?1:0;
        max[i][0] = t;
        ans = std::max(ans, t);
    }
    for(int j=0; j<width; j++) {
        int t = map[0][j]?1:0;
        max[0][j] = t;
        ans = std::max(ans, t);
    }

    for(int i=1; i<height; i++) {
        for(int j=1; j<width; j++) {
            if(!map[i][j]) {
                max[i][j] = 0;
            } else {
                max[i][j] = std::min(max[i][j-1], std::min(max[i-1][j], max[i-1][j-1]))+1;
                ans = std::max(ans, max[i][j]);
            }
        }
    }

    cout << ans*ans;
}
