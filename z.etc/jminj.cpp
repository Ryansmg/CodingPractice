#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <math.h>
using namespace std;
int ans[351][351], map[351][351];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++) cin >> map[i][j];
    }
    ans[0][0]=map[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                ans[i][j]=ans[i-1][j]+map[i][j];
            }
            else if(j==i-1){
                ans[i][j]=ans[i-1][j-1]+map[i][j];
            }
            else ans[i][j] = max(ans[i-1][j], ans[i-1][j-1])+map[i][j];
        }
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(max<ans[n-1][i]) max=ans[n-1][i];
    }
    cout << max;
}