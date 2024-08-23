#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    char c[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G'};
    int p = 1;
    while(p*b<a) p*=b;
    while(1) {
		printf("%c", c[a/p]);
        a %= p;
        if(p==1) break;
        p /= b;
    }
}
