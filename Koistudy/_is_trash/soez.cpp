#include <bits/stdc++.h>
#include <string>
using namespace std;
#define int long long
#define USE_FAST_IO 1
#define fastio if(USE_FAST_IO) { ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); }

template <typename T>
void print(T s, string end="\n") {
    cout << s << end;
}

template <typename T2>
T2 input(T2 c) {
    T2 in; cin >> in; return in;
}

signed main()
{
    //fastio;
int n, i, j, x, y;
int a[20][20]={};
for(i=1; i<=19; i++) //한 줄씩 바둑판 상황 입력 받기
  for(j=1; j<=19; j++)
    scanf("%lld", &a[i][j]);

scanf("%lld", &n); //좌표 개수 입력받기

for(i=1; i<=n; i++) //좌표의 개수만큼
{
  scanf("%lld %lld", &x, &y);
  for(j=1; j<=19; j++) //가로 줄 흑<->백 바꾸기
  {
    if(a[x][j]==0) a[x][j]=1;
    else a[x][j] = 0;
  }
  for(j=1; j<=19; j++) //세로 줄 흑<->백 바꾸기
  {
    if(a[j][y]==0) a[j][y]=1;
    else a[j][y] = 0;
  }
}
    for(i=1; i<=19; i++) //한 줄(위에서 아래로) 씩
    {
    for(j=1; j<=19; j++) //한 열(왼쪽에서 오른쪽으로) 씩
    {
        printf("%lld ", a[i][j]); //값 출력
    }
        printf("\n"); //줄  
    }
}