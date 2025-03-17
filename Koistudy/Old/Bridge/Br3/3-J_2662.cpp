#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    int evenWrong = 0, oddWrong = 0;
    for(int i=0; i<n; i++) {
        int expected = i%2;
        ll t; cin >> t;
        if(t%2 != expected) {
            if(expected==0) evenWrong++;
            else oddWrong++;
        }
    }
    if(evenWrong != oddWrong) cout << -1;
    else cout << evenWrong;
}