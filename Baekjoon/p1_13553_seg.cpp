#include <bits/stdc++.h>
using namespace std; using L = long long;
#define forf(i,s,e) for(L i=s;i<=e;i++)
using vl = vector<L>;

// 13553. 수열과 쿼리 8
// #mo #segtree

struct Fenwick {
    vl tree; L n;
    explicit Fenwick(L treeSize) { n = treeSize; tree = vl(treeSize+9, 0); }
    void update(L tar, L val) { while(tar < n) tree[tar] += val, tar += (tar & -tar); }
    L query(L left, L right) { if(left==1) return query(right); return query(right) - query(left-1); }
    L query(L tar) { L ans = 0; while(tar > 0) ans += tree[tar], tar -= (tar & -tar);  return ans; }
};

L sqrtCnt; //sqrt(쿼리의 개수)
struct query {
    L i, j, order; query()=default;
    query(L a, L b, L c) { i = a; j = b; order = c; }
    bool operator<(const query &b) const {
        L a = i / sqrtCnt, a2 = b.i / sqrtCnt;
        if(a == a2) return j < b.j; return a < a2;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    L n, k, l, r; cin >> n >> k;
    vl arr(n); forf(i,0,n-1)cin>>arr[i];
    L m; cin>>m; sqrtCnt = sqrt(m);
    vector<query> queries;
    forf(i, 0, m-1) {cin>>l>>r; queries.emplace_back(l, r, i); }
    sort(queries.begin(), queries.end());
    vl ans(m); L cur = 0;
    Fenwick seg(100010);
    auto q = [&](L i) -> L { return seg.query(max(1LL, arr[i-1]-k), min(100009LL, arr[i-1]+k)); };
    l = queries[0].i, r = queries[0].j;
    forf(i, l, r) cur += q(i), seg.update(arr[i-1], 1);
    ans[queries[0].order] = cur;
    forf(i, 1, m-1) {
        L nl = queries[i].i, nr = queries[i].j;
        while(l < nl) seg.update(arr[l-1], -1), cur -= q(l++);
        while(nr < r) seg.update(arr[r-1], -1), cur -= q(r--);
        while(nl < l) cur += q(--l), seg.update(arr[l-1], 1);
        while(r < nr) cur += q(++r), seg.update(arr[r-1], 1);
        ans[queries[i].order] = cur;
    }
    for(L i:arr) cout<<i<<'\n';
}
