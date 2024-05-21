#include <bits/stdc++.h>
#define int long long
#define lint __int128
#define llmax 9223372036854775807
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define filein freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/input.txt", "r", stdin)
#define all(vec) (vec).begin(), (vec).end()

using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;
using iii = array<int, 3>;

template <typename T> void compress(v<T> &v, const bool &autosort=true) { if(autosort) sort(all(v)); v.erase(v.unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
int input() { int t=llmax; cin >> t; return t;}
lint linput() { return (lint) input(); }
template <typename T> void print(const T &i, const string& end="") { cout << i << end; }
void print(const lint &i, const string& end="") { cout << (int)i << end;}
template <typename T> T temp() { T t; return t; }


signed main()
{
    int n, k; cin >> n >> k;
    int arr[7] = {0};
    int m[] = {1000, 1000, 2000, 3000, 3000, 6000, 6000};
    for(int i=0; i<n; i++) {
        int t = input();
        for(int j=0; j<t; j++)
            arr[input()-1]++;
    }
    int ans = 0;
    for(int i=0; i<7; i++)
        ans += (arr[i]>=k ? m[i] : 0);
    cout << ans * n;
}
