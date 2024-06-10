#pragma region macros
#include <bits/stdc++.h>
#define int long long
#define double long double
#define llmax 9223372036854775807
#define INF 1000000000000000000
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(vec) (vec).begin(), (vec).end()
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)
using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T> T input() {T t; cin >> t; return t;}
int input() { int t; cin >> t; return t;}
#pragma endregion

struct query {
    int i, j, order;
    query()=default;
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

int cnt[10010] = {0};

ii qu() {
    int maxn = -1, ans = -1;
    forf(i, 1, 10000) if(cnt[i] > maxn){
        ans = i;
        maxn = max(cnt[i], maxn);
    }
    return {maxn, ans};
}

signed main() {
    int n, c; cin >> n >> c;

    vector<int> arr(1,-1);
    forn(i, n) arr.push_back(input());
    int m; cin >> m;
    sqrtsize = (int) sqrt(m);
    vector<query> queries;
    for(int i=0; i<m; i++) {
        int b, d;
        cin >> b >> d;
        queries.emplace_back(b, d, i);
    }
    sort(queries.begin(), queries.end(), cmp);
    vector<pair<bool, int>> ans(m);
    int l = queries[0].i, r = queries[0].j;
    for(int i=l; i<=r; i++) {
        cnt[arr[i]]++;
    }
    auto q = qu();
    ans[queries[0].order] = {((r-l+1)/2 < q[0]), q[1]};
    for(int i=1; i<m; i++) {
        int nl = queries[i].i;
        int nr = queries[i].j;
        while(l < nl) {
            cnt[arr[l]]--;
            l++;
        }
        while(nl < l) {
            l--;
            cnt[arr[l]]++;
        }
        while(r < nr) {
            r++;
            cnt[arr[r]]++;
        }
        while(nr < r) {
            cnt[arr[r]]--;
            r--;
        }
        q = qu();
        ans[queries[i].order] = {((r-l+1)/2 < q[0]), q[1]};
    }
    for(auto i : ans) {
        if(!i.first) cout << "no" << '\n';
        else cout << "yes " << i.second << "\n";
    }
}
