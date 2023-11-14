#include <stdio.h>
#include <string.h>

int main()
{
    char input[100000];
    scanf("%s", input);
    int wasOpen = 0;
    int pipeCount = 0;
    int ans = 0;
    int len = strlen(input);

    for(int i=0; i<len; i++)
    {
        if(input[i] == '(')
        {
            pipeCount++;
            wasOpen = 1;
        }
        else {
            if(wasOpen)
            {
                ans += --pipeCount;
            } else {
                pipeCount--;
                ans++;
            }
            wasOpen = 0;
        }
    }

    printf("%d", ans);
}