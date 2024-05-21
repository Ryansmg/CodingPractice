#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define int ll
#define inf 7203685477

// #15561 구간 합 최대? 2
// #segtree (금광세그)

struct nd {
    ll lval; //왼쪽 값 포함 최대 부분합 = max(L_lval, L_all+R_lval)
    ll rval; //오른쪽 값 포함 최대 부분합 = max(R_rval, R_all+L_rval)
    ll val; //최대 부분합 = max(L_val, R_val, L_rval + R_lval)
    ll all; //전체 합 = L_all + R_all
    nd()= default;
    nd(ll a, ll b, ll c, ll d) : lval(a), rval(b), val(c), all(d){}
};

void init(vector<ll> &a, vector<nd> &tree, ll node, ll start, ll end)
{
    if(start==end) {
        tree[node] = {a[start-1], a[start-1], a[start-1], a[start-1]};
    } else {
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = {0,0,0,0};
        tree[node].lval = max(tree[node*2].lval, tree[node*2].all + tree[node*2+1].lval);
        tree[node].rval = max(tree[node*2+1].rval, tree[node*2+1].all + tree[node*2].rval);
        tree[node].val = max(max(tree[node*2].val, tree[node*2+1].val), tree[node*2].rval + tree[node*2+1].lval);
        tree[node].all = tree[node*2].all + tree[node*2+1].all;
    }
}

void update(vector<nd> &tree, ll node, ll start, ll end, ll index, ll val, vector<int> &a)
{
    if(index<start || end<index) return;
    if(start==end) {
        tree[node] = {val, val, val, val};
        a[start-1] = val;
    } else {
        update(tree, node*2, start, (start+end)/2, index, val, a);
        update(tree, node*2+1, (start+end)/2+1, end, index, val, a);
        tree[node] = {0,0,0,0};
        tree[node].lval = max(tree[node*2].lval, tree[node*2].all + tree[node*2+1].lval);
        tree[node].rval = max(tree[node*2+1].rval, tree[node*2+1].all + tree[node*2].rval);
        tree[node].val = max(max(tree[node*2].val, tree[node*2+1].val), tree[node*2].rval + tree[node*2+1].lval);
        tree[node].all = tree[node*2].all + tree[node*2+1].all;
    }
}

//left, right : 구할 범위 / start, end : 탐색 범위
nd query(vector<nd> &tree, ll node, ll start, ll end, ll left, ll right) {
    if(end < left || right < start) return {0, -inf, -inf, -inf};
    if(left <= start && end <= right) return tree[node];
    nd f = query(tree, node*2, start, (start+end)/2, left, right);
    nd s = query(tree, node*2+1, (start+end)/2+1, end, left, right);
    nd c = {0, 0, 0, 0};
    c.lval = max(f.lval, f.all + s.lval);
    c.rval = max(s.rval, s.all + f.rval);
    c.val = max(max(f.val, s.val), f.rval + s.lval);
    c.all = f.all + s.all;
    return c;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, q, u, v; cin >> n >> q >> u >> v;
    vector<ll> a;
    for(ll i=0; i<n; i++) {
        ll t; cin>>t; a.push_back(t*u+v);
    }
    vector<nd> tree(n*4, {0,0,0,0});
    init(a, tree, 1, 1, n);
    for(ll i=0; i<q; i++)
    {
        ll aa,b,c; cin >> aa >> b >> c;
        if(aa) {
            update(tree, 1, 1, n, b, c*u+v, a);
            //for(int j : a) cout << j << " ";
            //cout << endl;
        } else {
            cout << query(tree, 1, 1, n, b, c).val - v << "\n";
        }
    }
}
