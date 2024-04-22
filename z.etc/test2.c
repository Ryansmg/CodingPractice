#include <stdio.h>

int main()
{
    // n, m 입력받기
    int n, m;
    scanf("%d %d", &n, &m);
    int in[n+1]; in[0] = 0;

    // 수열 입력받기
    for(int i=1; i<=n; i++) 
        scanf(" %d", in+i);
    
    // 누적 합 배열 생성
    int dp[n]; dp[0] = 0;
    dp[1] = in[1];
    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + in[i];
    
    // 쿼리(질문) 처리
    for(int i=0; i<m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        printf("%d ", dp[b] - dp[a-1]);
    }
}