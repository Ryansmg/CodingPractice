#include <stdio.h>
#define lint long long

//색상환

int b[1001][1001] = {0}; //b[n][k]
bool calced[1001][1001] = {false};
lint br(int n, int k)
{
    if(n<0 || k<0) return 0;
    if(k==0) return 1;
    if(calced[n][k]) return b[n][k];
    else {
        b[n][k] = ((int)(br(n-2, k-1) + br(n-1, k))) % 1000000003;
        calced[n][k] = true;
        return b[n][k];
    }
}
int main()
{
    int n; //색의 개수
    int k; //고를 색 개수
    scanf("%d", &n);
    scanf(" %d", &k);
    b[1][1] = 1; calced[1][1] = true;
    printf("%lld", (br(n-3, k-1) + br(n-1, k)) % 1000000003);
}

/*
점화식 An,k = (원에서 n개 중 k개 선택)
1) 추가된 색 선택 : Bn-3,k-1
2) 추가된 색 선택 x : Bn-1,k
Bn,k = (직선에서 n개 중 k개 선택)
1) Bn-2,k-1
2) Bn-1,k
*/