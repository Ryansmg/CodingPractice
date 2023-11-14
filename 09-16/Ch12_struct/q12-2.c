#include <stdio.h>
typedef struct MENU{
    char name[20];
    int cnt, price;
} menu;

int main()
{
    menu bunsik[] = {
        {"placeholder", 0, 0},
        {"토스트", 0, 1500},
        {"떡볶이", 0, 3500},
        {"핫도그", 0, 1000},
        {"김치볶음밥", 0, 6500},
        {"닭다리", 0, 4000}
    };
    for(int i=1; i<sizeof(bunsik)/sizeof(menu); i++){
        printf("%d. %s (%d원)\n", i, bunsik[i].name, bunsik[i].price);
    }
    printf("몇 개의 메뉴를 입력하시겠습니까? ");
    int order_cnt;
    scanf("%d", &order_cnt);
    for(int i=0; i<order_cnt; i++) {
        int menu_num, menu_cnt;
        printf("메뉴 번호: ");
        scanf("%d", &menu_num);
        printf("개수: ");
        scanf("%d", &menu_cnt);
        bunsik[menu_num].cnt = menu_cnt;
    }
    int is_coupon = 0;
    {
        char inp;
        printf("쿠폰을 사용하시겠습니까? (y/n)");
        scanf(" %c", &inp);
        if(inp == 'y' || inp == 'Y')
            is_coupon = 1;
    }
    int sum = 0;
    int most_expensive = 0;
    for(int i=1; i<sizeof(bunsik)/sizeof(menu); i++){
        sum+= bunsik[i].cnt * bunsik[i].price;
    }
    printf("현재 총 주문 금액은 %d원입니다.\n", sum);
    if(is_coupon) {
        most_expensive = 0;
        for(int i=1; i<sizeof(bunsik)/sizeof(menu);i++)
            if(bunsik[i].cnt > 0 && most_expensive < bunsik[i].price)
                most_expensive = bunsik[i].price;
    }
    printf("최종 결제 금액은 %d원입니다.", sum - most_expensive/10);
}