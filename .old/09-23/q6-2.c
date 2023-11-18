#include <stdio.h>

int main()
{
    for(int i=1; i<=2000; i++)
    {
        int size = (i >= 10) ? 10 : 1;
        size = (i >= 100) ? 100 : size;
        size = (i >= 1000) ? 1000 : size;

        int armst = 0;
        for(int j=1; j<=size; j *= 10)
        {
            int n = (i%(size*10/j))/(size/j);
            armst += n*n*n;
        }
        if(armst == i) printf("%d\n", i);
    }
}