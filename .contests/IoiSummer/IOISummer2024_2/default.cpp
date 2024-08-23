#include <bits/stdc++.h>
using namespace std;
using i32 = int; using i64 = long long;
const i64 i64max = 9223372036854775807;
const i64 INF    = 1000000000000000000;
const i64 inf    = 3000000000;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
#define forn(i, n) for(i64 i=0; i<n; i++)
#define forf(i, a, b) for(i64 i=a; i<=b; i++)
#define all(vec) (vec).begin(), (vec).end()
template <typename T> void sort(v<T> &arr) { sort(all(arr)); }
template <typename T> void compress(v<T> &arr, bool autosort = true) { if(autosort) sort(arr); arr.erase(unique(all(arr), arr.end())); }
i64 idx(i64 val, const v<i64> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
