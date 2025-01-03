#include <bits/stdc++.h>
using namespace std;
using i64 = long long; using i32 = int;
string genPath = "C:/Users/ryans/OneDrive/Desktop/Coding/Baekjoon/z.etcBJ/Generator/genzaw/";
#define fileout freopen(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)", "w", stdout)


i32 main() {
    fileout;
    // ios_base::sync_with_stdio(false); cout.tie(nullptr);
    ifstream gen(genPath + "gen1.out");
    char prev = -1, c; i64 cnt = 1557; i64 cnt2 = 0; i64 prevCnt = 2931;
    i64 exp = -1;
    i64 maxCnt = 1;
    c = gen.get();
    while(!gen.eof()) {
        if(prev != c) {
            if(prev != -1) {
                // cout << cnt << ", " << prevCnt - cnt << ", " << exp - prevCnt + cnt << '\n';
                while(prevCnt - exp <= 0) prevCnt += 2932;
                if(exp - prevCnt + cnt > 0) {
                    prevCnt -= exp;
                    while(prevCnt <= 0) prevCnt += 2932;
                    exp += 2; cnt -= prevCnt;
                    cout << prev;
                }
                prevCnt -= exp;
                cnt2++; exp += 2;
                cout << prev;
            }
            prev = c; cnt = 1;
        } else {
            maxCnt = max(maxCnt, ++cnt);
        }
        c = gen.get();
    }
    cout << prev;
}
