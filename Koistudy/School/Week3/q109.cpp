#include <iostream>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    if(a>b) swap(a,b);
    if(a>c) swap(a, c);
    if(b>c) swap(b, c);
    if(a+b<=c) cout << "Not";
    else if(a==b&&b==c) cout << "Regular";
    else if(a==b||b==c)  cout << "Isosceles";
    else if(a*a+b*b==c*c) cout << "Right";
    else cout << "Normal";
}