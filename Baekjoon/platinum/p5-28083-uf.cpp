#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(vec) (vec).begin(), (vec).end()

// 28083. 마왕의 성
// #sorting #disjoint_set

using namespace std;
template <typename T> using v = vector<T>;
int input() { int t; cin >> t; return t;}
template <typename T> T temp() { T t; return t; }

int findRoot(vector<int> &parent, int n) {
    if(n==-1) return -1;
    if(parent[n] == n) return n;
    return parent[n] = findRoot(parent, parent[n]);
}
bool unionRoot(v<int> &parent, int a, int b) {
    if(findRoot(parent, a) == findRoot(parent, b)) return false;
    parent[findRoot(parent,b)] = findRoot(parent, a); return true;
}

struct point { int x, y; };
bool cmp(const pair<int, point> &a, const pair<int, point> &b) {
    if(a.first==b.first)
        return a.second.x==b.second.x ? a.second.y < b.second.y : a.second.x < b.second.x;
    return a.first < b.first;
}

signed main()
{
    fastio;
    int n, m; cin >> n >> m;
    v<v<int>> height(n, temp<v<int>>());
    v<v<int>> cost(n, temp<v<int>>());
    v<int> uftemp(m, -1);
    v<v<int>> group(n, uftemp);
    v<v<int>> answers(n, uftemp);
    v<int> ans, par;
    v<pair<int, point>> points;
    int curGroupN = -1;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            int t = input();
            height[i].push_back(t);
            points.push_back({t,{i, j}});
        }
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cost[i].push_back(input());
    sort(all(points), cmp);
    // 같은 높이 합치기
    for(auto p : points) {
        int curGroup;
        if(group[p.second.x][p.second.y] == -1) {
            curGroupN++;
            ans.push_back(cost[p.second.x][p.second.y]);
            par.push_back(curGroupN);
            group[p.second.x][p.second.y] = curGroupN;
            curGroup = curGroupN;
        } else {
            curGroup = findRoot(par, group[p.second.x][p.second.y]);
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for(int i=0; i<4; i++) {
            int nx = p.second.x + dx[i], ny = p.second.y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(height[nx][ny] != height[p.second.x][p.second.y]) continue;
            if(findRoot(par, group[nx][ny]) == findRoot(par, curGroup)) continue;
            if(group[nx][ny] == -1) {
                ans[curGroup] += cost[nx][ny];
                group[nx][ny] = curGroup;
            } else {
                ans[curGroup] += ans[findRoot(par, group[nx][ny])];
                unionRoot(par, curGroup, group[nx][ny]);
            }
        }
    }
    int ind = 0, size = n * m;
    // 높이 순서대로 계산
    for(int i = 0; i < size; i++) {
        auto p = points[i];
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        curGroupN = findRoot(par, group[p.second.x][p.second.y]);
        for(int j=0; j<4; j++) {
            int nx = p.second.x + dx[j], ny = p.second.y + dy[j];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(height[nx][ny] > height[p.second.x][p.second.y]) continue;
            if(findRoot(par, group[nx][ny]) == findRoot(par, curGroupN)) continue;

            ans[curGroupN] += ans[findRoot(par, group[nx][ny])];
            unionRoot(par, curGroupN, group[nx][ny]);
            group[nx][ny] = curGroupN;
        }
        if(i!=size-1 && p.first != points[i+1].first) {
            for(; ind <= i; ind++) {
                auto p2 = points[ind].second;
                answers[p2.x][p2.y] = ans[findRoot(par, group[p2.x][p2.y])];
            }
        }
    }
    for(; ind<size; ind++) {
        auto p2 = points[ind].second;
        answers[p2.x][p2.y] = ans[findRoot(par, group[p2.x][p2.y])];
    }
    for(const auto& a : answers) {
        for(int i : a) cout << i << " ";
        cout << "\n";
    }
}
