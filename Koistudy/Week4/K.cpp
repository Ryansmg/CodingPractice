#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i64 = long long;
#define v2l vector<vector<i64>>
#define vl vector<i64>
#define Size(v) ((i64) v.size())

v2l board(4, vl(4));

vl mergeLeft(const vl& a) {
    vl ans;
    for(i64 i : a) {
        if(!i) continue;
        while(!ans.empty() && ans.back() == i) ans.pop_back(), i *= 2;
        ans.push_back(i);
    }
    while(Size(ans) < 4) ans.push_back(0);
    return ans;
}
vl mergeRight(vl a) { reverse(a.begin(), a.end()); auto ans = mergeLeft(a); reverse(ans.begin(), ans.end()); return ans; }
void setRow(i64 i, const vl& a) { board[i] = a; }
vl getRow(i64 i) { return board[i]; }
void setColumn(i64 i, const vl& a) { for(int j = 0; j < 4; j++) board[j][i] = a[j]; }
vl getColumn(i64 i) {
    vl ans(4); for(int j = 0; j < 4; j++) ans[j] = board[j][i];
    return ans;
}
void move(i64 dir) {
    if(dir == 1) for(int i = 0; i < 4; i++) setColumn(i, mergeLeft(getColumn(i)));
    if(dir == 2) for(int i = 0; i < 4; i++) setRow(i, mergeLeft(getRow(i)));
    if(dir == 3) for(int i = 0; i < 4; i++) setColumn(i, mergeRight(getColumn(i)));
    if(dir == 4) for(int i = 0; i < 4; i++) setRow(i, mergeRight(getRow(i)));
}


int main() {
    i64 n; cin >> n;
    for(auto& i : board) for(auto& j : i) cin >> j;
    for(i64 i = 0; i < n; i++) {
        i64 m, x, y, c;
        cin >> m >> x >> y >> c;
        move(m);
        board[x-1][y-1] = c;
    }
    for(const auto& i : board) {
        for(auto& j : i) cout << j << " ";
        cout << "\n";
    }
}
