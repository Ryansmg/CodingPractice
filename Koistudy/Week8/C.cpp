#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define forn(i, n) for(i64 i = 0; i < n; i++)
#define forf(i, a, b) for(i64 i = a; i <= b; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
    fastio;
    int n, q; cin >> n >> q;
    int sq = 600; // sqrt(n) 하면 TLE
    vector<i64> arr(n + 1);
    vector<i64> bucket(sq + 2);

#define push(i) \
    if(bucket[i/sq]) { \
        forf(j, i/sq*sq, i/sq*sq + sq - 1) { \
            arr[j] = bucket[j/sq];\
        } \
        bucket[i/sq] = 0; \
    }

    forn(Q, q) {
        i64 a, b, c; cin >> a >> b >> c;
        a--; b--;
        for(; a%sq && a<=b; a++) {
            push(a);
            arr[a] = c;
        }
        for(; (b+1)%sq && a<=b; b--) {
            push(b);
            arr[b] = c;
        }
        for(; a<=b; a+=sq) bucket[a/sq] = c;
    }
    forn(i, n) {
        push(i);
        cout << arr[i] << ' ';
    }
}
