//#include "numbers.h"
#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
bool numbers(std::vector<int>, std::vector<int>, std::vector<int>, std::vector<int>) ;
void init();

void assertion(bool x, int s) {
    if(x) return;
    else if(s < 0) puts("Wrong Input");
    else printf("Wrong Answer\n");
    exit(0);
}

static int T;

int main() {
    assertion(scanf("%d", &T) == 1, -1);
    init();
    for(int tc = 1; tc <= T; tc++) {
        std::vector<int> A, B, U, V;
        int N, M;
        assertion(scanf("%d%d", &N, &M) == 2, -1);
        for(int i = 0; i < N; i++) {
            int c;
            assertion(scanf("%d", &c) == 1, -1);
            A.push_back(c);
        }
        for(int i = 0; i < N; i++) {
            int c;
            assertion(scanf("%d", &c) == 1, -1);
            B.push_back(c);
        }
        for(int i = 0; i < M; i++) {
            int u, v;
            assertion(scanf("%d%d", &u, &v) == 2, -1);
            U.push_back(u);
            V.push_back(v);
        }
        bool result = numbers(A, B, U, V);
        if(result) printf("1\n");
        else printf("0\n");
    }
}

///////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
using i32 = int; using i64 = long long;
const i64 i64max = 9223372036854775807;
const i64 INF    = 1000000000000000000;
const i64 inf    = 3000000000;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
#define forn(i, n) for(i64 i=0; i<n; i++)
#define forf(i, a, b) for(i64 i=a; i<=b; i++)
#define all(vec) (vec).begin(), (vec).end()
template <typename T> void sort(v<T> &arr) { sort(all(arr)); }
template <typename T> void compress(v<T> &arr, bool autosort = true) { if(autosort) sort(arr); arr.erase(unique(all(arr), arr.end())); }
i64 idx(i64 val, const v<i64> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

struct seg {
    i32 n; v<i32> tree;
    explicit seg(const v<int> &arr) {
        n = (i32) arr.size();
        tree = v<i32>(4*n+10, -1);
        init(arr, 1, 1, n);
    }
    i32 query(i32 l, i32 r) {
        return query(1, 1, n, l, r);
    }
    i32 init(const v<int> &arr, i32 node, i32 start, i32 end) {
        if(start == end) return tree[node] = arr[start-1];
        i32 mid = (start+end)/2;
        return tree[node] = max(
                init(arr, node*2, start, mid),
                init(arr, node*2+1, mid+1, end)
            );
    }
    i32 query(i32 node, i32 start, i32 end, i32 left, i32 right) {
        if(end < left || right < start) return -1;
        if(left <= start && end <= right) return tree[node];
        i32 mid = (start+end)/2;
        return max(
                query(node*2, start, mid, left, right),
                query(node*2+1, mid+1, end, left, right)
        );
    }
};

void init() { }

void tleassert(bool b) { while(!b) cout << ""; }
void mleassert(bool b) {
    if(b) return;
    std::vector<i64> arr(214748364, 1), arr2(214748364, 1), arr3(214748364, 1);
    for(i64 i : arr) cout << i; for(i64 i : arr2) cout << i; for(i64 i : arr3) cout << i;
}

bool numbers(std::vector<int> A, std::vector<int> B, std::vector<int> U, std::vector<int> V) {
    // 스타 그래프 가정
    int N = (i32) A.size();
    int M = (i32) U.size();
    if(N==1) return A[0]==B[0];
    mleassert(M == N-1);
    forn(i, N) if(A[i] < B[i]) return false;
    v2<int> con(N+10, v<int>());
    set<int> s;
    for(const int &i : A) s.insert(i);
    for(const int &i : B) if(s.find(i) == s.end()) return false;
    i64 center = -1;
    forn(i, M) {
        con[U[i]].push_back(V[i]);
        con[V[i]].push_back(U[i]);
        if(s.find(U[i]) != s.end()) center = U[i];
        else s.insert(U[i]);
        if(s.find(V[i]) != s.end()) center = V[i];
        else s.insert(V[i]);
    }
    tleassert(center != -1);
    i64 ac = A[center-1];
    forn(i, N) if(A[i] != B[i] && B[i] > ac) return false;
    return true;
}
//    int N = (i32) A.size();
//    v2<int> con(N+10, v<int>());
//    v<bool> vis(N+10, false);
//    int M = (i32) U.size();
//    // 체인 그래프 가정
//    mleassert(M == N-1);
//    forn(i, N) if(A[i] < B[i]) return false;
//    set<int> s;
//    for(const int &i : A) s.insert(i);
//    for(const int &i : B) if(s.find(i) == s.end()) return false;
//    s = set<int>();
//    forn(i, M) {
//        con[U[i]].push_back(V[i]);
//        con[V[i]].push_back(U[i]);
//        if(s.find(U[i]) != s.end()) s.erase(U[i]);
//        else s.insert(U[i]);
//        if(s.find(V[i]) != s.end()) s.erase(V[i]);
//        else s.insert(V[i]);
//    }
//    i64 st = *s.begin();
////    mleassert(st != -1);
//    tleassert(s.size() == 2);
//    queue<i32> q; q.push(st); vis[st] = true;
//    v<i32> chain;
//    while(!q.empty()) {
//        i32 t = q.front(); q.pop();
//        chain.push_back(t);
//        for(i32 i : con[t]) {
//            if(vis[i]) continue;
//            vis[i] = true;
//            q.push(i);
//        }
//    }
//    v<int> na, nb;
//    v2<int> aIdx(N+10, v<int>());
//    forn(i, N) {
//        na.push_back(A[chain[i]-1]);
//        aIdx[na[i]].push_back(i);
//        nb.push_back(B[chain[i]-1]);
//    }
//    seg seg(nb);
//    forn(i, N) {
//        if(na[i] == nb[i]) continue;
//        bool isAvailable = false;
//        auto ptr = lower_bound(all(aIdx[nb[i]]), i);
//        if(ptr != aIdx[nb[i]].end())
//            if(seg.query(i+1, *ptr+1) == nb[i]) isAvailable = true;
//        if(ptr != aIdx[nb[i]].begin()) {
//            ptr--;
//            if(seg.query(*ptr+1, i+1) == nb[i]) isAvailable = true;
//        }
//        if(!isAvailable) return false;
//    }
//
//    return true;
//}

/*
1
5 4
1 2 3 4 5
1 2 3 4 5
1 5
1 4
4 3
5 2
 */

/*
bool numbers(std::vector<int> A, std::vector<int> B, std::vector<int> U, std::vector<int> V) {
    int N = (i64) A.size();
    int M = (i64) U.size();
    // 완전 그래프 가정
    forn(i, N) if(A[i] < B[i]) return false;
    set<int> s;
    for(const int &i : A) s.insert(i);
    for(const int &i : B) if(s.find(i) == s.end()) return false;
    return true;
}
 */