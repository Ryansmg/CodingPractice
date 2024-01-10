#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define INF 2100000000

using namespace std;

//최솟값
//비재귀 세그먼트 트리 ( https://bit.ly/48AJUn0 참고)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> tree(3*n);
    for(ll i=n; i<2*n; i++) cin >> tree[i];

    //init
    for(ll i = n-1; i>0; i--) tree[i] = min(tree[i<<1], tree[i<<1|1]);
    
    for(ll ii = 0; ii < m; ii++)
    {
        ll b, c;
        cin >> b >> c;
        //query, [l,r)
        ll l = b+n-1, r = c+n, ans = INF;
        for(; l<r; l>>=1, r>>=1){
            if(l&1) ans = min(tree[l++], ans);
            if(r&1) ans = min(tree[--r], ans);
        }
        cout << ans << "\n";
    }
}
