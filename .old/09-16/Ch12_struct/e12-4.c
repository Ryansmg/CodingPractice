#include <stdio.h>
struct sin {
    int id;
    char name[20];
    char address[50];
    char tel[15];
    int age;
    float ki;
};

int main()
{
    struct sin kk[4] = {
        {10, "안정무", "장항동", "123-1111", 19, 172.1},
        {13, "강산결", "마두동", "123-2222", 17, 167.1},
        {15, "윤필립", "장항동", "123-3333", 15, 165.1},
        {17, "권기석", "정발산", "123-5555", 14, 170.1}
    };
    int i;
    for(i=0; i<4; i++)
        printf("%d %s %s %s %d %.1f\n", kk[i].id, kk[i].name, kk[i].address, kk[i].tel, kk[i].age, kk[i].ki);
}