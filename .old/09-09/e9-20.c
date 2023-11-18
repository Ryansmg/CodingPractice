#include <stdio.h>
double power(double a, int b);
int main()
{
    printf("%.5lf", power(3.1415926, 3));
    return 0;
}
double power(double a, int b)
{
    if(b==0) return 1;
    return a * power(a, b-1);
}