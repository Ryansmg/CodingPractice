#include <stdio.h>
#include <string.h>

int main()
{
    char c[1000005];
    int alp[26] = {0}, max=-1, maxInd;
    bool multi = false;
    scanf("%s", c);
    int size = strlen(c);
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<26; j++)
        {
            if(c[i] == ('A' + j)) {alp[j]++;break;}
            if(c[i] == ('a' + j)) {alp[j]++;break;}
        }
    }
    for(int i=0; i<26; i++)
    {
        if(alp[i] > max)
        {
            multi = false;
            maxInd = i;
            max = alp[i];
        } else if(alp[i] == max)
            multi = true;
    }
    if(multi) printf("?");
    else printf("%c", 'A' + maxInd);
}