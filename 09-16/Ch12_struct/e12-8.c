#include <stdio.h>

struct person {
    char name[20];
    char part[20];
    int age;
};
void per(struct person *kk)
{
    int i;
    for(i=0; i<3; i++){
        printf("이름: %s\n", kk->name);
        printf("부서: %s\n", kk->part);
        printf("나이: %d\n", kk->age);
        kk++;
    }
}

int main()
{
    struct person kk[3];
    int i;
    for(i=0; i<3; i++){
    printf("이름을 입력하세요");
    scanf("%s", kk[i].name);
    printf("\n부서를 입력하시오");
    scanf("%s", kk[i].part);
    printf("\n나이를 입력하세요");
    scanf("%d", &kk[i].age);
    }

    per(kk);
    return 0;
}