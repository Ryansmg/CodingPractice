#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void init(vector<ll> &tree, vector<ll> &in, ll node, ll start, ll end)
{
    if(start==end) tree[node] = in[start];
    else {
        init(tree, in, 2*node, start, (start+end)/2);
        init(tree, in, 2*node+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void update_lazy(vector<ll> &tree, vector<ll> &lazy, ll node, ll start, ll end)
{
    if(lazy[node]==0) return;
    tree[node] += (end-start+1) * lazy[node];
    if(start!=end) {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node]=0;
}

//start: 탐색, left: 대상
void update_range(vector<ll> &tree, vector<ll> &lazy, ll node, ll start, ll end, ll left, ll right, ll diff)
{
    update_lazy(tree, lazy, node, start, end);
    if(right<start || end<left) return;
    if(left<=start && end <= right) {
        tree[node] += (end-start+1) * diff;
        if(start!=end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
    } else {
        update_range(tree, lazy, node*2, start, (start+end)/2, left, right, diff);
        update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, diff);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

ll query(vector<ll> &tree, vector<ll> &lazy, ll node, ll start, ll end, ll left, ll right)
{
    update_lazy(tree, lazy, node, start, end);
    if(right<start || end<left) return 0;
    if(left<=start&&end<=right) return tree[node]; 
    return query(tree, lazy, node*2, start, (start+end)/2, left, right) + 
        query(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
}

void print_tree(vector<ll> &tree, ll n)
{
    ll a = 1, cnt=0;
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

    ll n, m, k; cin >> n >> m >> k;
    vector<ll> tree(4*n, 0);
    vector<ll> lazy(4*n, 0);
    vector<ll> in;
    for(int i=0; i<n; i++) {
        ll a; cin >> a; in.push_back(a);
    }
    init(tree, in, 1, 0, n-1);
    for(int i=0; i<m+k; i++)
    {
        int a; cin >> a;
        if(a==1)
        {
            ll b, c, d; cin >> b >> c >> d;
            update_range(tree, lazy, 1, 0, n-1, b-1, c-1, d);
        } else {
            ll b, c; cin >> b >> c;
            cout << query(tree, lazy, 1, 0, n-1, b-1, c-1) << "\n";
        }
    }
}