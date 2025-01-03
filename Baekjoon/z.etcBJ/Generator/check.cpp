#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main() {
    long long n; cin >> n;
    ifstream ans(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\Generator\genzaw\gen)" + to_string(n) + ".out"),
        output(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\Generator\output\gen)" + to_string(n) + ".out");
    string s1, s2;
    long long line = 1;
    while(!ans.eof()) {
        if(output.eof()) { cout << "short output\n"; }
        assert(!output.eof());
        getline(ans, s1); getline(output, s2);
        if(s1 != s2) {
            cout << "line " << line << "\n";
            long long pos = 0;
            while(s1[pos] == s2[pos]) pos++;
            cout << "pos: " << pos << '\n';
            // cout << "output   : " << s2 << '\n';
            // cout << "expected : " << s1 << '\n';
        }
        assert(s1 == s2);
        line++;
    }
    if(!output.eof()) { cout << "long output\n"; }
    assert(output.eof());
    cout << "Accepted";
}
