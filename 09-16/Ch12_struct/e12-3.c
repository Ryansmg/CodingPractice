#include <stdio.h>

struct sin {
    char name[15];
    int age;
    float ki;
}
s1 = {"강산결", 17, 167.5};

struct sin s2 = {"손민기", 16, 170.0};

int main()
{
    struct sin s3 = {"안정무", 19, 172.1};
    printf("name: %s age: %d ki: %.1f\n", s1.name, s1.age, s1.ki);
    printf("name: %s age: %d ki: %.1f\n", s2.name, s2.age, s2.ki);
    printf("name: %s age: %d ki: %.1f\n", s3.name, s3.age, s3.ki);
}