#include <bits/stdc++.h>
#define int long long
using namespace std;

// 7578. 공장
// #segtree
// 1 3 0 2 4

void init(vector<int> &a, vector<int> &tree, int node, int start, int end)
{
    if(start==end) {
        tree[node] = a[start];
    } else {
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void update(vector<int> &tree, int node, int start, int end, int index, int val)
{
    if(index<start || end<index) return;
    if(start==end) {
        tree[node] = val;
    } else {
        update(tree, node*2, start, (start+end)/2, index, val);
        update(tree, node*2+1, (start+end)/2+1, end, index, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

//left, right : 구할 범위 / start, end : 탐색 범위
int query(vector<int> &tree, int node, int start, int end, int left, int right) {
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    return query(tree, node*2, start, (start+end)/2, left, right) 
        + query(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int tn = 1000000, treeSize = 4*tn;
vector<int> tree(treeSize, 0);
signed main()
{
    int n, ans=0; cin >> n;
    vector<pair<int, int>> find;
    for(int i=0; i<n; i++) {
        int a; cin >> a; find.emplace_back(a, i);
    }
    sort(find.begin(), find.end());
    for(int i=0; i<n; i++) {
        int a; cin >> a; pair<int, int> temp = {a, -1};
        int ind = lower_bound(find.begin(), find.end(), temp)->second;
        //cout << "ind: " << ind << ", query: " << query(tree, 1, 1, tn, ind+1, tn) << "\n";
        ans += query(tree, 1, 1, tn, ind+1, tn);
        update(tree, 1, 1, tn, ind, 1);
    }
    cout << ans;
}