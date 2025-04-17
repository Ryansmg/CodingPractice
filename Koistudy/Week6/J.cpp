#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, ns, t;
    cin >> p >> ns >> t;
    vector<int> par(p + 1);
    for(int i = 0; i < ns; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        par[b] = par[c] = a;
    }
    vector<int> ans;
    int cur = t;
    while(true) {
        ans.push_back(cur);
        if(cur == 1) break;
        cur = par[cur];
    }
    cout << int(ans.size()) << '\n';
    for(int i = int(ans.size()) - 1; i >= 0; i--) cout << ans[i] << '\n';
}
