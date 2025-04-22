#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // 입력받기
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    string ans; // 답, 불가능한 경우 NO를 출력해야 하기 때문에 저장해놨다가 마지막에 출력
    stack<int> st; // 스택
    int cur = 1; // 현재 스택에 push할 수 있는 수
    for(int i = 0; i < n; i++) {
        // 출력해야 하는 수가 스택의 안쪽에 있는 경우 불가능하다.
        if(!st.empty() && st.top() > arr[i]) { cout << "NO\n"; return 0; }

        // 그게 아닌 경우 st.top() + 1 ~ arr[i]를 스택에 넣은 후 pop하면 된다.
        while(st.empty() || st.top() < arr[i]) ans.push_back('+'), st.push(cur++);
        ans.push_back('-'); st.pop();
    }

    // 답안 출력
    for(char c : ans) cout << c << "\n";
}
