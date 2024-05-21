#include <bits/stdc++.h>
#define int long long
#define lint __int128
#define llmax 9223372036854775807
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(vec) (vec).begin(), (vec).end()

using namespace std;
template <typename T> using v = vector<T>;
template <typename T> using pq = priority_queue<T>;
using ii = array<int, 2>;

template <typename T> void compress(v<T> &v, bool autosort=true) { if(autosort) sort(all(v)); v.erase(v.unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
int input() { int t=llmax; cin >> t; return t;}
lint linput() { return (lint) input(); }
template <typename T> void print(T i, const string& end="") { cout << i << end; }
void print(lint i, const string& end="") { cout << (int)i << end;}
template <typename T> T temp() { T t; return t; }

// 11049. 행렬 곱셈 순서
// #dp
// 이게 어떻게 골드 3 :blobthinkingfast:

signed main()
{
    int n = input();
    v<ii> arr;
    for(int i=0; i<n; i++)
        arr.push_back({input(), input()});
    
}
