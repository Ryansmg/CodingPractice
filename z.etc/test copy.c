#include <stdio.h>
int main() {
    double f; scanf("%lf", &f);
    for(int i=63; i>=0; i--)
        printf("%d",(*(long long*)&f)&(1LL<<i)?1:0);
}