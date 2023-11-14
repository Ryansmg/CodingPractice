#include <stdio.h>
#include <string.h>

int main(){
    int arr[10][10] = {0}, x=0, y=5, n=1, t=0;
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<n; j++){
            arr[j][n-1-j] = ++t;
        }
        n++;
    }
    t=26;
    n=1;
    for(i=0; i<4; i++){
        for(j=0; j<n; j++){
            arr[4-j][4-(n-1-j)] = --t;
        }
        n++;
    }

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(arr[i][j]==0) printf("   ");
            else printf("%3d", arr[i][j]);
        }
        printf("\n");
    }

    /*
    int arr[100][100]={0}, x=0, y=5;
    int n, cnt=26, i, j;
    scanf("%d", &n);
    while(n>0){
        for(i=0; i<n; i++) arr[x][--y] = --cnt;
        n--;
        for(i=0; i<n; i++) arr[++x][y] = --cnt;
        for(i=0; i<n; i++) arr[x][++y] = --cnt;
        n--;
        for(i=0; i<n; i++) arr[--x][y] = --cnt;
    }

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(arr[i][j]==0) printf("   ");
            else printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
    /*
    //다이아몬드, 모래시계 출력
    int arr[5][5]={0}, a=2, b=2, i, j, n=0;
    for(i=0; i<5; i++){
        for(j=a; j<=b; j++) arr[4-j][4-i] = ++n;
        if(i<2) {
            a--; b++;
        }
        else {
            a++; b--;
        }
    }

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(arr[i][j]==0) printf("   ");
            else printf("%3d", arr[i][j]);
        }
        printf("\n");
    }

    int arr1[5][5] = {0};
    n=0; a=0; b=4;

    for(i=0; i<5; i++){
        for(j=a; j<=b; j++) arr1[i][j] = ++n;
        if(i<2) {
            a++; b--;
        }
        else {
            a--; b++;
        }
    }

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(arr1[i][j]==0) printf("   ");
            else printf("%3d", arr1[i][j]);
        }
        printf("\n");
    }

    /*
    int arr[5][5] = {0};
    int i, j, left=0, n=0;
    for(i=0; i<5; i++){
        if(left==0){
            for(j=0; j<5; j++){
                arr[i][j] = ++n;
            }
            left=1;
        } else {
            for(j=0; j<5; j++){
                arr[i][4-j] = ++n;
            }
            left=0;
        }
    }

    for(i=0; i<5; i++){
      for(j=0; j<5; j++){
            printf("%3d", arr[i][j]);
       }
       printf("\n");
    }

    /*
    int arr[5][5] = {0};
    int i, j, n=0;
    for(i=0; i<5; i++){
        for(j=i; j<5; j++){
            arr[i][j] = ++n;
        }
    }

    for(j=0; j<5; j++){
        for(i=0; i<5; i++){
            if(arr[i][j]==0) printf("   ");
            else printf("%3d", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int arr1[5][5] = {0};
    n=0;
    for(i=0; i<5; i++){
        for(j=0; j<i+1; j++){
            arr1[i][j] = ++n;
        }
    }

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(arr1[4-i][4-j]==0) printf("   ");
            else printf("%3d", arr1[4-i][4-j]);
        }
        printf("\n");
    }

    printf("\n");

    for(j=0; j<5; j++){
        for(i=0; i<5; i++){
            if(arr1[i][j]==0) printf("   ");
            else printf("%3d", arr1[i][j]);
        }
        printf("\n");
    }
    /*
    char a[] = "Hello software";
    printf("%c \n", a[6]);
    printf("%d \n", sizeof(a));
    printf("%d \n", a[14]);
    printf("%s \n", a);
    a[6] = 'S';
    printf("%s \n", a);

    /*
    int n, div=2, index=0, i;
    int arr[32];
    scanf(" %d", &n);

    if(n==0) printf("0");
    while(n!=0){
        if(n%div>0){
            n-=div/2;
            arr[index] = 1;
        } else {
            arr[index] = 0;
        }
        div *= 2;
        index++;
    }

    for(i=0; i<index; i++){
        printf("%d", arr[index-i-1]);
    }

    /*
    int n; 
    scanf(" %d", &n);
    int arr[100];
    int i, j, temp;
    for(i=0; i<n; i++) scanf(" %d", &arr[i]);

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int ans;
    scanf(" %d", &ans);
    printf("%d", arr[ans]);

    /*
    int n; //카드의 전체 장 수
    scanf(" %d", &n);
    int arr[100]; //있는 카드
    int i;
    for(i=0; i<n-1; i++) scanf(" %d", &arr[i]);

    int sum=0;
    for(i=1; i<=n; i++) sum += i;
    for(i=0; i<n-1; i++) sum -= arr[i];
    printf("%d", sum);

/*
    int arr[] = {10, 20, 30, 25, 15, 5, 11, 22, 9, 17};
    int i, j;
    for(i=0; i<10; i++){
        printf("%-2d ", arr[i]);
        for(j=0; j<arr[i]; j++) printf("*");
        printf("\n");
    }
    

    /*

    char arr[] = {'c', 'o', 'm', 'p', 'u', 't', 'e', 'r'};
    int i, size;
    size = strlen(arr);
    for(i=0; i<size; i++){
        printf("%c", arr[i]);
    }

    /*
    char arr[] = "Hello\0World\0";
    char arr2[] = { 'A', 'B', 'C', '\0' };

    printf("문자열 일부 %s \n", arr);
    printf("문자 일부 %s \n", arr2);
    printf("문자열 배열의 크기 = %d \n", sizeof(arr));
    printf("문자 배열의 크기 = %d \n", sizeof(arr2));

    /*
    int a1[1000], a2[1000], count, i, j, temp;
    printf("정수의 개수를 입력하세요: ");
    scanf(" %d", &count);
    for(i=0; i<count; i++){
        scanf(" %d", &a1[i]);
        a2[i] = a1[i];
    }

    for(i=0; i<count; i++){
        for(j=i+1; j<count; j++){
            if(a1[i] > a1[j]) {
                temp = a1[i];
                a1[i] = a1[j];
                a1[j] = temp;
            }
        }
    }

    printf("선택정렬:\n");
    for(i=0; i<count; i++)
        printf("%3d", a1[i]);


    for(i=0; i<count-1; i++){
        for(j=0; j<count-1-i; j++){
            if(a2[j] > a2[j+1]){
                temp = a2[j];
                a2[j] = a2[j+1];
                a2[j+1] = temp;
            }
        }
    }

    printf("\nBubble Sort:\n");
    for(i=0; i<count; i++)
        printf("%3d", a2[i]);
    /*
    int day, count;
    int i, j;
    printf("1일은 무슨 요일입니까(0~6)? ");
    scanf(" %d", &day);
    printf("총 며칠입니까? ");
    scanf(" %d", &count);

    printf("일 월 화 수 목 금 토\n");
    for(i=0; i<6-day; i++) printf("   ");
    for(i=1; i<=count; i++){
        printf("%2d ", i);
        if(++day == 7) {
            printf("\n");
            day = 0;
        }
    }
    


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

    /*
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