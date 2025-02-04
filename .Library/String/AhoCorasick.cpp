/* Update : 2025-02-04 */

#include <bits/stdc++.h>

class AhoCorasick {
    signed charCnt; char offset;
    std::vector<std::vector<signed>> con; std::vector<signed> finish, fail; long long av = 0; bool findAvailable = false;
    signed next() { con.emplace_back(charCnt, -1); finish.emplace_back(0); fail.emplace_back(-1); return av++; }
public:
    explicit AhoCorasick(signed size = 26, char startChar = 'a') : charCnt(size), offset(startChar) { next(); }
    void insert(const std::string& s, long long idx = 0, long long p = 0) { // s[idx] == 만들어야 할 노드
        assert(!findAvailable);
        if(idx == std::ssize(s)) { finish[p] = 1; return; }
        signed nxt = s[idx] - offset;
        if(con[p][nxt] == -1)  con[p][nxt] = next();
        insert(s, idx+1, con[p][nxt]);
    }
    void init() {
        std::queue<signed> q; q.emplace(0);
        fail[0] = 0;
        while(!q.empty()) {
            signed cur = q.front(); q.pop();
            for(long long i = 0; i < charCnt; i++) {
                if(con[cur][i] == -1) continue;
                signed nxt = con[cur][i], x = fail[cur];
                if(!cur) { fail[nxt] = 0; q.emplace(nxt); continue; }
                while(x && con[x][i] == -1) x = fail[x];
                if(con[x][i] != -1) x = con[x][i];
                fail[nxt] = x;
                finish[nxt] += finish[fail[nxt]];
                q.emplace(nxt);
            }
        }
        findAvailable = true;
    }
    /// s의 부분문자열과 insert한 문자열이 일치하는 개수를 반환함.
    /// 이 함수를 호출한 이후에는 insert() 사용 불가
    long long findAt(const std::string& s) {
        if(!findAvailable) init();
        signed cur = 0; long long ans = 0;
        for(char i : s) {
            signed idx = i - offset;
            while(cur && con[cur][idx] == -1) cur = fail[cur];
            if(con[cur][idx] != -1) cur = con[cur][idx];
            ans += finish[cur];
        }
        return ans;
    }
};

/// Example : BOJ 9250. 문자열 집합 판별
int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n; cin >> n;
    AhoCorasick ac(26, 'a');
    for(long long i = 0; i < n; i++) {
        string s; cin >> s;
        ac.insert(s);
    }
    long long q; cin >> q;
    for(long long i = 0; i < q; i++) {
        string s; cin >> s;
        cout << (ac.findAt(s) ? "YES" : "NO") << '\n';
    }
}