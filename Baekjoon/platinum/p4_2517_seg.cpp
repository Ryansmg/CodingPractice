#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//달리기

bool oper(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

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
    
    int n; cin >> n;
    vector<int> tree(2*n);
    for(int i=0; i<n; i++) cin >> tree[i+n];
    
    vector<int> ansvec(n);
    vector<pair<int, int>> indvec;
    for(int i=0; i<n; i++) indvec.push_back({tree[i+n], i});
    sort(indvec.begin(), indvec.end(), oper);

    int curlimit = 0;

    for(int i=0; i<n; i++) tree[i+n] = tree[i+n]==0?0:1;
    init(tree, n);
    for(auto p : indvec)
    {
        if(curlimit<p.first) {
            pair<int, int> tp = {curlimit, 0};
            for(int i = lower_bound(indvec.begin(), indvec.end(), tp, oper) - indvec.begin();
                indvec[i].first<p.first; i++)
            {
                update(tree, indvec[i].second, 0, n);
            }
            curlimit = p.first;
        }
        ansvec[p.second] = query(tree, 0, p.second, n);
    }
    for(int i : ansvec) cout << i+1 << "\n";
}
