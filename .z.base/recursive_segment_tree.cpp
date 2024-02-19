#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define div 1000000007

// #11505 구간 곱 구하기
// (재귀형 세그먼트 트리)

void init(vector<ll> &a, vector<ll> &tree, ll node, ll start, ll end)
{
    if(start==end) {
        tree[node] = a[start];
    } else {
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] * tree[node*2+1] % div;
    }
}

void update(vector<ll> &a, vector<ll> &tree, ll node, ll start, ll end, ll index, ll val)
{
    if(index<start || end<index) return;
    if(start==end) {
        a[index] = val % div;
        tree[node] = val % div;
    } else {
        update(a, tree, node*2, start, (start+end)/2, index, val);
        update(a, tree, node*2+1, (start+end)/2+1, end, index, val);
        tree[node] = tree[node*2] * tree[node*2+1] % div;
    }
}

//left, right : 구할 범위 / start, end : 탐색 범위
ll query(vector<ll> &tree, ll node, ll start, ll end, ll left, ll right) {
    if(end < left || right < start) return 1;
    if(left <= start && end <= right) return tree[node] % div;
    return query(tree, node*2, start, (start+end)/2, left, right) 
        * query(tree, node*2+1, (start+end)/2+1, end, left, right) % div;
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
    ll n, m, k; cin >> n >> m >> k; //수 개수, 변경 횟수, 쿼리 횟수
    vector<ll> a;
    for(ll i=0; i<n; i++) {
        ll t; cin>>t; a.push_back(t);
    }
    vector<ll> tree(n*4, 0);
    init(a, tree, 1, 0, n-1);
    for(ll i=0; i<m+k; i++)
    {
        ll aa,b,c; cin >> aa >> b >> c;
        if(aa==1) update(a, tree, 1, 0, n-1, b-1, c);
        else cout << query(tree, 1, 0, n-1, b-1, c-1) << "\n";
    }
}