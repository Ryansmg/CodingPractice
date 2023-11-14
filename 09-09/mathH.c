#include <stdio.h>
#include <math.h>
#define PI 3.141592
int main()
{
    float radian = 30.0f, s, c, t;
    s = sin(radian*PI/180);
    c = cos(radian*PI/180);
    t = tan(radian*PI/180);
    printf("sin °ª=%f\n", s);
    printf("cos °ª=%f\n", c);
    printf("tan °ª=%f\n", t);

    float x1,y1;
    x1=exp(1);
    y1=exp(1.0);
    printf("x=%f\ny=%f\n", x1, y1);

    float x=10, y=9, z=2;
    int a = -2;

    printf("log(10.0) = %f \n", log(x));
    printf("log10(10.0) = %f \n", log10(x));
    printf("sqrt(9) = %f \n", sqrt(y));
    printf("abs(-2) = %d \n", abs(a));
    printf("pow(9,2) = %f \n", pow(y,z));
}