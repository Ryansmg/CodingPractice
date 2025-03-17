#include <bits/stdc++.h>
using namespace std;
string s = "0123456789ABCDEFGHIJKLMNOP";
vector<char> ans;
void convert(int n, int k) {
    if(n<k) {
        cout << s[n%k];
        return;
    }
    convert(n/k, k);
    cout << s[n%k];
}
int main() {
    int n, k; cin >> n >> k;
    convert(n, k);
}
