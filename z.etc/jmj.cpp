#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <math.h>
#include <tuple>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s[10]={};
    int arr[300]={};
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
        int m=s[i].size();
        int k=1;
        for(int j=m-1;j>=0;j--){
            arr[s[i][j]]+=k;
            k=k*10;
        }
    }
    sort(arr, arr+300);
    int t=0, ans=0, l=9;
    while(arr[t]==0) t++;
    for(int i=299;i>=t;i--){
        ans+=arr[i]*l;
        l--;
    }
    cout << ans;
}