#include <stdio.h>

//가장 긴 바이토닉 부분 수열
int main()
{
    int size;
    //정방향
    int input[1010], max[1010] = {0}, maxV = 1;
    bool isMax[1010] = {false};

    //역방향
    int max2[1010] = {0}, maxV2 = 1; bool isMax2[1010] = {false};

    scanf("%d", &size);

    for(int i=0; i<size; i++)
        scanf(" %d", input + i);

    max[0] = 1;
    isMax[0] = true;
    for(int i=1; i<size; i++)
    {
        max[i] = 1;
        for(int j=i-1; j>=0; j--)
        {
            if(input[j] < input[i] && max[i] < max[j]+1)
            {
                max[i] = max[j]+1;
                if(maxV < max[i]) {maxV = max[i]; isMax[i] = true;}
                if(isMax[j]) break;
            }
        }
    }
    
    max2[0] = 1;
    isMax2[0] = true;
    for(int i=size-1; i>=0; i--)
    {
        max2[i] = 1;
        for(int j=i+1; j<size; j++)
        {
            if(input[j] < input[i] && max2[i] < max2[j]+1)
            {
                max2[i] = max2[j]+1;
                if(maxV2 < max2[i]) {maxV2 = max2[i]; isMax2[i] = true;}
                if(isMax2[j]) break;
            }
        }
    }

    int maxx = 0;
    for(int i=0; i<size; i++)
    {
        if(maxx < max[i] + max2[i]) maxx = max[i] + max2[i];
        //printf("[%d]=%d\n", i, max[i] + max2[i]);
    }

    printf("%d", maxx-1);
}