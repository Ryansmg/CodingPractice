#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main() {
    ifstream ans(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\ans.txt)"),
        output(R"(C:\Users\ryans\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)");
    string s1, s2;
    long long line = 1;
    while(!ans.eof()) {
        if(output.eof()) { cout << "short output\n"; }
        assert(!output.eof());
        getline(ans, s1); getline(output, s2);
        if(s1 != s2) {
            cout << "line " << line << "\n";
            cout << "output   : " << s2 << '\n';
            cout << "expected : " << s1 << '\n';
        }
        assert(s1 == s2);
        line++;
    }
    if(!output.eof()) { cout << "long output\n"; }
    assert(output.eof());
    cout << "Accepted";
}
