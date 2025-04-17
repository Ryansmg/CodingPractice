#include <bits/stdc++.h>
using namespace std;

string inorder, preorder;
int n;

void solve(int in_l, int in_r, int pre_l, int pre_r) {
    if(in_l > in_r || pre_l > pre_r) return;
    char cur = preorder[pre_l];
    int cur_in = -1;
    for(int i = in_l; i <= in_r; i++) if(inorder[i] == cur) cur_in = i;
    solve(in_l, cur_in-1, pre_l + 1, pre_l + cur_in - in_l);
    solve(cur_in+1, in_r, pre_l + cur_in - in_l + 1, pre_r);
    cout << cur;
}

int main() {
    cin >> inorder >> preorder;
    n = (int) inorder.size();
    solve(0, n-1, 0, n-1);
}
