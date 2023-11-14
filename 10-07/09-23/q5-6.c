#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        char value[100];
        scanf(" %s", value);
        printf("￦");
        for(int j=0; j<strlen(value); j++){
            printf("%c", value[j]);
            if(j%3 == strlen(value)%3-1 && j!= strlen(value)-1) printf(",");
        }
        printf("\n");
    }
}