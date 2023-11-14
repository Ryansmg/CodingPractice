#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
char* f()
{
    char* name = (char*)malloc(sizeof(char) * 100);
    printf("이름을 입력하시오: ");
    fgets(name, sizeof(name), stdin);
    return name;
}

int main()
{
    char* str1;
    char* str2;
    str1 = f();
    printf("str1에 내 이름을 출력 ");
    printf("%s\n", str1);

    str2 = f();
    printf("str2에 내 이름을 출력 ");
    printf("%s\n", str2);

    free(str1);
    free(str2);
    return 0;
}