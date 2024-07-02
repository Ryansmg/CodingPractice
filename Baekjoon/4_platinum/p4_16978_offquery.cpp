#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

//16978. 수열과 쿼리 22
//#segtree #offline_queries

struct tri {
    ll a, b, c;
    tri(){}
    tri(ll x, ll y, ll z) {
        a=x; b=y; c=z;
    }
};

struct quad {
    ll a, b, c, d;
    quad(){}
    quad(ll x, ll y, ll z, ll w) {
        a=x; b=y; c=z; d=w;
    }
};

void init(vector<ll> &tree, vector<ll> &a, ll node, ll start, ll end) {
    if(start==end) {
        tree[node] = a[start-1];
    } else {
        init(tree, a, node*2, start, (start+end)/2);
        init(tree, a, node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void update(vector<ll> &tree, ll node, ll start, ll end, ll tar, ll val) {
    if(tar < start || end < tar) return;
    if(start==end) tree[node] = val;
    else {
        update(tree, node*2, start, (start+end)/2, tar, val);
        update(tree, node*2+1, (start+end)/2+1, end, tar, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

ll query(vector<ll> &tree, ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    return query(tree, node*2, start, (start+end)/2, left, right) + 
        query(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> tree(n*4);
    vector<ll> a;
    for(ll i=0; i<n; i++) {
        ll t; cin >> t;
        a.push_back(t);
    }
    init(tree, a, 1, 1, n);
    ll m; cin >> m;
    vector<tri> q1s;
    vector<quad> q2s;
    ll q2cnt = 0;
    for(ll i=0; i<m; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        if(x==1) q1s.emplace_back(x, y, z); //[y] = z
        else {
            ll w; cin >> w;
            q2s.emplace_back(y, z, w, q2cnt); //ans[d] = b~c
            q2cnt++;
        }
    }
    vector<quad> temp;
    ll q1cnt = q1s.size();
    vector<vector<quad>> offq(q1cnt+1, temp);
    vector<ll> ans(q2cnt);
    for(quad t : q2s) {
        offq[t.a].push_back(t);
    }
    for(quad t : offq[0]) {
        ans[t.d] = query(tree, 1, 1, n, t.b, t.c);
    }
    for(ll i=0; i<q1cnt; i++) {
        update(tree, 1, 1, n, q1s[i].b, q1s[i].c);
        for(quad t : offq[i+1]) {
            ans[t.d] = query(tree, 1, 1, n, t.b, t.c);
        }
    }
    for(ll i : ans) cout << i << "\n";
}
