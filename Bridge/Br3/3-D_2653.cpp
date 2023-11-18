#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll i;
    cin >> i;
    ll j = i%2==0 ? i/2-1 : i/2;
    cout << j;
}
