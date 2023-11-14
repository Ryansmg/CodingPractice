#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n, //정점의 개수
    m, //간선의 개수
    v; //시작점
    vector<int> vertex[1001];

    scanf("%d %d %d", &n, &m, &v);
    for(int i=0; i<m; i++)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }

    //DFS

    bool visitedDFS[1001] = {false};
    stack<int> st;
    st.push(v);
    while(st.size()!=0)
    {
        int top = st.top();
        if(!visitedDFS[top]) printf("%d ", top);
        visitedDFS[top] = true;
        st.pop();
        int size = vertex[top].size();
        
        for(int i=0; i<size-1; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                if(vertex[top][i] < vertex[top][j]){
                    int temp = vertex[top][i];
                    vertex[top][i] = vertex[top][j];
                    vertex[top][j] = temp;
                }
            }
        }

        for(int i : vertex[top])
            if(!visitedDFS[i])
            {
                st.push(i);
            }
    }
    printf("\n");

    //BFS

    bool visitedBFS[1001] = {false};
    queue<int> que;
    que.push(v);
    while(que.size()!=0)
    {
        int top = que.front();
        if(!visitedBFS[top]) printf("%d ", top);
        visitedBFS[top] = true;
        que.pop();
        int size = vertex[top].size();
        
        for(int i=0; i<size-1; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                if(vertex[top][i] > vertex[top][j]){
                    int temp = vertex[top][i];
                    vertex[top][i] = vertex[top][j];
                    vertex[top][j] = temp;
                }
            }
        }

        for(int i : vertex[top])
            if(!visitedBFS[i])
            {
                que.push(i);
            }
    }

}