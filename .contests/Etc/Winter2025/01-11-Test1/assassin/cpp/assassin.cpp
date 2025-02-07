#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define forn(i, n) for(int i=0; i<n; i++)
#define forf(i, a, b) for(int i = a; i <= b; i++)
template <typename T> using v = vector<T>;


v<v<int>> set_tasks(int N){
    v<v<int>> S;
    S.resize(23, v<int>()); // 0~10 : 비트, 11~20 : 비트 확인, 21~22 : 홀수

    forf(i, 1, N) {
        forn(j, 11) {
            if(i & (1 << j)) {
                S[j].emplace_back(i);
                if(j != 10) S[j+11].emplace_back(i);
            }
        }
        if(__popcount(i) & 1) S[21].emplace_back(i), S[22].emplace_back(i);
    }

    return S;
}

v<int> find_location(v<v<int>> R){
    v<int> ans;
    for(v<int>& s : R) {
        i64 bitCnt = 0, cans = 0;
        i64 spy = -1;
        bool isOddSpy = s[21] != s[22];
        bool isOdd = s[21];
        forn(j, 11) {
            if(s[j]) cans ^= 1 << j, bitCnt++;
            if(j != 10 && s[j] != s[j+11]) spy = j;
        }
        if(isOddSpy) {
            ans.emplace_back(cans); continue;
        }
        if(isOdd == (bitCnt & 1)) {
            ans.emplace_back(cans); continue;
        }
        if(spy == -1) spy = 10;
        ans.emplace_back(cans ^ (1 << spy));
    }
    return ans;
}
