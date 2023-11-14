#include <stdio.h>
#include <string.h>

int main()
{
    int type, i;
    char input[100];
    char *korDict[5] = {"책", "컴퓨터", "프로그램", "키보드", "마우스"};
    char *engDict[5] = {"book", "computer", "program", "keyboard", "mouse"};
    printf("(영한 : 1, 한영 : 2): ");
    scanf(" %d", &type);
    if(type==1)
    {
        printf("영어 단어를 입력하세요: ");
        scanf(" %s", input);
        for(i=0; i<5; i++)
        {
            if(strcmp(engDict[i], input) == 0)
            {
                printf("'%s'는 한글로 '%s'입니다.", input, korDict[i]);
            }
        }
    }
    else if(type==2)
    {
        printf("한글 단어를 입력하세요: ");
        scanf(" %s", input);
        for(i=0; i<5; i++)
        {
            if(strcmp(korDict[i], input) == 0)
            {
                printf("'%s'는 영어로 '%s'입니다.", input, engDict[i]);
            }
        }
    }
}