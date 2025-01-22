#include <bits/stdc++.h>
using namespace std;
using i32 = int; using i64 = long long;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

i32 main() {
    // how to use:
    // 1. set timeLimit (ms)
    // 2. set generator.exe, solution.exe, target.exe
    //   generator.exe generates random testcase at input.txt,
    //   solution.exe generates answer at ans.txt,
    //   target.exe generates wrong answer at output.txt
    // 3. wait
    
    i64 timeLimit = 10000;
    
    // settings
    constexpr bool stop_at_TLE_encounter = true;
    constexpr bool use_generated_input = false;
    constexpr bool use_generated_answer = false;
    constexpr i64 log_flush_rate = 1;
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma clang diagnostic push
#pragma ide diagnostic ignored "Simplify"
    fastio;
    timeLimit = timeLimit * 3 + 100; i64 tc = 0;
    while(true) {
        tc++;
        i64 genCl, solCl, tarCl, chCl, cl = clock();
        // generate input
        if(!use_generated_input) system(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\findCounterExample\generator.exe)");
        genCl = clock() - cl; cl = clock();
        // generate answer
        if (!use_generated_answer) system(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\findCounterExample\solution.exe)");
        solCl = clock() - cl; cl = clock();
        // generate (possibly) wrong answer
        system(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\findCounterExample\target.exe)");
        tarCl = clock() - cl; cl = clock();

        ifstream ans(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\ans.txt)"),
            output(R"(C:\Users\ryans\OneDrive\Desktop\Coding\Baekjoon\z.etcBJ\output.txt)");
        string s1, s2;
        long long line = 0;
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
        ans.close();
        output.close();
        chCl = clock() - cl;
        cout << "Testcase " << tc << " : Accepted, " << line << " lines, " << "gen/sol/tar/chk (ms) : " <<
            genCl << "/" << solCl << "/" << tarCl << "/" << chCl << "\n";
        if(tc % log_flush_rate == 0) cout.flush();
        if(tarCl > timeLimit && stop_at_TLE_encounter) cerr << "Time Limit Exceeded" << endl;
        if(stop_at_TLE_encounter) assert(tarCl <= timeLimit);
#pragma clang diagnostic pop
    }
}
