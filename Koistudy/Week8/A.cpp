#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define forn(i, n) for(i64 i = 0; i < n; i++)
#define forf(i, a, b) for(i64 i = a; i <= b; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
    fastio;
    int n, q; cin >> n >> q;
    vector<i64> arr(n+1);
    forf(i, 1, n) cin >> arr[i];
    forf(i, 1, n) arr[i] += arr[i-1];
    forn(Q, q) {
        i64 a, b; cin >> a >> b;
        cout << arr[b] - arr[a-1] << '\n';
    }
}