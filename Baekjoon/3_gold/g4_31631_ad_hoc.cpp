#include <iostream>
#include <vector>
using namespace std;

//:rightplant:
//#ad_hoc

int main()
{
    int n;
    cin >> n;
    vector<int> ans(n);
    int start = (n-1)/2;
    bool rf = true; int temp=0;
    if(n%4==3) rf = false; //해결
    // n%4==1 해결
    if(n%4==0) {
        rf = false;
        start++;
        temp=1;
        ans[start-1] = 2;
    }
    if(n%4==2) {
        ans[start+1] = 2;
        temp=1;
    }
    ans[start] = 1;
    if(n%4==0) start--;
    int left = start, right = start;
    if(n%2==0) right++;
    for(int i=2+temp; i<=n; i++) {
        if(rf) {
            ans[++right] = i++;
            if(i>n) break;
            ans[--left] = i;
        } else {
            ans[--left] = i++;
            if(i>n) break;
            ans[++right] = i;
        }
        rf = !rf;
    }
    for(int i : ans) cout << i << " ";
}
