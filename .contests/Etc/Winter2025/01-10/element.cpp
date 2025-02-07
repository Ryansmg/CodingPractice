#ifdef LOCAL
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define _MAXN 100000

static int _selected[_MAXN + 1];
static int _numQueries;
static int _N;

static void _checkQuery(int i, int j) {
    if(i < 1 || i > _N || j < 1 || j > _N || i == j || _numQueries > 2 * _N) {
        assert(0);
    }
}

int debate(int i, int j) {
    _numQueries++;
    _checkQuery(i, j);
    return _selected[i] == _selected[j];
}

int element(int);

int main() {

    int _ret;
    _ret = scanf("%d",&_N);
    assert(_ret == 1);
    for(int i=1;i<=_N;i++) {
        _ret = scanf("%d",&_selected[i]);
        assert(_ret == 1);
    }

    int _answer = element(_N);

    printf("%d\n",_answer);
    printf("%d\n",_numQueries);

    return 0;
}
#else
#include "element.h"
#endif
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(i64 i=0; i<n; i++)

using i64 = long long;
using vl = vector<long long>;
class UF {
    bool useUnionFind = false; i64 n{};
    vl groupNum, groupSize;
    i64 uf_find(i64 tar) { if(groupNum[tar] == tar) return tar;
        return groupNum[tar] = uf_find(groupNum[tar]); }
    void uf_union(i64 a, i64 b) {
        if(uf_find(a) == uf_find(b)) return;
        if(groupSize[uf_find(a)] < groupSize[uf_find(b)]) swap(a, b);
        groupSize[uf_find(a)] += groupSize[uf_find(b)]; groupSize[uf_find(b)] = 0; groupNum[uf_find(b)] = uf_find(a);
    }
    void uf_init() {
        if(useUnionFind) { return; } useUnionFind = true;
        groupNum.resize(n, -1); groupSize.resize(n, 0);
        forn(i, n) groupNum[i] = i, groupSize[i] = 1;
    }
public:
    void merge(i64 a, i64 b) { uf_init(); uf_union(a, b); }
    explicit UF(i64 maxNodeNum) : n(maxNodeNum+1) { }
    /// union-find ( 0 <= group < nodeCnt ), O(N) (calls uf_find for all nodes)
    /// @return {[node] = group}
    [[nodiscard]] vl getAllGroup() { uf_init(); forn(i, n) groupNum[i] = uf_find(i);
        return groupNum; }
    vl getAllGroupSize() { uf_init(); return groupSize; }
    /// union-find ( 0 <= group < nodeCnt ), O(1) (O(N) at first uf call)
    i64 group(i64 node) { uf_init(); return uf_find(node); }
    /// union-find ( 0 <= group < nodeCnt ), O(1) (O(N) at first uf call)
    i64 size(i64 group) { uf_init(); return groupSize[group]; }
};


int element(int n) {
    int ans = 1, cnt = 1;
    UF uf(n);
    vector<vector<i64>> diff(n+1, vl());
    vector<i64> t; for(int i=2; i<=n; i++) t.emplace_back(i);
    shuffle(t.begin(), t.end(), mt19937(random_device()()));
    for(int i=2; i<=n; i++) {
        if(cnt == 0) ans = i;
        if(ans == i || debate(ans, i)) cnt++, uf.merge(ans, i);
        else cnt--, diff[ans].emplace_back(i), diff[i].emplace_back(ans);
    }
    set<i64> d;
    for(int i=1; i<=n; i++) if(uf.group(i) == uf.group(ans)) for(i64 j : diff[i]) d.emplace(j);
    int realCnt = 0;
    for(int i=1; i<=n; i++) {
        if(!d.contains(i) && (uf.group(ans) == uf.group(i) || debate(ans, i))) {
            realCnt++, uf.merge(ans, i);
            if(realCnt > n/2) return ans;
            for(i64 j : diff[i]) d.emplace(j);
        }
        if(realCnt + n - i <= n/2) return -1;
    }
    return realCnt > n/2 ? ans : -1;
}
