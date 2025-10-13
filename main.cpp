#include <bits/stdc++.h>
#define ent '\n'
#define int long long

using namespace std;
typedef long long ll;

const int maxn = 500'012;

vector<int> g[maxn];
vector<pair<int, int>> u[maxn];
int first[maxn], last[maxn], cnt[maxn];
int t[maxn * 60];
signed L[maxn * 60], R[maxn * 60];
int a[maxn], root[maxn];
int n, m;
int nv;

int build(int l, int r) {
    int v = ++nv;
    if(l == r) {
        return v;
    }

    int mid = (l + r) >> 1;
    L[v] = build(l, mid);
    R[v] = build(mid + 1, r);
    return v;
}

int copy(int v) {
    int u = ++nv;

    t[u] = t[v];
    L[u] = L[v], R[u] = R[v];
    return u;
}

int upd(int v, int tl, int tr, int pos, int x) {
    if(pos > tr || pos < tl) return v;
    int u = copy(v);

    if(tl == tr) {
        t[u] += x;
        return u;
    }

    int mid = (tl + tr) >> 1;
    if(pos <= mid) {
        L[u] = upd(L[v], tl, mid, pos, x);
    }
    else {
        R[u] = upd(R[v], mid + 1, tr, pos, x);
    }
    t[u] = t[L[u]] + t[R[u]];
    return u;
}

int get(int v, int tl, int tr, int l, int r) {
    if(tl > r || l > tr) return 0;
    if(tl >= l && tr <= r) return t[v];
    int mid = (tl + tr) >> 1;
    return get(L[v], tl, mid, l, r) + get(R[v], mid + 1, tr, l, r);
}

void append(int lx, int rx, int ly, int ry, int x) {
    if(lx > rx || ly > ry) return;

    u[lx].push_back({ly, x});
    u[lx].push_back({ry + 1, -x});
    u[rx + 1].push_back({ly, -x});
    u[rx + 1].push_back({ry + 1, x});
}

void work(int l, int r) {
    if(l > r) return;
    int mid = last[a[l]];

    if(cnt[a[l]] % 2) {
        append(1, l,  mid, n, a[l]);
    }

    for(int i = 0; i + 1 < g[a[l]].size(); i++) {
        int tl = g[a[l]][i], tr = g[a[l]][i + 1];

        if((cnt[a[l]] - i) % 2 == 0) {
            append(tl + 1, tr, mid, n, a[l]);
        }
        if(i % 2 == 0) {
            append(1, l, tl, tr - 1, a[l]);
        }
    }

    for(int i = 0; i + 1 < g[a[l]].size(); i++) {
        work(g[a[l]][i] + 1, g[a[l]][i + 1] - 1);
    }

    work(mid + 1, r);
}

set<signed> s[maxn];

void upd(int i, int x) {
    for(; i <= n; i |= (i + 1)) {
        s[i].insert(x);
    }
}

int get(int i, int x) {
    int val = 1e18;
    for(; i >= 0; i = (i & (i + 1)) - 1) {
        auto it = s[i].lower_bound(x);

        if(it != s[i].end()) {
            val = min(val, (int)*it);
        }
    }

    return val;
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        if(!first[a[i]]) {
            first[a[i]] = i;
        }
        last[a[i]] = i;
        cnt[a[i]]++;
        g[a[i]].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
        if(i == first[a[i]]) {
            upd(i, last[a[i]]);
        }
    }

    work(1, n);

    root[0] = build(1, n);

    for(int i = 1; i <= n; i++) {
        root[i] = root[i - 1];
        for(auto [pos, x] : u[i]) {
            root[i] = upd(root[i], 1, n, pos, x);
        }
    }

    int prv = 0;
    while(m--) {
        int x, y;
        cin >> x >> y;

        int l = (x + prv - 1) % n + 1, r = (y + prv - 1) % n + 1;

        if(l > r) swap(l, r);

        int ans = get(root[l], 1, n, 1, r);
        int tr = get(l, r);

        if(tr <= n) {
            int tl = first[a[tr]];
            if(tl < l && r < tr) {
                int x = a[tl];
                auto pl = lower_bound(g[x].begin(), g[x].end(), l) - g[x].begin();
                auto pr = upper_bound(g[x].begin(), g[x].end(), r) - g[x].begin();

                if((pr - pl) % 2 == 1) {
                    ans += x;
                }
            }
        }
        cout << ans << ' ';
        prv = ans;
    }
    cout << ent;

    for(int i = 0; i <= n + 5; i++) {
        first[i] = last[i] = root[i] = cnt[i] = 0;
        g[i].clear(), u[i].clear(), s[i].clear();
    }

    for(int i = 0; i <= nv + 5; i++) {
        t[i] = L[i] = R[i] = 0;
    }

    nv = 0;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}