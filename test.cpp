#include <bits/stdc++.h>
using namespace std;

string reversed(string s) { reverse(s.begin(), s.end()); return s; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) {
        string s; cin >> s;
        cout << (s == reversed(s) ? "YES" : "NO") << '\n';
    }
}
