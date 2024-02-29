#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define pair pair<int, int>
using namespace std;

//14897. 서로 다른 수와 쿼리 1
//#mo

struct query {
    int i, j, order;
    query(){}
    query(int a, int b, int c) {
        i = a; j = b; order = c;
    }
};

int sqrtsize;

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

    int n;
    cin >> n;
    sqrtsize = sqrt(n);

    vector<int> a(1,1);

    vector<int> comp;
    for(int i=0; i<n; i++) {
        int asdf; cin >> asdf; a.push_back(asdf);
        comp.push_back(asdf);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    int maxa = -1;
    for(int i=1; i<=n; i++) {
        a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin() + 1;
        maxa = max(maxa, a[i]);
    }

    int m; cin >> m;
    vector<query> queries;
    for(int i=0; i<m; i++) {
        int b, c;
        cin >> b >> c;
        queries.emplace_back(b, c, i);
    }
    sort(queries.begin(), queries.end(), cmp);
    vector<int> cnt(maxa+1, 0);
    int ansnow = 0;
    vector<int> ans(m);
    int l = queries[0].i, r = queries[0].j;
    for(int i=l; i<=r; i++) {
        if(cnt[a[i]]==0) ansnow++;
        cnt[a[i]]++;
    }
    ans[queries[0].order] = ansnow;
    for(int i=1; i<m; i++) {
        int nl = queries[i].i;
        int nr = queries[i].j;
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
    for(int i : ans) cout << i << "\n";
}
