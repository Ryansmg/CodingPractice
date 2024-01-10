#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define INF 9223372036854775800
using namespace std;

// 히스토그램

void setMin(vector<ll> &tree, vector<ll> &indtree, ll tarind, ll valind1, ll valind2){
    if(tree[valind1] < tree[valind2]){
        tree[tarind] = tree[valind1];
        indtree[tarind] = indtree[valind1];
    } else {
        tree[tarind] = tree[valind2];
        indtree[tarind] = indtree[valind2];
    }
}
void init(vector<ll> &tree, vector<ll> &indtree, ll n)
{
    for(ll i=n-1; i>0; i--) setMin(tree, indtree, i, i<<1, i<<1|1);
}
//0<=tar<n, tree[0]==NULL
void update(vector<ll> &tree, vector<ll> &indtree, ll tar, ll val, ll n)
{
    tree[tar+=n] = val;
    for(ll i = tar; i>1; i>>=1) setMin(tree, indtree, i>>1, i, i^1);
}
//[left,right) (0<=left,right<n , tree[0]==NULL)
pair<ll, ll> query(vector<ll> &tree, vector<ll> &indtree, ll left, ll right, ll n)
{
    ll ans = INF, ansind = -1;
    for(left+=n, right+=n; left<right; left>>=1, right>>=1)
    {
        if(left&1 && tree[left++] < ans) {ans = tree[left-1]; ansind = indtree[left-1];}
        if(right&1 && tree[--right] < ans) {ans = tree[right]; ansind = indtree[right];}
    }
    return {ans, ansind};
}
//[left, right)
ll answer(vector<ll> &tree, vector<ll> &indtree, ll left, ll right, ll n)
{
    if(left+1>=right) return tree[n+left];
    auto minpair = query(tree, indtree, left, right, n);
    ll minh = minpair.first; ll minhind = minpair.second;
    ll ans = minh * (right-left);
    if(left<minhind) ans = max(ans, answer(tree, indtree, left, minhind, n));
    if(minhind+1<right) ans = max(ans, answer(tree, indtree, minhind+1, right, n));
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    vector<ll> tree(2*n+2);
    vector<ll> indtree(2*n+2);
    for(int i=n; i<2*n; i++) {
        cin>>tree[i];
        indtree[i] = i-n;
    }
    init(tree, indtree, n);
    cout << answer(tree, indtree, 0, n, n);
}
