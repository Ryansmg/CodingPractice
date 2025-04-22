#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n; cin >> n;
    // 스택 안의 값들이 strictly decreasing하도록 관리하면,
    // 스택의 크기의 최댓값 - 1 이 문제의 답이 된다.
    stack<int> st;
    int ans_idx = 1, ans_val = 0;
    for(int i = 1; i <= n; i++) {
        int t; cin >> t;
        while(!st.empty() && st.top() <= t) st.pop();
        st.push(t);

        if(ans_val < st.size()) ans_idx = i, ans_val = st.size();
    }
    cout << ans_idx << " " << ans_val - 1 << "\n";
}
