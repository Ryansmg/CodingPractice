#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    vector<int> count;
    ll sum = 0;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        count.push_back(a);
    }
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        sum += count[i] * a;
    }
    cout << sum;
}