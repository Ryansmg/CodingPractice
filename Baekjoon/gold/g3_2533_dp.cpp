#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//2533. 사회망 서비스(SNS)
//#tree #dp

void calc(int a, vector<vector<int>> &child, vector<bool> &visited, vector<int> &earlymin, vector<int> &normalmin, int &ans)
{
    visited[a] = true;
    for (int i : child[a])
    {
        if(visited[i]) continue;
        calc(i, child, visited, earlymin, normalmin, ans);
        normalmin[a] += earlymin[i];
        earlymin[a] += min(normalmin[i], earlymin[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> temp;
    vector<vector<int>> child(n + 1, temp);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        child[b].push_back(a);
        child[a].push_back(b);
    }
    int ans = 2147000000;
    vector<int> earlymin(n + 1, 1);
    vector<int> normalmin(n + 1, 0);
    vector<bool> visited(n + 1, 0);
    calc(1, child, visited, earlymin, normalmin, ans);
    ans = min(min(ans, normalmin[1]), earlymin[1]);
    cout << ans;
}
