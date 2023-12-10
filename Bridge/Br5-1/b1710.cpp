#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) 
            cout << n*i - j + 1 << " ";
        cout << "\n";
    }
}