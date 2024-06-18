#include <bits/stdc++.h>
int ans;
void calc(int i) {
    if(!i) return;
    ans += i&1;
    calc(i>>1);
    std::cout << (i&1);
}
int main() {
    calc(2147483600);
    printf("%d", ans);
}