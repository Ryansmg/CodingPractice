#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 arr[100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, q; cin >> n >> q;
    for(int i = 0; i < q; i++) {
        int a, b, w; cin >> a >> b >> w;
        arr[a] += w; arr[b+1] -= w;
    }
    for(int i = 1; i <= n; i++) cout << (arr[i] += arr[i-1]) << " ";
}
