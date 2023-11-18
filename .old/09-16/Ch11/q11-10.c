#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void grade(double *arr, int n, double *sum, double *avg, double *max);

int main()
{
    int i;
    double arr[MAX] = {0}, sum, avg, max;
    printf("%d명의 학생 점수를 입력하시오: ", MAX);
    for(i=0; i<MAX; i++)
    {
        scanf("%lf", arr+i);
    }
    grade(arr, MAX, &sum, &avg, &max);

    printf("\n배열의 메모리 크기: %d 바이트 \n\n", sizeof(arr));
    printf("학생수: %d\n", MAX);
    printf("총  합: %.2lf\n", sum);
    printf("평  균: %.2lf\n", avg);
    printf("최대값: %.2lf\n", max);

    return 0;
}

void grade(double *p, int n, double *psum, double *pavg, double *pmax)
{
    int i;
    *psum=0, *pmax = *p;
    for(i=0; i<n; i++)
    {
        *psum += *(p+i);
        if(*pmax < *(p+i))
            *pmax = *(p+i);
    }
    *pavg = *psum/n;
}