#define USE_INT128 false
#define GCC_OPTIMIZE_ENABLE false
#include <bits/stdc++.h>
#if GCC_OPTIMIZE_ENABLE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#define int long long
#define llmax 9223372036854775807
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)
#define all(vec) (vec).begin(), (vec).end()

using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
int input() { int t=llmax; cin >> t; return t;}
template <typename T> void print(const T &i, const string& end="") { cout << i << end; }
#if USE_INT128
#define lint __int128
lint linput() { return (lint) input(); }
void print(const lint &i, const string& end="") { cout << (int)i << end;}
#endif
template <typename T> T temp() { T t; return t; }

// c

iii cmpair;

bool cmp(iii a, iii b) {
    int ansa = 0, ansb = 0;
    for(int i=0; i<3; i++) {
        ansa += cmpair[i] == a[i];
        ansb += cmpair[i] == b[i];
    }
    if(ansa!=ansb) return ansa < ansb;
    if(a[0]==-1) return true;
    if(a[0]==b[0]) {
        if (a[1] == b[1])
            return a[2] < b[2];
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

signed main()
{
    //filein;
    fastio;
    int tc = input();
    for(int asdf=0; asdf<tc; asdf++) {
        int n = input();
        v<int> arr;
        pq<iii, v<iii>, cmp> pairs;
        int ans = 0;
        for (int i = 0; i < n; i++) arr.push_back(input());
        pairs.push_back({arr[0], arr[1], arr[2]});
        for (int pos1 = 1; pos1 < n - 2; pos1++) {
            iii cur = {arr[pos1], arr[pos1+1], arr[pos1+2]};
            cmpair = cur;
            iii cur2 = {-1, arr[pos1+1], arr[pos1+2]};
            sort(all(pairs), cmp);
            ans += lower_bound(all(pairs), cur, cmp) - upper_bound(all(pairs), cur2, cmp);
            pairs.push_back(cur);
        }
        cout << ans << '\n';
    }
}
