#include <stdio.h>
#define n 9
#define arrLen 333

int main()
{
    int maxLenX[arrLen] = {0}, minLenX[arrLen] = {0};
    int maxFound = 0, minFound = 0;
    int max = -1, min = 2100000000;
    for(int i=1; i<=n; i++)
    {
        int x = i;
        int count = 0; 
        while(x!=4) {
            printf("%d -> ", x);
            if(x%2==0) {
                x /= 2;
            } else {
                x = x*3+1;
            }
            count++;
        }
        printf("4 (%d)\n", count);

        if(count == 0) continue;

        if(count == max) {
            maxLenX[maxFound] = i;
            maxFound++;
        }
        if(count > max) {
            max = count;
            for(int j=0; j<arrLen; j++) maxLenX[j] = 0;
            maxLenX[0] = i;
            maxFound = 1;
        }
        if(count == min) {
            minLenX[minFound] = i;
            minFound++;
        }
        
        if(count < min) {
            min = count;
            for(int j=0; j<arrLen; j++) minLenX[j] = 0;
            minLenX[0] = i;
            minFound = 1;
        }
    }
    printf("가장 긴 연결 : %d", maxLenX[0]);
    int i = 1;
    while(maxLenX[i] != 0){
        printf(", %d", maxLenX[i]);
        i++;
    }
    printf("\n가장 짧은 연결 : %d", minLenX[0]);
    i = 1;
    while(minLenX[i] != 0){
        printf(", %d", minLenX[i]);
        i++;
    }
}