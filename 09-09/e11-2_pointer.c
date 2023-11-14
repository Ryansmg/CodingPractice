#include <stdio.h>
int main()
{
    int b=2, *pb;
    printf("%d\n", b);
    pb = &b;
    *pb = 5;
    printf("%d", b);

    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int *pa = a;
    if(pa == &a[0]) printf("\nsame\n");
    printf("%d %d" , *a, a[0]);
}