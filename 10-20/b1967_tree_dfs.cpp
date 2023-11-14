//트리의 지름

#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int>> child; //자식 노드
vector<int> weight; //부모와 연결된 간선의 가중치
int maxLength = 0;
int n; //node 개수

int depth(int n); //n번노드~leaf노드 최대 거리

int main()
{
    scanf("%d", &n);
    child.resize(n+1);
    weight.resize(n+1);
    for(int i=0; i<n-1; i++)
    {
        int parent, childN, weightN;
        scanf(" %d %d %d", &parent, &childN, &weightN);
        child[parent].push_back(childN);
        weight[childN] = weightN;
    }

    int max = 0, secMax = 0;
    for(int i : child[1])
    {
        int dep = depth(i) + weight[i];
        if(max < dep) {secMax = max; max = dep;}
        else if(secMax < dep) {secMax = dep;}
    }
    if(maxLength < (max + secMax)) maxLength = max + secMax;

    printf("%d", maxLength);
}

int depth(int n)
{
    int max = 0, secMax = 0;
    for(int i : child[n])
    {
        int dep = depth(i) + weight[i];
        if(max < dep) {secMax = max; max = dep;}
        else if(secMax < dep) {secMax = dep;}
    }
    if(maxLength < (max + secMax)) maxLength = max + secMax;
    return max;
}