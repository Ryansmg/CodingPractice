#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define size 10

int main()
{
    int *p;
    p = (int*) malloc(sizeof(int)*100);
    if(p==NULL)
    {
        printf("메모리가 부족해서 할당할 수 없음");
        exit(1);
    }
    int i;
    for(i=0; i<size; i++)
    {
        p[i] = i;
        printf("%d ", p[i]);
    }
    free(p);
    return 0;
}