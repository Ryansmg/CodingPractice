/* Update : 2025-02-04 */

#include <bits/stdc++.h>

long long moQuerySortVal = -1;
struct moQuery {
    long long i, j, order;
    bool operator<(const moQuery& b) const {
        if(i/moQuerySortVal == b.i/moQuerySortVal) return j < b.j;
        return i/moQuerySortVal < b.i/moQuerySortVal;
    }
};

// Example : BOJ 13547. 수열과 쿼리 5
int main() {
    using namespace std; ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n, m, t, b, c; cin >> n; moQuerySortVal = sqrt(n);
    vector<long long> a(1, 1); long long maxA = -1;
    for(long long i = 0; i < n; i++) { cin >> t; a.push_back(t); maxA = max(maxA, t); }
    cin >> m; vector<moQuery> queries;
    for(long long i = 0; i < m; i++) { cin >> b >> c; queries.emplace_back(b, c, i); }
    sort(queries.begin(), queries.end());
    vector<long long> cnt(maxA+1, 0), ans(m);
    long long cur = 0,l = queries[0].i, r = queries[0].j;
    for(long long i = l; i <= r; i++) if(cnt[a[i]]++ == 0) cur++;
    ans[queries[0].order] = cur;
    for(long long i = 1; i <= m-1; i++) {
        long long nl = queries[i].i, nr = queries[i].j;
        while(l < nl) if(--cnt[a[l++]]==0) cur--;
        while(nl < l) if(cnt[a[--l]]++==0) cur++;
        while(r < nr) if(cnt[a[++r]]++==0) cur++;
        while(nr < r) if(--cnt[a[r--]]==0) cur--;
        ans[queries[i].order] = cur;
    }
    for(auto i : ans) cout << i << '\n';
}