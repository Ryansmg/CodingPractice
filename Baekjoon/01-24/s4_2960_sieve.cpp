#include <iostream>
#include <vector>
using namespace std;

//에라토스테네스의 체

int main()
{
    int n, k; cin >> n >> k;
    vector<bool> isp(n+1, true);
    isp[0] = isp[1] = false;
    int ck = 0, i, p = 2;
    while(true){
        while(!isp[p]) p++;
        i = p;
        ck++;
        if(ck==k) goto end;
        for(i=p*2; i<=n; i+=p) {
            if(isp[i]) ck++;
            isp[i] = false;
            if(ck==k) goto end;
        }
        p++;
    }
    end:
    cout << i;
}