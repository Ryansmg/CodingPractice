#include <vector>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s, bs; cin >> s >> bs;
    int sl = s.length();
    int bsl = bs.length();
    vector<char> st;
    for(int i = 0; i < sl; i++) {
        st.push_back(s[i]);
        bool redo = true;
        while(st.back() == bs[bsl-1] && redo) {
            redo = false;
            if(i-bsl+1>=0) {
                bool match = true;
                int stl = st.size();
                for(int j=0; j < bsl; j++) {
                    if(st[j + stl - bsl] != bs[j]) {
                        match = false;
                        break;
                    }
                }
                if(match) {
                    for(int i=0; i<bsl; i++) {
                    st.pop_back();
                    }
                    redo = true;
                }
            }
        }
    }
    if(st.empty()) {
        cout << "FRULA";
    } else {
        for(char c : st) cout << c;
    }
}