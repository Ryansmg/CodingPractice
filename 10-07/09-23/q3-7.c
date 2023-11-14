#include <stdio.h>

int main()
{
    int r, y; float m;
    printf("R, M, Y가 입력된다 : ");
    scanf("%d %f %d", &r, &m, &y);
    for(int i=0; i<y; i++)
    {
        m = m * (1.0f+(r/100.0f));
    }
    printf("Y년 후의 최종 금액을 출력한다. : %d", (int) m);
}