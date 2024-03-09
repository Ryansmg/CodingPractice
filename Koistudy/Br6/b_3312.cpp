#include <iostream>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    bool a = false, ab = false, b = false, o = false;
    for(int aaa=0; aaa<=1; aaa++){
    for(int bbb=0; bbb<=1; bbb++) {
        char c1 = s1[aaa], c2 = s2[bbb];
        if(c1>c2) swap(c1, c2);
        if(c1=='A' && c2=='B') ab=true;
        else if(c1=='A') a=true;
        else if(c1=='B') b=true;
        else o=true;
    }
    }
    if(a) cout << "A ";
    if(ab) cout << "AB ";
    if(b) cout << "B ";
    if(o) cout << "O";
}