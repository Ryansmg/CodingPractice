#include <bits/stdc++.h>
#define int long long
#define INF 9223372036854775800
using namespace std;

// 1219. 오민식의 고민
// #bellman_ford

struct edge
{
    int start, end, weight;
    edge() {}
    edge(int a, int b, int c) : start(a), end(b), weight(c){};
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, start, end, m; // 도시 수, 시작 도시, 도착 도시, 간선 수
    cin >> n >> start >> end >> m;
    vector<int> money(n, -INF);
    vector<edge> edges;
    vector<vector<edge>> con(n, edges);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
        con[a].emplace_back(a, b, c);
    }
    vector<int> income;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        income.push_back(a);
    }
    money[start] = income[start];
    bool vis[n] = {0};
    vector<int> cycleConcheck;
    for (int i = 0; i < n; i++)
    {
        for (edge e : edges)
        {
            if (money[e.start] == -INF)
                continue;
            if (money[e.end] < money[e.start] - e.weight + income[e.end])
            {
                if (i == n - 1)
                {
                    cycleConcheck.push_back(e.end);
                }
                money[e.end] = money[e.start] - e.weight + income[e.end];
            }
        }
    }
    if (money[end] == -INF)
    {
        cout << "gg";
        return 0;
    }
    while (!cycleConcheck.empty())
    {
        int top = cycleConcheck.back();
        cycleConcheck.pop_back();
        if (vis[top])
            continue;
        vis[top] = true;
        if (top == end)
        {
            cout << "Gee";
            return 0;
        }
        for (edge e2 : con[top])
        {
            if (vis[e2.end])
                continue;
            cycleConcheck.push_back(e2.end);
        }
    }
    cout << money[end];
}
