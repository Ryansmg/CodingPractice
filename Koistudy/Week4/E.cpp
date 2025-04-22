#include <iostream>
#include <stack>
using namespace std;
using i64 = long long;

int main() {
    string s; cin >> s;
    stack<i64> st; // -1이면 (, -2이면 [, 아니면 괄호열의 값을 의미
    for(char c : s) {
        if(c == '(') st.push(-1);
        else if(c == '[') st.push(-2);
        else {
            // val : ( 123 ) 인 경우 괄호로 묶인 수, ()인 경우 1
            i64 val = 1;
            if(!st.empty() && st.top() >= 0) val = st.top(), st.pop();

            // 잘못된 괄호 문자열
            if(st.empty() || st.top() != (c == ')' ? -1 : -2)) {
                cout << 0; return 0;
            }

            st.pop(); val *= (c == ')' ? 2 : 3);
            // 계산 결과 스택의 상태가 ( 3 8 ) 과 같은 경우 두 수를 합쳐준다.
            if(!st.empty() && st.top() >= 0) val += st.top(), st.pop();
            st.push(val);
        }
    }
    if(st.size() != 1) cout << 0;
    else cout << st.top();
}
