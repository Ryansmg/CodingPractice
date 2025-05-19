#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 arr[510][510];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, q; cin >> n >> q;
    for(int i = 0; i < q; i++) {
        int r1, c1, r2, c2, w;
        cin >> r1 >> c1 >> r2 >> c2 >> w;
        arr[r1][c1] += w;
        arr[r2+1][c1] -= w;
        arr[r1][c2+1] -= w;
        arr[r2+1][c2+1] += w;
    }

    for(int r = 1; r <= n; r++)
        for(int c = 1; c <= n; c++)
            arr[r][c] += arr[r][c-1];
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= n; c++)
            cout << (arr[r][c] += arr[r-1][c]) << " ";
        cout << "\n";
    }
}
