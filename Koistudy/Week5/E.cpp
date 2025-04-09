#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    i64 n, m, k, cur = 0;
    cin >> n >> m >> k;
    queue<i64, list<i64>> q; q.push(1);
    while(true) {
        i64 a, b, f = q.front();
        q.pop();
        a = f * n % 1000000007; b = f * m % 1000000007; cur += 2;
        if(k <= cur) {
            cout << ((k & 1) ? a : b) << "\n";
            break;
        }
        q.push(a); q.push(b);
    }
}