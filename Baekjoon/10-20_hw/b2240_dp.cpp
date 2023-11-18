#include <stdio.h>
#include <vector>
using namespace std;

//자두나무
int max(int a, int b) {
    return (a>b) ? a : b;
}

int main()
{
    int t, w;
    scanf("%d %d", &t, &w);
    vector<pair<int, int>> pre(w+1, {0, 0}); //vec[이동횟수].first : 1번 자리, .second : 2번 자리
    vector<pair<int, int>> now(w+1, {0, 0});
    int p;
    scanf(" %d", &p);
    if(p==1){
        pre[0].first = 1;
        pre[1].second = 0;
    } else {
        pre[0].first = 0;
        pre[1].second = 1;
    }
    for(int i=1; i<t; i++)
    {
        scanf(" %d", &p);
        if(p == 1)
        {
            now[0].first = pre[0].first + 1;
            now[0].second = pre[0].second;
            for(int i=1; i<=w; i++)
            {
                now[i].first = max(pre[i-1].second + 1, pre[i].first + 1);
                now[i].second = max(pre[i-1].first, pre[i].second);
            }
        } else {
            now[0].second = pre[0].second + 1;
            now[0].first = pre[0].first;
            for(int i=1; i<=w; i++)
            {
                now[i].first = max(pre[i-1].second, pre[i].first);
                now[i].second = max(pre[i-1].first + 1, pre[i].second + 1);
            }
        }
        
        for(int j=0; j<=w; j++)
        {
            pre[j].first = now[j].first;
            pre[j].second = now[j].second;
            now[j].first = 0;
            now[j].second = 0;
        }
    }

    int ans = 0;
    for(int i=0; i<=w; i++)
    {
        ans = max(ans, pre[i].first);
        ans = max(ans, pre[i].second);
    }
    printf("%d", ans);
}
