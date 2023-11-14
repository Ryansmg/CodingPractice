#include <stdio.h>

int main()
{
    int year, month, length, day;
    scanf("%d년 %d월", &year, &month);
    switch(month){ //배열을 사용하는 방법도 존재
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            length = 31;
            break;
        case 2:
            length = 28;
            if(year%4==0 && year%100!=0) length = 29;
            else if(year%400==0) length = 29;
            break;
        default:
            length=30;
            break;
    }

    //TODO 요일 계산
    day = 5;
    printf("%d\n", month);

    int i;
    printf("일 월 화 수 목 금 토\n");
    for(i=0; i<day; i++) printf("   ");
    for(i=1; i<=length; i++)
    {
        printf("%-3d", i);
        day++;
        if(day==7)
        {
            day=0; printf("\n");
        }
    }
}