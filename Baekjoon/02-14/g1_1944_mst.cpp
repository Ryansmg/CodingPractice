#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define ll long long
using namespace std;

struct point
{
    int x, y;
    point() {}
    point(int a, int b)
    {
        x = a;
        y = b;
    }
    bool operator<(const point &a) const
    {
        if (y == a.y)
            return x < a.x;
        return y < a.y;
    }
};

struct edge
{
    point parent;
    point target;
    ll weight;
    edge(point a, point b, ll c)
    {
        parent = a;
        target = b;
        weight = c;
    }
    edge() {}
    bool operator()(edge x, edge y)
    {
        return x.weight > y.weight;
    }
};

struct wpoint
{
    int x, y, weight;
    wpoint() {}
    wpoint(int a, int b, int c)
    {
        x = a;
        y = b;
        weight = c;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> cmap;
    vector<char> temp;
    point start;
    vector<point> keys;
    for (int i = 0; i < n; i++)
    {
        cmap.push_back(temp);
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            cmap[i].push_back(c);
            if (c == 'S')
            {
                point p(j, i);
                start = p;
            }
            if (c == 'K')
            {
                point p(j, i);
                keys.push_back(p);
            }
        }
    }

    // bfs -> 모든 간선 구하기
    map<point, vector<edge>> edges;
    vector<point> bsfs = keys;
    bsfs.push_back(start);
    for (point bst : bsfs)
    {
        vector<bool> vt(n, false);
        vector<vector<bool>> visited(n, vt);
        vector<edge> startedges;
        queue<wpoint> bq;
        bq.push({bst.x, bst.y, 0});
        while (!bq.empty())
        {
            wpoint front = bq.front();
            bq.pop();
            if (visited[front.y][front.x])
                continue;
            visited[front.y][front.x] = true;
            if (cmap[front.y][front.x] == 'K' && (front.y != bst.y || bst.x != front.x))
            {
                point tar(front.x, front.y);
                startedges.push_back({bst, tar, front.weight});
            }
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            for (int i = 0; i < 4; i++)
            {
                if (front.x + dx[i] < 0 || front.x + dx[i] >= n || front.y + dy[i] < 0 || front.y + dy[i] >= n)
                    continue;
                if (cmap[front.y + dy[i]][front.x + dx[i]] == '1')
                    continue;
                bq.push({front.x + dx[i], front.y + dy[i], front.weight + 1});
            }
        }
        edges[bst] = startedges;
    }
    if (edges[start].size() != m)
    {
        cout << -1;
        return 0;
    }

    // prim
    priority_queue<edge, vector<edge>, edge> pq;
    vector<bool> vt(n, false);
    vector<vector<bool>> visited(n, vt);
    for (edge e : edges[start])
        pq.push(e);
    visited[start.y][start.x] = true;
    int edgesfound = 0;
    int ans = 0;
    while (edgesfound < m)
    {
        edge top = pq.top();
        pq.pop();
        if (visited[top.target.y][top.target.x])
            continue;
        visited[top.target.y][top.target.x] = true;
        ans += top.weight;
        edgesfound++;
        for (edge e : edges[top.target])
        {
            if (!visited[e.target.y][e.target.x])
                pq.push(e);
        }
    }
    cout << ans;
}
