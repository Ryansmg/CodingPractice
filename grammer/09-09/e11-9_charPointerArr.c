#include <stdio.h>
#include <string.h>

int main()
{
    char a[3][9] = {"computer", "hello", "abc"}; //2차원 배열에 char 집어넣음 -> 공간 낭비
    char *b[3] = {"computer", "hello", "abc"}; //세 상수의 주소를 배열에 저장
    int i;
    strcpy(a[1], "bye"); //직접 대입 불가능
    b[1] = "bye"; //strcpy 불가능
    //strcpy(b[1], "bye");
    for(i=0; i<3; i++){
        printf("%s\n", a[i]);
        printf("%s\n", b[i]);
    }
}