#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n; string s;
    cin >> n >> s;

    stack<char> st; // 스택
    vector<string> ans; // 답안 저장

    int i = 0; // 현재 push할 수 있는 index
    for(char c = '1'; c <= '0' + n; c++) {
        // pop했을 때 c가 나오도록 push
        while(st.empty() || st.top() != c) {
            // 더 이상 push할 수 없으면 불가능한 경우임.
            if(i == n) {
                cout << -1; return 0;
            }
            st.push(s[i++]);
            ans.push_back("push");
        }
        st.pop();
        ans.push_back("pop");
    }

    // 정답 출력
    for(const string& s : ans) cout << s << "\n";
}
