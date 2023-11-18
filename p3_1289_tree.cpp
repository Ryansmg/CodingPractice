#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
#define div 1000000007
#define ll long long

void log(stack<int> st)
{
    
        stack<int> st2 = st;
        while(!st2.empty()) {
            cout << st2.top() << " ";
            st2.pop();
        }
        cout << endl;
}

//트리의 가중치

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; //정점의 개수
    cin >> n;
    vector<pair<int, int>> temp; //정점번호, 가중치
    vector<vector<pair<int, int>>> con(n+1, temp); //연결된 정점 저장
    vector<vector<int>> weights(n+1); //가능한 경로의 가중치
    vector<bool> visited(n+1);
    ll ans = 0;
    for(int i=0; i<n-1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        con[a].push_back({b, w});
        con[b].push_back({a, w});
    }

    stack<int> st;
    st.push(1);

    while(!st.empty())
    {
        int top = st.top();
        if(visited[top])
        {
            st.pop();
            if(weights[top].empty()) weights[top].push_back(1);
            for(auto p : con[top]){
                for(int i : weights[p.first]){
                    weights[top].push_back((i * p.second)%div);
                    //if(i!=1){ans += i; ans %= div;}
                }


                int size = con[top].size();
                for(int i=0; i<size; i++) {  
                    if(weights[con[top][i].first].empty()) continue;
                    for(int j : weights[con[top][i].first] )
                    {
                        ans += j*con[top][i].second;
                    }
                    for(int k=i+1; k<size; k++)
                    { 
                        for(int j : weights[con[top][i].first] )
                        {
                            for(int l : weights[con[top][k].first])
                            {
                                ans += j*l*con[top][i].second*con[top][k].second;
                            }
                        }
                    }
                }
                

            }
            continue;
        }
        visited[top] = true;
        
        for(auto a : con[top])
        {
            if(visited[a.first]) continue;
            st.push(a.first);
        }
    }
    
    int size = con[1].size();
    for(int i=0; i<size; i++) {  
        for(int j : weights[con[1][i].first] )
        {
            ans += j*con[1][i].second;
        }
        for(int k=i+1; k<size; k++)
        { 
            for(int j : weights[con[1][i].first] )
            {
                for(int l : weights[con[1][k].first])
                {
                    ans += j*l*con[1][i].second*con[1][k].second;
                }
            }
        }
    }
    
    cout << ans;
}
