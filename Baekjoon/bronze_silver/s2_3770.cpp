#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forf(name, start, end) for(int name = start; name <= end; name++)
#define all(v) v.begin(), v.end()
template <typename T> using v = vector<T>;
using ii = array<int, 2>;

// 3770. 대한민국

signed main() {
    fastio; int T; cin >> T;
    forf(ti, 1, T) {
        cout << "Test case " << ti << ": ";
        int n, m, k, ans=0; cin >> n >> m >> k;
        v<ii> arr;
        forf(i, 1, k) { int a, b; cin >> a >> b; arr.push_back({a, b}); }
        sort(all(arr));
        v<int> r(1010, 0);
        for(ii q : arr) {
            forf(i, q[1]+1, 1000) ans += r[i];
            r[q[1]]++;
        }
        cout << ans << '\n';
    }
}
