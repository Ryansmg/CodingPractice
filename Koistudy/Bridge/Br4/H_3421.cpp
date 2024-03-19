#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

ll max(ll a, ll b) {
    return a>b?a:b;
}
int main() {
    ll n; cin >> n;
    vector<int> temp(n);
    vector<vector<int>> note(n, temp);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n/2.0; j++) {
            note[i][j] = (i+1) * (j+1);
            note[i][n-j-1] = note[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cout << note[i][j] << " ";
        cout << "\n";
    }

}