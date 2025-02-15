/* Update : 2025-02-11 */

#include <vector>
#include <functional>


/// requirements: (TreeType + TreeType), (LazyType + UpdateType), (TreeType + LazyIter&&), (LazyType + LazyIter&&)
/// <br> usage: node merge, node update, lazy update, lazy update
template <typename TreeType, typename LazyType, typename UpdateType>
class Lazyprop {
public:
    /// tree & lazy are copied values, should not be modified
    struct iter {
        signed node, start, end; TreeType tree; LazyType lazy; Lazyprop* segPtr;
        iter left() { segPtr->push(node<<1, start, (start+end)>>1);
            return iter(node<<1, start, (start+end)>>1, segPtr->tree[node<<1], segPtr->lazy[node<<1], segPtr); }
        iter right() { segPtr->push(node<<1|1, ((start+end)>>1)+1, end);
            return iter(node<<1|1, ((start+end)>>1)+1, end, segPtr->tree[node<<1|1], segPtr->lazy[node<<1|1], segPtr); }
        bool leaf() { return start == end; }
    };
protected:
    std::vector<TreeType> tree; std::vector<LazyType> lazy; signed n=-1;
    void push(signed node, signed start, signed end) {
        tree[node] = tree[node] + iter(node, start, end, tree[node], lazy[node], this);
        if(start!=end) { lazy[node<<1] = lazy[node<<1] + iter(node, start, end, tree[node], lazy[node], this);
            lazy[node<<1|1] = lazy[node<<1|1] + iter(node, start, end, tree[node], lazy[node], this); }
        lazy[node] = LazyType();
    }
public:
    explicit Lazyprop(signed treeSize) { tree = std::vector<TreeType>(4*treeSize, TreeType()); lazy = std::vector<LazyType>(4*treeSize, LazyType()); n = treeSize; }
    explicit Lazyprop(const std::vector<TreeType> &a) : Lazyprop((signed) a.size()) { init(a, 1, 1, n); }
    void update(signed left, signed right, UpdateType diff) { if(left > right) { return; } update(1, left, right, 1, n, diff); }
    TreeType query(signed left, signed right) { if(left > right) { return TreeType(); } return query(1, left, right, 1, n); }
    TreeType query(signed tar) { return query(tar, tar); }
    iter root() { push(1, 1, n); return iter(1, 1, n, tree[1], lazy[1], this); }
    // ret[i] == query(i+1)
    std::vector<TreeType> getLeafs() { std::vector<TreeType> ret(n);
        std::function<void(long long, long long, long long)> f = [&](long long p, long long s, long long e) { push(p, s, e);
            if(s == e) ret[s-1] = tree[p];
            else f(p<<1, s, (s+e)>>1), f(p<<1|1, ((s+e)>>1)+1, e); };
        f(1, 1, n); return ret; }
protected:
    TreeType& init(const std::vector<TreeType> &a, signed node, signed start, signed end) {
        if(start==end) return tree[node] = a[start-1];
        else return tree[node] = init(a, node<<1, start, (start+end)>>1) + init(a, node<<1|1, ((start+end)>>1)+1, end);
    }
    TreeType& update(signed node, signed left, signed right, signed start, signed end, UpdateType diff) {
        push(node, start, end); if(end < left || right < start) return tree[node];
        if(left <= start && end <= right) { lazy[node] = lazy[node] + diff; push(node, start, end); return tree[node]; }
        return tree[node] = update(node<<1, left, right, start, (start+end)>>1, diff) + update(node<<1|1, left, right, ((start+end)>>1)+1, end, diff);
    }
    TreeType query(signed node, signed left, signed right, signed start, signed end) {
        push(node, start, end); if(right < start || end < left) return TreeType();
        if(left <= start && end <= right) return tree[node];
        return query(node<<1, left, right, start, (start+end)>>1) + query(node<<1|1, left, right, ((start+end)>>1)+1, end);
    }
};

struct SumLazy {
    long long v = 0;
    SumLazy operator+(long long i) const {
        return SumLazy(v + i);
    }
    SumLazy operator+(const Lazyprop<long long, SumLazy, long long>::iter& i) const {
        return SumLazy(v + i.lazy.v);
    }
};
long long operator+(long long a, const Lazyprop<long long, SumLazy, long long>::iter& b) {
    return a + (b.end - b.start + 1) * b.lazy.v;
}

// Example : BOJ 10999. 구간 합 구하기 2
#include <iostream>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    Lazyprop<long long, SumLazy, long long> seg(arr); // 기본 구간 합 세그먼트 트리
    for(int i = 0; i < m + k; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) {
            int d; cin >> d;
            seg.update(b, c, d);
        } else {
            cout << seg.query(b, c) << '\n';
        }
    }
}