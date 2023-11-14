#include <stdio.h>
int main()
{
    double a = 3.14159;
    double *p1 = &a;
    double **pa = &p1;

    printf("%3p %3p \n", p1, *pa);
    printf("%3g %3g \n", a, **pa);
}