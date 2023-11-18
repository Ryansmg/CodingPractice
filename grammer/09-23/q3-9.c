#include <stdio.h>

int main()
{
    int price;
    printf("물건 값으로 세자리 자연수가 입력으로 주어진다. : ");
    scanf("%d", &price);
    int change = 1000 - price;
    int hund = 0, fifty = 0, ten = 0;
    while(change >= 100){
        change -= 100;
        hund += 1;
    }
    while(change >= 50)
    {
        change -= 50;
        fifty += 1;
    }
    ten = change / 10;
    printf("동전 100원, 50원, 10원의 개수를 출력 : %d %d %d", hund, fifty, ten);
}