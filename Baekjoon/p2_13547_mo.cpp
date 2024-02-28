#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#include <unordered_map>
typedef long long ll;
#define pair pair<ll, ll>
using namespace std;

//수열과 쿼리 5
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

ll sqrtsize;

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
    for(ll i=0; i<n; i++) {
        ll asdf; cin >> asdf; a.push_back(asdf);
    }
    ll m; cin >> m;
    vector<query> queries;
    for(ll i=0; i<m; i++) {
        ll b, c;
        cin >> b >> c;
        queries.emplace_back(b, c, i);
    }
    sort(queries.begin(), queries.end(), cmp);
    unordered_map<ll, ll> cnt; //<i,j> == i j개 있음
    vector<ll> ans(m);
    ll l = queries[0].i, r = queries[0].j;
    for(ll i=l; i<=r; i++) {
        auto ptr = cnt.find(a[i]);
        if(ptr == cnt.end()) {
            cnt.emplace(a[i], 1);
        } else {
            ptr->second++;
        }
    }
    ans[queries[0].order] = cnt.size();
    for(ll i=1; i<m; i++) {
        ll nl = queries[i].i;
        ll nr = queries[i].j;
        while(l < nl) {
            assert(cnt.find(a[l]) != cnt.end());
            cnt[a[l]]--;
            if(cnt[a[l]]==0) cnt.erase(a[l]);
            l++;
        }
        while(nl < l) {
            l--;
            auto ptr = cnt.find(a[l]);
            if(ptr==cnt.end()) cnt.insert({a[l], 1});
            else ptr->second++;
        }
        while(r < nr) {
            r++;
            auto ptr = cnt.find(a[r]);
            if(ptr==cnt.end()) cnt.insert({a[r], 1});
            else ptr->second++;
        }
        while(nr < r) {
            assert(cnt.find(a[r]) != cnt.end());
            cnt[a[r]]--;
            if(cnt[a[r]]==0) cnt.erase(a[r]);
            r--;
        }
        ans[queries[i].order] = cnt.size();
    }
    for(ll i : ans) cout << i << "\n";
}
