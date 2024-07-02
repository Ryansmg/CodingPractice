#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

//ACM Craft

int max(int a, int b){ return (a>b)?a:b; }

int main()
{
    string ans = "";
    int t; //테스트케이스 개수
    scanf("%d", &t);
    for(int asdf = 0; asdf < t; asdf++)
    {
        int n; //건물의 개수
        int k; //간선 개수
        scanf(" %d %d", &n, &k);
        vector<int> time;
        vector<bool> visited(n+1);
        vector<int> maxTime(n+1);
        vector<vector<int>> parent;
        { vector<int> temp; parent.push_back(temp); }
        time.push_back(-1);
        for(int i=0; i<n; i++) {
            int a;
            scanf(" %d", &a);
            time.push_back(a);
            vector<int> temp;
            parent.push_back(temp);
        }
        for(int i=0; i<k; i++)
        {
            int a, b;
            scanf(" %d %d", &a, &b);
            parent[b].push_back(a);
        }
        int w; //건설해야 할 건물의 번호
        scanf(" %d", &w);
        stack<int> dfs;
        dfs.push(w);
        while(!dfs.empty())
        {
            int cur = dfs.top();
            if(visited[cur]) {dfs.pop();continue;}
            bool canBuild = true;
            for(int i : parent[cur]) if(!visited[i]) { canBuild = false; break; }
            if(canBuild){
                dfs.pop();
                visited[cur] = true;
                maxTime[cur] = time[cur];
                for(int i : parent[cur]) maxTime[cur] = max(maxTime[cur], maxTime[i] + time[cur]);
                continue;
            } else {
                for(int i : parent[cur]) dfs.push(i);
            }
        }
        ans += to_string(maxTime[w]) + "\n";
    }
    cout << ans;
}