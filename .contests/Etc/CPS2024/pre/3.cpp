#include <bits/stdc++.h>
using namespace std;
bool check1(int i) {
    if(i/10==1) return true;
    if(i%10==1) return true;
    return false;
}
int main() {
    int ans = 0;
    for(int i=0; i<=23; i++)
        for(int j=0; j<=59; j++)
            for(int k=0; k<=59; k++)
                if(check1(i)||check1(j)||check1(k)) {
                    ans++;
                }
    printf("%d", ans);
}
