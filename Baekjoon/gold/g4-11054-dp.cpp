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

template <typename T> void compress(v<T> &v, bool autosort=true) { if(autosort) sort(all(v)); v.erase(v.unique(all(v)), v.end()); }
template <typename T> T idx(const T &val, const v<T> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }
int input() { int t=llmax; cin >> t; return t;}
lint linput() { return (lint) input(); }
template <typename T> void print(T i, const string& end="") { cout << i << end; }
void print(lint i, const string& end="") { cout << (int)i << end;}
template <typename T> T temp() { T t; return t; }

// 11054. 가장 긴 바이토닉 부분 수열
// #dp

signed main()
{
    fastio;
    int n = input();
    v<int> arr;
    for(int i=0; i<n; i++) arr.push_back(input());
    v<int> increase(n, 1);
    v<int> decrease(n, 1);
    int ans = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i])
                increase[i] = max(increase[i], increase[j]+1);
            if(arr[j] > arr[i]) {
                int temp = max(increase[j], decrease[j]);
                decrease[i] = max(decrease[i], temp+1);
            }
        }
        ans = max(ans, increase[i]);
        ans = max(ans, decrease[i]);
    }
    cout << ans;
}
