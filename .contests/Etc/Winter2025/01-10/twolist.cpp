#ifdef LOCAL
#include <iostream>
int twolist(int);

static const int MX=500010;

static int n, A[MX], B[MX];
static int cnt;

int compare(int i, int j){
    cnt++;
    return A[i]<B[j] ? -1 : 1;
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &A[i]);
    for(int i=1; i<=n; i++) scanf("%d", &B[i]);

    printf("Your answer: %d\n", twolist(n));
    printf("Compare count: %d\n", cnt);

    return 0;
}
#else
#include "twolist.h"
#endif

int twolist(int n){
    int l = 1, r = n;
    int a = 0;
    while(l <= r) {
        int am = (l + r) / 2;
        int bm = n - am;
        if(compare(am, bm) < 0) {
            a = am; l = am + 1;
        } else {
            r = am - 1;
        }
    }
    // a, n-a, a+1, n-a-1 중 3번째로 큰 애
    int x = compare(a+1, n-a);
    return x<0 ? a+1 : n + n-a;
}
