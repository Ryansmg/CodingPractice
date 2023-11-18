#include <stdio.h>
#include <string.h>

int main(){
    /*
    int day, count;
    int i, j;
    printf("1일은 무슨 요일입니까(0~6)? ");
    scanf(" %d", &day);
    printf("총 며칠입니까? ");
    scanf(" %d", &count);

    printf("일 월 화 수 목 금 토\n");
    for(i=0; i<day; i++) printf("   ");
    for(i=1; i<=count; i++){
        printf("%2d ", i);
        if(++day == 7) {
            printf("\n");
            day = 0;
        }
    }
    
    /*

    int input;
    printf("1. 일요일\n2. 월요일\n3. 화요일\n4. 수요일\n5. 목요일\n6. 금요일\n7. 토요일\n수를 입력하세요 : ");
    scanf("%d", &input);
    switch(input){
        case 2:
        case 4:
        case 6: printf("학교 가는 날"); break;
        case 1:
        case 3:
        case 5:
        case 7: printf("학교 안 가는 날"); break;
        default: printf("잘못 입력되었습니다."); break;
    }

    /*
    int i, j, k, l;

    for(i=1; i<=9; i++) {
        if(i > 5) l=10-i;
        else l=i;

        for(k=1; k<=5-l; k++) printf("  ");
        for(j=1; j<=l; j++) printf("%2d", j);
        printf("\n");
    }

    /*
    int i, j;
    for(i=1; i<=7; i++) {
        for(j=1; j<=10; j++){
            printf("%2d ", i*j);
        }
        printf("\n");
    }

    /*
    int a, b, temp;
    int i, j;
    printf("두 개의 정수를 입력하여라: ");
    scanf("%d %d", &a, &b);

    if(a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    for(i=1; i<10; i++){
        for(j=a; j<=b; j++){
            printf("%d*%d=%d\t", j, i, j*i);
        }
        printf("\n");
    }

    /*
    char repeat;
    int i,j;
    char c1, c2;
    do {
   
    printf("문자를 입력하라 ? ");
    scanf(" %c %c", &c1, &c2);

    if(c1 >= 97 && c1 <= 122) { 
        for(i = c1; i <= c2; i++) {
            printf("%c", i-32);
        }
    } else {
        for(i = c1; i <= c2; i++) {
            printf("%c", i+32);
        }
    }

    printf("다시 실행할까요(Y/N)?" );
    scanf(" %c", &repeat);

    } while (repeat == 'Y' || repeat == 'y');

    /*
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    a = (((a > b) ? a : b) > c) ? ((a > b) ? a : b) : c;

    printf("%d", a);

    /*
    char word[100];
    printf("문자 길이가 10이 넘는 문자열을 입력해 보세요.");
    fgets(word, sizeof(word), stdin);
    printf("입력받은 %d개의 문자: %s", sizeof(word), word);

    /*
    char name[100];
    printf("문자열을 입력하시오:");
    gets(name);

    printf("당신의 이름 = %s 입니다.", name);

    /*
    char ch, word[100];
    printf("문자 하나를 입력하세요: ");
    scanf("%c", &ch);

    printf("단어 하나를 입력하세요: ");
    scanf(" %s", word);

    printf("결과 =%c %s \n", ch, word);

    /*
    int a;
    float b;
    char k;
    printf("문자 하나와 실수 하나, 정수 한 개를 입력하시오. ");
    scanf("%c %f %d", &k, &b, &a); //키보드로부터 입력받는 함수

    printf("출력= %c    %1f     %d", k, b, a);
    */
    
    int a, b, c=3, d=5, e, f;
    a = c | d;
    b = c & d;
    e = c ^ d;
    f = ~d;
    printf("c|d= %d c&d= %d \n", a, b);
    printf("c^d= %d ~d= %d", e, f);

    /*
    int a, b;
    a=0x41;
    b=0x42;
    printf("%d %o %x %c \n", a, a, a, a);
    printf("%d %o %x %c", b, b, b, b);
    */
}