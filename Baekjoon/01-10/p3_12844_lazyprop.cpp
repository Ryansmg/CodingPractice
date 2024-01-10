#include <iostream>
#include <vector>
using namespace std;

//XOR

void init(vector<int> &tree, vector<int> &in, int node, int start, int end)
{
    if(start==end) {
        tree[node] = in[start];
    } else {
        init(tree, in, node*2, start, (start+end)/2);
        init(tree, in, 2*node+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] ^ tree[node*2+1];
    }
}

void update_lazy(vector<int> &tree, vector<int> &lazy, int node, int start, int end)
{
    if(lazy[node]==0) return;
    if((end-start+1)%2==1) tree[node] ^= lazy[node];
    if(start!=end) {
        lazy[2*node] ^= lazy[node];
        lazy[2*node+1] ^= lazy[node];
    }
    lazy[node] = 0;
}

//start: 탐색 범위, left: 업데이트할 범위
void update_range(vector<int> &tree, vector<int> &lazy, int node, int left, int right, int start, int end, int diff)
{
    update_lazy(tree, lazy, node, start, end);
    if(end < left || right < start) return;
    if(left <= start && end <= right) {
        if((end-start+1)%2==1) tree[node] ^= diff;
        if(start != end)
        {
            lazy[node*2] ^= diff;
            lazy[node*2+1] ^= diff;
        }
    } else {
        update_range(tree, lazy, 2*node, left, right, start, (start+end)/2, diff);
        update_range(tree, lazy, 2*node+1, left, right, (start+end)/2+1, end, diff);
        tree[node] = tree[node*2] ^ tree[node*2+1];
    }
}
//start: 탐색, left: 대상
int query(vector<int> &tree, vector<int> &lazy, int node, int left, int right, int start, int end)
{
    update_lazy(tree, lazy, node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) {
        return tree[node];
    } else {
        return query(tree, lazy, 2*node, left, right, start, (start+end)/2) ^ 
            query(tree, lazy, 2*node+1, left, right, (start+end)/2+1, end);
    }
}

void print_tree(vector<int> &tree, int n)
{
    int a = 1, cnt=0;
    cout << "==tree==\n";
    for(int i=1; i<4*n; i++)
    {
        cout << tree[i] << " ";
        if(++cnt==a) {
            cout << "\n"; a*=2; cnt=0;
        }
    }
    cout << "\n========\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m; cin>>n;
    vector<int> tree(4*n, 0);
    vector<int> lazy(4*n, 0);
    vector<int> in;
    for(int i=0; i<n; i++)
    {
        int a; cin >> a;
        in.emplace_back(a);
    }
    init(tree, in, 1, 0, n-1);
    cin >> m;
    for(int iii=0; iii<m; iii++)
    {
        //print_tree(tree, n);
        int a; cin >> a;
        if(a==1)
        {
            int i, j, k; cin >> i >> j >> k;
            update_range(tree, lazy, 1, i, j, 0, n-1, k);
        } else {
            int i, j; cin >> i >> j;
            cout << query(tree, lazy, 1, i, j, 0, n-1) << "\n";
        }
    }
}