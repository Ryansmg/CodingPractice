#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
typedef long long ll;
#define pair pair<ll, ll>
using namespace std;

//13547. 수열과 쿼리 5
//#mo

//mo's algorithm (모스 알고리즘)
//https://justicehui.github.io/hard-algorithm/2019/06/17/MoAlgorithm/

struct query {
    ll i, j, order;
    query(){}
    query(ll a, ll b, ll c) {
        i = a; j = b; order = c;
    }
};

ll sqrtsize; //sqrt(쿼리의 개수)
bool cmp(query a, query b) {
    if(a.i/sqrtsize == b.i/sqrtsize) {
        return a.j < b.j;
    } else return a.i/sqrtsize < b.i/sqrtsize;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    sqrtsize = sqrt(n);

    vector<ll> a(1,1);
    ll maxa = -1;
    for(ll i=0; i<n; i++) {
        ll asdf; cin >> asdf; a.push_back(asdf);
        maxa = max(maxa, asdf);
    }
    ll m; cin >> m;
    vector<query> queries;
    for(ll i=0; i<m; i++) {
        ll b, c;
        cin >> b >> c;
        queries.emplace_back(b, c, i);
    }
    sort(queries.begin(), queries.end(), cmp);
    vector<ll> cnt(maxa+1, 0);
    ll ansnow = 0;
    vector<ll> ans(m);
    ll l = queries[0].i, r = queries[0].j;
    for(ll i=l; i<=r; i++) {
        if(cnt[a[i]]==0) ansnow++;
        cnt[a[i]]++;
    }
    ans[queries[0].order] = ansnow;
    for(ll i=1; i<m; i++) {
        ll nl = queries[i].i;
        ll nr = queries[i].j;
        while(l < nl) {
            cnt[a[l]]--;
            if(cnt[a[l]]==0) ansnow--;
            l++;
        }
        while(nl < l) {
            l--;
            if(cnt[a[l]]==0) ansnow++;
            cnt[a[l]]++;
        }
        while(r < nr) {
            r++;
            if(cnt[a[r]]==0) ansnow++;
            cnt[a[r]]++;
        }
        while(nr < r) {
            cnt[a[r]]--;
            if(cnt[a[r]]==0) ansnow--;
            r--;
        }
        ans[queries[i].order] = ansnow;
    }
    for(ll i : ans) cout << i << "\n";
}
