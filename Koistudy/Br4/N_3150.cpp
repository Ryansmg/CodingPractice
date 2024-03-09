#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

int min(int a, int b) {
    return a<b?a:b;
}
int abs(int a) {
    return a > -a ? a : -a;
}
int main() {
    ll n; cin >> n;
    vector<int> base;
    vector<int> pass;
    ll ans=0;
    string s; cin >> s;
    for(char c : s) base.push_back(c-'0');
    cin >> s; for(char c : s) pass.push_back(c-'0');
    for(int i=0; i<n; i++) {
        ans += min(abs(base[i]-pass[i]), 10-abs(base[i]-pass[i]));
    }
    cout << ans;
}