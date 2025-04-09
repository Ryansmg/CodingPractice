#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    i64 n, m, k; cin >> n >> m >> k;
    queue<i64> q; // 노드가 들어갈 수 있는 자리의 높이를 저장하는 큐
    if(k != n + 1) { cout << "impossible."; return 0; }
    if(n == 0) { cout << m; return 0; }
    i64 ans = 0;
    n--; q.push(1); q.push(1);
    for(int i = 0; i < n; i++) {
        ans = q.front();
        q.push(q.front() + 1);
        q.push(q.front() + 1);
        q.pop();
    }
    for(int i = 0; i < m; i++) {
        ans = q.front();
        q.push(q.front() + 1);
        q.pop();
    }
    cout << ans + 1;
}
