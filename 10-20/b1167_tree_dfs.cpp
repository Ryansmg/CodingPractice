//트리의 지름
//정석 풀이는 dfs 두 번 사용 (임의의 노드에서 가장 먼 노드 탐색, 그 노드에서 가장 먼 노드 탐색)

#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

vector<int> child[100002]; //자식 노드
bool visited[100002] = {false};
map<int, int> weight[100002]; //부모와 연결된 간선의 가중치 (weight[child].find(parent)->second)
int maxLength = 0;
int n; //node 개수

int depth(int n, int parent); //n번노드~leaf노드 최대 거리

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int parent, childN, weightN;
        scanf(" %d", &parent);
        while(true)
        {
            scanf(" %d", &childN);
            if(childN == -1) break;
            scanf(" %d", &weightN);
            child[parent].push_back(childN);
            weight[childN].insert({parent, weightN});
        }
    }

    int max = 0, secMax = 0;
    visited[1] = true;
    for(int i : child[1])
    {
        int dep = depth(i, 1) + weight[i].find(1)->second;
        if(max < dep) {secMax = max; max = dep;}
        else if(secMax < dep) {secMax = dep;}
    }
    if(maxLength < (max + secMax)) maxLength = max + secMax;

    printf("%d", maxLength);
}

int depth(int n, int parent)
{
    visited[n] = true;
    int max = 0, secMax = 0;
    for(int i : child[n])
    {
        if(visited[i]) continue;
        int dep = depth(i, n) + weight[i].find(n)->second;
        if(max < dep) {secMax = max; max = dep;}
        else if(secMax < dep) {secMax = dep;}
    }
    if(maxLength < (max + secMax)) maxLength = max + secMax;
    return max;
}