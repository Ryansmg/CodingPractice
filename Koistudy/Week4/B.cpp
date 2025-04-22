#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s; cin >> s;
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '[' || c == '{') st.push(c);
        else {
            if(st.empty() || st.top() != (c == ')' ? '(' : (c == ']' ? '[' : '{'))) {
                cout << "X\n"; return 0;
            }
            st.pop();
        }
    }
    cout << (st.empty() ? "O" : "X") << "\n";
}
