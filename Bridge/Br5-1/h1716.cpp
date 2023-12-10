#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    for(int i=n; i>=1; i--) {
        for(int j=0; j<m; j++) 
            cout << n*(m-j) - i + 1<< " ";
        cout << "\n";
    }
}