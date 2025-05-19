#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define forn(i, n) for(i64 i = 0; i < n; i++)
#define forf(i, a, b) for(i64 i = a; i <= b; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
    fastio;
    int n, q; cin >> n >> q;
    int sq = sqrt(n);
    vector<i64> arr(n + 1);
    vector<i64> bucket(sq + 2);
    forf(i, 1, n) cin >> arr[i], bucket[i/sq] += arr[i];
    forn(Q, q) {
        i64 op, a, b; cin >> op >> a >> b;
        if(op == 1) {
            i64 ans = 0;
            for(; a%sq && a<=b; a++) ans += arr[a];
            for(; (b+1)%sq && a<=b; b--) ans += arr[b];
            for(; a<=b; a+=sq) ans+=bucket[a/sq];
            cout << ans << '\n';
        } else {
            bucket[a/sq] += b - arr[a];
            arr[a] = b;
        }
    }
}
