#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define inf 2147483640
using namespace std;

// 파티

struct path
{
    int target;
    int weight;
    path(){};
    path(int a, int b)
    {
        target = a;
        weight = b;
    }
};

struct pqi
{
    int target;
    int length;
    pqi(){};
    pqi(int a, int b)
    {
        target = a;
        length = b;
    }
};

struct pqcmp
{
    bool operator()(pqi a, pqi b)
    {
        return a.length > b.length;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, // 마을 수
        m, // 도로 수
        x; // 파티 마을
    cin >> n >> m >> x;
    vector<vector<path>> toParty(n + 1);
    vector<vector<path>> toHome(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        path p(a, c);
        path h(b, c);
        toParty[b].push_back(p);
        toHome[a].push_back(h);
    }
    priority_queue<pqi, vector<pqi>, pqcmp> toP;
    vector<int> minDist(n + 1, inf);
    pqi tpq(x, 0);
    toP.push(tpq);
    while (!toP.empty())
    {
        pqi top = toP.top();
        toP.pop();
        if (minDist[top.target] != inf)
            continue;
        minDist[top.target] = top.length;
        for (path i : toParty[top.target])
        {
            toP.emplace(i.target, top.length + i.weight);
        }
    }
    priority_queue<pqi, vector<pqi>, pqcmp> toh;
    vector<int> minDist2(n + 1, inf);
    toh.push(tpq);
    while (!toh.empty())
    {
        pqi top = toh.top();
        toh.pop();
        if (minDist2[top.target] != inf)
            continue;
        minDist2[top.target] = top.length;
        for (path p : toHome[top.target])
        {
            toh.emplace(p.target, top.length + p.weight);
        }
    }
    int maxi = -1 * inf;
    for (int i = 1; i <= n; i++)
    {
        maxi = max(maxi, minDist[i] + minDist2[i]);
    }
    cout << maxi;
}