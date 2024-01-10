#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int l,c;
    scanf("%d %d", &l, &c);
    char chars[15];
    int index[15] = {0};
    for(int i=0; i<c; i++)
        scanf(" %c", chars+i);

    sort(chars, chars+c-1);
    
    while(true)
    {
        index[l-1]++;
        for(int i=l-1; i>0; i--) 
            if(index[i] == c-(l-1-i)) {index[i-1]++; index[i] = index[i-1]+1;}
            else break;
        
        int indSum = 0;
        for(int i=0; i<l; i++) indSum += index[i];
        if(indSum == (c-1)*l) break;
        for(int i=0; i<l; i++) printf("%d ", index[i]);
        printf("\n");
    }
}