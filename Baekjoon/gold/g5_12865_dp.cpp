#include <stdio.h>
#include <list>

using namespace std;

//평범한 배낭

int main()
{
    int n, //물품의 수
    k, //버틸 수 있는 무게
    w[105], //각 물건의 무게
    v[105]; //각 물건의 가치
    int max[100010] = {0}; //k에 따른 최대 가치
    
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++)
    {
        scanf(" %d %d", w+i, v+i);
    }

    for(int i=0; i<n; i++)
    {
        for(int vol = k; vol >= 1; vol--)
        {
            if(w[i] <= vol)
            {
                int val = max[vol-w[i]] + v[i];
                max[vol] = (val > max[vol]) ? val : max[vol];
            }
        }
    }
    printf("%d", max[k]);
}
