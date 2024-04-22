#include <stdio.h>

int main()
{
    int tar, in; //tar를 in진법으로 변환
    scanf("%d %d", &tar, &in);
    char arr[100]; //역순으로 출력하기 위한 배열
    int size = 0;
    while(tar > 0) {
        int out = tar % in;
        tar /= in;
        // 숫자 || 알파벳 출력하는 경우를 구별
        if(out<=9) {
            arr[size] = '0' + out;
        } else {
            arr[size] = 'a' + out - 10;
        }
        size++;
    }
    //역순 출력
    for(int i = size-1; i>=0; i--)
        printf("%c", arr[i]);
}
