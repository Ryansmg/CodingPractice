#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    ll two=0, five=0;
    while(n%5==0) {
        five++;
        n/=5;
    }
    while(n%2==0) {
        two++;
        n/=2;
    }
    if(n!=1 || two>five) cout << -1;
    else cout << five + five - two;
}
