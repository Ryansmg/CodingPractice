#include <iostream>
#include <stack>
using namespace std;

int priority(char c) {
    switch(c) {
        case '+':
        case '-':
            return 0;
        case '*':
        case '/':
            return 1;
        case '(':
            return -2;
        default:
            return -1;
    }
}

// Week4 G. 후위표현식 II
int main() {
    string s; cin >> s;
    stack<char> st;
    for(char c : s) {
        // 괄호가 닫혔을 경우 괄호로 묶인 식 안의 연산을 전부 처리
        if(c == ')') {
            while(st.top() != '(') cout << st.top(), st.pop();
            st.pop();
            continue;
        }
        if(c == '(') { st.push(c); continue; }

        // 문자인 경우 바로 출력
        if(priority(c) == -1) cout << c;
        // 나보다 우선순위가 높은 연산을 모두 처리한 후 스택에 현재 연산을 push
        else {
            while(!st.empty() && priority(st.top()) >= priority(c)) cout << st.top(), st.pop();
            st.push(c);
        }
    }

    // 남은 연산 전부 처리
    while(!st.empty()) cout << st.top(), st.pop();
}
