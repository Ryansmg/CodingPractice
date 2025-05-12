#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using i64 = long long;

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

i64 calc(i64 a, i64 b, char op) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    return a / b;
}

// Week4 H. 수식계산 II
int main() {
    string s; cin >> s;
    int n = (int) s.size();

    // 구현의 편의를 위해 먼저 연산자와 수를 분리해서 저장하자.
    vector<string> arr;
    i64 cur = 0;
    for(int i = 0; i < n; i++) {
        if(isdigit(s[i])) {
            cur = s[i] - '0';
            while(++i < n && isdigit(s[i])) cur = cur * 10 + s[i] - '0';
            i--;
            arr.push_back(to_string(cur));
        } else {
            arr.push_back(string(1, s[i]));
        }
    }

    stack<char> op; // 연산자를 넣는 스택
    stack<i64> val; // 값을 넣는 스택

    // val 맨 위의 두 값을 가져와 op 맨 위의 연산자로 계산한 후 val에 push하는 연산을 정의
    #define calculate { i64 b = val.top(); val.pop(); i64 a = val.top(); val.pop(); val.push(calc(a, b, op.top())); op.pop(); }

    // 그 이후는 후위표현식 II와 유사하게 해주면 된다.
    for(const string& c : arr) {
        if(c == ")") {
            while(op.top() != '(') calculate
            op.pop();
            continue;
        }
        if(c == "(") { op.push('('); continue; }

        // 수인 경우 val 스택에 넣음
        if(isdigit(c[0])) val.push(stoll(c));
        // 나보다 우선순위가 높은 연산을 모두 처리한 후 스택에 현재 연산을 push
        else {
            while(!op.empty() && priority(op.top()) >= priority(c[0])) calculate
            op.push(c[0]);
        }
    }

    // 남은 연산 전부 처리
    while(!op.empty()) calculate
    cout << val.top();
}
