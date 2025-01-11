#include <bits/stdc++.h>
#define int long long
#define llmax 9223372036854775807
#define inf 3000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
int input() { int t; cin >> t; return t;}

signed main()
{
    int n = input();
    int f = input();
    for(int i=2; i<=n; i++) {
        if(input()>f) {
            cout << i; return 0;
        }
    }
    cout << -1;
}