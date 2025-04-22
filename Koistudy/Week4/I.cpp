#include <vector>
#include <iostream>
using namespace std;

// Week4 I. chemoon100의 짝 맞추기

int main() {
    vector<char> st;
    string s; cin >> s;
    for(char c : s) {
        while(!st.empty() && st.back() == c) {
            st.pop_back(); c = (c == 'c' ? 'a' : c + 1);
        }
        st.push_back(c);
    }
    for(char c : st) cout << c;
}
