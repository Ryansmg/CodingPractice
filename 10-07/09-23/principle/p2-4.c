#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int ans = 0;
    scanf("%s", str);
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i] == '1'){
            ans++;
        }
        else if(str[i] != '0') {
            printf("다시 입력하시오.");
            return 0;
        }
    }
    if(ans%2==0) printf("짝수입니다.");
    else printf("홀수입니다.");
    
    return 0;
}