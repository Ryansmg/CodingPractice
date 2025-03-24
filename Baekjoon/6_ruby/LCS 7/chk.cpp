#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerTestlibCmd(argc, argv);
    int al = ans.readInt();
    int bl = ouf.readInt();
    if(al == bl && al == 0) quitf(_ok, "correct");
    if(al == bl) {
        string a = inf.readToken();
        string b = inf.readToken();
        string o = ouf.readToken();
        int j = 0;
        for(int i=0; i<a.length(); i++) {
            if(j < o.length() && o[j] == a[i]) j++;
        }
        if(j != o.length()) quitf(_wa, "wrong lcs a");
        j = 0;
        for(int i=0; i<b.length(); i++) {
            if(j < o.length() && o[j] == b[i]) j++;
        }
        if(j != o.length()) quitf(_wa, "wrong lcs b");
    } else quitf(_wa, "wrong length");
    quitf(_ok, "correct");
}