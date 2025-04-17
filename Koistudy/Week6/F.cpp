#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> pre, post;
long long ans = 1;

void solve(int pre_l, int pre_r, int post_l, int post_r) {
    if(post_l >= post_r || pre_l >= pre_r) return;
    assert(post[post_r] == pre[pre_l]);
    // 서브트리가 하나인 경우
    if(pre[pre_l+1] == post[post_r-1]) {
        ans <<= 1;
        solve(pre_l+1, pre_r, post_l, post_r-1);
    } else {
        // 후위순회에서 왼쪽 서브트리에 해당하는 범위
        // 왼쪽 서브트리의 크기 = l_post_idx - post_l + 1
        int l_post_idx = -1;
        for(int i = post_l; i <= post_r; i++) if(post[i] == pre[pre_l+1]) l_post_idx = i;
        solve(pre_l + 1, pre_l + l_post_idx - post_l + 1, post_l, l_post_idx);
        solve(pre_l + l_post_idx - post_l + 2, pre_r, l_post_idx + 1, post_r - 1);
    }
}

int main() {
    cin >> n;
    pre = post = vector<int>(n);
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> post[i];
    solve(0, n-1, 0, n-1);
    cout << ans;
}
