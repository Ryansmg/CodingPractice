//#include "password.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

static std::string s;
static int N, T;
static int questions; // Number of questions asked

std::string solve(int N, int T);

void WA(std::string s) {
    std::cout << "Wrong Answer, " << s << std::endl;
    exit(0);
}

bool ask_question(std::string p) {
    questions++;
    if (p.size() > s.size()) WA("Wrong query size");
    if (p.empty()) WA("Wrong query size");
    for (int i = 0; i < p.size(); i++) {
        if (p[i] != '0' && p[i] != '1') {
            WA("String is not a binary string");
        }
    }
    if(questions > T) {
        WA("Too many queries");
    }
    std::string ss = p + "#" + s;
    std::vector<int> pr(ss.size() + 1);
    pr[0] = -1;
    bool answer = false;
    for (int i = 1; i <= ss.size(); i++) {
        int k = pr[i - 1];
        while (k >= 0 && ss[k] != ss[i - 1])
            k = pr[k];
        pr[i] = k + 1;
        if (pr[i] == p.size()) {
            answer = true;
            break;
        }
    }
    return answer;
}

int main() {
    std::cin >> N >> T;
    std::cin >> s;
    if(s.size() != N) {
        std::cout << "Input Error: size of s is not N" << std::endl;
        return 0;
    }
    std::string ans = solve(s.size(), T);
    std::cout << questions << std::endl << ans << std::endl;
    return 0;
}

///////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
using i32 = int; using i64 = long long;
const i64 i64max = 9223372036854775807;
const i64 INF    = 1000000000000000000;
const i64 inf    = 3000000000;
template <typename T> using v = vector<T>;
template <typename T> using v2 = v<v<T>>;
#define forn(i, n) for(i64 i=0; i<n; i++)
#define forf(i, a, b) for(i64 i=a; i<=b; i++)
#define all(vec) (vec).begin(), (vec).end()
template <typename T> void sort(v<T> &arr) { sort(all(arr)); }
template <typename T> void compress(v<T> &arr, bool autosort = true) { if(autosort) sort(arr); arr.erase(unique(all(arr)), arr.end()); }
i64 idx(i64 val, const v<i64> &compressed) { return lower_bound(all(compressed), val) - compressed.begin(); }

#ifndef LOCAL
#define NDEBUG
#endif

string merge(string a, const string &b) {
    assert(a.back() == b[0]);
    a.pop_back(); a += b; return a;
}

string solve(int n, int t) {
    if(N==1) { if(ask_question("0")) return "0"; return "1"; }
    else if(N==2) { string arr[] = { "00", "01", "10", "11" }; for(int i=0; i<3; i++) if(ask_question(arr[i])) return arr[i]; return arr[3]; }
    // else if(N==3) { string arr[] = { "000", "001", "010", "011", "100", "101", "110", "111" }; for(int i=0; i<7; i++) if(ask_question(arr[i])) return arr[i]; return arr[7]; }
    // else if(N==4) { string arr[] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" }; for(int i=0; i<15; i++) if(ask_question(arr[i])) return arr[i]; return arr[15]; }
    // else if(N==5) { string arr[] = { "00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111", "01000", "01001", "01010", "01011", "01100", "01101", "01110", "01111", "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111", "11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111" }; for(int i=0; i<31; i++) if(ask_question(arr[i])) return arr[i]; return arr[31]; }

    v<string> pre00, pre01, pre10, pre11;
    v<string> cur00, cur01, cur10, cur11;
    pre00.push_back("00"), pre01.push_back("01"), pre10.push_back("10"), pre11.push_back("11");
    forf(i, 3, N) {
        for(i64 i=0; i<pre00.size(); i++) {
            string s = merge(pre00[i], pre00[i]);
            if(ask_question(s)) cur00.push_back(s);
            for(i64 j=i+1; j<pre00.size(); j++) {
                s = merge(pre00[i], pre00[j]);
                if(ask_question(s)) cur00.push_back(s);
            }
        }
        for(i64 i=0; i<pre00.size(); i++) {
            string s = merge(pre00[i], pre00[i]);
            if(ask_question(s)) cur00.push_back(s);
            for(i64 j=i+1; j<pre00.size(); j++) {
                s = merge(pre00[i], pre00[j]);
                if(ask_question(s)) cur00.push_back(s);
            }
        }
    }
}