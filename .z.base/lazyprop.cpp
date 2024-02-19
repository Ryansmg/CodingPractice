#include <iostream>
#include <vector>
#define ll long long
using namespace std;

// #1395 스위치
// (느리게 갱신되는 세그먼트 트리) : #lazyprop

void update_lazy(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end) {
    if(lazy[node] == 0) return;
    tree[node] = (end-start+1) - tree[node];
    if(start != end) {
        lazy[node*2] ^= lazy[node];
        lazy[node*2+1] ^= lazy[node];
    }
    lazy[node] = 0;
}

//left, right :  업데이트할 범위 / start, end : 탐색 범위
void update_range(vector<ll> &tree, vector<ll> &lazy, ll node, ll start, ll end, ll left, ll right, ll diff)
{
    update_lazy(tree, lazy, node, start, end);
    if(right<start || end<left) return;
    if(left <= start && end <= right) {
        tree[node] = (end-start+1) - tree[node];
        if (start != end) {
            lazy[node*2] ^= diff;
            lazy[node*2+1] ^= diff;
        }
    } else {
        update_range(tree, lazy, node*2, start, (start+end)/2, left, right, diff);
        update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, diff);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

//left, right : 구할 범위 / start, end : 탐색 범위
ll query(vector<ll> &tree, vector<ll> &lazy, ll node, ll start, ll end, ll left, ll right) {
    update_lazy(tree, lazy, node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    return query(tree, lazy, node*2, start, (start+end)/2, left, right) 
        + query(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m; //수 개수, 일 개수
    vector<ll> tree(n*4, 0);
    vector<ll> lazy(n*4, 0);
    for(ll i=0; i<m; i++)
    {
        ll a,b,c; cin >> a >> b >> c;
        if(a==0) update_range(tree, lazy, 1, 0, n-1, b-1, c-1, 1);
        else cout << query(tree, lazy, 1, 0, n-1, b-1, c-1) << "\n";
    }
}
