/* Update : 2025-02-04 */

#include <bits/stdc++.h>

struct KMP {
    long long size; std::vector<long long> pi; std::string s;
    explicit KMP(const std::string& s) : size(std::ssize(s)), pi(std::ssize(s), 0), s(s) {
        for(long long j=0, i=1; i<size; i++) {
            while(j && s[i] != s[j]) j = pi[j-1];
            if(s[i] == s[j]) pi[i] = ++j;
        }
    }
    /// t에서 문자열을 찾고, 시작 위치들이 담긴 벡터를 반환
    std::vector<long long> findAt(const std::string& t) {
        std::vector<long long> ans; long long n = std::ssize(t);
        for(long long i=0, j=0; i<n; i++) {
            while(j && t[i] != s[j]) j = pi[j-1];
            if(t[i] == s[j]) {
                if(j == size-1) ans.emplace_back(i-size+1), j=pi[j];
                else j++;
            }
        }
        return ans;
    }
};

// Example : BOJ 1786. 찾기
int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string t, p;
    getline(cin, t); getline(cin, p);
    KMP kmp(p);
    auto ans = kmp.findAt(t);
    cout << ans.size() << '\n';
    for(long long i : ans) cout << i+1 << ' ';
}
