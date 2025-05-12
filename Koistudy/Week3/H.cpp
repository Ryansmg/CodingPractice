#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;
i64 mod1 = 1000000007;

// A, C의 n을 A로 모으는 이동 = n-1을 B로 모으는 이동 + 1 + 2*(n-1)을 A로 모으는 이동
// A, C의 n을 B로 모으는 이동 = n-1을 A로 모으는 이동 + 1 + 2*(n-1)을 C로 모으는 이동 + 1 + 2*(n-1)을 이동
// 2*(n-1)을 이동시키기 : 2*(n-2)를 이동시키기 + 2 + 2*(n-2)를 이동시키기

int main() {
    vector<i64> dp1(1001000), dp2(1001000), dp3(1001000);
    dp1[1] = 1; dp2[1] = 2; dp3[1] = 2;
    for(i64 i = 2; i <= 1000010; i++) dp3[i] = (dp3[i-1] * 2 + 2) % mod1;
    for(i64 i = 2; i <= 1000010; i++) {
        dp1[i] = (dp2[i-1] + 1 + dp3[i-1]) % mod1;
        dp2[i] = (dp1[i-1] + 2 + 2*dp3[i-1]) % mod1;
    }
    i64 n; cin >> n; cout << dp2[n] << '\n';
}
