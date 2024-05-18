#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;

// #17353 하늘에서 떨어지는 1, 2, ..., R-L+1개의 별
// #lazyprop

void init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
    if(start==end) tree[node] = a[start-1];
    else {
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void update_lazy(vector<int> &tree, vector<pii> &lazy, int node, int start, int end) {
    if(start == end) {
        tree[node] += lazy[node].second*start - lazy[node].first + lazy[node].second;
        //if(start==2) cout << '+' << lazy[node].second*start - lazy[node].first + lazy[node].second << "\n";
    }
    else {
        lazy[node*2].first += lazy[node].first;
        lazy[node*2].second += lazy[node].second;
        lazy[node*2+1].first += lazy[node].first;
        lazy[node*2+1].second += lazy[node].second;
    }
    lazy[node] = {0,0};
}

//left, right :  업데이트할 범위 / start, end : 탐색 범위
void update_range(vector<int> &tree, vector<pii> &lazy, int node, int start, int end, const int left, const int right)
{
    update_lazy(tree, lazy, node, start, end);
    if(right<start || end<left) return;
    if(left <= start && end <= right) {
        tree[node] += start - left + 1;
        //if(start==2 && end==2) cout << '+' << start - left + 1 << "\n";
        if (start != end) {
            lazy[node*2].first += left;
            lazy[node*2].second++;
            lazy[node*2+1].first += left;
            lazy[node*2+1].second++;
        }
    } else {
        update_range(tree, lazy, node*2, start, (start+end)/2, left, right);
        update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

//left, right : 구할 범위 / start, end : 탐색 범위
int query(vector<int> &tree, vector<pii> &lazy, int node, int start, int end, const int left, const int right) {
    update_lazy(tree, lazy, node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    return query(tree, lazy, node*2, start, (start+end)/2, left, right) 
        + query(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; //수 개수, 일 개수
    vector<int> tree(n*4, 0);
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int t; cin >> t; arr.push_back(t);
    }
    init(arr, tree, 1, 1, n);
    //L의 합, L의 개수
    vector<pii> lazy(n*4, {0,0});
    int q; cin >> q;
    for(int i=0; i<q; i++)
    {
        int a,b,c; cin >> a >> b;
        if(a==1) {
            cin >> c;
            update_range(tree, lazy, 1, 1, n, b, c);
        }
        else cout << query(tree, lazy, 1, 1, n, b, b) << "\n";
    }
}
