#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i,n;
    printf("\n난수 발생 srand(100) 사용 후 \n");
    srand(100);
    for(i=0; i<10; i++)
    {
        printf("%7d", rand());
    }

    printf("\n난수 발생 srand(time) 사용 후 \n");
    srand((unsigned) time(NULL));
    for(i=0; i<10; i++){
        printf("%7d", rand());
    }
    printf("\n난수 발생 범위 조절(1-6)\n");
    for(i=0; i<10; i++)
    {
        n=rand()%6 + 1;
        printf("%7d", n);
    }
}