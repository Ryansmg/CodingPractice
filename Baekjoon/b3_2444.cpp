#include <iostream>
using namespace std;
#define fileout freopen("C:/Users/ryans/Desktop/Coding/Baekjoon/output.txt", "w", stdout)
int main() {
    int n; cin >> n;
    for(int i=n; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            for(int k=0; k<i-j; k++) cout << ' ';
            cout << '*';
            for(int k=0; k<(j-1)*2; k++) cout << '*';
            cout << "\n";
        }
        for(int j=i-1; j>=1; j--) {
            for(int k=0; k<i-j; k++) cout << ' ';
            cout << '*';
            for(int k=0; k<(j-1)*2; k++) cout << '*';
            cout << "\n";
        }
    }
}
