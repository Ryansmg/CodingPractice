#include <iostream>
using namespace std;
#define ll long long

ll max(ll a, ll b) {
    return a>b?a:b;
}
ll* minPtr(ll* ap, ll* bp) {
    return *ap<*bp?ap:bp;
}
int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    int i = 0;
    while(max(a,b)<=c) {
        *minPtr(&a, &b) += max(a,b);
        i++;
    }
    cout << i;
}