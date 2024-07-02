#pragma region macros
#include <bits/stdc++.h>
#define int long long
#define double long double
#define cint const int &
#define llmax 9223372036854775807
#define INF 1000000000000000000
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define forn(name, val) for(int name = 0; name < val; name++)
#define forf(name, start, end) for(int name = start; name <= end; name++)
#define pass {cout << "";}
using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;
#define all(vec) (vec).begin(), (vec).end()
template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
template <typename T=int> T input() {T t; cin >> t; return t;}
#pragma endregion

// 제271회 웰노운컵
// #greedy #priority_queue #sorting

struct prob {
    int A, B, ord;
    prob()=default;
    prob(int a, int b, int o) : A(a), B(b), ord(o){}
};

struct pc {
    bool operator()(const prob &a, const prob &b) {
        return a.A < b.A;
    }
};
bool cmp(const prob &a, const prob &b) {
    return a.B < b.B;
}

signed main() {
    int n = input();
    v<int> a;
    forn(i, n) a.push_back(input());
    v<prob> arr; priority_queue<prob, v<prob>, pc> pq;
    forn(i, n)
        arr.emplace_back(a[i], input(), i);
    sort(all(arr), cmp);
    int ans = arr[0].A;
    for(int i=2; i<n; i+=2) {
        pq.push(arr[i-1]);
        pq.push(arr[i]);
        ans += pq.top().A;
        pq.pop();
    }
    cout << ans;
}
