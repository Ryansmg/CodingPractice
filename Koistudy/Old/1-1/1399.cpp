#include <bits/stdc++.h>
using namespace std;
#define int long long
#define i64 long long
#define v vector
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
int input() {int i; cin >> i; return i;}

class lazyprop {
protected:
    v<int> tree, lazy; int n=-1;
public:
    lazyprop(){};
    explicit lazyprop(int treeSize) {
        lazy = tree = v<int>(4*treeSize, 0); n = treeSize;
        init(1, 1, n);
    }
    void update(int left, int right, int diff) { update(1, left, right, 1, n, diff); }
    int query(int left, int right) { return query(1, left, right, 1, n); }
protected:
    void push(int node, int start, int end) {
        tree[node] += lazy[node] * (end-start+1);
        if(start!=end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    int init(int node, int start, int end) {
        if(start==end) return tree[node]=1;
        else return tree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
    }
    int update(int node, int left, int right, int start, int end, int diff) {
        push(node, start, end);
        if(end < left || right < start) return 0;
        if(left <= start && end <= right) {
            lazy[node] += diff;
            push(node, start, end);
            return tree[node];
        }
        return tree[node] = update(node*2, left, right, start, (start+end)/2, diff) +
                            update(node*2+1, left, right, (start+end)/2+1, end, diff);
    }
    int query(int node, int left, int right, int start, int end) {
        push(node, start, end);
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return tree[node];
        return query(node*2, left, right, start, (start+end)/2) + query(node*2+1, left, right, (start+end)/2+1, end);
    }
};

// 콩 모으기

lazyprop seg;
i64 t = 1;
i64 n;

i64 update(i64 start, i64 len) {
    if(start == n) {
        seg.update(1, len, 1);
        return len;
    }
    if (start + len <= n) {
        seg.update(start + 1, start + len, 1);
        return start + len;
    }
    seg.update(start+1, n, 1); seg.update(1, start + len - n, 1);
    return start + len - n;
}

signed main() {
//    fastio;
    for(int i=1000000; i<=1000000; i++) {
        n = i;
        t = 1;
        seg = lazyprop(n);
        while (true) {
            i64 cur = seg.query(t, t);
            if (cur == n) {
                cout << t << ',';
                break;
            }
            seg.update(t, t, -cur);
            t = update(t, cur);
        }
    }
}
