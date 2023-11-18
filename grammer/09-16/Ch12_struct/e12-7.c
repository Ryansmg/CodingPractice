#include <stdio.h>

struct person {
    char name[20];
    char part[20];
    int age;
};
void per(struct person kk)
{
    printf("이름: %s\n", kk.name);
    printf("부서: %s\n", kk.part);
    printf("나이: %d\n", kk.age);
}

int main()
{
    struct person kk;
    printf("이름을 입력하세요");
    scanf("%s", kk.name);
    printf("\n부서를 입력하시오");
    scanf("%s", kk.part);
    printf("\n나이를 입력하세요");
    scanf("%d", &kk.age);

    per(kk);
    return 0;
}