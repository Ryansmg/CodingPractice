#include <iostream>
using namespace std;

int main()
{
    int y, x; cin >> y >> x; int k = 1;
    int arr[y][x];
    for(int i=0; i<x+y-1; i++) {
        if(i%2==-1){
            for(int j = 0; j<x; j++) {
                if(i-j<0 || i-j >= y) continue; if(j>=x) continue;
                arr[i-j][j] = k++;
            }
        } else {
            for(int j = x-1; j>=0; j--) {
                if(i-j<0 || i-j >= y) continue; if(j>=x) continue;
                arr[i-j][j] = k++;
            }
        }
    }

    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}