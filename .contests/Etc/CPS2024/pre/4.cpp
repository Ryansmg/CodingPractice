#include <bits/stdc++.h>
using namespace std;
int main() {
    int ans = 0;
    for(int i=2; i<=60; i+=2) ans |= i;
    for(int i=1; i<=32; i<<=1) cout << (ans&i?1:0); // 011111
}
