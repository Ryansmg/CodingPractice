#include <stdio.h>
struct point {
    int xpos;
    int ypos;
};
typedef struct point Point;

typedef struct person
{
    char name[20];
    char phoneNum[20];
    int age;
} Person;

int main()
{
    Point pos = {100, 200};
    Person man = {"±ÇÃ¶", "010-1234-5678", 17};
    printf("%d %d \n%s %s %d", pos.xpos, pos.ypos, man.name, man.phoneNum, man.age);

    return 0;
}