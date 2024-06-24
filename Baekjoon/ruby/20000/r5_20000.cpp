#include <bits/stdc++.h>
#define forf(a,b,c) for(int a=b;a<=c;a++)
using l=long long;
using namespace std;

void p1() {
    cout << "#include <cstdio>\nint main(){\n    int N;\n    scanf(\"%d\",&N);\n    if(N==1){\n        puts(\"4\");\n    }\n";
    forf(i,2,20000)cout << "    else if(N=="<<i<<"){\n        puts(\""<<4*i<<"\");\n    }\n";
    cout << "    else{\n        puts(\"Still working on it...\");\n    }\n    return 0;\n}\n";
}
void p2() {

}
void p3() { }
void p4() { }
void p5() { }
void p6() { }
void p7() { }
void p8() { }
void p9() { }

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); l N; cin>>N;
    freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout);
    if(!N)cout<<"BOJ 20000\n";if(N==1)p1();if(N==2)p2();if(N==3)p3();if(N==4)p4();
    if(N==5)p5();if(N==6)p6();if(N==7)p7();if(N==8)p8();if(N==9)p9();
}