#include <iostream>
#include <string>
using namespace std;

int main() {
    // cnt : 여는 괄호의 개수 - 닫는 괄호의 개수
    // 중간에 음수가 되거나 끝났을 때 0이 아니면 잘못된 괄호 문자열임.
    int cnt = 0;
    string s; cin >> s;
    for(char c : s) {
        if(c == '(') cnt++;
        else {
            if(cnt == 0) {
                cout << "NO\n";
                return 0;
            }
            cnt--;
        }
    }
    cout << (cnt ? "NO" : "YES") << "\n";
}
