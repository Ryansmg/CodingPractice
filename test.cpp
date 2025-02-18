//code by p1ckle/sft/yukicoder
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long int
#define F first
#define X first
#define S second
#define Y second
#define mid ((start+end)/2)
#define all(x) x.begin(), x.end()
#define ub(a, b) upper_bound(all(a), b)
#define lb(a, b) lower_bound(all(a), b)
#define pb push_back
#define endl '\n'

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int inf = 1e18, mod = 1e9+7;

int n, q, T;
vi vq;
int a[200003], b[200003], s[200003];

int seg[800013];
int init(int start, int end, int idx) {

    if (start == end) return seg[idx] = b[start];
    return seg[idx] = max(init(start, mid, idx*2), init(mid+1, end, idx*2+1));

}

int query(int start, int end, int idx, int left, int right) {

    if (start > right || end < left) return 0;
    if (start >= left && end <= right) return seg[idx];
    return max(query(start, mid, idx*2, left, right), query(mid+1, end, idx*2+1, left, right));

}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {

        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> a[n-i+1];
        for (int i = 1; i <= n; i++) {

            s[i] = (a[i]^s[i-1]);
            int t = 0, nt = a[i];
            while (nt > 0) {

                nt >>= 1;
                t++;

            }
            b[i] = t;

        }
        b[n+1] = 31; a[n+1] = 2147483647;
        init(1, n+1, 1);

        while (q--) {

            int x, xb = 0; cin >> x;
            int xt = x;
            while (xt > 0) {xt >>= 1; xb++;}

            int ans = 0;
            while (1) {

                int st = ans+1, ed = n, cn = ans+1;
                while (st <= ed) {

                    int m = (st+ed)/2;
                    int tm = query(1, n, 1, ans+1, m);

                    if (tm < xb) {

                        st = m+1;
                        cn = m;

                    }
                    else ed = m-1;

                }

                st = cn;
                ans = st-1;
                if ((x^s[st-1]) < a[st]) break;
                ans = st;

                xt = (x^s[ans]); xb = 0;
                while (xt > 0) {xt >>= 1; xb++;}

            }
            cout << ans << ' ';

        }
        cout << endl;

    }

}