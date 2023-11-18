#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int pwin=0, cwin=0;
    char* name[] = {"가위", "바위", "보"};
    for(int i=0; i<5; i++)
    {
        int com = rand()%3;
        int pl;
        scanf(" %d", &pl);
        pl = pl%3;
        if(com==pl) continue;
        switch(com)
        {
            case 0:
                if(pl==1) pwin++;
                else cwin++;
                break;
            case 1:
                if(pl==2) pwin++;
                else cwin++;
                break;
            case 2:
                if(pl==0) pwin++;
                else cwin++;
                break;
        }
    }
    printf("결과\n%s 이겼다.\n이긴 횟수 %d회", (pwin>=cwin) ? "사용자" : "컴퓨터", (pwin>=cwin) ? pwin : cwin);
}