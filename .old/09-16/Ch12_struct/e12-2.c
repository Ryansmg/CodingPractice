#include <stdio.h>

struct sungjuk
{
    char name[15];
    int kor;
    int eng;
    int computer;
    int tot;
    float ave;
};

int main()
{
    struct sungjuk soo;
    printf("이름: "); gets(soo.name);
    printf("국어: "); scanf(" %d", &soo.kor);
    printf("영어: "); scanf(" %d", &soo.eng);
    printf("컴퓨터: "); scanf(" %d", &soo.computer);

    soo.tot = soo.kor + soo.eng + soo.computer;
    soo.ave = soo.tot / 3.;

    printf("이름 :%s\n국어: %d\n영어: %d\n컴퓨터: %d\n", soo.name, soo.kor, soo.eng, soo.computer);
    printf("총점: %d 평균: %.0f\n", soo.tot, soo.ave);
}