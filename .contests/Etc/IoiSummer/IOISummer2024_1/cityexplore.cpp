#include <cstdio>
#include <vector>
#include <cstdlib>

#define NMAX  1400
#define DMAX  7
#define QMAX  45000

extern void city_explore(int T, int N) ;

static int T,N,M,Asktotal,Answertotal;
static int edge_list[NMAX][DMAX];
static int checked[NMAX][DMAX];
static int degree[NMAX];
static int visited[NMAX];
static void WA(int wa_num) {
    printf("Wrong Answer[%d]\n",wa_num);
    exit(0);
}

void assertion(bool x, int s) {
    if(x) return;
    else if(s < 0) puts("Wrong Input");
    else printf("Wrong Answer\n");
    exit(0);
}

void report(int A, int B) {
    int i;
    if(A < 0||A >= B||B >= N) WA(1);
    for(i = 0 ; i < degree[A] ; i++) {
        if(edge_list[A][i] == B) {
            if(checked[A][i] == 1) WA(3);
            Answertotal++;
            checked[A][i] = 1;
            return;
        }
    }
    WA(2);
}
static void dfs(int now, std::vector<int> &P) {
    visited[now] = 1;
    int i;
    for(i = 0 ; i < degree[now] ; i++) {
        if(visited[edge_list[now][i]] == 0 && P[edge_list[now][i]] == 1) dfs(edge_list[now][i], P);
    }
}
int investigate(int A, int B, std::vector<int> &P) {
    int i;
    Asktotal++;
    if(Asktotal>QMAX) WA(5);
    if(A < 0||A >= B||B >= N) WA(4);
    if(P[A] != 1) WA(4);
    if(P[B] != 1) WA(4);
    for(i = 0 ; i < N ; i++) {
        if(P[i]<0||P[i]>1) WA(4);
        visited[i] = 0;
    }
    dfs(A, P);
    return visited[B];
}
int main() {
    int i;
    assertion(scanf("%d%d%d",&T,&N,&M) == 3, -1);
    Answertotal = 0;
    for(i = 0 ; i < N ; i++) degree[i] = 0;
    for(i = 0 ; i < M ; i++) {
        int ea,eb;
        assertion(scanf("%d%d",&ea,&eb) == 2, -1);
        checked[ea][degree[ea]] =  0;
        checked[eb][degree[eb]] =  0;
        edge_list[ea][degree[ea]++] = eb;
        edge_list[eb][degree[eb]++] = ea;
    }
    city_explore(T, N);
    if(Answertotal<M) WA(6);
    printf("Accepted\n");
    return 0;
}

////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#else
#define fastio
#endif
#define all(vec) (vec).begin(), (vec).end()
using i64 = long long;
using i32 = int;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;

void city_explore(int t, int n) {
    int i;

    std::vector<int> P(N);

    for(i = 0 ; i < 2 ; i++) P[i] = 0;
    for(i = 2 ; i < N ; i++) P[i] = 1;
    if(investigate(3, 5, P) != 1) return;
    report(2, 4);
    report(2, 5);
    report(3, 4);
    P[0] = 1;
    P[3] = 0;
    P[5] = 0;
    if(investigate(0, 4, P) != 0) return;
    report(0, 1);
    report(0, 3);
    report(1, 4);
    report(1, 2);
}
