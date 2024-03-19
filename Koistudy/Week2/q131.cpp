#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    char c[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G'};
    int p = 1;
    while(p<a) p*=b;
    p/=b;
    while(1) {
        cout << c[a/p];
        a -= a/p*p;
        if(p==1) break;
        p /= b;
    }
}
