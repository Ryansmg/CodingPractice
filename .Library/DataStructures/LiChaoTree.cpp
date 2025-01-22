/* Update : 2025-01-23 */

#include <bits/stdc++.h>
using namespace std;

class LiChaoTree {
public:
    struct Line { long long a = 0, b = 9223372036854775807; long long operator[](long long x) const { return a*x+b; } };
    LiChaoTree() : left(0), right(0) {}
    LiChaoTree(long long l, long long r, bool useMaxQuery = false) : left(l), right(r) { tr.emplace_back(); if(useMaxQuery) mode = -1; }
    void update(const Line& line) { update({mode*line.a, mode*line.b}, 0, left, right); }
    void update(long long a, long long b) { update({mode*a, mode*b}, 0, left, right); }
    void updateAt(long long l, long long r, const Line& line) { updateAt(l, r, 0, left, right, {mode*line.a, mode*line.b}); }
    long long query(long long x) const { return mode*query(x, 0, left, right); }
    long long operator[](long long x) const { return mode*query(x, 0, left, right); }
private:
    struct Node { signed l = -1, r = -1; Line line = Line(); };
    vector<Node> tr; long long left, right; long long mode = 1;
    void updateAt(long long l, long long r, long long p, long long s, long long e, const Line& line) {
        if(r < s || e < l) return;
        if(l <= s && e <= r) { update(line, p, s, e); return; }
        if(tr[p].l == -1) tr[p].l = int(tr.size()), tr.emplace_back();
        if(tr[p].r == -1) tr[p].r = int(tr.size()), tr.emplace_back();
        updateAt(l, r, tr[p].l, s, (s+e)/2, line);
        updateAt(l, r, tr[p].r, (s+e)/2+1, e, line);
    }
    void update(const Line& line, long long p, long long s, long long e) {
        long long m = (s + e) >> 1; Line low = tr[p].line, high = line;
        if(low[s] > high[s]) swap(low, high);
        if(low[e] <= high[e]) { tr[p].line = low; return; }
        if(low[m] < high[m]) {
            tr[p].line = low;
            if(tr[p].r == -1) tr[p].r = int(tr.size()), tr.emplace_back();
            update(high, tr[p].r, m+1, e);
        } else {
            tr[p].line = high;
            if(tr[p].l == -1) tr[p].l = int(tr.size()), tr.emplace_back();
            update(low, tr[p].l, s, m);
        }
    }
    long long query(long long x, long long p, long long s, long long e) const {
        if(p == -1) { return 9223372036854775807; } long long m = (s + e) >> 1;
        if(x <= m) return min(tr[p].line[x], query(x, tr[p].l, s, m));
        return min(tr[p].line[x], query(x, tr[p].r, m+1, e));
    }
};

// Example : BOJ 12795. 반평면 땅따먹기
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    LiChaoTree lct(-2000000000000, 2000000000000, true);
    int Q; cin >> Q;
    for(int i = 0; i < Q; i++) {
        int op; cin >> op;
        if(op == 1) {
            int a, b; cin >> a >> b;
            lct.update({a, b});
        } else {
            int x; cin >> x;
            cout << lct.query(x) << '\n';
        }
    }
}