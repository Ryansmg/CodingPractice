#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n, m;
    cin >> n >> m;
    if((m-1)*n <= m) cout << "YES";
    else cout << "NO";
}