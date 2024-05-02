#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int a, b; cin >> a >> b;
    vector<int> s(b, 0);
    for(int i=0; i<a; i++) {
        string str; cin >> str;
        for(int j=0; j<b; j++) {
            s[j] = str[j]=='0'?0:s[j]+1;
        }
        for(int j=0; j<b; j++) cout << s[j] << " ";
        cout << "\n";
    }
}