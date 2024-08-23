#include <iostream>
using namespace std;

int main() 
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a>b) swap(a, b);
    if(c>d) swap(c, d);
    if(a+c==d && b==d) cout << "YES";
    else cout << "NO";
}