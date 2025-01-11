#include <stdio.h>
int n;
int ans(int i) {
    if(i==1) return 1;
    return ans(i-1)*2+1;
}
// k개, s에서 e로 m을 이용해서 이동시킨다.
void f(int k, char s, char e, char m) {
    if(k==0) return;
    f(k-1, s, m, e);
    printf("%c %c\n", s, e);
    f(k-1, m, e, s);
}
int main() {
    scanf("%d", &n);
//    printf("%d\n", ans(n));
    f(n, '1', '3', '2');
    return 0;
}