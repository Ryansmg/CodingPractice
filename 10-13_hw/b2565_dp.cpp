#include <stdio.h>

//전깃줄

int start[101];
int end[101];
int num;

int main()
{
    scanf("%d", &num);
    int maxCross = -1; int maxCrossIndex;
    for(int i=0; i<num; i++){
        scanf(" %d %d", start+i, end+i);
    }
    
    for(int i=0; i<num-1; i++)
    {
        for(int j=i+1; j<num; j++)
        {
            if(start[i]>start[j]){
                int temp = start[j];
                start[j] = start[i];
                start[i] = temp;
                temp = end[j];
                end[j] = end[i];
                end[i] = temp;
            }
        }
    }

    //end[]의 최대 증가수열 길이 구하기
    int max[101] = {1};
    bool isMax[101] = {false};
    int maxV = 0;

    isMax[0] = true;
    for(int i=1; i<num; i++)
    {
        max[i] = 1;
        for(int j=i-1; j>=0; j--)
        {
            if(end[j] < end[i] && max[j]+1 > max[i])
            {
                max[i] = max[j]+1;
                if(maxV < max[i])
                {
                    maxV = max[i];
                    isMax[i] = true;
                }
                if(isMax[j]) break;
            }
        }
    }

    printf("%d", num - maxV);
}
