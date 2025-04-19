#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    i64 n, m;
    cin >> n >> m;
    vector<queue<i64, list<i64>>> queues(m + 1);
    for(int i = 1; i <= n; i++) {
        i64 k; cin >> k;
        queues[k].push(i);
    }
    for(int i = 1; i <= m; i++) {
        cout << queues[i].size() << " ";
        while(!queues[i].empty()) cout << queues[i].front() << " ", queues[i].pop();
        cout << "\n";
    }
}
