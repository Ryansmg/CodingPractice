#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
extern std::vector<int> findarray(int, std::vector<int>, std::vector<int>, std::vector<int>) ;
void assertion(bool x, int s) {
    if(x) return;
    else if(s < 0) puts("Wrong Input");
    else printf("Wrong Answer\n");
    exit(0);
}
static int N, Q;
int main() {
    assertion(scanf("%d%d", &N, &Q) == 2, -1);
    std::vector<int> L, R, A;
    for (int i = 0; i < Q; i++) {
        int l, r, a;
        assertion(scanf("%d%d%d", &l, &r, &a) == 3, -1);
        L.push_back(l);
        R.push_back(r);
        A.push_back(a);
    }
    std::vector<int> ans = findarray(N, L, R, A);
    for(int i = 0; i < N; i++) printf("%d ", ans[i]);
}

/////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define all(vec) (vec).begin(), (vec).end()
template <typename T> using v = vector<T>;
#define forn(i, n) for(int i=0; i<n; i++)
#define forf(i, s, e) for(int i=s; i<=e; i++)

v<int> par, sz;
int findPar(int n) {
    if(par[n] == n) return n;
    return par[n] = findPar(par[n]);
}
void setPar(int tar, int val) {
    sz[findPar(val)] += sz[findPar(tar)];
    par[findPar(tar)] = findPar(val);
}

class lazyprop {
    v<int> tree, lazy;
    int n;
public:
    explicit lazyprop(int size) {
        tree = lazy = v<int>(4*size+16, -1);
        n = size;
    }
    void update(int left, int right, int val) {
        update(1, 0, n-1, left, right, val);
    }
    void getLeafNodes(v<int> &ans) {
        getLeafNodes(1, 0, n-1, ans);
    }
private:
    void push(int node, int start, int end) {
        tree[node] = max(tree[node], lazy[node]);
        if(start != end) {
            lazy[node*2] = max(lazy[node*2], lazy[node]);
            lazy[node*2+1] = max(lazy[node*2+1], lazy[node]);
        }
        lazy[node] = -1;
    }
    int update(int node, int start, int end, int left, int right, int val) {
        push(node, start, end);
        if (end < left || right < start) return -1;
        if (left <= start && end <= right) {
            lazy[node] = val;
            push(node, start, end);
            return tree[node];
        }
        int mid = (start + end) / 2;
        return tree[node] = max(
                update(node * 2, start, mid, left, right, val),
                update(node * 2 + 1, mid + 1, end, left, right, val)
        );
    }
    void getLeafNodes(int node, int start, int end, v<int> &ans) {
        push(node, start, end);
        if(start==end) ans[start] = tree[node];
        else {
            int mid = (start+end)/2;
            getLeafNodes(node*2, start, mid, ans);
            getLeafNodes(node*2+1, mid+1, end, ans);
        }
    }
};

struct query {
    int l, r, a;
    query(int L, int R, int A) { l = L, r = R, a = A; }
};

bool cmp(const query &a, const query &b) {
    if(a.a != b.a) return a.a < b.a;
    if(a.l != b.l) return a.l < b.l; return a.r < b.r;
}

#define impossible v<int>(n, -1)
std::vector<int> findarray(int n, std::vector<int> L, std::vector<int> R, std::vector<int> A) {
    for(int i = 0; i <= n+10; i++) {
        par.push_back(i);
        sz.push_back(1);
    }
    int q = (int) L.size();
    v<query> queries;
    set<int> chk;
    forn(i, q) {
        queries.emplace_back(L[i], R[i], A[i]);
        chk.insert(A[i]);
    }
    sort(all(queries), cmp);
    lazyprop equal(n), larger(n);
    int preA = queries[0].a;
    int equalL = queries[0].l, equalR = queries[0].r;
    int largerL = equalL, largerR = equalR;
    forf(i, 1, q-1) {
        auto u = queries[i];
        if(preA != u.a) {
            equal.update(equalL, equalR, preA);
            larger.update(largerL, largerR, preA);
            equalL = largerL = u.l;
            equalR = largerR = u.r;
            preA = u.a;
            continue;
        }
        if(equalR < u.l || u.r < equalL) return impossible;
        equalL = max(equalL, u.l);
        largerL = min(largerL, u.l);
        equalR = min(equalR, u.r);
        largerR = max(largerR, u.r);
    }
    equal.update(equalL, equalR, preA);
    larger.update(largerL, largerR, preA);

    v<int> m1, m2, ans; m1.resize(n); m2.resize(n);
    ans = v<int>(n, -1);
    equal.getLeafNodes(m1);
    larger.getLeafNodes(m2);
    forn(i, n) {
        if(m1[i] == -1) continue;
        if(m1[i] < m2[i]) continue;
        if(findPar(m1[i]) != m1[i]) continue;
        ans[i] = m1[i];
        setPar(m1[i], m1[i]+1);
    }
    for(const int& i : chk)
        if(findPar(i) == i)
            return impossible;
    forn(i, n) {
        if(ans[i] != -1) continue;
        if(m2[i] == -1) {
            ans[i] = findPar(0);
            setPar(0, findPar(0)+1);
            continue;
        }
        if(findPar(m2[i]) >= n) return impossible;
        ans[i] = findPar(m2[i]);
        setPar(m2[i], findPar(m2[i])+1);
    }
    if(sz[n] != n+1) return impossible;
    return ans;
}
