#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    if(n==1) {
        cout << 0;
        return 0;
    }
    if(n==2) {
        cout << m;
        return 0;
    }
    cout << 2*m;
}
