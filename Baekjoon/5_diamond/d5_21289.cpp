#include <cstdio>
#include <cstdlib>
#include <vector>

long long jungsanghwa_time(long long K, std::vector<long long> X, std::vector<long long> Y);

void my_assert(bool x){
	if(!x){
		puts("Wrong input");
		exit(0);
	}
}

int main(){
	int N;
    long long K;
	my_assert(scanf("%d %lld", &N, &K) == 2);
	std::vector<long long> X(N), Y(N);
	for(int i = 0; i < N; i++){
		my_assert(scanf("%lld %lld", &X[i], &Y[i]) == 2);
	}
	long long ans = jungsanghwa_time(K, X, Y);
    if(ans != -1) printf("%lld\n", ans);
    else printf("NATT");
}

////////////////////////////////////////////////////////////////////////////////////////

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
template <typename T> void compress(v<T> &arr, bool autosort = true) { if(autosort) sort(arr); arr.erase(unique(all(arr)), arr.end()); }
i64 idx(i64 val, const v<i64> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

struct edge {
    i64 s, e, w;
    edge(i64 start, i64 end, i64 weight) : s(start), e(end), w(weight) {}
    bool operator>(const edge &other) const {
        if(w == other.w) return e > other.e;
        return w > other.w;
    }
};

struct house {
    i64 y, id;
    house(i64 ypos, i64 Id) : y(ypos), id(Id) {}
    bool operator<(const house &other) const {
        return y < other.y;
    }
};

i64 jungsanghwa_time(i64 k, v<i64> xv, v<i64> yv){
    v<i64> compX = xv; compress(compX);
    i64 xRange = (i64) compX.size();
    v2<house> houses(xRange, v<house>());
    i64 n = (i64) xv.size();
    i64 curId = 0;
    forn(i, n) houses[idx(xv[i], compX)].emplace_back(yv[i], curId++);
    for(auto &v : houses) sort(v);
    v2<edge> con(curId, v<edge>());
    forn(x, xRange) {
        i64 yRange = (i64) houses[x].size();
        forn(y, yRange) {
            i64 yCut = y==yRange-1 ? INF : houses[x][y+1].y-1;
            if(x > 0 && compX[x] - compX[x-1] == 1) {
                for(auto ptr = lower_bound(all(houses[x-1]), houses[x][y]); ptr != houses[x-1].end() && ptr->y < yCut; ptr++) {
                    if(ptr->y - houses[x][y].y == 0) continue;
                    i64 yi = ptr - houses[x-1].begin();
                    con[houses[x][y].id].emplace_back(houses[x][y].id, houses[x-1][yi].id, ptr->y - houses[x][y].y);
                    con[houses[x-1][yi].id].emplace_back(houses[x-1][yi].id, houses[x][y].id, ptr->y - houses[x][y].y);
                }
            }
            if(x < xRange - 1 && compX[x+1] - compX[x] == 1) {
                for(auto ptr = lower_bound(all(houses[x+1]), houses[x][y]); ptr != houses[x+1].end() && ptr->y < yCut; ptr++) {
                    i64 yi = ptr - houses[x+1].begin();
                    con[houses[x][y].id].emplace_back(houses[x][y].id, houses[x+1][yi].id, ptr->y - houses[x][y].y);
                    con[houses[x+1][yi].id].emplace_back(houses[x+1][yi].id, houses[x][y].id, ptr->y - houses[x][y].y);
                }
            }
        }
    }

    priority_queue<edge, v<edge>, greater<>> pq;
    v<i64> vis(curId, -1);
    v<i64> pre = vis;
    pq.emplace(0, 0, 0);
    while(!pq.empty()) {
        edge t = pq.top(); pq.pop();
        if(vis[t.e] != -1) continue;
        if(t.w >= k) continue;
        vis[t.e] = t.w; pre[t.e] = t.s;
        if(t.e == n-1) break;
        for(const edge &i : con[t.e]) {
            if(vis[i.e] != -1) continue;
            pq.push(i);
        }
    }
    if(vis[n-1] == -1) return -1;
    i64 ans = 0;
    for(i64 i = n-1; i != 0; i = pre[i]) ans = max(ans, vis[i]);
    return ans;
}
