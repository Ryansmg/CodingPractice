#include <iostream>
using namespace std;

int main(){
    string in[10][10];
    string s;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cin >> s;
            in[i][j] = s;
        }
    }
    for(int i=0; i<10; i++) {
        //가로
        string start = in[i][0];
        for(int j=1; j<10; j++) {
            if(in[i][j].compare(start) != 0) break;
            if(j==9) {
                cout << 1; return 0;
            }
        }
        //세로
        start = in[0][i];
        for(int j=1; j<10; j++) {
            if(in[j][i].compare(start) != 0) break;
            if(j==9) {
                cout << 1; return 0;
            }
        }
    }
    cout << 0;
}