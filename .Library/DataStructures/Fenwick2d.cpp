/* Update : 2025-01-23 */

#include <bits/stdc++.h>
using namespace std;


struct Fenwick2d {
    vector<vector<long long>> tree; signed xn, yn;
    explicit Fenwick2d(signed xlen, signed ylen) : xn(xlen), yn(ylen) { tree.resize(xlen+10, vector<long long>(ylen+10, 0)); }
    void update(signed x, signed y, long long v){ for(; x<=xn; x+=x&-x) for(signed yy=y; yy<=yn; yy+=yy&-yy) tree[x][yy] += v; }
    long long query(signed x, signed y) { long long ret = 0; for(; x; x-=x&-x) for(signed yy=y; yy; yy-=yy&-yy) ret += tree[x][yy];
        return ret; }
    long long query(signed x1, signed y1, signed x2, signed y2) { return query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1); }
};

// Example : BOJ 11658. 구간 합 구하기 3
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, t; cin >> n >> m;
    Fenwick2d seg(n, n);
    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= n; y++) {
            cin >> t; seg.update(x, y, t);
        }
    }
    for(int i = 0; i < m; i++) {
        int w; cin >> w;
        if(w == 0) {
            int x, y, c; cin >> x >> y >> c;
            seg.update(x, y, c - seg.query(x, y, x, y));
        } else {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            cout << seg.query(x1, y1, x2, y2) << '\n';
        }
    }
}