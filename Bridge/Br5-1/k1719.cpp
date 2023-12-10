#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n; m = n;
    int k = 1;
    vector<int> tarr(n);
    vector<vector<int>> arr(n, tarr);
    for(int i=0; i<n; i++) {
        if(i%2==0) {
            for(int j=0; j<n; j++) {
                arr[j][i] = k++;
            }
        } else {
            for(int j=n-1; j>=0; j--) {
                arr[j][i] = k++;
            }
        }
    }

    for(auto a : arr) {
        for(auto b : a)
            cout << b << " ";
        cout << "\n";
    }
}