#include <iostream>
using namespace std;

int arr[1010][1010];
signed main()
{
    int h, w, t; cin >> h >> w >> t;
    for(int i=0; i<t; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1; x <= x2; x++){
            arr[x-1][y1-1]++;
            arr[x-1][y2]--;
        }
    }
    for(int i=0; i<h; i++) {
        for(int j=1; j<w; j++)
            arr[i][j] += arr[i][j-1];
    }
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++)
            cout << arr[i][j]%2 << ' ';
        cout << '\n';
    }
}
