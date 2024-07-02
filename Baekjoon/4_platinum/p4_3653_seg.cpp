#include <iostream>
#include <vector>
using namespace std;

//영화 수집

void init(vector<int> &tree, int n)
{
    for(int i=n-1; i>0; i--) tree[i] = tree[i<<1] + tree[i<<1|1];
}

void update(vector<int> &tree, int ind, int val, int n)
{
    for(tree[ind+=n]=val; ind>1; ind>>=1) tree[ind>>1] = tree[ind] + tree[ind^1];
}

int query(vector<int> &tree, int start, int end, int n)
{
    int sum = 0;
    for(start+=n, end+=n; start<end; start>>=1, end>>=1)
    {
        if(start&1) sum += tree[start++];
        if(end&1) sum += tree[--end];
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tcn; cin >> tcn;
    for(int tcni=0; tcni<tcn; tcni++)
    {
        int n, //가진 영화 수
        m; //보려고 하는 영화 수
        cin >> n >> m;
        vector<int> inds; inds.emplace_back(-1);
        for(int i=m; i<m+n; i++) inds.emplace_back(i);
        vector<int> tree(2*(m+n)); //(m~n-1에서 빼서 0~m-1에 넣는 방식)
        for(int i = 0; i<m; i++) tree[i+n+m] = 0;
        for(int i = m; i<m+n; i++) tree[i+n+m] = 1;
        init(tree, n+m);
        for(int i=0; i<m; i++)
        {
            int in; cin>>in;
            cout << query(tree, 0, inds[in], n+m) << " ";
            update(tree, inds[in], 0, n+m);
            inds[in] = m-i-1;
            update(tree, inds[in], 1, n+m);
        }
        cout << "\n";
    }
}