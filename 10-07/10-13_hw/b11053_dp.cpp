#include <stdio.h>

//증가수열 최대 길이
int main()
{
    int size; int input[1010], max[1010] = {0}, maxV = 1;
    bool isMax[1010] = {false};
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

    printf("%d", maxV);
}