#include <stdio.h>
int n;
int f(int a, int b, int i) {
    if(i==n) return a+b;
    return f(b, a+b, i+1);
}
int main() {
    n = 7;
    printf("%d", f(1, 1, 3));
}