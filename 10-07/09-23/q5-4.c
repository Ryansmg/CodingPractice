#include <stdio.h>

int change(int money, int unit)
{
    int count = 0;
    while(money >= unit)
    {
        money -= unit;
        count++;
    }
    if(count != 0) printf("%d = %d\n", unit, count);
    return money;
}

int main()
{
    while(1){
        int money;
        printf("금액을 입력하세요 : ");
        scanf(" %d", &money);
        if(money == 0) return 0;
        int plus = 10-(money % 10);
        money += (plus <= 5) ? plus : -1*(money%10);

        money = change(money, 10000);
        money = change(money, 5000);
        money = change(money, 1000);
        money = change(money, 500);
        money = change(money, 100);
        money = change(money, 50);
        money = change(money, 10);
    }
}