#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = signed;
template <typename T> using v = vector<T>;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define forn(i, n) for(i64 i=0; i<n; i++)
#define forf(i, a, b) for(i64 i=a; i <= b; i++)
#define Size(v) ((i64) v.size())

i64 mod = 1000000007;

v<i64> par, in, out, inRev;
v<v<i64>> child;

struct lz {
    i64 checkPar = -1, cpa = 1, cpb = 0;
    i64 a = 1, b = 0;
    lz() = default;
    lz(i64 A, i64 B) : a(A), b(B) {}
    lz(i64 P, i64 A, i64 B) : checkPar(P), cpa(A), cpb(B) {}
};

v<i64> tree; v<lz> lazy;

void push(i64 node, i64 start, i64 end) {
    if(lazy[node].a != 1 || lazy[node].b != 0) {
        if(start == end) {
            tree[start] *= lazy[node].a;
            tree[start] += lazy[node].b;
        } else {
            if(lazy[node*2].checkPar != -1) push(node*2, start, (start+end)/2);
            lazy[node*2].a *= lazy[node].a;
            lazy[node*2].b = lazy[node].a * lazy[node*2].b + lazy[node].b;
            if(lazy[node*2+1].checkPar != -1) push(node*2+1, (start+end)/2+1, end);
            lazy[node*2+1].a *= lazy[node].a;
            lazy[node*2+1].b = lazy[node].a * lazy[node*2+1].b + lazy[node].b;
        }
    }
    lazy[node].a = 1; lazy[node].b = 0;
    if(lazy[node].checkPar != -1) {
        if(start == end) {
            // if(!(inRev[start] == lazy[node].checkPar || par[inRev[start]] == lazy[node].checkPar)) {
            //     cerr << "asdf"; exit(1);
            // }
            tree[start] *= lazy[node].cpa;
            tree[start] += lazy[node].cpb;
        } else {
            i64 ts = start, te = (start+end)/2;
            for(i64 ptr = node*2; ptr <= node*2+1; ptr++) {
                if(inRev[ts] != 1 && in[par[inRev[ts]]] > in[lazy[node].checkPar]) {
                    ts = (start+end)/2+1; te = end;
                    continue;
                }
                if(lazy[ptr].checkPar == -1 || lazy[ptr].checkPar == lazy[node].checkPar) {
                    lazy[ptr].checkPar = lazy[node].checkPar;
                    lazy[ptr].cpa *= lazy[node].cpa;
                    lazy[ptr].cpb = lazy[node].cpa * lazy[ptr].cpb + lazy[node].cpb;
                } else {
                    push(ptr, ts, te);
                    lazy[ptr] = lazy[node];
                }

                ts = (start+end)/2+1; te = end;
            }
        }
        lazy[node].cpa = 1; lazy[node].cpb = 0; lazy[node].checkPar = -1;

    }
}

void update(i64 node, i64 start, i64 end, i64 left, i64 right, lz diff) {
    push(node, start, end);
    if(end < left || right < start) return;
    if(left <= start && end <= right) {
        lazy[node] = diff;
        push(node, start, end);
        return;
    }
    update(node*2, start, (start+end)/2, left, right, diff);
    update(node*2+1, (start+end)/2+1, end, left, right, diff);
}

i64 query(i64 node, i64 start, i64 end, i64 tar) {
    push(node, start, end);
    if(start == end) return tree[start];
    if(tar <= (start + end) / 2) return query(node*2, start, (start+end)/2, tar);
    return query(node*2+1, (start+end)/2+1, end, tar);
}

i64 ettn = 0;
void ett(i64 node, i64 par = -1) {
    in[node] = ++ettn;
    for(const i64 i : child[node]) {
        if(i == par) continue;
        ett(i, node);
    }
    out[node] = ettn;
}

i32 main() {
    fastio;
    i64 n; cin >> n;
    tree = v<i64>(n+1, 0);
    lazy = v<lz>(4*n+10, lz());
    v<i64> arr(n+1, 0);
    forf(i, 1, n) cin >> arr[i];
    par = in = out = inRev = v<i64>(n+1, -1);
    child = v<v<i64>>(n+1, v<i64>());
    forf(i, 2, n) {
        int p; cin >> p;
        par[i] = p; child[p].push_back(i);
    }
    ett(1);
    forf(i, 1, n) inRev[in[i]] = i;
    forf(i, 1, n) tree[in[i]] = arr[i];
    i64 q; cin >> q;
    forn(asdf, q) {
        i64 t, v, a, b; cin >> t >> v;
        if(t == 1) {
            cin >> a >> b;
            if(par[v] != -1) update(1, 1, n, par[v], par[v], lz(a, b));
            update(1, 1, n, in[v], out[v], lz(v, a, b));
        } else if(t == 2) {
            cin >> a >> b;
            update(1, 1, n, in[v], out[v], lz(a, b));
        } else {
            cout << query(1, 1, n, in[v]) << '\n';
        }
    }
}
