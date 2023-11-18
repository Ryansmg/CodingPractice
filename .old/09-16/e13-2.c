#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("output.txt", "w");

    if(fp == NULL){
        printf("파일 열기 실패\n");
        return 1;
    }

    fputs("문자열 출력하기\n", fp);
    fputs("긴 문장을 출력하기", fp);

    fclose(fp);
    return 0;
}