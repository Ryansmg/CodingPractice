#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("앞면은 1\n뒷면은 2\n종료는 다른 값을 입력하기\n동전을 던졌습니다. 앞면? 뒷면? : ");
    int in;
    scanf("%d", &in);
    if(in!=1 && in!=2) return 0;
    srand(time(NULL));
    int ai = rand()%2+1;
    printf("사용자 : %s 동전 : %s\n", (in==1) ? "앞면" : "뒷면", (ai==1) ? "앞면" : "뒷면");
    printf("%s", (ai==in) ? "맞았습니다!" : "꽝");
}