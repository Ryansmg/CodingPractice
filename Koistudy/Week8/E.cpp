#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using f64 = double;
#define forn(i, n) for(i64 i = 0; i < n; i++)
#define forf(i, a, b) for(i64 i = a; i <= b; i++)
#define all(v) (v).begin(), (v).end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int arr[100010];
int bucket[310];
int in[100010];
int sq = 400;

void add(int pos) { arr[pos]++; bucket[pos/sq]++; }
int query(int l, int r) {
    int ret = 0;
    for(; l % sq && l <= r; l++) ret += arr[l];
    for(; (r + 1) % sq && l <= r; r--) ret += arr[r];
    for(; l <= r; l += sq) ret += bucket[l / sq];
    return ret;
}

int main() {
    fastio;
    int n; cin >> n;
    forn(i, n) cin >> in[i];
    i64 ans = 0;
    forn(i, n) {
        ans += query(in[i]+1, 100005);
        add(in[i]);
    }
    cout << ans;
}
