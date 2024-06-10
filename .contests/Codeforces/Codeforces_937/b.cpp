#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    for(int i=0; i<t; i++) {
        int n; cin >> n;
        for(int j=0; j<n*2; j++) {
            for(int k=0; k<n*2; k++) {
                if((k/2)%2==(j/2)%2) cout << '#';
                else cout << '.';
            }
            cout << "\n";
        }
    }
}