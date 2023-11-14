#include <stdio.h>

int main()
{
    int a[100], b[100], n;
    printf("항의 수, A1, B1 = ? ");
    scanf("%d, %d, %d", &n, a, b);
    printf("  N    An    Bn    Cn\n");
    printf("=====================\n");
    printf("%3d%6d%6d%6d\n", 1, a[0], b[0], 1);
    for(int i=1; i<n; i++){
        b[i] = b[i-1] + i;
        a[i] = a[i-1] + b[i-1];
        printf("%3d%6d%6d%6d\n", i+1, a[i], b[i], i+1);
    }
    printf("=====================");
}