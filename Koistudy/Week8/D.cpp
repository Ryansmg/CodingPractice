#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using f64 = double;
#define forn(i, n) for(i64 i = 0; i < n; i++)
#define forf(i, a, b) for(i64 i = a; i <= b; i++)
#define all(v) (v).begin(), (v).end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

f64 arr[300010];
vector<f64> bucket[600];
int sq = 1000;
int n, q;

void upd(int pos, f64 val) {
    int vi = pos/sq;
    bucket[vi].erase(lower_bound(all(bucket[vi]), arr[pos]));
    arr[pos] = val;
    vector<f64> t1 = { val }, t2 = bucket[vi];
    bucket[vi].push_back(0);
    merge(all(t1), all(t2), bucket[vi].begin());
}

i64 query(int pos) {
    f64 a = arr[pos];
    i64 ans = 0;
    for(const auto& b : bucket)
        ans += b.end() - upper_bound(all(b), a);
    return ans;
}

int main() {
    fastio;
    cin >> n;
    forn(i, n) cin >> arr[i];
    forn(vi, 600) {
        for(int i = vi*sq; i < vi*sq + sq && i < n; i++)
            bucket[vi].push_back(arr[i]);
        sort(all(bucket[vi]));
    }
    cin >> q;
    forn(Q, q) {
        int op; cin >> op;
        if(op == 1) {
            int a; cin >> a; a--;
            cout << query(a) + 1 << '\n';
        } else {
            int a; f64 b; cin >> a >> b; a--;
            upd(a, b);
        }
    }
}
