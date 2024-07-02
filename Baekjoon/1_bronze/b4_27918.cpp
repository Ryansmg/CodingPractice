#include <bits/stdc++.h>
using namespace std;
__int128 operator ""_I(const char* str, size_t len) {
    __int128 t = 0; int st=0, sign=1; if(*str == '-') sign=-1, st=1;
    for(int i=st; i < len; i++) { t *= 10; t += (*(str + i) - '0'); }
    return t*sign;
}
istream &operator>>(istream &in, __int128 &l) {
    string s; in >> s; size_t len = s.size(); int sign = 1, st = 0; l=0;
    if(s[0]=='-') sign=-1, st=1; for(int i=st; i<len; i++) { l *= 10; l += s[i]-'0'; }
    l*=sign; return in;
}
ostream &operator<<(ostream &out,const __int128 &i) {
    __int128 t = i<0?-i:i; if(!t) out << 0; if(i<0) out << '-';
    stack<char> st; while(t) { st.push((char)((t%10)+'0')); t/=10; }
    while(!st.empty()){out<<st.top();st.pop();} return out;
}
int main() {
    __int128 n; cin >> n;
    __int128 d=0, p=0;
    for(int i=0; i<n; i++) {
        char c; cin >> c;
        if(c=='D')d++;else p++;
        if(abs(d-p)>=2)break;
    }
    cout << d << ':' << p;
}
