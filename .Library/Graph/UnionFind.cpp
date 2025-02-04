/* Update : 2025-02-04 */

#include <bits/stdc++.h>

/// Union-Find
class UF {
    bool useUnionFind = false; long long n{};
    std::vector<signed> groupNum, groupSize;
    long long uf_find(long long tar) { if(groupNum[tar] == tar) return tar;
        return groupNum[tar] = uf_find(groupNum[tar]); }
    void uf_union(long long a, long long b) {
        if(uf_find(a) == uf_find(b)) return;
        if(groupSize[uf_find(a)] < groupSize[uf_find(b)]) std::swap(a, b);
        groupSize[uf_find(a)] += groupSize[uf_find(b)]; groupSize[uf_find(b)] = 0; groupNum[uf_find(b)] = uf_find(a);
    }
    void uf_init() {
        if(useUnionFind) { return; } useUnionFind = true;
        groupNum.resize(n, -1); groupSize.resize(n, 0);
        for(long long i = 0; i < n; i++) groupNum[i] = i, groupSize[i] = 1;
    }
public:
    void merge(long long a, long long b) { uf_init(); uf_union(a, b); }
    void clear() { useUnionFind = false; n = 0; groupNum = groupSize = std::vector<signed>(); }
    explicit UF(long long maxNodeNum) : n(maxNodeNum+1) { }
    /// union-find ( 0 <= parent <= maxNodeNum ), O(N) (calls uf_find for all nodes)
    /// @return {[node] = parent}
    [[nodiscard]] std::vector<signed> getAllGroup() { uf_init(); for(long long i = 0; i < n; i++) groupNum[i] = uf_find(i);
        return groupNum; }
    std::vector<signed> getAllGroupSize() { uf_init(); return groupSize; }
    /// union-find ( 0 <= parent <= maxNodeNum ), O(1) (O(N) at first uf call)
    long long group(long long node) { uf_init(); return uf_find(node); }
    /// union-find ( 0 <= parent <= maxNodeNum ), O(1) (O(N) at first uf call)
    long long size(long long group) { uf_init(); return groupSize[group]; }
};

/// Union-Find with Rollback
class UFR {
    signed n; std::vector<signed> parent, rank; std::stack<std::tuple<signed, signed, bool>> history;
public:
    explicit UFR(signed maxNodeNum) : n(maxNodeNum+1), parent(n), rank(n, 1) { iota(parent.begin(), parent.end(), 0); }
    inline signed group(signed x) { return x == parent[x] ? x : group(parent[x]); }
    inline signed operator[](signed x) { return group(x); } inline signed find(signed x) { return group(x); }
    void merge(signed a, signed b) {
        a = group(a); b = group(b);
        if(a == b) { history.emplace(a, b, false); return; }
        if(rank[a] < rank[b]) std::swap(a, b);
        bool rankIncrement = rank[a] == rank[b];
        history.emplace(a, b, rankIncrement);
        parent[b] = a; rank[a] += rankIncrement;
    }
    void rollback(signed cnt = 1) {
        for(long long k = 0; k < cnt; k++) {
            auto [a, b, i] = history.top(); history.pop();
            if(a != b) parent[b] = b, rank[a] -= i;
        }
    }
};

// Example : BOJ 1717. 집합의 표현
int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n, m; cin >> n >> m;
    UF uf(n);
    for(long long i = 0; i < m; i++) {
        long long op, a, b; cin >> op >> a >> b;
        if(op == 0) uf.merge(a, b);
        else cout << (uf.group(a) == uf.group(b) ? "YES" : "NO") << '\n';
    }
}
