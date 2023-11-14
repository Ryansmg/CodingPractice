#include <stdio.h>
#include <vector>
using namespace std;

//햄버거 분배

int main()
{
    int n, range, ans=0;
    scanf("%d %d", &n, &range);
    vector<char> burger(n);
    for(int i=0; i<n; i++) {
        char c;
        scanf(" %c", &c);
        burger[i] = c;
    }
    for(int i=0; i<n; i++)
    {
        if(burger[i]!='P') continue;

        int ind = (i-range)>=0 ? i-range : 0;
        for(int j=ind; j<=i+range && j<n; j++)
        {
            if(burger[j]=='H') {
                burger[j] = 'N';
                ans++;
                break;
            }
        }
    }
    printf("%d", ans);
}