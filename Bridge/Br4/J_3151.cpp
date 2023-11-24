#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

ll max(ll a, ll b) {
    return a>b?a:b;
}
int main() {
    char a; cin >> a;
    string base = "5!!5!!5\n3!4!1!4!3\n1!7!7!1\n!98!\n1!96!1\n3!92!3\n5!7!5\n7!3!7\n9!";
    for(char c : base) {
        if(c=='!') cout << a;
        else if(c>='0' && c<='9')
            for(int i=0; i<c-'0'; i++) cout << " ";
        else cout << c;
    }
}