#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n; m = n;
    for(int i=1; i<=n; i++) {
        if(i%2!=1) for(int j=0; j<m; j++) cout << n*(i-1) + j + 1 << " ";
        else for(int j=m-1; j>=0; j--) cout << n*(i-1) + j + 1<< " ";
        cout << "\n";
    }
}