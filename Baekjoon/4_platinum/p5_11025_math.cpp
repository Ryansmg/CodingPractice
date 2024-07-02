#include <iostream>
#include <vector>
#define ll long long
using namespace std;

//요세푸스 문제 3
//#math #dp

int main()
{
    int a, b;
    cin >> a >> b;
    int pre = 1, now;
    for(int i=2; i<=a; i++) {
        now = ((pre + b - 1) % i + 1);
        pre = now;
    }
    cout << pre;
}